    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ActiveClass_Get_ActiveClassName, &self->f_ActiveClass_Get_ActiveClassName, setObj, fakeLib,"ActiveClass_Get_ActiveClassName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ActiveClass_Get_ActiveClassParent, &self->f_ActiveClass_Get_ActiveClassParent, setObj, fakeLib,"ActiveClass_Get_ActiveClassParent")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ActiveClass_Get_Name, &self->f_ActiveClass_Get_Name, setObj, fakeLib,"ActiveClass_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Bus_Get_Name, &self->f_Bus_Get_Name, setObj, fakeLib,"Bus_Get_Name")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CNData_Get_Name, &self->f_CNData_Get_Name, setObj, fakeLib,"CNData_Get_Name")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CapControls_Get_Capacitor, &self->f_CapControls_Get_Capacitor, setObj, fakeLib,"CapControls_Get_Capacitor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CapControls_Get_MonitoredObj, &self->f_CapControls_Get_MonitoredObj, setObj, fakeLib,"CapControls_Get_MonitoredObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CapControls_Get_Name, &self->f_CapControls_Get_Name, setObj, fakeLib,"CapControls_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Capacitors_Get_Name, &self->f_Capacitors_Get_Name, setObj, fakeLib,"Capacitors_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Circuit_Get_Name, &self->f_Circuit_Get_Name, setObj, fakeLib,"Circuit_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CktElement_Get_DisplayName, &self->f_CktElement_Get_DisplayName, setObj, fakeLib,"CktElement_Get_DisplayName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CktElement_Get_EnergyMeter, &self->f_CktElement_Get_EnergyMeter, setObj, fakeLib,"CktElement_Get_EnergyMeter")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CktElement_Get_GUID, &self->f_CktElement_Get_GUID, setObj, fakeLib,"CktElement_Get_GUID")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CktElement_Get_Name, &self->f_CktElement_Get_Name, setObj, fakeLib,"CktElement_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_CktElement_Get_VariableName, &self->f_CktElement_Get_VariableName, setObj, fakeLib,"CktElement_Get_VariableName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSSElement_Get_Name, &self->f_DSSElement_Get_Name, setObj, fakeLib,"DSSElement_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSSProperty_Get_Description, &self->f_DSSProperty_Get_Description, setObj, fakeLib,"DSSProperty_Get_Description")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSSProperty_Get_Name, &self->f_DSSProperty_Get_Name, setObj, fakeLib,"DSSProperty_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSSProperty_Get_Val, &self->f_DSSProperty_Get_Val, setObj, fakeLib,"DSSProperty_Get_Val")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSS_Get_DataPath, &self->f_DSS_Get_DataPath, setObj, fakeLib,"DSS_Get_DataPath")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSS_Get_DefaultEditor, &self->f_DSS_Get_DefaultEditor, setObj, fakeLib,"DSS_Get_DefaultEditor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_DSS_Get_Version, &self->f_DSS_Get_Version, setObj, fakeLib,"DSS_Get_Version")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Error_Get_Description, &self->f_Error_Get_Description, setObj, fakeLib,"Error_Get_Description")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Fuses_Get_MonitoredObj, &self->f_Fuses_Get_MonitoredObj, setObj, fakeLib,"Fuses_Get_MonitoredObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Fuses_Get_Name, &self->f_Fuses_Get_Name, setObj, fakeLib,"Fuses_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Fuses_Get_SwitchedObj, &self->f_Fuses_Get_SwitchedObj, setObj, fakeLib,"Fuses_Get_SwitchedObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Fuses_Get_TCCcurve, &self->f_Fuses_Get_TCCcurve, setObj, fakeLib,"Fuses_Get_TCCcurve")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_GICSources_Get_Bus1, &self->f_GICSources_Get_Bus1, setObj, fakeLib,"GICSources_Get_Bus1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_GICSources_Get_Bus2, &self->f_GICSources_Get_Bus2, setObj, fakeLib,"GICSources_Get_Bus2")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_GICSources_Get_Name, &self->f_GICSources_Get_Name, setObj, fakeLib,"GICSources_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Generators_Get_Bus1, &self->f_Generators_Get_Bus1, setObj, fakeLib,"Generators_Get_Bus1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Generators_Get_Name, &self->f_Generators_Get_Name, setObj, fakeLib,"Generators_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Generators_Get_Yearly, &self->f_Generators_Get_Yearly, setObj, fakeLib,"Generators_Get_Yearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Generators_Get_daily, &self->f_Generators_Get_daily, setObj, fakeLib,"Generators_Get_daily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Generators_Get_duty, &self->f_Generators_Get_duty, setObj, fakeLib,"Generators_Get_duty")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ISources_Get_Name, &self->f_ISources_Get_Name, setObj, fakeLib,"ISources_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_LineCodes_Get_Name, &self->f_LineCodes_Get_Name, setObj, fakeLib,"LineCodes_Get_Name")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_LineGeometries_Get_Name, &self->f_LineGeometries_Get_Name, setObj, fakeLib,"LineGeometries_Get_Name")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_LineSpacings_Get_Name, &self->f_LineSpacings_Get_Name, setObj, fakeLib,"LineSpacings_Get_Name")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_Bus1, &self->f_Lines_Get_Bus1, setObj, fakeLib,"Lines_Get_Bus1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_Bus2, &self->f_Lines_Get_Bus2, setObj, fakeLib,"Lines_Get_Bus2")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_Geometry, &self->f_Lines_Get_Geometry, setObj, fakeLib,"Lines_Get_Geometry")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_LineCode, &self->f_Lines_Get_LineCode, setObj, fakeLib,"Lines_Get_LineCode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_Name, &self->f_Lines_Get_Name, setObj, fakeLib,"Lines_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Lines_Get_Spacing, &self->f_Lines_Get_Spacing, setObj, fakeLib,"Lines_Get_Spacing")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_LoadShapes_Get_Name, &self->f_LoadShapes_Get_Name, setObj, fakeLib,"LoadShapes_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_CVRcurve, &self->f_Loads_Get_CVRcurve, setObj, fakeLib,"Loads_Get_CVRcurve")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_Growth, &self->f_Loads_Get_Growth, setObj, fakeLib,"Loads_Get_Growth")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_Name, &self->f_Loads_Get_Name, setObj, fakeLib,"Loads_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_Sensor, &self->f_Loads_Get_Sensor, setObj, fakeLib,"Loads_Get_Sensor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_Spectrum, &self->f_Loads_Get_Spectrum, setObj, fakeLib,"Loads_Get_Spectrum")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_Yearly, &self->f_Loads_Get_Yearly, setObj, fakeLib,"Loads_Get_Yearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_daily, &self->f_Loads_Get_daily, setObj, fakeLib,"Loads_Get_daily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Loads_Get_duty, &self->f_Loads_Get_duty, setObj, fakeLib,"Loads_Get_duty")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Meters_Get_MeteredElement, &self->f_Meters_Get_MeteredElement, setObj, fakeLib,"Meters_Get_MeteredElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Meters_Get_Name, &self->f_Meters_Get_Name, setObj, fakeLib,"Meters_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Monitors_Get_Element, &self->f_Monitors_Get_Element, setObj, fakeLib,"Monitors_Get_Element")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Monitors_Get_FileName, &self->f_Monitors_Get_FileName, setObj, fakeLib,"Monitors_Get_FileName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Monitors_Get_Name, &self->f_Monitors_Get_Name, setObj, fakeLib,"Monitors_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PDElements_Get_Name, &self->f_PDElements_Get_Name, setObj, fakeLib,"PDElements_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_Name, &self->f_PVSystems_Get_Name, setObj, fakeLib,"PVSystems_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_Sensor, &self->f_PVSystems_Get_Sensor, setObj, fakeLib,"PVSystems_Get_Sensor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_Tdaily, &self->f_PVSystems_Get_Tdaily, setObj, fakeLib,"PVSystems_Get_Tdaily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_Tduty, &self->f_PVSystems_Get_Tduty, setObj, fakeLib,"PVSystems_Get_Tduty")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_Tyearly, &self->f_PVSystems_Get_Tyearly, setObj, fakeLib,"PVSystems_Get_Tyearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_daily, &self->f_PVSystems_Get_daily, setObj, fakeLib,"PVSystems_Get_daily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_duty, &self->f_PVSystems_Get_duty, setObj, fakeLib,"PVSystems_Get_duty")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_PVSystems_Get_yearly, &self->f_PVSystems_Get_yearly, setObj, fakeLib,"PVSystems_Get_yearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_BeginQuote, &self->f_Parser_Get_BeginQuote, setObj, fakeLib,"Parser_Get_BeginQuote")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_CmdString, &self->f_Parser_Get_CmdString, setObj, fakeLib,"Parser_Get_CmdString")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_Delimiters, &self->f_Parser_Get_Delimiters, setObj, fakeLib,"Parser_Get_Delimiters")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_EndQuote, &self->f_Parser_Get_EndQuote, setObj, fakeLib,"Parser_Get_EndQuote")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_NextParam, &self->f_Parser_Get_NextParam, setObj, fakeLib,"Parser_Get_NextParam")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_StrValue, &self->f_Parser_Get_StrValue, setObj, fakeLib,"Parser_Get_StrValue")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Parser_Get_WhiteSpace, &self->f_Parser_Get_WhiteSpace, setObj, fakeLib,"Parser_Get_WhiteSpace")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reactors_Get_Bus1, &self->f_Reactors_Get_Bus1, setObj, fakeLib,"Reactors_Get_Bus1")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reactors_Get_Bus2, &self->f_Reactors_Get_Bus2, setObj, fakeLib,"Reactors_Get_Bus2")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reactors_Get_LCurve, &self->f_Reactors_Get_LCurve, setObj, fakeLib,"Reactors_Get_LCurve")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reactors_Get_Name, &self->f_Reactors_Get_Name, setObj, fakeLib,"Reactors_Get_Name")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reactors_Get_RCurve, &self->f_Reactors_Get_RCurve, setObj, fakeLib,"Reactors_Get_RCurve")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reclosers_Get_MonitoredObj, &self->f_Reclosers_Get_MonitoredObj, setObj, fakeLib,"Reclosers_Get_MonitoredObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reclosers_Get_Name, &self->f_Reclosers_Get_Name, setObj, fakeLib,"Reclosers_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Reclosers_Get_SwitchedObj, &self->f_Reclosers_Get_SwitchedObj, setObj, fakeLib,"Reclosers_Get_SwitchedObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ReduceCkt_Get_EditString, &self->f_ReduceCkt_Get_EditString, setObj, fakeLib,"ReduceCkt_Get_EditString")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ReduceCkt_Get_EnergyMeter, &self->f_ReduceCkt_Get_EnergyMeter, setObj, fakeLib,"ReduceCkt_Get_EnergyMeter")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_ReduceCkt_Get_StartPDElement, &self->f_ReduceCkt_Get_StartPDElement, setObj, fakeLib,"ReduceCkt_Get_StartPDElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_RegControls_Get_MonitoredBus, &self->f_RegControls_Get_MonitoredBus, setObj, fakeLib,"RegControls_Get_MonitoredBus")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_RegControls_Get_Name, &self->f_RegControls_Get_Name, setObj, fakeLib,"RegControls_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_RegControls_Get_Transformer, &self->f_RegControls_Get_Transformer, setObj, fakeLib,"RegControls_Get_Transformer")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Relays_Get_MonitoredObj, &self->f_Relays_Get_MonitoredObj, setObj, fakeLib,"Relays_Get_MonitoredObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Relays_Get_Name, &self->f_Relays_Get_Name, setObj, fakeLib,"Relays_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Relays_Get_SwitchedObj, &self->f_Relays_Get_SwitchedObj, setObj, fakeLib,"Relays_Get_SwitchedObj")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Sensors_Get_MeteredElement, &self->f_Sensors_Get_MeteredElement, setObj, fakeLib,"Sensors_Get_MeteredElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Sensors_Get_Name, &self->f_Sensors_Get_Name, setObj, fakeLib,"Sensors_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Settings_Get_AutoBusList, &self->f_Settings_Get_AutoBusList, setObj, fakeLib,"Settings_Get_AutoBusList")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Settings_Get_PriceCurve, &self->f_Settings_Get_PriceCurve, setObj, fakeLib,"Settings_Get_PriceCurve")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Solution_Get_DefaultDaily, &self->f_Solution_Get_DefaultDaily, setObj, fakeLib,"Solution_Get_DefaultDaily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Solution_Get_DefaultYearly, &self->f_Solution_Get_DefaultYearly, setObj, fakeLib,"Solution_Get_DefaultYearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Solution_Get_LDCurve, &self->f_Solution_Get_LDCurve, setObj, fakeLib,"Solution_Get_LDCurve")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Solution_Get_ModeID, &self->f_Solution_Get_ModeID, setObj, fakeLib,"Solution_Get_ModeID")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Storages_Get_Name, &self->f_Storages_Get_Name, setObj, fakeLib,"Storages_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_SwtControls_Get_Name, &self->f_SwtControls_Get_Name, setObj, fakeLib,"SwtControls_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_SwtControls_Get_SwitchedObj, &self->f_SwtControls_Get_SwitchedObj, setObj, fakeLib,"SwtControls_Get_SwitchedObj")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_TSData_Get_Name, &self->f_TSData_Get_Name, setObj, fakeLib,"TSData_Get_Name")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Text_Get_Command, &self->f_Text_Get_Command, setObj, fakeLib,"Text_Get_Command")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Text_Get_Result, &self->f_Text_Get_Result, setObj, fakeLib,"Text_Get_Result")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Topology_Get_BranchName, &self->f_Topology_Get_BranchName, setObj, fakeLib,"Topology_Get_BranchName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Topology_Get_BusName, &self->f_Topology_Get_BusName, setObj, fakeLib,"Topology_Get_BusName")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Transformers_Get_Name, &self->f_Transformers_Get_Name, setObj, fakeLib,"Transformers_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Transformers_Get_XfmrCode, &self->f_Transformers_Get_XfmrCode, setObj, fakeLib,"Transformers_Get_XfmrCode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Transformers_Get_strWdgCurrents, &self->f_Transformers_Get_strWdgCurrents, setObj, fakeLib,"Transformers_Get_strWdgCurrents")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_Vsources_Get_Name, &self->f_Vsources_Get_Name, setObj, fakeLib,"Vsources_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WindGens_Get_Bus1, &self->f_WindGens_Get_Bus1, setObj, fakeLib,"WindGens_Get_Bus1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WindGens_Get_Name, &self->f_WindGens_Get_Name, setObj, fakeLib,"WindGens_Get_Name")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WindGens_Get_Yearly, &self->f_WindGens_Get_Yearly, setObj, fakeLib,"WindGens_Get_Yearly")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WindGens_Get_daily, &self->f_WindGens_Get_daily, setObj, fakeLib,"WindGens_Get_daily")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WindGens_Get_duty, &self->f_WindGens_Get_duty, setObj, fakeLib,"WindGens_Get_duty")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_WireData_Get_Name, &self->f_WireData_Get_Name, setObj, fakeLib,"WireData_Get_Name")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_empty, ctx_XYCurves_Get_Name, &self->f_XYCurves_Get_Name, setObj, fakeLib,"XYCurves_Get_Name")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_ActiveClass_ToJSON, &self->f_ActiveClass_ToJSON, setObj, fakeLib,"ActiveClass_ToJSON")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_Circuit_ToJSON, &self->f_Circuit_ToJSON, setObj, fakeLib,"Circuit_ToJSON")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_CktElement_Get_Controller, &self->f_CktElement_Get_Controller, setObj, fakeLib,"CktElement_Get_Controller")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSSElement_ToJSON, &self->f_DSSElement_ToJSON, setObj, fakeLib,"DSSElement_ToJSON")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSS_Executive_Get_Command, &self->f_DSS_Executive_Get_Command, setObj, fakeLib,"DSS_Executive_Get_Command")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSS_Executive_Get_CommandHelp, &self->f_DSS_Executive_Get_CommandHelp, setObj, fakeLib,"DSS_Executive_Get_CommandHelp")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSS_Executive_Get_Option, &self->f_DSS_Executive_Get_Option, setObj, fakeLib,"DSS_Executive_Get_Option")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSS_Executive_Get_OptionHelp, &self->f_DSS_Executive_Get_OptionHelp, setObj, fakeLib,"DSS_Executive_Get_OptionHelp")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str, Signature_one_int32, ctx_DSS_Executive_Get_OptionValue, &self->f_DSS_Executive_Get_OptionValue, setObj, fakeLib,"DSS_Executive_Get_OptionValue")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_ActiveClass_Get_AllNames, &self->f_ActiveClass_Get_AllNames, setObj, fakeLib,"ActiveClass_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Bus_Get_AllPCEatBus, &self->f_Bus_Get_AllPCEatBus, setObj, fakeLib,"Bus_Get_AllPCEatBus")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Bus_Get_AllPDEatBus, &self->f_Bus_Get_AllPDEatBus, setObj, fakeLib,"Bus_Get_AllPDEatBus")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Bus_Get_LineList, &self->f_Bus_Get_LineList, setObj, fakeLib,"Bus_Get_LineList")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Bus_Get_LoadList, &self->f_Bus_Get_LoadList, setObj, fakeLib,"Bus_Get_LoadList")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CNData_Get_AllNames, &self->f_CNData_Get_AllNames, setObj, fakeLib,"CNData_Get_AllNames")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CapControls_Get_AllNames, &self->f_CapControls_Get_AllNames, setObj, fakeLib,"CapControls_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Capacitors_Get_AllNames, &self->f_Capacitors_Get_AllNames, setObj, fakeLib,"Capacitors_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Circuit_Get_AllBusNames, &self->f_Circuit_Get_AllBusNames, setObj, fakeLib,"Circuit_Get_AllBusNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Circuit_Get_AllElementNames, &self->f_Circuit_Get_AllElementNames, setObj, fakeLib,"Circuit_Get_AllElementNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Circuit_Get_AllNodeNames, &self->f_Circuit_Get_AllNodeNames, setObj, fakeLib,"Circuit_Get_AllNodeNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Circuit_Get_YNodeOrder, &self->f_Circuit_Get_YNodeOrder, setObj, fakeLib,"Circuit_Get_YNodeOrder")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CktElement_Get_AllPropertyNames, &self->f_CktElement_Get_AllPropertyNames, setObj, fakeLib,"CktElement_Get_AllPropertyNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CktElement_Get_AllVariableNames, &self->f_CktElement_Get_AllVariableNames, setObj, fakeLib,"CktElement_Get_AllVariableNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CktElement_Get_BusNames, &self->f_CktElement_Get_BusNames, setObj, fakeLib,"CktElement_Get_BusNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_CtrlQueue_Get_Queue, &self->f_CtrlQueue_Get_Queue, setObj, fakeLib,"CtrlQueue_Get_Queue")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_DSSElement_Get_AllPropertyNames, &self->f_DSSElement_Get_AllPropertyNames, setObj, fakeLib,"DSSElement_Get_AllPropertyNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_DSS_Get_Classes, &self->f_DSS_Get_Classes, setObj, fakeLib,"DSS_Get_Classes")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_DSS_Get_UserClasses, &self->f_DSS_Get_UserClasses, setObj, fakeLib,"DSS_Get_UserClasses")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Fuses_Get_AllNames, &self->f_Fuses_Get_AllNames, setObj, fakeLib,"Fuses_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Fuses_Get_NormalState, &self->f_Fuses_Get_NormalState, setObj, fakeLib,"Fuses_Get_NormalState")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Fuses_Get_State, &self->f_Fuses_Get_State, setObj, fakeLib,"Fuses_Get_State")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_GICSources_Get_AllNames, &self->f_GICSources_Get_AllNames, setObj, fakeLib,"GICSources_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Generators_Get_AllNames, &self->f_Generators_Get_AllNames, setObj, fakeLib,"Generators_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Generators_Get_RegisterNames, &self->f_Generators_Get_RegisterNames, setObj, fakeLib,"Generators_Get_RegisterNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_ISources_Get_AllNames, &self->f_ISources_Get_AllNames, setObj, fakeLib,"ISources_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_LineCodes_Get_AllNames, &self->f_LineCodes_Get_AllNames, setObj, fakeLib,"LineCodes_Get_AllNames")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_LineGeometries_Get_AllNames, &self->f_LineGeometries_Get_AllNames, setObj, fakeLib,"LineGeometries_Get_AllNames")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_LineGeometries_Get_Conductors, &self->f_LineGeometries_Get_Conductors, setObj, fakeLib,"LineGeometries_Get_Conductors")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_LineSpacings_Get_AllNames, &self->f_LineSpacings_Get_AllNames, setObj, fakeLib,"LineSpacings_Get_AllNames")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Lines_Get_AllNames, &self->f_Lines_Get_AllNames, setObj, fakeLib,"Lines_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_LoadShapes_Get_AllNames, &self->f_LoadShapes_Get_AllNames, setObj, fakeLib,"LoadShapes_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Loads_Get_AllNames, &self->f_Loads_Get_AllNames, setObj, fakeLib,"Loads_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Meters_Get_AllBranchesInZone, &self->f_Meters_Get_AllBranchesInZone, setObj, fakeLib,"Meters_Get_AllBranchesInZone")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Meters_Get_AllEndElements, &self->f_Meters_Get_AllEndElements, setObj, fakeLib,"Meters_Get_AllEndElements")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Meters_Get_AllNames, &self->f_Meters_Get_AllNames, setObj, fakeLib,"Meters_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Meters_Get_RegisterNames, &self->f_Meters_Get_RegisterNames, setObj, fakeLib,"Meters_Get_RegisterNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Meters_Get_ZonePCE, &self->f_Meters_Get_ZonePCE, setObj, fakeLib,"Meters_Get_ZonePCE")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Monitors_Get_AllNames, &self->f_Monitors_Get_AllNames, setObj, fakeLib,"Monitors_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Monitors_Get_Header, &self->f_Monitors_Get_Header, setObj, fakeLib,"Monitors_Get_Header")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_PDElements_Get_AllNames, &self->f_PDElements_Get_AllNames, setObj, fakeLib,"PDElements_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_PVSystems_Get_AllNames, &self->f_PVSystems_Get_AllNames, setObj, fakeLib,"PVSystems_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_PVSystems_Get_RegisterNames, &self->f_PVSystems_Get_RegisterNames, setObj, fakeLib,"PVSystems_Get_RegisterNames")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Reactors_Get_AllNames, &self->f_Reactors_Get_AllNames, setObj, fakeLib,"Reactors_Get_AllNames")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Reclosers_Get_AllNames, &self->f_Reclosers_Get_AllNames, setObj, fakeLib,"Reclosers_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_RegControls_Get_AllNames, &self->f_RegControls_Get_AllNames, setObj, fakeLib,"RegControls_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Relays_Get_AllNames, &self->f_Relays_Get_AllNames, setObj, fakeLib,"Relays_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Sensors_Get_AllNames, &self->f_Sensors_Get_AllNames, setObj, fakeLib,"Sensors_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Solution_Get_EventLog, &self->f_Solution_Get_EventLog, setObj, fakeLib,"Solution_Get_EventLog")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Solution_Get_IncMatrixCols, &self->f_Solution_Get_IncMatrixCols, setObj, fakeLib,"Solution_Get_IncMatrixCols")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Solution_Get_IncMatrixRows, &self->f_Solution_Get_IncMatrixRows, setObj, fakeLib,"Solution_Get_IncMatrixRows")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Storages_Get_AllNames, &self->f_Storages_Get_AllNames, setObj, fakeLib,"Storages_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Storages_Get_RegisterNames, &self->f_Storages_Get_RegisterNames, setObj, fakeLib,"Storages_Get_RegisterNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_SwtControls_Get_AllNames, &self->f_SwtControls_Get_AllNames, setObj, fakeLib,"SwtControls_Get_AllNames")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_TSData_Get_AllNames, &self->f_TSData_Get_AllNames, setObj, fakeLib,"TSData_Get_AllNames")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Topology_Get_AllIsolatedBranches, &self->f_Topology_Get_AllIsolatedBranches, setObj, fakeLib,"Topology_Get_AllIsolatedBranches")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Topology_Get_AllIsolatedLoads, &self->f_Topology_Get_AllIsolatedLoads, setObj, fakeLib,"Topology_Get_AllIsolatedLoads")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Topology_Get_AllLoopedPairs, &self->f_Topology_Get_AllLoopedPairs, setObj, fakeLib,"Topology_Get_AllLoopedPairs")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Transformers_Get_AllNames, &self->f_Transformers_Get_AllNames, setObj, fakeLib,"Transformers_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_Vsources_Get_AllNames, &self->f_Vsources_Get_AllNames, setObj, fakeLib,"Vsources_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_WindGens_Get_AllNames, &self->f_WindGens_Get_AllNames, setObj, fakeLib,"WindGens_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_WindGens_Get_RegisterNames, &self->f_WindGens_Get_RegisterNames, setObj, fakeLib,"WindGens_Get_RegisterNames")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_WireData_Get_AllNames, &self->f_WireData_Get_AllNames, setObj, fakeLib,"WireData_Get_AllNames")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_empty, ctx_XYCurves_Get_AllNames, &self->f_XYCurves_Get_AllNames, setObj, fakeLib,"XYCurves_Get_AllNames")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_one_int32, ctx_Circuit_Get_AllNodeNamesByPhase, &self->f_Circuit_Get_AllNodeNamesByPhase, setObj, fakeLib,"Circuit_Get_AllNodeNamesByPhase")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_str_list, Signature_str, ctx_ZIP_List, &self->f_ZIP_List, setObj, fakeLib,"ZIP_List")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_CplxSeqVoltages_GR, &self->f_Bus_Get_CplxSeqVoltages_GR, setObj, fakeLib,"Bus_Get_CplxSeqVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_Isc_GR, &self->f_Bus_Get_Isc_GR, setObj, fakeLib,"Bus_Get_Isc_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_SeqVoltages_GR, &self->f_Bus_Get_SeqVoltages_GR, setObj, fakeLib,"Bus_Get_SeqVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_VLL_GR, &self->f_Bus_Get_VLL_GR, setObj, fakeLib,"Bus_Get_VLL_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_VMagAngle_GR, &self->f_Bus_Get_VMagAngle_GR, setObj, fakeLib,"Bus_Get_VMagAngle_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_Voc_GR, &self->f_Bus_Get_Voc_GR, setObj, fakeLib,"Bus_Get_Voc_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_Voltages_GR, &self->f_Bus_Get_Voltages_GR, setObj, fakeLib,"Bus_Get_Voltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_YscMatrix_GR, &self->f_Bus_Get_YscMatrix_GR, setObj, fakeLib,"Bus_Get_YscMatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_ZSC012Matrix_GR, &self->f_Bus_Get_ZSC012Matrix_GR, setObj, fakeLib,"Bus_Get_ZSC012Matrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_Zsc0_GR, &self->f_Bus_Get_Zsc0_GR, setObj, fakeLib,"Bus_Get_Zsc0_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_Zsc1_GR, &self->f_Bus_Get_Zsc1_GR, setObj, fakeLib,"Bus_Get_Zsc1_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_ZscMatrix_GR, &self->f_Bus_Get_ZscMatrix_GR, setObj, fakeLib,"Bus_Get_ZscMatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_puVLL_GR, &self->f_Bus_Get_puVLL_GR, setObj, fakeLib,"Bus_Get_puVLL_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_puVmagAngle_GR, &self->f_Bus_Get_puVmagAngle_GR, setObj, fakeLib,"Bus_Get_puVmagAngle_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Bus_Get_puVoltages_GR, &self->f_Bus_Get_puVoltages_GR, setObj, fakeLib,"Bus_Get_puVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllBusDistances_GR, &self->f_Circuit_Get_AllBusDistances_GR, setObj, fakeLib,"Circuit_Get_AllBusDistances_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllBusVmag_GR, &self->f_Circuit_Get_AllBusVmag_GR, setObj, fakeLib,"Circuit_Get_AllBusVmag_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllBusVmagPu_GR, &self->f_Circuit_Get_AllBusVmagPu_GR, setObj, fakeLib,"Circuit_Get_AllBusVmagPu_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllBusVolts_GR, &self->f_Circuit_Get_AllBusVolts_GR, setObj, fakeLib,"Circuit_Get_AllBusVolts_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllElementLosses_GR, &self->f_Circuit_Get_AllElementLosses_GR, setObj, fakeLib,"Circuit_Get_AllElementLosses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_AllNodeDistances_GR, &self->f_Circuit_Get_AllNodeDistances_GR, setObj, fakeLib,"Circuit_Get_AllNodeDistances_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_LineLosses_GR, &self->f_Circuit_Get_LineLosses_GR, setObj, fakeLib,"Circuit_Get_LineLosses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_Losses_GR, &self->f_Circuit_Get_Losses_GR, setObj, fakeLib,"Circuit_Get_Losses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_SubstationLosses_GR, &self->f_Circuit_Get_SubstationLosses_GR, setObj, fakeLib,"Circuit_Get_SubstationLosses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_SystemY_GR, &self->f_Circuit_Get_SystemY_GR, setObj, fakeLib,"Circuit_Get_SystemY_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_TotalPower_GR, &self->f_Circuit_Get_TotalPower_GR, setObj, fakeLib,"Circuit_Get_TotalPower_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_YCurrents_GR, &self->f_Circuit_Get_YCurrents_GR, setObj, fakeLib,"Circuit_Get_YCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Circuit_Get_YNodeVarray_GR, &self->f_Circuit_Get_YNodeVarray_GR, setObj, fakeLib,"Circuit_Get_YNodeVarray_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_AllVariableValues_GR, &self->f_CktElement_Get_AllVariableValues_GR, setObj, fakeLib,"CktElement_Get_AllVariableValues_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_CplxSeqCurrents_GR, &self->f_CktElement_Get_CplxSeqCurrents_GR, setObj, fakeLib,"CktElement_Get_CplxSeqCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_CplxSeqVoltages_GR, &self->f_CktElement_Get_CplxSeqVoltages_GR, setObj, fakeLib,"CktElement_Get_CplxSeqVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Currents_GR, &self->f_CktElement_Get_Currents_GR, setObj, fakeLib,"CktElement_Get_Currents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_CurrentsMagAng_GR, &self->f_CktElement_Get_CurrentsMagAng_GR, setObj, fakeLib,"CktElement_Get_CurrentsMagAng_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Losses_GR, &self->f_CktElement_Get_Losses_GR, setObj, fakeLib,"CktElement_Get_Losses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_PhaseLosses_GR, &self->f_CktElement_Get_PhaseLosses_GR, setObj, fakeLib,"CktElement_Get_PhaseLosses_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Powers_GR, &self->f_CktElement_Get_Powers_GR, setObj, fakeLib,"CktElement_Get_Powers_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Residuals_GR, &self->f_CktElement_Get_Residuals_GR, setObj, fakeLib,"CktElement_Get_Residuals_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_SeqCurrents_GR, &self->f_CktElement_Get_SeqCurrents_GR, setObj, fakeLib,"CktElement_Get_SeqCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_SeqPowers_GR, &self->f_CktElement_Get_SeqPowers_GR, setObj, fakeLib,"CktElement_Get_SeqPowers_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_SeqVoltages_GR, &self->f_CktElement_Get_SeqVoltages_GR, setObj, fakeLib,"CktElement_Get_SeqVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_TotalPowers_GR, &self->f_CktElement_Get_TotalPowers_GR, setObj, fakeLib,"CktElement_Get_TotalPowers_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Voltages_GR, &self->f_CktElement_Get_Voltages_GR, setObj, fakeLib,"CktElement_Get_Voltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_VoltagesMagAng_GR, &self->f_CktElement_Get_VoltagesMagAng_GR, setObj, fakeLib,"CktElement_Get_VoltagesMagAng_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_CktElement_Get_Yprim_GR, &self->f_CktElement_Get_Yprim_GR, setObj, fakeLib,"CktElement_Get_Yprim_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Generators_Get_RegisterValues_GR, &self->f_Generators_Get_RegisterValues_GR, setObj, fakeLib,"Generators_Get_RegisterValues_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineCodes_Get_Cmatrix_GR, &self->f_LineCodes_Get_Cmatrix_GR, setObj, fakeLib,"LineCodes_Get_Cmatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineCodes_Get_Rmatrix_GR, &self->f_LineCodes_Get_Rmatrix_GR, setObj, fakeLib,"LineCodes_Get_Rmatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineCodes_Get_Xmatrix_GR, &self->f_LineCodes_Get_Xmatrix_GR, setObj, fakeLib,"LineCodes_Get_Xmatrix_GR")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineGeometries_Get_Xcoords_GR, &self->f_LineGeometries_Get_Xcoords_GR, setObj, fakeLib,"LineGeometries_Get_Xcoords_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineGeometries_Get_Ycoords_GR, &self->f_LineGeometries_Get_Ycoords_GR, setObj, fakeLib,"LineGeometries_Get_Ycoords_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineSpacings_Get_Xcoords_GR, &self->f_LineSpacings_Get_Xcoords_GR, setObj, fakeLib,"LineSpacings_Get_Xcoords_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LineSpacings_Get_Ycoords_GR, &self->f_LineSpacings_Get_Ycoords_GR, setObj, fakeLib,"LineSpacings_Get_Ycoords_GR")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Lines_Get_Cmatrix_GR, &self->f_Lines_Get_Cmatrix_GR, setObj, fakeLib,"Lines_Get_Cmatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Lines_Get_Rmatrix_GR, &self->f_Lines_Get_Rmatrix_GR, setObj, fakeLib,"Lines_Get_Rmatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Lines_Get_Xmatrix_GR, &self->f_Lines_Get_Xmatrix_GR, setObj, fakeLib,"Lines_Get_Xmatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Lines_Get_Yprim_GR, &self->f_Lines_Get_Yprim_GR, setObj, fakeLib,"Lines_Get_Yprim_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LoadShapes_Get_Pmult_GR, &self->f_LoadShapes_Get_Pmult_GR, setObj, fakeLib,"LoadShapes_Get_Pmult_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LoadShapes_Get_Qmult_GR, &self->f_LoadShapes_Get_Qmult_GR, setObj, fakeLib,"LoadShapes_Get_Qmult_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_LoadShapes_Get_TimeArray_GR, &self->f_LoadShapes_Get_TimeArray_GR, setObj, fakeLib,"LoadShapes_Get_TimeArray_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Loads_Get_ZIPV_GR, &self->f_Loads_Get_ZIPV_GR, setObj, fakeLib,"Loads_Get_ZIPV_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Meters_Get_AllocFactors_GR, &self->f_Meters_Get_AllocFactors_GR, setObj, fakeLib,"Meters_Get_AllocFactors_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Meters_Get_CalcCurrent_GR, &self->f_Meters_Get_CalcCurrent_GR, setObj, fakeLib,"Meters_Get_CalcCurrent_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Meters_Get_Peakcurrent_GR, &self->f_Meters_Get_Peakcurrent_GR, setObj, fakeLib,"Meters_Get_Peakcurrent_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Meters_Get_RegisterValues_GR, &self->f_Meters_Get_RegisterValues_GR, setObj, fakeLib,"Meters_Get_RegisterValues_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Meters_Get_Totals_GR, &self->f_Meters_Get_Totals_GR, setObj, fakeLib,"Meters_Get_Totals_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Monitors_Get_dblFreq_GR, &self->f_Monitors_Get_dblFreq_GR, setObj, fakeLib,"Monitors_Get_dblFreq_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Monitors_Get_dblHour_GR, &self->f_Monitors_Get_dblHour_GR, setObj, fakeLib,"Monitors_Get_dblHour_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllCplxSeqCurrents_GR, &self->f_PDElements_Get_AllCplxSeqCurrents_GR, setObj, fakeLib,"PDElements_Get_AllCplxSeqCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllCurrents_GR, &self->f_PDElements_Get_AllCurrents_GR, setObj, fakeLib,"PDElements_Get_AllCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllCurrentsMagAng_GR, &self->f_PDElements_Get_AllCurrentsMagAng_GR, setObj, fakeLib,"PDElements_Get_AllCurrentsMagAng_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllPowers_GR, &self->f_PDElements_Get_AllPowers_GR, setObj, fakeLib,"PDElements_Get_AllPowers_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllSeqCurrents_GR, &self->f_PDElements_Get_AllSeqCurrents_GR, setObj, fakeLib,"PDElements_Get_AllSeqCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PDElements_Get_AllSeqPowers_GR, &self->f_PDElements_Get_AllSeqPowers_GR, setObj, fakeLib,"PDElements_Get_AllSeqPowers_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_PVSystems_Get_RegisterValues_GR, &self->f_PVSystems_Get_RegisterValues_GR, setObj, fakeLib,"PVSystems_Get_RegisterValues_GR")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Rmatrix_GR, &self->f_Reactors_Get_Rmatrix_GR, setObj, fakeLib,"Reactors_Get_Rmatrix_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Xmatrix_GR, &self->f_Reactors_Get_Xmatrix_GR, setObj, fakeLib,"Reactors_Get_Xmatrix_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Z_GR, &self->f_Reactors_Get_Z_GR, setObj, fakeLib,"Reactors_Get_Z_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Z0_GR, &self->f_Reactors_Get_Z0_GR, setObj, fakeLib,"Reactors_Get_Z0_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Z1_GR, &self->f_Reactors_Get_Z1_GR, setObj, fakeLib,"Reactors_Get_Z1_GR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reactors_Get_Z2_GR, &self->f_Reactors_Get_Z2_GR, setObj, fakeLib,"Reactors_Get_Z2_GR")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Reclosers_Get_RecloseIntervals_GR, &self->f_Reclosers_Get_RecloseIntervals_GR, setObj, fakeLib,"Reclosers_Get_RecloseIntervals_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Sensors_Get_AllocationFactor_GR, &self->f_Sensors_Get_AllocationFactor_GR, setObj, fakeLib,"Sensors_Get_AllocationFactor_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Sensors_Get_Currents_GR, &self->f_Sensors_Get_Currents_GR, setObj, fakeLib,"Sensors_Get_Currents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Sensors_Get_kVARS_GR, &self->f_Sensors_Get_kVARS_GR, setObj, fakeLib,"Sensors_Get_kVARS_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Sensors_Get_kVS_GR, &self->f_Sensors_Get_kVS_GR, setObj, fakeLib,"Sensors_Get_kVS_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Sensors_Get_kWS_GR, &self->f_Sensors_Get_kWS_GR, setObj, fakeLib,"Sensors_Get_kWS_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Settings_Get_VoltageBases_GR, &self->f_Settings_Get_VoltageBases_GR, setObj, fakeLib,"Settings_Get_VoltageBases_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Storages_Get_RegisterValues_GR, &self->f_Storages_Get_RegisterValues_GR, setObj, fakeLib,"Storages_Get_RegisterValues_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Transformers_Get_AllLossesByType_GR, &self->f_Transformers_Get_AllLossesByType_GR, setObj, fakeLib,"Transformers_Get_AllLossesByType_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Transformers_Get_LossesByType_GR, &self->f_Transformers_Get_LossesByType_GR, setObj, fakeLib,"Transformers_Get_LossesByType_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Transformers_Get_WdgCurrents_GR, &self->f_Transformers_Get_WdgCurrents_GR, setObj, fakeLib,"Transformers_Get_WdgCurrents_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_Transformers_Get_WdgVoltages_GR, &self->f_Transformers_Get_WdgVoltages_GR, setObj, fakeLib,"Transformers_Get_WdgVoltages_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_WindGens_Get_RegisterValues_GR, &self->f_WindGens_Get_RegisterValues_GR, setObj, fakeLib,"WindGens_Get_RegisterValues_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_XYCurves_Get_Xarray_GR, &self->f_XYCurves_Get_Xarray_GR, setObj, fakeLib,"XYCurves_Get_Xarray_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_empty, ctx_XYCurves_Get_Yarray_GR, &self->f_XYCurves_Get_Yarray_GR, setObj, fakeLib,"XYCurves_Get_Yarray_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Circuit_Get_AllNodeDistancesByPhase_GR, &self->f_Circuit_Get_AllNodeDistancesByPhase_GR, setObj, fakeLib,"Circuit_Get_AllNodeDistancesByPhase_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Circuit_Get_AllNodeVmagByPhase_GR, &self->f_Circuit_Get_AllNodeVmagByPhase_GR, setObj, fakeLib,"Circuit_Get_AllNodeVmagByPhase_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Circuit_Get_AllNodeVmagPUByPhase_GR, &self->f_Circuit_Get_AllNodeVmagPUByPhase_GR, setObj, fakeLib,"Circuit_Get_AllNodeVmagPUByPhase_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Monitors_Get_Channel_GR, &self->f_Monitors_Get_Channel_GR, setObj, fakeLib,"Monitors_Get_Channel_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Parser_Get_Matrix_GR, &self->f_Parser_Get_Matrix_GR, setObj, fakeLib,"Parser_Get_Matrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Parser_Get_SymMatrix_GR, &self->f_Parser_Get_SymMatrix_GR, setObj, fakeLib,"Parser_Get_SymMatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_float64, Signature_one_int32, ctx_Parser_Get_Vector_GR, &self->f_Parser_Get_Vector_GR, setObj, fakeLib,"Parser_Get_Vector_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Bus_Get_Nodes_GR, &self->f_Bus_Get_Nodes_GR, setObj, fakeLib,"Bus_Get_Nodes_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Capacitors_Get_States_GR, &self->f_Capacitors_Get_States_GR, setObj, fakeLib,"Capacitors_Get_States_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_CktElement_Get_NodeOrder_GR, &self->f_CktElement_Get_NodeOrder_GR, setObj, fakeLib,"CktElement_Get_NodeOrder_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_CktElement_Get_NodeRef_GR, &self->f_CktElement_Get_NodeRef_GR, setObj, fakeLib,"CktElement_Get_NodeRef_GR")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_LineGeometries_Get_Units_GR, &self->f_LineGeometries_Get_Units_GR, setObj, fakeLib,"LineGeometries_Get_Units_GR")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_PDElements_Get_AllNumConductors_GR, &self->f_PDElements_Get_AllNumConductors_GR, setObj, fakeLib,"PDElements_Get_AllNumConductors_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_PDElements_Get_AllNumPhases_GR, &self->f_PDElements_Get_AllNumPhases_GR, setObj, fakeLib,"PDElements_Get_AllNumPhases_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_PDElements_Get_AllNumTerminals_GR, &self->f_PDElements_Get_AllNumTerminals_GR, setObj, fakeLib,"PDElements_Get_AllNumTerminals_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Parallel_Get_ActorProgress_GR, &self->f_Parallel_Get_ActorProgress_GR, setObj, fakeLib,"Parallel_Get_ActorProgress_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Parallel_Get_ActorStatus_GR, &self->f_Parallel_Get_ActorStatus_GR, setObj, fakeLib,"Parallel_Get_ActorStatus_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Settings_Get_LossRegs_GR, &self->f_Settings_Get_LossRegs_GR, setObj, fakeLib,"Settings_Get_LossRegs_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Settings_Get_UEregs_GR, &self->f_Settings_Get_UEregs_GR, setObj, fakeLib,"Settings_Get_UEregs_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Solution_Get_BusLevels_GR, &self->f_Solution_Get_BusLevels_GR, setObj, fakeLib,"Solution_Get_BusLevels_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Solution_Get_IncMatrix_GR, &self->f_Solution_Get_IncMatrix_GR, setObj, fakeLib,"Solution_Get_IncMatrix_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int32, Signature_empty, ctx_Solution_Get_Laplacian_GR, &self->f_Solution_Get_Laplacian_GR, setObj, fakeLib,"Solution_Get_Laplacian_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_int8, Signature_empty, ctx_Monitors_Get_ByteStream_GR, &self->f_Monitors_Get_ByteStream_GR, setObj, fakeLib,"Monitors_Get_ByteStream_GR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ActiveClass_Get_Count, &self->f_ActiveClass_Get_Count, setObj, fakeLib,"ActiveClass_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ActiveClass_Get_First, &self->f_ActiveClass_Get_First, setObj, fakeLib,"ActiveClass_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ActiveClass_Get_Next, &self->f_ActiveClass_Get_Next, setObj, fakeLib,"ActiveClass_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ActiveClass_Get_NumElements, &self->f_ActiveClass_Get_NumElements, setObj, fakeLib,"ActiveClass_Get_NumElements")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Bus_Get_N_Customers, &self->f_Bus_Get_N_Customers, setObj, fakeLib,"Bus_Get_N_Customers")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Bus_Get_Next, &self->f_Bus_Get_Next, setObj, fakeLib,"Bus_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Bus_Get_NumNodes, &self->f_Bus_Get_NumNodes, setObj, fakeLib,"Bus_Get_NumNodes")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Bus_Get_SectionID, &self->f_Bus_Get_SectionID, setObj, fakeLib,"Bus_Get_SectionID")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_Count, &self->f_CNData_Get_Count, setObj, fakeLib,"CNData_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_First, &self->f_CNData_Get_First, setObj, fakeLib,"CNData_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_GMRUnits, &self->f_CNData_Get_GMRUnits, setObj, fakeLib,"CNData_Get_GMRUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_Next, &self->f_CNData_Get_Next, setObj, fakeLib,"CNData_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_RadiusUnits, &self->f_CNData_Get_RadiusUnits, setObj, fakeLib,"CNData_Get_RadiusUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_ResistanceUnits, &self->f_CNData_Get_ResistanceUnits, setObj, fakeLib,"CNData_Get_ResistanceUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_idx, &self->f_CNData_Get_idx, setObj, fakeLib,"CNData_Get_idx")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CNData_Get_k, &self->f_CNData_Get_k, setObj, fakeLib,"CNData_Get_k")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_Count, &self->f_CapControls_Get_Count, setObj, fakeLib,"CapControls_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_First, &self->f_CapControls_Get_First, setObj, fakeLib,"CapControls_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_Mode, &self->f_CapControls_Get_Mode, setObj, fakeLib,"CapControls_Get_Mode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_MonitoredTerm, &self->f_CapControls_Get_MonitoredTerm, setObj, fakeLib,"CapControls_Get_MonitoredTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_Next, &self->f_CapControls_Get_Next, setObj, fakeLib,"CapControls_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CapControls_Get_idx, &self->f_CapControls_Get_idx, setObj, fakeLib,"CapControls_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_AvailableSteps, &self->f_Capacitors_Get_AvailableSteps, setObj, fakeLib,"Capacitors_Get_AvailableSteps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_Count, &self->f_Capacitors_Get_Count, setObj, fakeLib,"Capacitors_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_First, &self->f_Capacitors_Get_First, setObj, fakeLib,"Capacitors_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_Next, &self->f_Capacitors_Get_Next, setObj, fakeLib,"Capacitors_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_NumSteps, &self->f_Capacitors_Get_NumSteps, setObj, fakeLib,"Capacitors_Get_NumSteps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Capacitors_Get_idx, &self->f_Capacitors_Get_idx, setObj, fakeLib,"Capacitors_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_FirstElement, &self->f_Circuit_FirstElement, setObj, fakeLib,"Circuit_FirstElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_FirstPCElement, &self->f_Circuit_FirstPCElement, setObj, fakeLib,"Circuit_FirstPCElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_FirstPDElement, &self->f_Circuit_FirstPDElement, setObj, fakeLib,"Circuit_FirstPDElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_Get_NumBuses, &self->f_Circuit_Get_NumBuses, setObj, fakeLib,"Circuit_Get_NumBuses")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_Get_NumCktElements, &self->f_Circuit_Get_NumCktElements, setObj, fakeLib,"Circuit_Get_NumCktElements")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_Get_NumNodes, &self->f_Circuit_Get_NumNodes, setObj, fakeLib,"Circuit_Get_NumNodes")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_Get_ParentPDElement, &self->f_Circuit_Get_ParentPDElement, setObj, fakeLib,"Circuit_Get_ParentPDElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_NextElement, &self->f_Circuit_NextElement, setObj, fakeLib,"Circuit_NextElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_NextPCElement, &self->f_Circuit_NextPCElement, setObj, fakeLib,"Circuit_NextPCElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Circuit_NextPDElement, &self->f_Circuit_NextPDElement, setObj, fakeLib,"Circuit_NextPDElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_Handle, &self->f_CktElement_Get_Handle, setObj, fakeLib,"CktElement_Get_Handle")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_NumConductors, &self->f_CktElement_Get_NumConductors, setObj, fakeLib,"CktElement_Get_NumConductors")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_NumControls, &self->f_CktElement_Get_NumControls, setObj, fakeLib,"CktElement_Get_NumControls")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_NumPhases, &self->f_CktElement_Get_NumPhases, setObj, fakeLib,"CktElement_Get_NumPhases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_NumProperties, &self->f_CktElement_Get_NumProperties, setObj, fakeLib,"CktElement_Get_NumProperties")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_NumTerminals, &self->f_CktElement_Get_NumTerminals, setObj, fakeLib,"CktElement_Get_NumTerminals")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_OCPDevIndex, &self->f_CktElement_Get_OCPDevIndex, setObj, fakeLib,"CktElement_Get_OCPDevIndex")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_OCPDevType, &self->f_CktElement_Get_OCPDevType, setObj, fakeLib,"CktElement_Get_OCPDevType")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CktElement_Get_VariableIdx, &self->f_CktElement_Get_VariableIdx, setObj, fakeLib,"CktElement_Get_VariableIdx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CtrlQueue_Get_ActionCode, &self->f_CtrlQueue_Get_ActionCode, setObj, fakeLib,"CtrlQueue_Get_ActionCode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CtrlQueue_Get_DeviceHandle, &self->f_CtrlQueue_Get_DeviceHandle, setObj, fakeLib,"CtrlQueue_Get_DeviceHandle")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CtrlQueue_Get_NumActions, &self->f_CtrlQueue_Get_NumActions, setObj, fakeLib,"CtrlQueue_Get_NumActions")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CtrlQueue_Get_PopAction, &self->f_CtrlQueue_Get_PopAction, setObj, fakeLib,"CtrlQueue_Get_PopAction")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_CtrlQueue_Get_QueueSize, &self->f_CtrlQueue_Get_QueueSize, setObj, fakeLib,"CtrlQueue_Get_QueueSize")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSSElement_Get_NumProperties, &self->f_DSSElement_Get_NumProperties, setObj, fakeLib,"DSSElement_Get_NumProperties")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSS_Executive_Get_NumCommands, &self->f_DSS_Executive_Get_NumCommands, setObj, fakeLib,"DSS_Executive_Get_NumCommands")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSS_Executive_Get_NumOptions, &self->f_DSS_Executive_Get_NumOptions, setObj, fakeLib,"DSS_Executive_Get_NumOptions")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSS_Get_NumCircuits, &self->f_DSS_Get_NumCircuits, setObj, fakeLib,"DSS_Get_NumCircuits")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSS_Get_NumClasses, &self->f_DSS_Get_NumClasses, setObj, fakeLib,"DSS_Get_NumClasses")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_DSS_Get_NumUserClasses, &self->f_DSS_Get_NumUserClasses, setObj, fakeLib,"DSS_Get_NumUserClasses")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Error_Get_Number, &self->f_Error_Get_Number, setObj, fakeLib,"Error_Get_Number")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_Count, &self->f_Fuses_Get_Count, setObj, fakeLib,"Fuses_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_First, &self->f_Fuses_Get_First, setObj, fakeLib,"Fuses_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_MonitoredTerm, &self->f_Fuses_Get_MonitoredTerm, setObj, fakeLib,"Fuses_Get_MonitoredTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_Next, &self->f_Fuses_Get_Next, setObj, fakeLib,"Fuses_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_NumPhases, &self->f_Fuses_Get_NumPhases, setObj, fakeLib,"Fuses_Get_NumPhases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_SwitchedTerm, &self->f_Fuses_Get_SwitchedTerm, setObj, fakeLib,"Fuses_Get_SwitchedTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Fuses_Get_idx, &self->f_Fuses_Get_idx, setObj, fakeLib,"Fuses_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_GICSources_Get_Count, &self->f_GICSources_Get_Count, setObj, fakeLib,"GICSources_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_GICSources_Get_First, &self->f_GICSources_Get_First, setObj, fakeLib,"GICSources_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_GICSources_Get_Next, &self->f_GICSources_Get_Next, setObj, fakeLib,"GICSources_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_GICSources_Get_Phases, &self->f_GICSources_Get_Phases, setObj, fakeLib,"GICSources_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_GICSources_Get_idx, &self->f_GICSources_Get_idx, setObj, fakeLib,"GICSources_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Class_, &self->f_Generators_Get_Class_, setObj, fakeLib,"Generators_Get_Class_")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Count, &self->f_Generators_Get_Count, setObj, fakeLib,"Generators_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_First, &self->f_Generators_Get_First, setObj, fakeLib,"Generators_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Model, &self->f_Generators_Get_Model, setObj, fakeLib,"Generators_Get_Model")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Next, &self->f_Generators_Get_Next, setObj, fakeLib,"Generators_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Phases, &self->f_Generators_Get_Phases, setObj, fakeLib,"Generators_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_Status, &self->f_Generators_Get_Status, setObj, fakeLib,"Generators_Get_Status")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Generators_Get_idx, &self->f_Generators_Get_idx, setObj, fakeLib,"Generators_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ISources_Get_Count, &self->f_ISources_Get_Count, setObj, fakeLib,"ISources_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ISources_Get_First, &self->f_ISources_Get_First, setObj, fakeLib,"ISources_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ISources_Get_Next, &self->f_ISources_Get_Next, setObj, fakeLib,"ISources_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_ISources_Get_idx, &self->f_ISources_Get_idx, setObj, fakeLib,"ISources_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_Count, &self->f_LineCodes_Get_Count, setObj, fakeLib,"LineCodes_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_First, &self->f_LineCodes_Get_First, setObj, fakeLib,"LineCodes_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_Next, &self->f_LineCodes_Get_Next, setObj, fakeLib,"LineCodes_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_Phases, &self->f_LineCodes_Get_Phases, setObj, fakeLib,"LineCodes_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_Units, &self->f_LineCodes_Get_Units, setObj, fakeLib,"LineCodes_Get_Units")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineCodes_Get_idx, &self->f_LineCodes_Get_idx, setObj, fakeLib,"LineCodes_Get_idx")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_Count, &self->f_LineGeometries_Get_Count, setObj, fakeLib,"LineGeometries_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_First, &self->f_LineGeometries_Get_First, setObj, fakeLib,"LineGeometries_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_Nconds, &self->f_LineGeometries_Get_Nconds, setObj, fakeLib,"LineGeometries_Get_Nconds")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_Next, &self->f_LineGeometries_Get_Next, setObj, fakeLib,"LineGeometries_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_Phases, &self->f_LineGeometries_Get_Phases, setObj, fakeLib,"LineGeometries_Get_Phases")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineGeometries_Get_idx, &self->f_LineGeometries_Get_idx, setObj, fakeLib,"LineGeometries_Get_idx")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_Count, &self->f_LineSpacings_Get_Count, setObj, fakeLib,"LineSpacings_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_First, &self->f_LineSpacings_Get_First, setObj, fakeLib,"LineSpacings_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_Nconds, &self->f_LineSpacings_Get_Nconds, setObj, fakeLib,"LineSpacings_Get_Nconds")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_Next, &self->f_LineSpacings_Get_Next, setObj, fakeLib,"LineSpacings_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_Phases, &self->f_LineSpacings_Get_Phases, setObj, fakeLib,"LineSpacings_Get_Phases")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_Units, &self->f_LineSpacings_Get_Units, setObj, fakeLib,"LineSpacings_Get_Units")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LineSpacings_Get_idx, &self->f_LineSpacings_Get_idx, setObj, fakeLib,"LineSpacings_Get_idx")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_Count, &self->f_Lines_Get_Count, setObj, fakeLib,"Lines_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_First, &self->f_Lines_Get_First, setObj, fakeLib,"Lines_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_Next, &self->f_Lines_Get_Next, setObj, fakeLib,"Lines_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_NumCust, &self->f_Lines_Get_NumCust, setObj, fakeLib,"Lines_Get_NumCust")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_Parent, &self->f_Lines_Get_Parent, setObj, fakeLib,"Lines_Get_Parent")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_Phases, &self->f_Lines_Get_Phases, setObj, fakeLib,"Lines_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_TotalCust, &self->f_Lines_Get_TotalCust, setObj, fakeLib,"Lines_Get_TotalCust")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_Units, &self->f_Lines_Get_Units, setObj, fakeLib,"Lines_Get_Units")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Lines_Get_idx, &self->f_Lines_Get_idx, setObj, fakeLib,"Lines_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LoadShapes_Get_Count, &self->f_LoadShapes_Get_Count, setObj, fakeLib,"LoadShapes_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LoadShapes_Get_First, &self->f_LoadShapes_Get_First, setObj, fakeLib,"LoadShapes_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LoadShapes_Get_Next, &self->f_LoadShapes_Get_Next, setObj, fakeLib,"LoadShapes_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LoadShapes_Get_Npts, &self->f_LoadShapes_Get_Npts, setObj, fakeLib,"LoadShapes_Get_Npts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_LoadShapes_Get_idx, &self->f_LoadShapes_Get_idx, setObj, fakeLib,"LoadShapes_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Class_, &self->f_Loads_Get_Class_, setObj, fakeLib,"Loads_Get_Class_")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Count, &self->f_Loads_Get_Count, setObj, fakeLib,"Loads_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_First, &self->f_Loads_Get_First, setObj, fakeLib,"Loads_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Model, &self->f_Loads_Get_Model, setObj, fakeLib,"Loads_Get_Model")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Next, &self->f_Loads_Get_Next, setObj, fakeLib,"Loads_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_NumCust, &self->f_Loads_Get_NumCust, setObj, fakeLib,"Loads_Get_NumCust")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Phases, &self->f_Loads_Get_Phases, setObj, fakeLib,"Loads_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_Status, &self->f_Loads_Get_Status, setObj, fakeLib,"Loads_Get_Status")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Loads_Get_idx, &self->f_Loads_Get_idx, setObj, fakeLib,"Loads_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_Count, &self->f_Meters_Get_Count, setObj, fakeLib,"Meters_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_CountBranches, &self->f_Meters_Get_CountBranches, setObj, fakeLib,"Meters_Get_CountBranches")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_CountEndElements, &self->f_Meters_Get_CountEndElements, setObj, fakeLib,"Meters_Get_CountEndElements")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_First, &self->f_Meters_Get_First, setObj, fakeLib,"Meters_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_MeteredTerminal, &self->f_Meters_Get_MeteredTerminal, setObj, fakeLib,"Meters_Get_MeteredTerminal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_Next, &self->f_Meters_Get_Next, setObj, fakeLib,"Meters_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_NumSectionBranches, &self->f_Meters_Get_NumSectionBranches, setObj, fakeLib,"Meters_Get_NumSectionBranches")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_NumSectionCustomers, &self->f_Meters_Get_NumSectionCustomers, setObj, fakeLib,"Meters_Get_NumSectionCustomers")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_NumSections, &self->f_Meters_Get_NumSections, setObj, fakeLib,"Meters_Get_NumSections")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_OCPDeviceType, &self->f_Meters_Get_OCPDeviceType, setObj, fakeLib,"Meters_Get_OCPDeviceType")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_SectSeqIdx, &self->f_Meters_Get_SectSeqIdx, setObj, fakeLib,"Meters_Get_SectSeqIdx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_SectTotalCust, &self->f_Meters_Get_SectTotalCust, setObj, fakeLib,"Meters_Get_SectTotalCust")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_SeqListSize, &self->f_Meters_Get_SeqListSize, setObj, fakeLib,"Meters_Get_SeqListSize")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_SequenceIndex, &self->f_Meters_Get_SequenceIndex, setObj, fakeLib,"Meters_Get_SequenceIndex")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_TotalCustomers, &self->f_Meters_Get_TotalCustomers, setObj, fakeLib,"Meters_Get_TotalCustomers")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Meters_Get_idx, &self->f_Meters_Get_idx, setObj, fakeLib,"Meters_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_Count, &self->f_Monitors_Get_Count, setObj, fakeLib,"Monitors_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_FileVersion, &self->f_Monitors_Get_FileVersion, setObj, fakeLib,"Monitors_Get_FileVersion")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_First, &self->f_Monitors_Get_First, setObj, fakeLib,"Monitors_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_Mode, &self->f_Monitors_Get_Mode, setObj, fakeLib,"Monitors_Get_Mode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_Next, &self->f_Monitors_Get_Next, setObj, fakeLib,"Monitors_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_NumChannels, &self->f_Monitors_Get_NumChannels, setObj, fakeLib,"Monitors_Get_NumChannels")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_RecordSize, &self->f_Monitors_Get_RecordSize, setObj, fakeLib,"Monitors_Get_RecordSize")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_SampleCount, &self->f_Monitors_Get_SampleCount, setObj, fakeLib,"Monitors_Get_SampleCount")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_Terminal, &self->f_Monitors_Get_Terminal, setObj, fakeLib,"Monitors_Get_Terminal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Monitors_Get_idx, &self->f_Monitors_Get_idx, setObj, fakeLib,"Monitors_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_Count, &self->f_PDElements_Get_Count, setObj, fakeLib,"PDElements_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_First, &self->f_PDElements_Get_First, setObj, fakeLib,"PDElements_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_FromTerminal, &self->f_PDElements_Get_FromTerminal, setObj, fakeLib,"PDElements_Get_FromTerminal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_Next, &self->f_PDElements_Get_Next, setObj, fakeLib,"PDElements_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_Numcustomers, &self->f_PDElements_Get_Numcustomers, setObj, fakeLib,"PDElements_Get_Numcustomers")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_ParentPDElement, &self->f_PDElements_Get_ParentPDElement, setObj, fakeLib,"PDElements_Get_ParentPDElement")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_SectionID, &self->f_PDElements_Get_SectionID, setObj, fakeLib,"PDElements_Get_SectionID")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PDElements_Get_Totalcustomers, &self->f_PDElements_Get_Totalcustomers, setObj, fakeLib,"PDElements_Get_Totalcustomers")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PVSystems_Get_Count, &self->f_PVSystems_Get_Count, setObj, fakeLib,"PVSystems_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PVSystems_Get_First, &self->f_PVSystems_Get_First, setObj, fakeLib,"PVSystems_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PVSystems_Get_Next, &self->f_PVSystems_Get_Next, setObj, fakeLib,"PVSystems_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_PVSystems_Get_idx, &self->f_PVSystems_Get_idx, setObj, fakeLib,"PVSystems_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_ActiveActor, &self->f_Parallel_Get_ActiveActor, setObj, fakeLib,"Parallel_Get_ActiveActor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_ActiveParallel, &self->f_Parallel_Get_ActiveParallel, setObj, fakeLib,"Parallel_Get_ActiveParallel")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_ActorCPU, &self->f_Parallel_Get_ActorCPU, setObj, fakeLib,"Parallel_Get_ActorCPU")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_ConcatenateReports, &self->f_Parallel_Get_ConcatenateReports, setObj, fakeLib,"Parallel_Get_ConcatenateReports")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_NumCPUs, &self->f_Parallel_Get_NumCPUs, setObj, fakeLib,"Parallel_Get_NumCPUs")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_NumCores, &self->f_Parallel_Get_NumCores, setObj, fakeLib,"Parallel_Get_NumCores")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parallel_Get_NumOfActors, &self->f_Parallel_Get_NumOfActors, setObj, fakeLib,"Parallel_Get_NumOfActors")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Parser_Get_IntValue, &self->f_Parser_Get_IntValue, setObj, fakeLib,"Parser_Get_IntValue")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_Count, &self->f_Reactors_Get_Count, setObj, fakeLib,"Reactors_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_First, &self->f_Reactors_Get_First, setObj, fakeLib,"Reactors_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_Next, &self->f_Reactors_Get_Next, setObj, fakeLib,"Reactors_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_Phases, &self->f_Reactors_Get_Phases, setObj, fakeLib,"Reactors_Get_Phases")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_SpecType, &self->f_Reactors_Get_SpecType, setObj, fakeLib,"Reactors_Get_SpecType")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reactors_Get_idx, &self->f_Reactors_Get_idx, setObj, fakeLib,"Reactors_Get_idx")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_Count, &self->f_Reclosers_Get_Count, setObj, fakeLib,"Reclosers_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_First, &self->f_Reclosers_Get_First, setObj, fakeLib,"Reclosers_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_MonitoredTerm, &self->f_Reclosers_Get_MonitoredTerm, setObj, fakeLib,"Reclosers_Get_MonitoredTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_Next, &self->f_Reclosers_Get_Next, setObj, fakeLib,"Reclosers_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_NormalState, &self->f_Reclosers_Get_NormalState, setObj, fakeLib,"Reclosers_Get_NormalState")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_NumFast, &self->f_Reclosers_Get_NumFast, setObj, fakeLib,"Reclosers_Get_NumFast")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_Shots, &self->f_Reclosers_Get_Shots, setObj, fakeLib,"Reclosers_Get_Shots")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_State, &self->f_Reclosers_Get_State, setObj, fakeLib,"Reclosers_Get_State")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_SwitchedTerm, &self->f_Reclosers_Get_SwitchedTerm, setObj, fakeLib,"Reclosers_Get_SwitchedTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Reclosers_Get_idx, &self->f_Reclosers_Get_idx, setObj, fakeLib,"Reclosers_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_Count, &self->f_RegControls_Get_Count, setObj, fakeLib,"RegControls_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_First, &self->f_RegControls_Get_First, setObj, fakeLib,"RegControls_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_MaxTapChange, &self->f_RegControls_Get_MaxTapChange, setObj, fakeLib,"RegControls_Get_MaxTapChange")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_Next, &self->f_RegControls_Get_Next, setObj, fakeLib,"RegControls_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_TapNumber, &self->f_RegControls_Get_TapNumber, setObj, fakeLib,"RegControls_Get_TapNumber")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_TapWinding, &self->f_RegControls_Get_TapWinding, setObj, fakeLib,"RegControls_Get_TapWinding")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_Winding, &self->f_RegControls_Get_Winding, setObj, fakeLib,"RegControls_Get_Winding")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_RegControls_Get_idx, &self->f_RegControls_Get_idx, setObj, fakeLib,"RegControls_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_Count, &self->f_Relays_Get_Count, setObj, fakeLib,"Relays_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_First, &self->f_Relays_Get_First, setObj, fakeLib,"Relays_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_MonitoredTerm, &self->f_Relays_Get_MonitoredTerm, setObj, fakeLib,"Relays_Get_MonitoredTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_Next, &self->f_Relays_Get_Next, setObj, fakeLib,"Relays_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_NormalState, &self->f_Relays_Get_NormalState, setObj, fakeLib,"Relays_Get_NormalState")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_State, &self->f_Relays_Get_State, setObj, fakeLib,"Relays_Get_State")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_SwitchedTerm, &self->f_Relays_Get_SwitchedTerm, setObj, fakeLib,"Relays_Get_SwitchedTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Relays_Get_idx, &self->f_Relays_Get_idx, setObj, fakeLib,"Relays_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Sensors_Get_Count, &self->f_Sensors_Get_Count, setObj, fakeLib,"Sensors_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Sensors_Get_First, &self->f_Sensors_Get_First, setObj, fakeLib,"Sensors_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Sensors_Get_MeteredTerminal, &self->f_Sensors_Get_MeteredTerminal, setObj, fakeLib,"Sensors_Get_MeteredTerminal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Sensors_Get_Next, &self->f_Sensors_Get_Next, setObj, fakeLib,"Sensors_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Sensors_Get_idx, &self->f_Sensors_Get_idx, setObj, fakeLib,"Sensors_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Settings_Get_CktModel, &self->f_Settings_Get_CktModel, setObj, fakeLib,"Settings_Get_CktModel")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Settings_Get_IterateDisabled, &self->f_Settings_Get_IterateDisabled, setObj, fakeLib,"Settings_Get_IterateDisabled")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_AddType, &self->f_Solution_Get_AddType, setObj, fakeLib,"Solution_Get_AddType")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Algorithm, &self->f_Solution_Get_Algorithm, setObj, fakeLib,"Solution_Get_Algorithm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_ControlIterations, &self->f_Solution_Get_ControlIterations, setObj, fakeLib,"Solution_Get_ControlIterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_ControlMode, &self->f_Solution_Get_ControlMode, setObj, fakeLib,"Solution_Get_ControlMode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Hour, &self->f_Solution_Get_Hour, setObj, fakeLib,"Solution_Get_Hour")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Iterations, &self->f_Solution_Get_Iterations, setObj, fakeLib,"Solution_Get_Iterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_LoadModel, &self->f_Solution_Get_LoadModel, setObj, fakeLib,"Solution_Get_LoadModel")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_MaxControlIterations, &self->f_Solution_Get_MaxControlIterations, setObj, fakeLib,"Solution_Get_MaxControlIterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_MaxIterations, &self->f_Solution_Get_MaxIterations, setObj, fakeLib,"Solution_Get_MaxIterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_MinIterations, &self->f_Solution_Get_MinIterations, setObj, fakeLib,"Solution_Get_MinIterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Mode, &self->f_Solution_Get_Mode, setObj, fakeLib,"Solution_Get_Mode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_MostIterationsDone, &self->f_Solution_Get_MostIterationsDone, setObj, fakeLib,"Solution_Get_MostIterationsDone")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Number, &self->f_Solution_Get_Number, setObj, fakeLib,"Solution_Get_Number")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Random, &self->f_Solution_Get_Random, setObj, fakeLib,"Solution_Get_Random")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Totaliterations, &self->f_Solution_Get_Totaliterations, setObj, fakeLib,"Solution_Get_Totaliterations")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Solution_Get_Year, &self->f_Solution_Get_Year, setObj, fakeLib,"Solution_Get_Year")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_ControlMode, &self->f_Storages_Get_ControlMode, setObj, fakeLib,"Storages_Get_ControlMode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_Count, &self->f_Storages_Get_Count, setObj, fakeLib,"Storages_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_First, &self->f_Storages_Get_First, setObj, fakeLib,"Storages_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_Next, &self->f_Storages_Get_Next, setObj, fakeLib,"Storages_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_SafeMode, &self->f_Storages_Get_SafeMode, setObj, fakeLib,"Storages_Get_SafeMode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_State, &self->f_Storages_Get_State, setObj, fakeLib,"Storages_Get_State")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_VarFollowInverter, &self->f_Storages_Get_VarFollowInverter, setObj, fakeLib,"Storages_Get_VarFollowInverter")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Storages_Get_idx, &self->f_Storages_Get_idx, setObj, fakeLib,"Storages_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_Action, &self->f_SwtControls_Get_Action, setObj, fakeLib,"SwtControls_Get_Action")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_Count, &self->f_SwtControls_Get_Count, setObj, fakeLib,"SwtControls_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_First, &self->f_SwtControls_Get_First, setObj, fakeLib,"SwtControls_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_Next, &self->f_SwtControls_Get_Next, setObj, fakeLib,"SwtControls_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_NormalState, &self->f_SwtControls_Get_NormalState, setObj, fakeLib,"SwtControls_Get_NormalState")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_State, &self->f_SwtControls_Get_State, setObj, fakeLib,"SwtControls_Get_State")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_SwitchedTerm, &self->f_SwtControls_Get_SwitchedTerm, setObj, fakeLib,"SwtControls_Get_SwitchedTerm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_SwtControls_Get_idx, &self->f_SwtControls_Get_idx, setObj, fakeLib,"SwtControls_Get_idx")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_Count, &self->f_TSData_Get_Count, setObj, fakeLib,"TSData_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_First, &self->f_TSData_Get_First, setObj, fakeLib,"TSData_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_GMRUnits, &self->f_TSData_Get_GMRUnits, setObj, fakeLib,"TSData_Get_GMRUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_Next, &self->f_TSData_Get_Next, setObj, fakeLib,"TSData_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_RadiusUnits, &self->f_TSData_Get_RadiusUnits, setObj, fakeLib,"TSData_Get_RadiusUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_ResistanceUnits, &self->f_TSData_Get_ResistanceUnits, setObj, fakeLib,"TSData_Get_ResistanceUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_TSData_Get_idx, &self->f_TSData_Get_idx, setObj, fakeLib,"TSData_Get_idx")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_ActiveBranch, &self->f_Topology_Get_ActiveBranch, setObj, fakeLib,"Topology_Get_ActiveBranch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_ActiveLevel, &self->f_Topology_Get_ActiveLevel, setObj, fakeLib,"Topology_Get_ActiveLevel")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_BackwardBranch, &self->f_Topology_Get_BackwardBranch, setObj, fakeLib,"Topology_Get_BackwardBranch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_First, &self->f_Topology_Get_First, setObj, fakeLib,"Topology_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_FirstLoad, &self->f_Topology_Get_FirstLoad, setObj, fakeLib,"Topology_Get_FirstLoad")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_ForwardBranch, &self->f_Topology_Get_ForwardBranch, setObj, fakeLib,"Topology_Get_ForwardBranch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_LoopedBranch, &self->f_Topology_Get_LoopedBranch, setObj, fakeLib,"Topology_Get_LoopedBranch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_Next, &self->f_Topology_Get_Next, setObj, fakeLib,"Topology_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_NextLoad, &self->f_Topology_Get_NextLoad, setObj, fakeLib,"Topology_Get_NextLoad")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_NumIsolatedBranches, &self->f_Topology_Get_NumIsolatedBranches, setObj, fakeLib,"Topology_Get_NumIsolatedBranches")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_NumIsolatedLoads, &self->f_Topology_Get_NumIsolatedLoads, setObj, fakeLib,"Topology_Get_NumIsolatedLoads")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_NumLoops, &self->f_Topology_Get_NumLoops, setObj, fakeLib,"Topology_Get_NumLoops")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Topology_Get_ParallelBranch, &self->f_Topology_Get_ParallelBranch, setObj, fakeLib,"Topology_Get_ParallelBranch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_CoreType, &self->f_Transformers_Get_CoreType, setObj, fakeLib,"Transformers_Get_CoreType")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_Count, &self->f_Transformers_Get_Count, setObj, fakeLib,"Transformers_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_First, &self->f_Transformers_Get_First, setObj, fakeLib,"Transformers_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_Next, &self->f_Transformers_Get_Next, setObj, fakeLib,"Transformers_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_NumTaps, &self->f_Transformers_Get_NumTaps, setObj, fakeLib,"Transformers_Get_NumTaps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_NumWindings, &self->f_Transformers_Get_NumWindings, setObj, fakeLib,"Transformers_Get_NumWindings")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_Wdg, &self->f_Transformers_Get_Wdg, setObj, fakeLib,"Transformers_Get_Wdg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Transformers_Get_idx, &self->f_Transformers_Get_idx, setObj, fakeLib,"Transformers_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Vsources_Get_Count, &self->f_Vsources_Get_Count, setObj, fakeLib,"Vsources_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Vsources_Get_First, &self->f_Vsources_Get_First, setObj, fakeLib,"Vsources_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Vsources_Get_Next, &self->f_Vsources_Get_Next, setObj, fakeLib,"Vsources_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Vsources_Get_Phases, &self->f_Vsources_Get_Phases, setObj, fakeLib,"Vsources_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_Vsources_Get_idx, &self->f_Vsources_Get_idx, setObj, fakeLib,"Vsources_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_Class_, &self->f_WindGens_Get_Class_, setObj, fakeLib,"WindGens_Get_Class_")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_Count, &self->f_WindGens_Get_Count, setObj, fakeLib,"WindGens_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_First, &self->f_WindGens_Get_First, setObj, fakeLib,"WindGens_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_NPoles, &self->f_WindGens_Get_NPoles, setObj, fakeLib,"WindGens_Get_NPoles")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_N_WTG, &self->f_WindGens_Get_N_WTG, setObj, fakeLib,"WindGens_Get_N_WTG")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_Next, &self->f_WindGens_Get_Next, setObj, fakeLib,"WindGens_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_Phases, &self->f_WindGens_Get_Phases, setObj, fakeLib,"WindGens_Get_Phases")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_QFlag, &self->f_WindGens_Get_QFlag, setObj, fakeLib,"WindGens_Get_QFlag")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_QMode, &self->f_WindGens_Get_QMode, setObj, fakeLib,"WindGens_Get_QMode")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WindGens_Get_idx, &self->f_WindGens_Get_idx, setObj, fakeLib,"WindGens_Get_idx")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_Count, &self->f_WireData_Get_Count, setObj, fakeLib,"WireData_Get_Count")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_First, &self->f_WireData_Get_First, setObj, fakeLib,"WireData_Get_First")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_GMRUnits, &self->f_WireData_Get_GMRUnits, setObj, fakeLib,"WireData_Get_GMRUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_Next, &self->f_WireData_Get_Next, setObj, fakeLib,"WireData_Get_Next")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_RadiusUnits, &self->f_WireData_Get_RadiusUnits, setObj, fakeLib,"WireData_Get_RadiusUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_ResistanceUnits, &self->f_WireData_Get_ResistanceUnits, setObj, fakeLib,"WireData_Get_ResistanceUnits")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_WireData_Get_idx, &self->f_WireData_Get_idx, setObj, fakeLib,"WireData_Get_idx")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_XYCurves_Get_Count, &self->f_XYCurves_Get_Count, setObj, fakeLib,"XYCurves_Get_Count")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_XYCurves_Get_First, &self->f_XYCurves_Get_First, setObj, fakeLib,"XYCurves_Get_First")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_XYCurves_Get_Next, &self->f_XYCurves_Get_Next, setObj, fakeLib,"XYCurves_Get_Next")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_XYCurves_Get_Npts, &self->f_XYCurves_Get_Npts, setObj, fakeLib,"XYCurves_Get_Npts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_XYCurves_Get_idx, &self->f_XYCurves_Get_idx, setObj, fakeLib,"XYCurves_Get_idx")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_empty, ctx_YMatrix_Get_Iteration, &self->f_YMatrix_Get_Iteration, setObj, fakeLib,"YMatrix_Get_Iteration")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_one_int32, ctx_Bus_GetUniqueNodeNumber, &self->f_Bus_GetUniqueNodeNumber, setObj, fakeLib,"Bus_GetUniqueNodeNumber")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_int32, Signature_one_int32, ctx_Circuit_SetActiveBusi, &self->f_Circuit_SetActiveBusi, setObj, fakeLib,"Circuit_SetActiveBusi")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_Cust_Duration, &self->f_Bus_Get_Cust_Duration, setObj, fakeLib,"Bus_Get_Cust_Duration")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_Cust_Interrupts, &self->f_Bus_Get_Cust_Interrupts, setObj, fakeLib,"Bus_Get_Cust_Interrupts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_Distance, &self->f_Bus_Get_Distance, setObj, fakeLib,"Bus_Get_Distance")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_Int_Duration, &self->f_Bus_Get_Int_Duration, setObj, fakeLib,"Bus_Get_Int_Duration")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_Lambda, &self->f_Bus_Get_Lambda, setObj, fakeLib,"Bus_Get_Lambda")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_N_interrupts, &self->f_Bus_Get_N_interrupts, setObj, fakeLib,"Bus_Get_N_interrupts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_TotalMiles, &self->f_Bus_Get_TotalMiles, setObj, fakeLib,"Bus_Get_TotalMiles")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_kVBase, &self->f_Bus_Get_kVBase, setObj, fakeLib,"Bus_Get_kVBase")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_x, &self->f_Bus_Get_x, setObj, fakeLib,"Bus_Get_x")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Bus_Get_y, &self->f_Bus_Get_y, setObj, fakeLib,"Bus_Get_y")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_DiaCable, &self->f_CNData_Get_DiaCable, setObj, fakeLib,"CNData_Get_DiaCable")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_DiaIns, &self->f_CNData_Get_DiaIns, setObj, fakeLib,"CNData_Get_DiaIns")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_DiaStrand, &self->f_CNData_Get_DiaStrand, setObj, fakeLib,"CNData_Get_DiaStrand")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_Diameter, &self->f_CNData_Get_Diameter, setObj, fakeLib,"CNData_Get_Diameter")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_EmergAmps, &self->f_CNData_Get_EmergAmps, setObj, fakeLib,"CNData_Get_EmergAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_EpsR, &self->f_CNData_Get_EpsR, setObj, fakeLib,"CNData_Get_EpsR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_GMRac, &self->f_CNData_Get_GMRac, setObj, fakeLib,"CNData_Get_GMRac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_GmrStrand, &self->f_CNData_Get_GmrStrand, setObj, fakeLib,"CNData_Get_GmrStrand")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_InsLayer, &self->f_CNData_Get_InsLayer, setObj, fakeLib,"CNData_Get_InsLayer")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_NormAmps, &self->f_CNData_Get_NormAmps, setObj, fakeLib,"CNData_Get_NormAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_RStrand, &self->f_CNData_Get_RStrand, setObj, fakeLib,"CNData_Get_RStrand")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_Rac, &self->f_CNData_Get_Rac, setObj, fakeLib,"CNData_Get_Rac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_Radius, &self->f_CNData_Get_Radius, setObj, fakeLib,"CNData_Get_Radius")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CNData_Get_Rdc, &self->f_CNData_Get_Rdc, setObj, fakeLib,"CNData_Get_Rdc")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_CTratio, &self->f_CapControls_Get_CTratio, setObj, fakeLib,"CapControls_Get_CTratio")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_DeadTime, &self->f_CapControls_Get_DeadTime, setObj, fakeLib,"CapControls_Get_DeadTime")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_Delay, &self->f_CapControls_Get_Delay, setObj, fakeLib,"CapControls_Get_Delay")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_DelayOff, &self->f_CapControls_Get_DelayOff, setObj, fakeLib,"CapControls_Get_DelayOff")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_OFFSetting, &self->f_CapControls_Get_OFFSetting, setObj, fakeLib,"CapControls_Get_OFFSetting")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_ONSetting, &self->f_CapControls_Get_ONSetting, setObj, fakeLib,"CapControls_Get_ONSetting")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_PTratio, &self->f_CapControls_Get_PTratio, setObj, fakeLib,"CapControls_Get_PTratio")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_Vmax, &self->f_CapControls_Get_Vmax, setObj, fakeLib,"CapControls_Get_Vmax")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CapControls_Get_Vmin, &self->f_CapControls_Get_Vmin, setObj, fakeLib,"CapControls_Get_Vmin")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Capacitors_Get_kV, &self->f_Capacitors_Get_kV, setObj, fakeLib,"Capacitors_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Capacitors_Get_kvar, &self->f_Capacitors_Get_kvar, setObj, fakeLib,"Capacitors_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CktElement_Get_EmergAmps, &self->f_CktElement_Get_EmergAmps, setObj, fakeLib,"CktElement_Get_EmergAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CktElement_Get_NormalAmps, &self->f_CktElement_Get_NormalAmps, setObj, fakeLib,"CktElement_Get_NormalAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_CktElement_Get_VariableValue, &self->f_CktElement_Get_VariableValue, setObj, fakeLib,"CktElement_Get_VariableValue")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Fuses_Get_Delay, &self->f_Fuses_Get_Delay, setObj, fakeLib,"Fuses_Get_Delay")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Fuses_Get_RatedCurrent, &self->f_Fuses_Get_RatedCurrent, setObj, fakeLib,"Fuses_Get_RatedCurrent")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_EE, &self->f_GICSources_Get_EE, setObj, fakeLib,"GICSources_Get_EE")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_EN, &self->f_GICSources_Get_EN, setObj, fakeLib,"GICSources_Get_EN")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_Lat1, &self->f_GICSources_Get_Lat1, setObj, fakeLib,"GICSources_Get_Lat1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_Lat2, &self->f_GICSources_Get_Lat2, setObj, fakeLib,"GICSources_Get_Lat2")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_Lon1, &self->f_GICSources_Get_Lon1, setObj, fakeLib,"GICSources_Get_Lon1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_Lon2, &self->f_GICSources_Get_Lon2, setObj, fakeLib,"GICSources_Get_Lon2")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_GICSources_Get_Volts, &self->f_GICSources_Get_Volts, setObj, fakeLib,"GICSources_Get_Volts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_PF, &self->f_Generators_Get_PF, setObj, fakeLib,"Generators_Get_PF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_Vmaxpu, &self->f_Generators_Get_Vmaxpu, setObj, fakeLib,"Generators_Get_Vmaxpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_Vminpu, &self->f_Generators_Get_Vminpu, setObj, fakeLib,"Generators_Get_Vminpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_kV, &self->f_Generators_Get_kV, setObj, fakeLib,"Generators_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_kVArated, &self->f_Generators_Get_kVArated, setObj, fakeLib,"Generators_Get_kVArated")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_kW, &self->f_Generators_Get_kW, setObj, fakeLib,"Generators_Get_kW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_kva, &self->f_Generators_Get_kva, setObj, fakeLib,"Generators_Get_kva")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Generators_Get_kvar, &self->f_Generators_Get_kvar, setObj, fakeLib,"Generators_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_ISources_Get_Amps, &self->f_ISources_Get_Amps, setObj, fakeLib,"ISources_Get_Amps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_ISources_Get_AngleDeg, &self->f_ISources_Get_AngleDeg, setObj, fakeLib,"ISources_Get_AngleDeg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_ISources_Get_Frequency, &self->f_ISources_Get_Frequency, setObj, fakeLib,"ISources_Get_Frequency")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_C0, &self->f_LineCodes_Get_C0, setObj, fakeLib,"LineCodes_Get_C0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_C1, &self->f_LineCodes_Get_C1, setObj, fakeLib,"LineCodes_Get_C1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_EmergAmps, &self->f_LineCodes_Get_EmergAmps, setObj, fakeLib,"LineCodes_Get_EmergAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_NormAmps, &self->f_LineCodes_Get_NormAmps, setObj, fakeLib,"LineCodes_Get_NormAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_R0, &self->f_LineCodes_Get_R0, setObj, fakeLib,"LineCodes_Get_R0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_R1, &self->f_LineCodes_Get_R1, setObj, fakeLib,"LineCodes_Get_R1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_X0, &self->f_LineCodes_Get_X0, setObj, fakeLib,"LineCodes_Get_X0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineCodes_Get_X1, &self->f_LineCodes_Get_X1, setObj, fakeLib,"LineCodes_Get_X1")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineGeometries_Get_EmergAmps, &self->f_LineGeometries_Get_EmergAmps, setObj, fakeLib,"LineGeometries_Get_EmergAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineGeometries_Get_NormAmps, &self->f_LineGeometries_Get_NormAmps, setObj, fakeLib,"LineGeometries_Get_NormAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LineGeometries_Get_RhoEarth, &self->f_LineGeometries_Get_RhoEarth, setObj, fakeLib,"LineGeometries_Get_RhoEarth")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_C0, &self->f_Lines_Get_C0, setObj, fakeLib,"Lines_Get_C0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_C1, &self->f_Lines_Get_C1, setObj, fakeLib,"Lines_Get_C1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_EmergAmps, &self->f_Lines_Get_EmergAmps, setObj, fakeLib,"Lines_Get_EmergAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_Length, &self->f_Lines_Get_Length, setObj, fakeLib,"Lines_Get_Length")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_NormAmps, &self->f_Lines_Get_NormAmps, setObj, fakeLib,"Lines_Get_NormAmps")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_R0, &self->f_Lines_Get_R0, setObj, fakeLib,"Lines_Get_R0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_R1, &self->f_Lines_Get_R1, setObj, fakeLib,"Lines_Get_R1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_Rg, &self->f_Lines_Get_Rg, setObj, fakeLib,"Lines_Get_Rg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_Rho, &self->f_Lines_Get_Rho, setObj, fakeLib,"Lines_Get_Rho")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_SeasonRating, &self->f_Lines_Get_SeasonRating, setObj, fakeLib,"Lines_Get_SeasonRating")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_X0, &self->f_Lines_Get_X0, setObj, fakeLib,"Lines_Get_X0")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_X1, &self->f_Lines_Get_X1, setObj, fakeLib,"Lines_Get_X1")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Lines_Get_Xg, &self->f_Lines_Get_Xg, setObj, fakeLib,"Lines_Get_Xg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_HrInterval, &self->f_LoadShapes_Get_HrInterval, setObj, fakeLib,"LoadShapes_Get_HrInterval")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_MaxP, &self->f_LoadShapes_Get_MaxP, setObj, fakeLib,"LoadShapes_Get_MaxP")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_MaxQ, &self->f_LoadShapes_Get_MaxQ, setObj, fakeLib,"LoadShapes_Get_MaxQ")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_MinInterval, &self->f_LoadShapes_Get_MinInterval, setObj, fakeLib,"LoadShapes_Get_MinInterval")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_PBase, &self->f_LoadShapes_Get_PBase, setObj, fakeLib,"LoadShapes_Get_PBase")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_Qbase, &self->f_LoadShapes_Get_Qbase, setObj, fakeLib,"LoadShapes_Get_Qbase")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_LoadShapes_Get_SInterval, &self->f_LoadShapes_Get_SInterval, setObj, fakeLib,"LoadShapes_Get_SInterval")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_AllocationFactor, &self->f_Loads_Get_AllocationFactor, setObj, fakeLib,"Loads_Get_AllocationFactor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_CVRvars, &self->f_Loads_Get_CVRvars, setObj, fakeLib,"Loads_Get_CVRvars")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_CVRwatts, &self->f_Loads_Get_CVRwatts, setObj, fakeLib,"Loads_Get_CVRwatts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Cfactor, &self->f_Loads_Get_Cfactor, setObj, fakeLib,"Loads_Get_Cfactor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_PF, &self->f_Loads_Get_PF, setObj, fakeLib,"Loads_Get_PF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_PctMean, &self->f_Loads_Get_PctMean, setObj, fakeLib,"Loads_Get_PctMean")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_PctStdDev, &self->f_Loads_Get_PctStdDev, setObj, fakeLib,"Loads_Get_PctStdDev")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_RelWeight, &self->f_Loads_Get_RelWeight, setObj, fakeLib,"Loads_Get_RelWeight")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Rneut, &self->f_Loads_Get_Rneut, setObj, fakeLib,"Loads_Get_Rneut")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Vmaxpu, &self->f_Loads_Get_Vmaxpu, setObj, fakeLib,"Loads_Get_Vmaxpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Vminemerg, &self->f_Loads_Get_Vminemerg, setObj, fakeLib,"Loads_Get_Vminemerg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Vminnorm, &self->f_Loads_Get_Vminnorm, setObj, fakeLib,"Loads_Get_Vminnorm")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Vminpu, &self->f_Loads_Get_Vminpu, setObj, fakeLib,"Loads_Get_Vminpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_Xneut, &self->f_Loads_Get_Xneut, setObj, fakeLib,"Loads_Get_Xneut")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kV, &self->f_Loads_Get_kV, setObj, fakeLib,"Loads_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kW, &self->f_Loads_Get_kW, setObj, fakeLib,"Loads_Get_kW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kva, &self->f_Loads_Get_kva, setObj, fakeLib,"Loads_Get_kva")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kvar, &self->f_Loads_Get_kvar, setObj, fakeLib,"Loads_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kwh, &self->f_Loads_Get_kwh, setObj, fakeLib,"Loads_Get_kwh")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_kwhdays, &self->f_Loads_Get_kwhdays, setObj, fakeLib,"Loads_Get_kwhdays")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_pctSeriesRL, &self->f_Loads_Get_pctSeriesRL, setObj, fakeLib,"Loads_Get_pctSeriesRL")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Loads_Get_xfkVA, &self->f_Loads_Get_xfkVA, setObj, fakeLib,"Loads_Get_xfkVA")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_AvgRepairTime, &self->f_Meters_Get_AvgRepairTime, setObj, fakeLib,"Meters_Get_AvgRepairTime")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_CustInterrupts, &self->f_Meters_Get_CustInterrupts, setObj, fakeLib,"Meters_Get_CustInterrupts")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_FaultRateXRepairHrs, &self->f_Meters_Get_FaultRateXRepairHrs, setObj, fakeLib,"Meters_Get_FaultRateXRepairHrs")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_SAIDI, &self->f_Meters_Get_SAIDI, setObj, fakeLib,"Meters_Get_SAIDI")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_SAIFI, &self->f_Meters_Get_SAIFI, setObj, fakeLib,"Meters_Get_SAIFI")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_SAIFIKW, &self->f_Meters_Get_SAIFIKW, setObj, fakeLib,"Meters_Get_SAIFIKW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Meters_Get_SumBranchFltRates, &self->f_Meters_Get_SumBranchFltRates, setObj, fakeLib,"Meters_Get_SumBranchFltRates")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_AccumulatedL, &self->f_PDElements_Get_AccumulatedL, setObj, fakeLib,"PDElements_Get_AccumulatedL")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_FaultRate, &self->f_PDElements_Get_FaultRate, setObj, fakeLib,"PDElements_Get_FaultRate")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_Lambda, &self->f_PDElements_Get_Lambda, setObj, fakeLib,"PDElements_Get_Lambda")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_RepairTime, &self->f_PDElements_Get_RepairTime, setObj, fakeLib,"PDElements_Get_RepairTime")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_TotalMiles, &self->f_PDElements_Get_TotalMiles, setObj, fakeLib,"PDElements_Get_TotalMiles")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PDElements_Get_pctPermanent, &self->f_PDElements_Get_pctPermanent, setObj, fakeLib,"PDElements_Get_pctPermanent")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_Irradiance, &self->f_PVSystems_Get_Irradiance, setObj, fakeLib,"PVSystems_Get_Irradiance")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_IrradianceNow, &self->f_PVSystems_Get_IrradianceNow, setObj, fakeLib,"PVSystems_Get_IrradianceNow")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_PF, &self->f_PVSystems_Get_PF, setObj, fakeLib,"PVSystems_Get_PF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_Pmpp, &self->f_PVSystems_Get_Pmpp, setObj, fakeLib,"PVSystems_Get_Pmpp")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_kVArated, &self->f_PVSystems_Get_kVArated, setObj, fakeLib,"PVSystems_Get_kVArated")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_kW, &self->f_PVSystems_Get_kW, setObj, fakeLib,"PVSystems_Get_kW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_PVSystems_Get_kvar, &self->f_PVSystems_Get_kvar, setObj, fakeLib,"PVSystems_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Parser_Get_DblValue, &self->f_Parser_Get_DblValue, setObj, fakeLib,"Parser_Get_DblValue")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_LmH, &self->f_Reactors_Get_LmH, setObj, fakeLib,"Reactors_Get_LmH")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_R, &self->f_Reactors_Get_R, setObj, fakeLib,"Reactors_Get_R")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_Rp, &self->f_Reactors_Get_Rp, setObj, fakeLib,"Reactors_Get_Rp")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_X, &self->f_Reactors_Get_X, setObj, fakeLib,"Reactors_Get_X")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_kV, &self->f_Reactors_Get_kV, setObj, fakeLib,"Reactors_Get_kV")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reactors_Get_kvar, &self->f_Reactors_Get_kvar, setObj, fakeLib,"Reactors_Get_kvar")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reclosers_Get_GroundInst, &self->f_Reclosers_Get_GroundInst, setObj, fakeLib,"Reclosers_Get_GroundInst")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reclosers_Get_GroundTrip, &self->f_Reclosers_Get_GroundTrip, setObj, fakeLib,"Reclosers_Get_GroundTrip")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reclosers_Get_PhaseInst, &self->f_Reclosers_Get_PhaseInst, setObj, fakeLib,"Reclosers_Get_PhaseInst")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Reclosers_Get_PhaseTrip, &self->f_Reclosers_Get_PhaseTrip, setObj, fakeLib,"Reclosers_Get_PhaseTrip")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_ReduceCkt_Get_Zmag, &self->f_ReduceCkt_Get_Zmag, setObj, fakeLib,"ReduceCkt_Get_Zmag")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_CTPrimary, &self->f_RegControls_Get_CTPrimary, setObj, fakeLib,"RegControls_Get_CTPrimary")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_Delay, &self->f_RegControls_Get_Delay, setObj, fakeLib,"RegControls_Get_Delay")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ForwardBand, &self->f_RegControls_Get_ForwardBand, setObj, fakeLib,"RegControls_Get_ForwardBand")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ForwardR, &self->f_RegControls_Get_ForwardR, setObj, fakeLib,"RegControls_Get_ForwardR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ForwardVreg, &self->f_RegControls_Get_ForwardVreg, setObj, fakeLib,"RegControls_Get_ForwardVreg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ForwardX, &self->f_RegControls_Get_ForwardX, setObj, fakeLib,"RegControls_Get_ForwardX")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_PTratio, &self->f_RegControls_Get_PTratio, setObj, fakeLib,"RegControls_Get_PTratio")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ReverseBand, &self->f_RegControls_Get_ReverseBand, setObj, fakeLib,"RegControls_Get_ReverseBand")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ReverseR, &self->f_RegControls_Get_ReverseR, setObj, fakeLib,"RegControls_Get_ReverseR")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ReverseVreg, &self->f_RegControls_Get_ReverseVreg, setObj, fakeLib,"RegControls_Get_ReverseVreg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_ReverseX, &self->f_RegControls_Get_ReverseX, setObj, fakeLib,"RegControls_Get_ReverseX")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_TapDelay, &self->f_RegControls_Get_TapDelay, setObj, fakeLib,"RegControls_Get_TapDelay")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_RegControls_Get_VoltageLimit, &self->f_RegControls_Get_VoltageLimit, setObj, fakeLib,"RegControls_Get_VoltageLimit")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Sensors_Get_PctError, &self->f_Sensors_Get_PctError, setObj, fakeLib,"Sensors_Get_PctError")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Sensors_Get_Weight, &self->f_Sensors_Get_Weight, setObj, fakeLib,"Sensors_Get_Weight")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Sensors_Get_kVbase, &self->f_Sensors_Get_kVbase, setObj, fakeLib,"Sensors_Get_kVbase")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_EmergVmaxpu, &self->f_Settings_Get_EmergVmaxpu, setObj, fakeLib,"Settings_Get_EmergVmaxpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_EmergVminpu, &self->f_Settings_Get_EmergVminpu, setObj, fakeLib,"Settings_Get_EmergVminpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_LossWeight, &self->f_Settings_Get_LossWeight, setObj, fakeLib,"Settings_Get_LossWeight")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_NormVmaxpu, &self->f_Settings_Get_NormVmaxpu, setObj, fakeLib,"Settings_Get_NormVmaxpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_NormVminpu, &self->f_Settings_Get_NormVminpu, setObj, fakeLib,"Settings_Get_NormVminpu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_PriceSignal, &self->f_Settings_Get_PriceSignal, setObj, fakeLib,"Settings_Get_PriceSignal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Settings_Get_UEweight, &self->f_Settings_Get_UEweight, setObj, fakeLib,"Settings_Get_UEweight")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Capkvar, &self->f_Solution_Get_Capkvar, setObj, fakeLib,"Solution_Get_Capkvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Frequency, &self->f_Solution_Get_Frequency, setObj, fakeLib,"Solution_Get_Frequency")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_GenMult, &self->f_Solution_Get_GenMult, setObj, fakeLib,"Solution_Get_GenMult")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_GenPF, &self->f_Solution_Get_GenPF, setObj, fakeLib,"Solution_Get_GenPF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_GenkW, &self->f_Solution_Get_GenkW, setObj, fakeLib,"Solution_Get_GenkW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_IntervalHrs, &self->f_Solution_Get_IntervalHrs, setObj, fakeLib,"Solution_Get_IntervalHrs")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_LoadMult, &self->f_Solution_Get_LoadMult, setObj, fakeLib,"Solution_Get_LoadMult")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Process_Time, &self->f_Solution_Get_Process_Time, setObj, fakeLib,"Solution_Get_Process_Time")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Seconds, &self->f_Solution_Get_Seconds, setObj, fakeLib,"Solution_Get_Seconds")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_StepSize, &self->f_Solution_Get_StepSize, setObj, fakeLib,"Solution_Get_StepSize")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Time_of_Step, &self->f_Solution_Get_Time_of_Step, setObj, fakeLib,"Solution_Get_Time_of_Step")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Tolerance, &self->f_Solution_Get_Tolerance, setObj, fakeLib,"Solution_Get_Tolerance")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_Total_Time, &self->f_Solution_Get_Total_Time, setObj, fakeLib,"Solution_Get_Total_Time")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_dblHour, &self->f_Solution_Get_dblHour, setObj, fakeLib,"Solution_Get_dblHour")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Solution_Get_pctGrowth, &self->f_Solution_Get_pctGrowth, setObj, fakeLib,"Solution_Get_pctGrowth")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_AmpLimit, &self->f_Storages_Get_AmpLimit, setObj, fakeLib,"Storages_Get_AmpLimit")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_AmpLimitGain, &self->f_Storages_Get_AmpLimitGain, setObj, fakeLib,"Storages_Get_AmpLimitGain")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_ChargeTrigger, &self->f_Storages_Get_ChargeTrigger, setObj, fakeLib,"Storages_Get_ChargeTrigger")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_DischargeTrigger, &self->f_Storages_Get_DischargeTrigger, setObj, fakeLib,"Storages_Get_DischargeTrigger")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_EffCharge, &self->f_Storages_Get_EffCharge, setObj, fakeLib,"Storages_Get_EffCharge")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_EffDischarge, &self->f_Storages_Get_EffDischarge, setObj, fakeLib,"Storages_Get_EffDischarge")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_Kp, &self->f_Storages_Get_Kp, setObj, fakeLib,"Storages_Get_Kp")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_PF, &self->f_Storages_Get_PF, setObj, fakeLib,"Storages_Get_PF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_PITol, &self->f_Storages_Get_PITol, setObj, fakeLib,"Storages_Get_PITol")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_SafeVoltage, &self->f_Storages_Get_SafeVoltage, setObj, fakeLib,"Storages_Get_SafeVoltage")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_TimeChargeTrig, &self->f_Storages_Get_TimeChargeTrig, setObj, fakeLib,"Storages_Get_TimeChargeTrig")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kV, &self->f_Storages_Get_kV, setObj, fakeLib,"Storages_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kVA, &self->f_Storages_Get_kVA, setObj, fakeLib,"Storages_Get_kVA")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kVDC, &self->f_Storages_Get_kVDC, setObj, fakeLib,"Storages_Get_kVDC")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kW, &self->f_Storages_Get_kW, setObj, fakeLib,"Storages_Get_kW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kWRated, &self->f_Storages_Get_kWRated, setObj, fakeLib,"Storages_Get_kWRated")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kWhRated, &self->f_Storages_Get_kWhRated, setObj, fakeLib,"Storages_Get_kWhRated")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_kvar, &self->f_Storages_Get_kvar, setObj, fakeLib,"Storages_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Storages_Get_puSOC, &self->f_Storages_Get_puSOC, setObj, fakeLib,"Storages_Get_puSOC")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_SwtControls_Get_Delay, &self->f_SwtControls_Get_Delay, setObj, fakeLib,"SwtControls_Get_Delay")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_DiaCable, &self->f_TSData_Get_DiaCable, setObj, fakeLib,"TSData_Get_DiaCable")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_DiaIns, &self->f_TSData_Get_DiaIns, setObj, fakeLib,"TSData_Get_DiaIns")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_DiaShield, &self->f_TSData_Get_DiaShield, setObj, fakeLib,"TSData_Get_DiaShield")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_Diameter, &self->f_TSData_Get_Diameter, setObj, fakeLib,"TSData_Get_Diameter")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_EmergAmps, &self->f_TSData_Get_EmergAmps, setObj, fakeLib,"TSData_Get_EmergAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_EpsR, &self->f_TSData_Get_EpsR, setObj, fakeLib,"TSData_Get_EpsR")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_GMRac, &self->f_TSData_Get_GMRac, setObj, fakeLib,"TSData_Get_GMRac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_InsLayer, &self->f_TSData_Get_InsLayer, setObj, fakeLib,"TSData_Get_InsLayer")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_NormAmps, &self->f_TSData_Get_NormAmps, setObj, fakeLib,"TSData_Get_NormAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_Rac, &self->f_TSData_Get_Rac, setObj, fakeLib,"TSData_Get_Rac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_Radius, &self->f_TSData_Get_Radius, setObj, fakeLib,"TSData_Get_Radius")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_Rdc, &self->f_TSData_Get_Rdc, setObj, fakeLib,"TSData_Get_Rdc")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_TapeLap, &self->f_TSData_Get_TapeLap, setObj, fakeLib,"TSData_Get_TapeLap")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_TSData_Get_TapeLayer, &self->f_TSData_Get_TapeLayer, setObj, fakeLib,"TSData_Get_TapeLayer")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_MaxTap, &self->f_Transformers_Get_MaxTap, setObj, fakeLib,"Transformers_Get_MaxTap")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_MinTap, &self->f_Transformers_Get_MinTap, setObj, fakeLib,"Transformers_Get_MinTap")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_R, &self->f_Transformers_Get_R, setObj, fakeLib,"Transformers_Get_R")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_RdcOhms, &self->f_Transformers_Get_RdcOhms, setObj, fakeLib,"Transformers_Get_RdcOhms")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Rneut, &self->f_Transformers_Get_Rneut, setObj, fakeLib,"Transformers_Get_Rneut")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Tap, &self->f_Transformers_Get_Tap, setObj, fakeLib,"Transformers_Get_Tap")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Xhl, &self->f_Transformers_Get_Xhl, setObj, fakeLib,"Transformers_Get_Xhl")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Xht, &self->f_Transformers_Get_Xht, setObj, fakeLib,"Transformers_Get_Xht")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Xlt, &self->f_Transformers_Get_Xlt, setObj, fakeLib,"Transformers_Get_Xlt")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_Xneut, &self->f_Transformers_Get_Xneut, setObj, fakeLib,"Transformers_Get_Xneut")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_kV, &self->f_Transformers_Get_kV, setObj, fakeLib,"Transformers_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Transformers_Get_kVA, &self->f_Transformers_Get_kVA, setObj, fakeLib,"Transformers_Get_kVA")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Vsources_Get_AngleDeg, &self->f_Vsources_Get_AngleDeg, setObj, fakeLib,"Vsources_Get_AngleDeg")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Vsources_Get_BasekV, &self->f_Vsources_Get_BasekV, setObj, fakeLib,"Vsources_Get_BasekV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Vsources_Get_Frequency, &self->f_Vsources_Get_Frequency, setObj, fakeLib,"Vsources_Get_Frequency")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_Vsources_Get_pu, &self->f_Vsources_Get_pu, setObj, fakeLib,"Vsources_Get_pu")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_Ag, &self->f_WindGens_Get_Ag, setObj, fakeLib,"WindGens_Get_Ag")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_Cp, &self->f_WindGens_Get_Cp, setObj, fakeLib,"WindGens_Get_Cp")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_Lamda, &self->f_WindGens_Get_Lamda, setObj, fakeLib,"WindGens_Get_Lamda")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_PF, &self->f_WindGens_Get_PF, setObj, fakeLib,"WindGens_Get_PF")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_PSS, &self->f_WindGens_Get_PSS, setObj, fakeLib,"WindGens_Get_PSS")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_QSS, &self->f_WindGens_Get_QSS, setObj, fakeLib,"WindGens_Get_QSS")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_RThev, &self->f_WindGens_Get_RThev, setObj, fakeLib,"WindGens_Get_RThev")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_Rad, &self->f_WindGens_Get_Rad, setObj, fakeLib,"WindGens_Get_Rad")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_VCutIn, &self->f_WindGens_Get_VCutIn, setObj, fakeLib,"WindGens_Get_VCutIn")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_VCutOut, &self->f_WindGens_Get_VCutOut, setObj, fakeLib,"WindGens_Get_VCutOut")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_Vss, &self->f_WindGens_Get_Vss, setObj, fakeLib,"WindGens_Get_Vss")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_WindSpeed, &self->f_WindGens_Get_WindSpeed, setObj, fakeLib,"WindGens_Get_WindSpeed")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_XThev, &self->f_WindGens_Get_XThev, setObj, fakeLib,"WindGens_Get_XThev")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_kV, &self->f_WindGens_Get_kV, setObj, fakeLib,"WindGens_Get_kV")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_kVA, &self->f_WindGens_Get_kVA, setObj, fakeLib,"WindGens_Get_kVA")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_kW, &self->f_WindGens_Get_kW, setObj, fakeLib,"WindGens_Get_kW")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_kvar, &self->f_WindGens_Get_kvar, setObj, fakeLib,"WindGens_Get_kvar")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WindGens_Get_pd, &self->f_WindGens_Get_pd, setObj, fakeLib,"WindGens_Get_pd")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_CapRadius, &self->f_WireData_Get_CapRadius, setObj, fakeLib,"WireData_Get_CapRadius")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_Diameter, &self->f_WireData_Get_Diameter, setObj, fakeLib,"WireData_Get_Diameter")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_EmergAmps, &self->f_WireData_Get_EmergAmps, setObj, fakeLib,"WireData_Get_EmergAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_GMRac, &self->f_WireData_Get_GMRac, setObj, fakeLib,"WireData_Get_GMRac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_NormAmps, &self->f_WireData_Get_NormAmps, setObj, fakeLib,"WireData_Get_NormAmps")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_Rac, &self->f_WireData_Get_Rac, setObj, fakeLib,"WireData_Get_Rac")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_Radius, &self->f_WireData_Get_Radius, setObj, fakeLib,"WireData_Get_Radius")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_WireData_Get_Rdc, &self->f_WireData_Get_Rdc, setObj, fakeLib,"WireData_Get_Rdc")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_Xscale, &self->f_XYCurves_Get_Xscale, setObj, fakeLib,"XYCurves_Get_Xscale")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_Xshift, &self->f_XYCurves_Get_Xshift, setObj, fakeLib,"XYCurves_Get_Xshift")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_Yscale, &self->f_XYCurves_Get_Yscale, setObj, fakeLib,"XYCurves_Get_Yscale")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_Yshift, &self->f_XYCurves_Get_Yshift, setObj, fakeLib,"XYCurves_Get_Yshift")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_x, &self->f_XYCurves_Get_x, setObj, fakeLib,"XYCurves_Get_x")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_float64, Signature_empty, ctx_XYCurves_Get_y, &self->f_XYCurves_Get_y, setObj, fakeLib,"XYCurves_Get_y")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Bus_Get_Coorddefined, &self->f_Bus_Get_Coorddefined, setObj, fakeLib,"Bus_Get_Coorddefined")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Bus_ZscRefresh, &self->f_Bus_ZscRefresh, setObj, fakeLib,"Bus_ZscRefresh")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CapControls_Get_UseVoltOverride, &self->f_CapControls_Get_UseVoltOverride, setObj, fakeLib,"CapControls_Get_UseVoltOverride")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Capacitors_AddStep, &self->f_Capacitors_AddStep, setObj, fakeLib,"Capacitors_AddStep")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Capacitors_Get_IsDelta, &self->f_Capacitors_Get_IsDelta, setObj, fakeLib,"Capacitors_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Capacitors_SubtractStep, &self->f_Capacitors_SubtractStep, setObj, fakeLib,"Capacitors_SubtractStep")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CktElement_Get_Enabled, &self->f_CktElement_Get_Enabled, setObj, fakeLib,"CktElement_Get_Enabled")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CktElement_Get_HasOCPDevice, &self->f_CktElement_Get_HasOCPDevice, setObj, fakeLib,"CktElement_Get_HasOCPDevice")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CktElement_Get_HasSwitchControl, &self->f_CktElement_Get_HasSwitchControl, setObj, fakeLib,"CktElement_Get_HasSwitchControl")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CktElement_Get_HasVoltControl, &self->f_CktElement_Get_HasVoltControl, setObj, fakeLib,"CktElement_Get_HasVoltControl")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_CktElement_Get_IsIsolated, &self->f_CktElement_Get_IsIsolated, setObj, fakeLib,"CktElement_Get_IsIsolated")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_AllowChangeDir, &self->f_DSS_Get_AllowChangeDir, setObj, fakeLib,"DSS_Get_AllowChangeDir")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_AllowDOScmd, &self->f_DSS_Get_AllowDOScmd, setObj, fakeLib,"DSS_Get_AllowDOScmd")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_AllowEditor, &self->f_DSS_Get_AllowEditor, setObj, fakeLib,"DSS_Get_AllowEditor")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_AllowForms, &self->f_DSS_Get_AllowForms, setObj, fakeLib,"DSS_Get_AllowForms")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_COMErrorResults, &self->f_DSS_Get_COMErrorResults, setObj, fakeLib,"DSS_Get_COMErrorResults")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_EnableArrayDimensions, &self->f_DSS_Get_EnableArrayDimensions, setObj, fakeLib,"DSS_Get_EnableArrayDimensions")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_DSS_Get_LegacyModels, &self->f_DSS_Get_LegacyModels, setObj, fakeLib,"DSS_Get_LegacyModels")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Error_Get_EarlyAbort, &self->f_Error_Get_EarlyAbort, setObj, fakeLib,"Error_Get_EarlyAbort")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Error_Get_ExtendedErrors, &self->f_Error_Get_ExtendedErrors, setObj, fakeLib,"Error_Get_ExtendedErrors")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Fuses_IsBlown, &self->f_Fuses_IsBlown, setObj, fakeLib,"Fuses_IsBlown")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Generators_Get_ForcedON, &self->f_Generators_Get_ForcedON, setObj, fakeLib,"Generators_Get_ForcedON")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Generators_Get_IsDelta, &self->f_Generators_Get_IsDelta, setObj, fakeLib,"Generators_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_LineCodes_Get_IsZ1Z0, &self->f_LineCodes_Get_IsZ1Z0, setObj, fakeLib,"LineCodes_Get_IsZ1Z0")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_LineGeometries_Get_Reduce, &self->f_LineGeometries_Get_Reduce, setObj, fakeLib,"LineGeometries_Get_Reduce")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Lines_Get_IsSwitch, &self->f_Lines_Get_IsSwitch, setObj, fakeLib,"Lines_Get_IsSwitch")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_LoadShapes_Get_UseActual, &self->f_LoadShapes_Get_UseActual, setObj, fakeLib,"LoadShapes_Get_UseActual")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Loads_Get_IsDelta, &self->f_Loads_Get_IsDelta, setObj, fakeLib,"Loads_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Meters_Get_DIFilesAreOpen, &self->f_Meters_Get_DIFilesAreOpen, setObj, fakeLib,"Meters_Get_DIFilesAreOpen")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_PDElements_Get_IsShunt, &self->f_PDElements_Get_IsShunt, setObj, fakeLib,"PDElements_Get_IsShunt")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Parser_Get_AutoIncrement, &self->f_Parser_Get_AutoIncrement, setObj, fakeLib,"Parser_Get_AutoIncrement")) goto ERROR_INIT;
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Reactors_Get_IsDelta, &self->f_Reactors_Get_IsDelta, setObj, fakeLib,"Reactors_Get_IsDelta")) goto ERROR_INIT;
#endif
#ifndef ALTDSS_ODDIE
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Reactors_Get_Parallel, &self->f_Reactors_Get_Parallel, setObj, fakeLib,"Reactors_Get_Parallel")) goto ERROR_INIT;
#endif
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_ReduceCkt_Get_KeepLoad, &self->f_ReduceCkt_Get_KeepLoad, setObj, fakeLib,"ReduceCkt_Get_KeepLoad")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_RegControls_Get_IsInverseTime, &self->f_RegControls_Get_IsInverseTime, setObj, fakeLib,"RegControls_Get_IsInverseTime")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_RegControls_Get_IsReversible, &self->f_RegControls_Get_IsReversible, setObj, fakeLib,"RegControls_Get_IsReversible")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Sensors_Get_IsDelta, &self->f_Sensors_Get_IsDelta, setObj, fakeLib,"Sensors_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Sensors_Get_ReverseDelta, &self->f_Sensors_Get_ReverseDelta, setObj, fakeLib,"Sensors_Get_ReverseDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Settings_Get_AllowDuplicates, &self->f_Settings_Get_AllowDuplicates, setObj, fakeLib,"Settings_Get_AllowDuplicates")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Settings_Get_ControlTrace, &self->f_Settings_Get_ControlTrace, setObj, fakeLib,"Settings_Get_ControlTrace")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Settings_Get_LoadsTerminalCheck, &self->f_Settings_Get_LoadsTerminalCheck, setObj, fakeLib,"Settings_Get_LoadsTerminalCheck")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Settings_Get_Trapezoidal, &self->f_Settings_Get_Trapezoidal, setObj, fakeLib,"Settings_Get_Trapezoidal")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Settings_Get_ZoneLock, &self->f_Settings_Get_ZoneLock, setObj, fakeLib,"Settings_Get_ZoneLock")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Solution_Get_ControlActionsDone, &self->f_Solution_Get_ControlActionsDone, setObj, fakeLib,"Solution_Get_ControlActionsDone")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Solution_Get_Converged, &self->f_Solution_Get_Converged, setObj, fakeLib,"Solution_Get_Converged")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Solution_Get_SystemYChanged, &self->f_Solution_Get_SystemYChanged, setObj, fakeLib,"Solution_Get_SystemYChanged")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Storages_Get_LimitCurrent, &self->f_Storages_Get_LimitCurrent, setObj, fakeLib,"Storages_Get_LimitCurrent")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_SwtControls_Get_IsLocked, &self->f_SwtControls_Get_IsLocked, setObj, fakeLib,"SwtControls_Get_IsLocked")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_Transformers_Get_IsDelta, &self->f_Transformers_Get_IsDelta, setObj, fakeLib,"Transformers_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_WindGens_Get_IsDelta, &self->f_WindGens_Get_IsDelta, setObj, fakeLib,"WindGens_Get_IsDelta")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_YMatrix_CheckConvergence, &self->f_YMatrix_CheckConvergence, setObj, fakeLib,"YMatrix_CheckConvergence")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_YMatrix_Get_LoadsNeedUpdating, &self->f_YMatrix_Get_LoadsNeedUpdating, setObj, fakeLib,"YMatrix_Get_LoadsNeedUpdating")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_YMatrix_Get_SolutionInitialized, &self->f_YMatrix_Get_SolutionInitialized, setObj, fakeLib,"YMatrix_Get_SolutionInitialized")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_YMatrix_Get_SystemYChanged, &self->f_YMatrix_Get_SystemYChanged, setObj, fakeLib,"YMatrix_Get_SystemYChanged")) goto ERROR_INIT;
    if (!AltDSS_Add_PyGetter(self, Signature_one_bool, Signature_empty, ctx_YMatrix_Get_UseAuxCurrents, &self->f_YMatrix_Get_UseAuxCurrents, setObj, fakeLib,"YMatrix_Get_UseAuxCurrents")) goto ERROR_INIT;
