'''
A compatibility layer for DSS C-API that mimics the official OpenDSS COM interface.

Copyright (c) 2016-2018 Paulo Meira
'''
from __future__ import absolute_import
from .._cffi_api_util import Base

from .IBus import IBus
from .ICktElement import ICktElement
from .ICktElement import ICktElement
from .ISolution import ISolution
from .IBus import IBus
from .IGenerators import IGenerators
from .IMeters import IMeters
from .IMonitors import IMonitors
from .ISettings import ISettings
from .ILines import ILines
from .ICtrlQueue import ICtrlQueue
from .ILoads import ILoads
from .ICktElement import ICktElement
from .IDSSElement import IDSSElement
from .IActiveClass import IActiveClass
from .ICapControls import ICapControls
from .IRegControls import IRegControls
from .ISwtControls import ISwtControls
from .ITransformers import ITransformers
from .ICapacitors import ICapacitors
from .ITopology import ITopology
from .ISensors import ISensors
from .IXYCurves import IXYCurves
from .IPDElements import IPDElements
from .IReclosers import IReclosers
from .IRelays import IRelays
from .ILoadShapes import ILoadShapes
from .IFuses import IFuses
from .IISources import IISources
from .IDSSimComs import IDSSimComs
from .IPVSystems import IPVSystems
from .IVsources import IVsources
from .ILineCodes import ILineCodes
from .ILineGeometries import ILineGeometries
from .ILineSpacings import ILineSpacings
from .IWireData import IWireData
from .ICNData import ICNData
from .ITSData import ITSData
from .IReactors import IReactors

