try:
    from enum import IntEnum, IntFlag
except (ModuleNotFoundError, ImportError):
    try:
        from aenum import IntEnum, IntFlag
    except (ModuleNotFoundError, ImportError):
        IntEnum = object
        IntFlag = object

#TODO: add missing enums

class MonitorModes(IntEnum):
    VI = 0x00
    """Monitor records Voltage and Current at the terminal (Default)"""

    Power = 0x01
    """Monitor records kW, kvar or kVA, angle values, etc. at the terminal to which it is connected."""

    Taps = 0x02
    """For monitoring Regulator and Transformer taps"""

    States = 0x03
    """For monitoring State Variables (for PC Elements only)"""

    Sequence = 0x10
    """Reports the monitored quantities as sequence quantities"""

    Magnitude = 0x20
    """Reports the monitored quantities in Magnitude Only"""

    PosOnly = 0x40
    """Reports the Positive Seq only or avg of all phases"""

class SolveModes(IntEnum):
    SnapShot = 0
    """Solve a single snapshot power flow"""

    Daily = 1
    """Solve following Daily load shapes"""

    Yearly = 2
    """Solve following Yearly load shapes"""

    Monte1 = 3
    """Monte Carlo Mode 1"""

    LD1 = 4
    """Load-duration Mode 1"""

    PeakDay = 5
    """Solves for Peak Day using Daily load curve"""

    DutyCycle = 6
    """Solve following Duty Cycle load shapes"""

    Direct = 7
    """Solve direct (forced admittance model)"""

    MonteFault = 8
    """Monte carlo Fault Study"""

    FaultStudy = 9
    """Fault study at all buses"""

    Monte2 = 10
    """Monte Carlo Mode 2"""

    Monte3 = 11
    """Monte Carlo Mode 3"""

    LD2 = 12
    """Load-Duration Mode 2"""

    AutoAdd = 13
    """Auto add generators or capacitors"""

    Dynamic = 14
    """Solve for dynamics"""

    Harmonic = 15
    """Harmonic solution mode"""

    Time = 16

    HarmonicT = 17


class Options(IntEnum):
    '''Deprecated. Please use instead:
        - AutoAddTypes
        - CktModels
        - ControlModes
        - SolutionLoadModels
        - SolutionAlgorithms
        - RandomModes
    '''

    PowerFlow = 1
    Admittance = 2
    NormalSolve = 0
    NewtonSolve = 1
    Static = 0
    Event = 1
    Time = 2
    Multiphase = 0
    PositiveSeq = 1
    Gaussian = 1
    Uniform = 2
    LogNormal = 3
    AddGen = 1
    AddCap = 2
    ControlOFF = -1

class SolutionLoadModels(IntEnum):
    PowerFlow = 1
    """Power Flow load model option"""

    Admittance = 2
    """Admittance load model option"""

class SolutionAlgorithms(IntEnum):
    NormalSolve = 0
    """Solution algorithm option - Normal solution"""

    NewtonSolve = 1
    """Solution algorithm option - Newton solution"""

class ControlModes(IntEnum):
    Static = 0
    """Control Mode option - Static"""

    Event = 1
    """Control Mode Option - Event driven solution mode"""

    Time = 2
    """Control mode option - Time driven mode"""

    Multirate = 3
    """Control mode option - Multirate mode"""

    Off = -1
    """Control Mode OFF"""

class CktModels(IntEnum):
    Multiphase = 0
    """Circuit model is multiphase (default)"""

    PositiveSeq = 1
    """Circuit model is positive sequence model only"""

class RandomModes(IntEnum):
    Gaussian = 1 # Gaussian
    Uniform = 2 # Uniform
    LogNormal = 3 # Log normal

class AutoAddTypes(IntEnum):
    AddGen = 1
    """Add generators in AutoAdd mode"""

    AddCap = 2
    """Add capacitors in AutoAdd mode"""

class CapControlModes(IntEnum):
    Current = 0
    """Current control, ON and OFF settings on CT secondary"""

    Voltage = 1
    """Voltage control, ON and OFF settings on the PT secondary base"""

    KVAR = 2
    """kVAR control, ON and OFF settings on PT / CT base"""

    Time = 3
    """Time control, ON and OFF settings are seconds from midnight"""

    PF = 4
    """ON and OFF settings are power factor, negative for leading"""


class StorageStates(IntEnum):
    Charging = -1
    Idling = 0
    Discharging = 1


