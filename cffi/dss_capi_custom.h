extern "Python" int32_t dss_python_cb_plot(void* ctx, char* params);
extern "Python" int32_t dss_python_cb_write(void* ctx, char* messageStr, int32_t messageType);

extern "Python" void dss_python_cb_init_controls(void* ctx);
extern "Python" void dss_python_cb_check_controls(void* ctx);
extern "Python" void dss_python_cb_step_controls(void* ctx);

extern "Python" void altdss_python_util_callback(void* ctx, int32_t eventCode, int32_t step, void* ptr);