class ICircuit(Base):
    __slots__ = [
        'Buses',
        'CktElements',
        'ActiveElement',
        'Solution',
        'ActiveBus',
        'Generators',
        'Meters',
        'Monitors',
        'Settings',
        'Lines',
        'CtrlQueue',
        'Loads',
        'ActiveCktElement',
        'ActiveDSSElement',
        'ActiveClass',
        'CapControls',
        'RegControls',
        'SwtControls',
        'Transformers',
        'Capacitors',
        'Topology',
        'Sensors',
        'XYCurves',
        'PDElements',
        'Reclosers',
        'Relays',
        'LoadShapes',
        'Fuses',
        'Isources',
        'ISources',
        'DSSim_Coms',
        'PVSystems',
        'Vsources',
        'LineCodes',
        'LineGeometries',
        'LineSpacings',
        'WireData',
        'CNData',
        'TSData',
        'Reactors',
        'Parallel',
    ]
    
    def __init__(self, api_util):
        self.Buses = IBus(api_util)
        self.CktElements = ICktElement(api_util)
        self.ActiveElement = ICktElement(api_util)
        self.Solution = ISolution(api_util)
        self.ActiveBus = IBus(api_util)
        self.Generators = IGenerators(api_util)
        self.Meters = IMeters(api_util)
        self.Monitors = IMonitors(api_util)
        self.Settings = ISettings(api_util)
        self.Lines = ILines(api_util)
        self.CtrlQueue = ICtrlQueue(api_util)
        self.Loads = ILoads(api_util)
        self.ActiveCktElement = ICktElement(api_util)
        self.ActiveDSSElement = IDSSElement(api_util)
        self.ActiveClass = IActiveClass(api_util)
        self.CapControls = ICapControls(api_util)
        self.RegControls = IRegControls(api_util)
        self.SwtControls = ISwtControls(api_util)
        self.Transformers = ITransformers(api_util)
        self.Capacitors = ICapacitors(api_util)
        self.Topology = ITopology(api_util)
        self.Sensors = ISensors(api_util)
        self.XYCurves = IXYCurves(api_util)
        self.PDElements = IPDElements(api_util)
        self.Reclosers = IReclosers(api_util)
        self.Relays = IRelays(api_util)
        self.LoadShapes = ILoadShapes(api_util)
        self.Fuses = IFuses(api_util)

        self.Isources = IISources(api_util)
        self.ISources = self.Isources

        self.DSSim_Coms = IDSSimComs(api_util)
        self.PVSystems = IPVSystems(api_util)
        self.Vsources = IVsources(api_util)
        self.LineCodes = ILineCodes(api_util)
        self.LineGeometries = ILineGeometries(api_util)
        self.LineSpacings = ILineSpacings(api_util)
        self.WireData = IWireData(api_util)
        self.CNData = ICNData(api_util)
        self.TSData = ITSData(api_util)
        self.Reactors = IReactors(api_util)

        if hasattr(api_util.lib, 'Parallel_CreateActor'):
            self.Parallel = IParallel(api_util)
        else:
            self.Parallel = None
            
        Base.__init__(self, api_util)
            
    def Capacity(self, Start, Increment):
        return self._lib.Circuit_Capacity(Start, Increment)

    def Disable(self, Name):
        if type(Name) is not bytes:
            Name = Name.encode(self._api_util.codec)

        self._lib.Circuit_Disable(Name)

    def Enable(self, Name):
        if type(Name) is not bytes:
            Name = Name.encode(self._api_util.codec)

        self._lib.Circuit_Enable(Name)

    def EndOfTimeStepUpdate(self):
        self._lib.Circuit_EndOfTimeStepUpdate()

    def FirstElement(self):
        return self._lib.Circuit_FirstElement()

    def FirstPCElement(self):
        return self._lib.Circuit_FirstPCElement()

    def FirstPDElement(self):
        return self._lib.Circuit_FirstPDElement()

    def AllNodeDistancesByPhase(self, Phase):
        '''(read-only) Returns an array of doubles representing the distances to parent EnergyMeter. Sequence of array corresponds to other node ByPhase properties.'''
        self._lib.Circuit_Get_AllNodeDistancesByPhase_GR(Phase)
        return self._get_float64_gr_array()

    def AllNodeNamesByPhase(self, Phase):
        '''(read-only) Return array of strings of the node names for the By Phase criteria. Sequence corresponds to other ByPhase properties.'''
        return self._get_string_array(self._lib.Circuit_Get_AllNodeNamesByPhase, Phase)

    def AllNodeVmagByPhase(self, Phase):
        '''(read-only) Returns Array of doubles represent voltage magnitudes for nodes on the specified phase.'''
        self._lib.Circuit_Get_AllNodeVmagByPhase_GR(Phase)
        return self._get_float64_gr_array()

    def AllNodeVmagPUByPhase(self, Phase):
        '''(read-only) Returns array of per unit voltage magnitudes for each node by phase'''
        self._lib.Circuit_Get_AllNodeVmagPUByPhase_GR(Phase)
        return self._get_float64_gr_array()

    def NextElement(self):
        return self._lib.Circuit_NextElement()

    def NextPCElement(self):
        return self._lib.Circuit_NextPCElement()

    def NextPDElement(self):
        return self._lib.Circuit_NextPDElement()

    def Sample(self):
        self._lib.Circuit_Sample()

    def SaveSample(self):
        self._lib.Circuit_SaveSample()

    def SetActiveBus(self, BusName):
        if type(BusName) is not bytes:
            BusName = BusName.encode(self._api_util.codec)

        return self._lib.Circuit_SetActiveBus(BusName)

    def SetActiveBusi(self, BusIndex):
        return self._lib.Circuit_SetActiveBusi(BusIndex)

    def SetActiveClass(self, ClassName):
        if type(ClassName) is not bytes:
            ClassName = ClassName.encode(self._api_util.codec)

        return self._lib.Circuit_SetActiveClass(ClassName)

    def SetActiveElement(self, FullName):
        if type(FullName) is not bytes:
            FullName = FullName.encode(self._api_util.codec)

        return self._lib.Circuit_SetActiveElement(FullName)

    def UpdateStorage(self):
        self._lib.Circuit_UpdateStorage()

    @property
    def AllBusDistances(self):
        '''(read-only) Returns distance from each bus to parent EnergyMeter. Corresponds to sequence in AllBusNames.'''
        self._lib.Circuit_Get_AllBusDistances_GR()
        return self._get_float64_gr_array()

    @property
    def AllBusNames(self):
        '''(read-only) Array of strings containing names of all buses in circuit (see AllNodeNames).'''
        return self._get_string_array(self._lib.Circuit_Get_AllBusNames)

    @property
    def AllBusVmag(self):
        '''(read-only) Array of magnitudes (doubles) of voltages at all buses'''
        self._lib.Circuit_Get_AllBusVmag_GR()
        return self._get_float64_gr_array()

    @property
    def AllBusVmagPu(self):
        '''(read-only) Double Array of all bus voltages (each node) magnitudes in Per unit'''
        self._lib.Circuit_Get_AllBusVmagPu_GR()
        return self._get_float64_gr_array()

    @property
    def AllBusVolts(self):
        '''(read-only) Complex array of all bus, node voltages from most recent solution'''
        self._lib.Circuit_Get_AllBusVolts_GR()
        return self._get_float64_gr_array()

    @property
    def AllElementLosses(self):
        '''(read-only) Array of total losses (complex) in each circuit element'''
        self._lib.Circuit_Get_AllElementLosses_GR()
        return self._get_float64_gr_array()

    @property
    def AllElementNames(self):
        '''(read-only) Array of strings containing Full Name of all elements.'''
        return self._get_string_array(self._lib.Circuit_Get_AllElementNames)

    @property
    def AllNodeDistances(self):
        '''(read-only) Returns an array of distances from parent EnergyMeter for each Node. Corresponds to AllBusVMag sequence.'''
        self._lib.Circuit_Get_AllNodeDistances_GR()
        return self._get_float64_gr_array()

    @property
    def AllNodeNames(self):
        '''(read-only) Array of strings containing full name of each node in system in same order as returned by AllBusVolts, etc.'''
        return self._get_string_array(self._lib.Circuit_Get_AllNodeNames)

    @property
    def LineLosses(self):
        '''(read-only) Complex total line losses in the circuit'''
        self._lib.Circuit_Get_LineLosses_GR()
        return self._get_float64_gr_array()

    @property
    def Losses(self):
        '''(read-only) Total losses in active circuit, complex number (two-element array of double).'''
        self._lib.Circuit_Get_Losses_GR()
        return self._get_float64_gr_array()

    @property
    def Name(self):
        '''(read-only) Name of the active circuit.'''
        return self._get_string(self._lib.Circuit_Get_Name())

    @property
    def NumBuses(self):
        '''(read-only) Total number of Buses in the circuit.'''
        return self._lib.Circuit_Get_NumBuses()

    @property
    def NumCktElements(self):
        '''(read-only) Number of CktElements in the circuit.'''
        return self._lib.Circuit_Get_NumCktElements()

    @property
    def NumNodes(self):
        '''(read-only) Total number of nodes in the circuit.'''
        return self._lib.Circuit_Get_NumNodes()

    @property
    def ParentPDElement(self):
        '''(read-only) Sets Parent PD element, if any, to be the active circuit element and returns index>0; Returns 0 if it fails or not applicable.'''
        return self._lib.Circuit_Get_ParentPDElement()

    @property
    def SubstationLosses(self):
        '''(read-only) Complex losses in all transformers designated to substations.'''
        self._lib.Circuit_Get_SubstationLosses_GR()
        return self._get_float64_gr_array()

    @property
    def SystemY(self):
        '''(read-only) System Y matrix (after a solution has been performed)'''
        self._lib.Circuit_Get_SystemY_GR()
        return self._get_float64_gr_array()

    @property
    def TotalPower(self):
        '''(read-only) Total power, watts delivered to the circuit'''
        self._lib.Circuit_Get_TotalPower_GR()
        return self._get_float64_gr_array()

    @property
    def YCurrents(self):
        '''(read-only) Array of doubles containing complex injection currents for the present solution. Is is the "I" vector of I=YV'''
        self._lib.Circuit_Get_YCurrents_GR()
        return self._get_float64_gr_array()

    @property
    def YNodeOrder(self):
        '''(read-only) Array of strings containing the names of the nodes in the same order as the Y matrix'''
        return self._get_string_array(self._lib.Circuit_Get_YNodeOrder)

    @property
    def YNodeVarray(self):
        '''(read-only) Complex array of actual node voltages in same order as SystemY matrix.'''
        self._lib.Circuit_Get_YNodeVarray_GR()
        return self._get_float64_gr_array()