class ActionCodes(IntEnum):
    none = 0
    """No action"""

    Open = 1
    """Open a switch"""

    Close = 2
    """Close a switch"""

    Reset = 3
    """Reset to the shelf state (unlocked, closed for a switch)"""

    Lock = 4
    """Lock a switch, preventing both manual and automatic operation"""

    Unlock = 5
    """Unlock a switch, permitting both manual and automatic operation"""

    TapUp = 6
    """Move a regulator tap up"""

    TapDown = 7
    """Move a regulator tap down"""


class LoadStatus(IntEnum):
    Variable = 0
    Fixed = 1
    Exempt = 2

class GeneratorStatus(IntEnum):
    Variable = 0
    Fixed = 1

class LoadModels(IntEnum):
    ConstPQ = 1
    ConstZ = 2
    Motor = 3
    CVR = 4
    ConstI = 5
    ConstPFixedQ = 6
    ConstPFixedX = 7
    ZIPV = 8

class LineUnits(IntEnum):
    none = 0
    """No line length unit"""

    Miles = 1
    """Line length units in miles"""

    kFt = 2
    """Line length units are in thousand feet"""

    km = 3
    """Line length units are km"""

    meter = 4
    """Line length units are meters"""

    ft = 5
    """Line units in feet"""

    inch = 6
    """Line length units are inches"""

    cm = 7
    """Line units are cm"""

    mm = 8
    """Line length units are mm"""


class YMatrixModes(IntEnum):
    SeriesOnly = 1
    WholeMatrix = 2

class OCPDevType(IntEnum):
    """Overcurrent Protection Device Type"""

    none = 0
    Fuse = 1
    Recloser = 2
    Relay = 3


class CoreType(IntEnum):
    """Transformer Core Type"""
    shell = 0 # shell
    one_phase = 1 # 1-phase
    three_leg = 3 # 3-leg
    four_leg = 4 # 4-leg
    five_leg = 5 # 5-leg
    core_1_phase = 9 # core-1-phase


class SparseSolverOptions(IntEnum):
    ReuseNothing = 0
    """
    Default behavior, following the official OpenDSS implementation.
    """

    ReuseCompressedMatrix = 1
    """
    Reuse only the prepared CSC matrix. This should be numerically exact, but
    may have some cost saving if the number of entries changed in the system Y
    matrix are a small fraction of the total entries.
    """

    ReuseSymbolicFactorization = 2
    """
    Reuse the symbolic factorization, implies ReuseCompressedMatrix
    """

    ReuseNumericFactorization = 3
    """
    Reuse the numeric factorization, implies ReuseSymbolicFactorization
    """

    AlwaysResetYPrimInvalid = 0x10000000
    """
    Bit flag, see CktElement.pas for details. Some components do not clear the
    dirty flag after their YPrim is updated, so YPrim is updated every time the
    system Y is changed, even if there are no changes to the component. This
    flag forces clearing the dirty flag, keeping the YPrim matrix constant when
    the component has not changed.
    """


class DSSJSONFlags(IntFlag):
    Full = 0x00000001
    """
    Return all properties, regardless of order or if the property was filled by the user
    """

    SkipRedundant = 0x00000002
    """
    Skip redundant properties
    """

    EnumAsInt = 0x00000004
    """
    Return enums as integers instead of strings
    """

    FullNames = 0x00000008
    """
    Use full names for the elements, including the class name
    """

    Pretty = 0x00000010
    """
    Try to "pretty" format the JSON output
    """

    ExcludeDisabled = 0x00000020
    """
    Exclude disabled elements (only valid when exporting a collection)
    """

    IncludeDSSClass = 0x00000040
    """
    Add "DSSClass" property to the output objects
    """

    LowercaseKeys = 0x00000080
    """
    Use lowercase representation for the property names (and other keys) instead of the internal variants.
    """

    IncludeDefaultObjs = 0x00000100
    """
    Include default unchanged objects in the exports.
    Any default object that has been edited is always exported. Affects whole circuit and batch exports.
    """

    SkipTimestamp = 0x00000200
    """
    Skip timestamp/version comment, which is added a pre-command by default. Affects whole circuit exports.
    """

    SkipBuses = 0x00000400
    """
    Skip exporting buses. Affects whole circuit exports.
    """


