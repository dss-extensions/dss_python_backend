import atexit
from weakref import WeakKeyDictionary
from .enums import AltDSSEvent
from . import ffi, lib

LEGACY_EVENTS = (
    AltDSSEvent.Legacy_InitControls,
    AltDSSEvent.Legacy_CheckControls,
    AltDSSEvent.Legacy_StepControls,
)

class EventCallbackManager:
    _ctx_to_manager = WeakKeyDictionary()

    def __init__(self, ctx):
        if ctx in EventCallbackManager._ctx_to_manager:
            raise ValueError('This context already has a manager. Use "get_manager_for_ctx" to get it.')

        EventCallbackManager._ctx_to_manager[ctx] = self
        self.ctx = ctx
        for evt_type in AltDSSEvent:
            setattr(self, evt_type.name, [])


    def unregister_all(self):
        for evt_type in AltDSSEvent:
            handlers = getattr(self, evt_type.name)
            if not handlers:
                continue

            handlers[:] = []
            lib.ctx_DSSEvents_UnregisterAlt(
                self.ctx,
                evt_type,
                lib.altdss_python_util_callback
            )

    def __del__(self):
        self.unregister_all()

    def register_func(self, evt: AltDSSEvent, func) -> bool:
        handlers = getattr(self, AltDSSEvent(evt).name)
        if len(handlers) == 0:
            if lib.ctx_DSSEvents_RegisterAlt(
                self.ctx,
                evt,
                lib.altdss_python_util_callback
            ) == 0:
                raise RuntimeError('Could not register main callback function.')

        if func in handlers:
            return False

        handlers.append(func)
        return True

    def unregister_func(self, evt: AltDSSEvent, func) -> bool:
        handlers = getattr(self, AltDSSEvent(evt).name)
        prev_len = len(handlers)
        handlers[:] = [f for f in handlers if f is not func]
        if len(handlers) == 0:
            lib.ctx_DSSEvents_UnregisterAlt(
                self.ctx,
                evt,
                lib.altdss_python_util_callback
            )

        return prev_len != len(handlers)


    def handle_event(self, ctx, evt: AltDSSEvent, step: int, ptr):
        evt = AltDSSEvent(evt)
        handlers = getattr(self, evt.name)

        # No arguments for legacy (classic COM impl.) OpenDSS events
        if evt in LEGACY_EVENTS:
            for handler in handlers:
                handler()

            return

        for handler in handlers:
            handler(ctx, evt, step, ptr)



def get_manager_for_ctx(ctx) -> EventCallbackManager:
    m = EventCallbackManager._ctx_to_manager.get(ctx)
    if m is None:
        m = EventCallbackManager(ctx)

    return m


@ffi.def_extern()
def altdss_python_util_callback(ctx, eventCode: int, step: int, ptr):
    m = EventCallbackManager._ctx_to_manager.get(ctx)
    if m is None:
        return

    try:
        m.handle_event(ctx, eventCode, step, ptr)

    except Exception as ex:
        err_ptr = lib.ctx_Error_Get_NumberPtr(ctx)
        err_ptr[0] = 1
        lib.ctx_Error_Set_Description(ctx, f"Python callback exception: {ex}".encode())


def _remove_callbacks():
    '''
    Remove all callbacks at exit. Since the native library may outlive the Python callbacks,
    we need to remove the callbacks here to ensure they are not called.
    '''
    for ctx_mgr in EventCallbackManager._ctx_to_manager.values():
        ctx_mgr.unregister_all()

atexit.register(_remove_callbacks)

__all__ = ['get_manager_for_ctx']