class DSSCompatFlags(IntFlag):
    NoSolverFloatChecks = 0x00000001
    """
    If enabled, don't check for NaNs in the inner solution loop.
    This can lead to various errors.
    This flag is useful for legacy applications that don't handle OpenDSS API errors properly.
    Through the development of DSS-Extensions, we noticed this is actually a quite common issue.
    """

    BadPrecision = 0x00000002
    """
    If enabled, toggle worse precision for certain aspects of the engine. For
    example, the sequence-to-phase (`As2p`) and sequence-to-phase (`Ap2s`)
    transform matrices. On DSS C-API, we fill the matrix explicitly using
    higher precision, while numerical inversion of an initially worse precision
    matrix is used in the official OpenDSS. We will introduce better precision
    for other aspects of the engine in the future, so this flag can be used to
    toggle the old/bad values where feasible.
    """

    InvControl9611 = 0x00000004
    """
    Toggle some InvControl behavior introduced in OpenDSS 9.6.1.1. It could be a regression
    but needs further investigation, so we added this flag in the time being.
    """

    SaveCalcVoltageBases = 0x00000008
    """
    When using "save circuit", the official OpenDSS always includes the "CalcVoltageBases" command in the
    saved script. We found that it is not always a good idea, so we removed the command (leaving it commented).
    Use this flag to enable the command in the saved script.
    """

    ActiveLine = 0x00000010
    """
    In the official OpenDSS implementation, the Lines API use the active circuit element instead of the
    active line. This can lead to unexpected behavior if the user is not aware of this detail.
    For example, if the user accidentally enables any other circuit element, the next time they use
    the Lines API, the line object that was previously enabled is overwritten with another unrelated
    object.
    This flag enables this behavior above if compatibility at this level is required. On DSS-Extensions,
    we changed the behavior to follow what most of the other APIs do: use the active object in the internal
    list. This change was done for DSS C-API v0.13.5, as well as the introduction of this flag.
    """

    NoPropertyTracking = 0x00000020
    """
    On DSS-Extensions/AltDSS, when setting a property invalidates a previous input value, the engine
    will try to mark the invalidated data as unset. This allows for better exports and tracking of
    the current state of DSS objects.
    Set this flag to disable this behavior, following the original OpenDSS implementation for potential
    compatibility with older software that may require the original behavior; note that may lead to
    erroneous interpretation of the data in the DSS properties. This was introduced in DSS C-API v0.14.0
    and will be further developed for future versions.
    """

    SkipSideEffects = 0x00000040
    """
    Some specific functions on the official OpenDSS APIs skip important side-effects.
    By default, on DSS-Extensions/AltDSS, those side-effects are enabled. Use this flag
    to try to follow the behavior of the official APIs. Beware that some side-effects are
    important and skipping them may result in incorrect results.
    This flag only affects some of the classic API functions, especially Loads and Generators.
    """


class AltDSSEvent(IntEnum):
    """
    Event codes used by the event callback system

    Legacy events are the events present the classic OpenDSS COM implementation,
    while the rest are extensions added here.
    """
    Legacy_InitControls = 0
    Legacy_CheckControls = 1
    Legacy_StepControls = 2
    Clear = 3
    ReprocessBuses = 4
    BuildSystemY = 5


class DSSPropertyNameStyle(IntEnum):
    """
    This enum is used in the PropertyNameStyle property to control the naming convention.
    Currently, this only affects capitalization, i.e., if you software already uses case
    insensitive string comparisons for the property names, this is not useful. Otherwise,
    you can use `Legacy` to use the older names.
    """

    Modern = 0
    """
    By default, the modern names are used. The names were reviewed to try to reach a convention across all components.
    """

    Lowercase = 1
    """
    Use all lowercase strings.
    """

    Legacy = 2
    """
    Use the previous capitalization of the property names.
    """

class DSSSaveFlags(IntFlag):
    """
    DSSSaveFlags are bit flags used in the Circuit_Save function to
    customize the saved circuit.
    """

    CalcVoltageBases = 0x0001
    """Include the command CalcVoltageBases."""

    SetVoltageBases = 0x0002
    """Include commands to set the voltage bases individually."""

    IncludeOptions = 0x0004
    """Include most of the options (from the Set/Get DSS commands)."""

    IncludeDisabled = 0x0008
    """Include disabled circuit elements (and LoadShapes)."""

    ExcludeDefault = 0x0010
    """Exclude default DSS items if they are not modified by the user."""

    SingleFile = 0x0020
    """Use a single file instead of a folder for output."""

    KeepOrder = 0x0040
    """Save the circuit elements in the order they were loaded in the active circuit. Guarantees better reproducibility, especially when the system is ill-conditioned. Requires "SingleFile" flag."""

    ExcludeMeterZones = 0x0080
    """Do not export meter zones (as "feeders") separately. Has no effect when using a single file."""

    IsOpen = 0x0100
    """Export commands to open terminals of elements."""

    ToString = 0x0200
    """Export to the result string. Requires "SingleFile" flag."""


class EnergyMeterRegisters(IntEnum):
    """
    Energy meter registers

    This enumeration lists the basic energy meter registers. Extra registers start
    at `VBaseStart`. This is exposed to make it easier to access common registers
    without needing to check the register names every time, plus makes it safer to
    access the registers by index directly without introducing bugs we found in
    OpenDSS code (both user code and engine code) in the past due to direct use
    of magic numbers.
    """
    kWh = 0
    kvarh = 1
    MaxkW = 2
    MaxkVA = 3
    ZonekWh = 4
    Zonekvarh = 5
    ZoneMaxkW = 6
    ZoneMaxkVA = 7
    OverloadkWhNorm = 8
    OverloadkWhEmerg = 9
    LoadEEN = 10
    LoadUE = 11
    ZoneLosseskWh = 12
    ZoneLosseskvarh = 13
    LossesMaxkW = 14
    LossesMaxkvar = 15
    LoadLosseskWh = 16
    LoadLosseskvarh = 17
    NoLoadLosseskWh = 18
    NoLoadLosseskvarh = 19
    MaxLoadLosses = 20
    MaxNoLoadLosses = 21
    LineLosseskWh = 22
    TransformerLosseskWh = 23
    LineModeLineLoss = 24
    ZeroModeLineLoss = 25
    ThreePhaseLineLoss = 26
    OnePhaseLineLoss = 27
    GenkWh = 28
    Genkvarh = 29
    GenMaxkW = 30
    GenMaxkVA = 31

    VBaseStart = 32
    """Anchor for the voltage base loss registers"""

class GeneratorRegisters(IntEnum):
    """
    Generator registers

    Enumeration of the generator registers by index.
    Currently shared between the Generator, Storage and PVSystem models.
    """

    kWh = 0
    kvarh = 1
    MaxkW = 2
    MaxkVA = 3
    Hours = 4
    Price = 5


class SetterFlags(IntFlag):
    """
    Setter flags customize how the update of DSS properties are handled by the
    engine and parts of the API. Use especially in the `Obj` and `Batch` APIs
    """

    ImplicitSizes = 0x00000001
    """
    Most array properties depend on sizes defined by other properties.
    Using this flag, many properties allow users to skip setting the other property
    directly, allowing the engine to use the size of the provided array to
    initialize the other property.
    """

    AvoidFullRecalc = 0x00000002
    """
    Some components like Loads don't need to update YPrim for every change, e.g. setting
    "`load.a_load.kW=1`" if was "kW" previously 2 should not force a YPrim update, but it does
    force an update by default.
    Using this flag will reproduce what the classic OpenDSS API for Loads (DSS.ActiveCircuit.Loads)
    does, but removes a lot of duplicated code. Besides that, we can extend the feature
    for other components if we think it fits.
    """

    SkipNA = 0x00000004
    """
    For batch operations with arrays, skip NA values

    Currently, NA values are interpreted as:
    - NaN for `float64`
    - INT32_MAX (0x7fffffff) for `int32`
    - Null pointers for strings (in this case, use a `"\\0"` string for empty strings)
    """

    AllowAllConductors = 0x40000000
    """
    Used internally for the "Wires" property ("Conductors").
    This was left public in case someone tries to implement some internal aspects in
    external functions.
    """


class DSSObjectFlags(IntFlag):
    """
    Object flags are bit flags used by various of the internal processes of the DSS engine.

    Most are internal state, but advanced/expert users can manipulate them for some interesting uses.
    """

    Editing = 0x0001

    HasBeenSaved = 0x0002

    DefaultAndUnedited = 0x0004

    Checked = 0x0008

    Flag = 0x0010
    """General purpose flag for each object"""

    HasEnergyMeter = 0x0020

    HasSensorObj = 0x0040

    IsIsolated = 0x0080

    HasControl = 0x0100

    IsMonitored = 0x0200
    """Indicates some control is monitoring this element"""

    HasOCPDevice = 0x0400,
    """Fuse, Relay, or Recloser"""

    HasAutoOCPDevice = 0x0800
    """Relay or Recloser only"""

    NeedsRecalc = 0x1000
    """Used for Edit command loops"""

    NeedsYPrim = 0x2000
    """Used for Edit command loops + setter flags"""


class GeneratorVariables(IntEnum):
    """
    Generator variables

    Enumeration of the generator *state variables* by (1-based) index.
    This is the implicit list and there can be more variables used by user-models
    and DynamicExp objects. For those, users can get the variable names from the
    API.
    """

    Frequency = 1
    '''Frequency (Hz)'''

    Theta = 2
    '''Theta (°)'''

    Vd = 3
    '''Vd (pu)'''

    PShaft = 4
    '''PShaft (W)'''

    dSpeed = 5
    '''dSpeed (°/s)'''

    dTheta = 6
    '''dTheta (°)'''


class IndMach012Variables(IntEnum):
    '''
    IndMach012 variables

    Enumeration of the IndMach012 *state variables* by (1-based) index.
    '''

    Frequency = 1
    '''Frequency'''

    Theta = 2
    '''Theta (deg)'''

    E1 = 3
    '''E1'''

    Pshaft = 4
    '''Pshaft'''

    dSpeed = 5
    '''dSpeed (deg/sec)'''

    dTheta = 6
    '''dTheta (deg)'''

    Slip = 7
    '''Slip'''

    puRs = 8
    '''puRs'''

    puXs = 9
    '''puXs'''

    puRr = 10
    '''puRr'''

    puXr = 11
    '''puXr'''

    puXm = 12
    '''puXm'''

    MaxSlip = 13
    '''Maxslip'''

    Is1 = 14
    '''Is1'''

    Is2 = 15
    '''Is2'''

    Ir1 = 16
    '''Ir1'''

    Ir2 = 17
    '''Ir2'''

    StatorLosses = 18
    '''Stator Losses'''

    RotorLosses = 19
    '''Rotor Losses'''

    ShaftPowerHP = 20
    '''Shaft Power (hp)'''

    PowerFactor = 21
    '''Power Factor'''

    Efficiency = 22
    '''Efficiency (%)'''


class PVSystemVariables(IntEnum):
    """
    PVSystem variables

    Enumeration of the PVSystem *state variables* by (1-based) index.
    This is the implicit list and there can be more variables used by user-models
    and DynamicExp objects.
    """

    Irradiance = 1
    '''Irradiance'''

    PanelkW = 2
    '''PanelkW'''

    P_TFactor = 3
    '''P_TFactor'''

    Efficiency = 4
    '''Efficiency'''

    Vreg = 5
    '''Vreg'''

    Vavg_DRC = 6
    '''Vavg (DRC)'''

    volt_var = 7
    '''volt-var'''

    volt_watt = 8
    '''volt-watt'''

    DRC = 9
    '''DRC'''

    VV_DRC = 10
    '''VV_DRC'''

    watt_pf = 11
    '''watt-pf'''

    watt_var = 12
    '''watt-var'''

    kW_out_desired = 13
    '''kW_out_desired'''

    GridVoltage = 14
    '''Grid voltage'''

    di_dt = 15
    '''di/dt'''

    it = 16
    '''it'''

    itHistory = 17
    '''it History'''

    RatedVDC = 18
    '''Rated VDC'''

    AvgDutyCycle = 19
    '''Avg duty cycle'''

    Target_Amps = 20
    '''Target (Amps)'''

    SeriesL = 21
    '''Series L'''

    MaxAmps_phase = 22
    '''Max. Amps (phase)'''


class StorageVariables(IntEnum):
    '''
    Storage variables

    Enumeration of the Storage state variables by (1-based) index.
    This is the implicit list and there can be more variables used by user-models
    and DynamicExp objects.
    '''

    kWh = 1
    '''kWh'''

    State = 2
    '''State'''

    kWOut = 3
    '''kWOut'''

    kWIn = 4
    '''kWIn'''

    kvarOut = 5
    '''kvarOut'''

    DCkW = 6
    '''DCkW'''

    kWTotalLosses = 7
    '''kWTotalLosses'''

    kWInvLosses = 8
    '''kWInvLosses'''

    kWIdlingLosses = 9
    '''kWIdlingLosses'''

    kWChDchLosses = 10
    '''kWChDchLosses'''

    kWhChng = 11
    '''kWh Chng'''

    InvEff = 12
    '''InvEff'''

    InverterON = 13
    '''InverterON'''

    Vref = 14
    '''Vref'''

    Vavg_DRC = 15
    '''Vavg (DRC)'''

    VV_Oper = 16
    '''VV Oper'''

    VW_Oper = 17
    '''VW Oper'''

    DRC_Oper = 18
    '''DRC Oper'''

    VV_DRC_Oper = 19
    '''VV_DRC Oper'''

    WP_Oper = 20
    '''WP Oper'''

    WV_Oper = 21
    '''WV Oper'''

    kWDesired = 22
    '''kWDesired'''

    kW_VW_Limit = 23
    '''kW VW Limit'''

    Limit_kWOut_Function = 24
    '''Limit kWOut Function'''

    kVA_Exceeded = 25
    '''kVA Exceeded'''

    GridVoltage = 26
    '''Grid voltage'''

    di_dt = 27
    '''di/dt'''

    it = 28
    '''it'''

    itHistory = 29
    '''it History'''

    RatedVDC = 30
    '''Rated VDC'''

    AvgDutyCycle = 31
    '''Avg duty cycle'''

    Target_Amps = 32
    '''Target (Amps)'''

    SeriesL = 33
    '''Series L'''

    MaxAmps_phase = 34
    '''Max. Amps (phase)'''


class UPFCVariables(IntEnum):
    '''
    UPFC variables

    Enumeration of the UPFC state variables by (1-based) index.
    '''

    ModeUPFC = 1
    '''ModeUPFC'''

    IUPFC = 2
    '''IUPFC'''

    Re_Vbin = 3
    '''Re{Vbin}'''

    Im_Vbin = 4
    '''Im{Vbin}'''

    Re_Vbout = 5
    '''Re{Vbout}'''

    Im_Vbout = 6
    '''Im{Vbout}'''

    Losses = 7
    '''Losses'''

    P_UPFC = 8
    '''P_UPFC'''

    Q_UPFC = 9
    '''Q_UPFC'''

    Qideal = 10
    '''Qideal'''

    Re_Sr0_1 = 11
    '''Re{Sr0^[1]}'''

    Im_Sr0_1 = 12
    '''Im{Sr0^[1]}'''

    Re_Sr1_1 = 13
    '''Re{Sr1^[1]}'''

    Im_Sr1_1 = 14
    '''Im{Sr1^[1]}'''


class VCCSRMSVariables(IntEnum):
    '''
    VCCS RMS variables

    Enumeration of the VCCS state variables by (1-based) index, when used in RMS mode (`RMSMode=true`).
    '''

    Vrms = 1
    '''Vrms'''

    Ipwr = 2
    '''Ipwr'''

    Hout = 3
    '''Hout'''

    Irms = 4
    '''Irms'''


class VCCSNonRMSVariables(IntEnum):
    '''
    VCCS non-RMS variables

    Enumeration of the VCCS state variables by (1-based) index, when used in non-RMS mode (`RMSMode=false`).
    '''

    Vwave = 1
    '''Vwave'''

    Iwave = 2
    '''Iwave'''

    Irms = 3
    '''Irms'''

    Ipeak = 4
    '''Ipeak'''

    BP1out = 5
    '''BP1out'''

    Hout = 6
    '''Hout'''



__all__ = [
    'ActionCodes',
    'AltDSSEvent',
    'AutoAddTypes',
    'CapControlModes',
    'CktModels',
    'ControlModes',
    'CoreType',
    'DSSCompatFlags',
    'DSSJSONFlags',
    'DSSObjectFlags',
    'DSSPropertyNameStyle',
    'DSSSaveFlags',
    'EnergyMeterRegisters',
    'GeneratorRegisters',
    'GeneratorStatus',
    'GeneratorVariables',
    'IndMach012Variables',
    'LineUnits',
    'LoadModels',
    'LoadStatus',
    'MonitorModes',
    'OCPDevType',
    'Options',
    'PVSystemVariables',
    'RandomModes',
    'SetterFlags',
    'SolutionAlgorithms',
    'SolutionLoadModels',
    'SolveModes',
    'SparseSolverOptions',
    'StorageStates',
    'StorageVariables',
    'UPFCVariables',
    'VCCSNonRMSVariables',
    'VCCSRMSVariables',
    'YMatrixModes',
]
