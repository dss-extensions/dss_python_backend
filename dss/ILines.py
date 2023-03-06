'''
A compatibility layer for DSS C-API that mimics the official OpenDSS COM interface.

Copyright (c) 2016-2023 Paulo Meira

Copyright (c) 2018-2023 DSS Extensions contributors
'''
from ._cffi_api_util import Iterable
from ._types import Float64Array
from typing import AnyStr

class ILines(Iterable):
    __slots__ = []

    _columns = [
        'Name',
        'idx',
        'Phases',
        'Bus1',
        'Bus2',
        'LineCode',
        'Geometry',
        'Length',
        'IsSwitch',
        'Parent',
        'Spacing',
        'EmergAmps', 
        'NormAmps',
        'SeasonRating',
        'Yprim',
        'NumCust',
        'TotalCust',
        'Rho',
        'R0',
        'R1',
        'X0',
        'X1',
        'Rg', 
        'Xg',
        'C0',
        'C1',
        'Rmatrix',
        'Xmatrix',
        'Cmatrix',
        'Units', 
    ]

    def New(self, Name):
        if type(Name) is not bytes:
            Name = Name.encode(self._api_util.codec)

        return self.CheckForError(self._lib.Lines_New(Name))

    @property
    def Bus1(self) -> str:
        '''Name of bus for terminal 1.'''
        return self._get_string(self.CheckForError(self._lib.Lines_Get_Bus1()))

    @Bus1.setter
    def Bus1(self, Value):
        if type(Value) is not bytes:
            Value = Value.encode(self._api_util.codec)

        self.CheckForError(self._lib.Lines_Set_Bus1(Value))

    @property
    def Bus2(self) -> str:
        '''Name of bus for terminal 2.'''
        return self._get_string(self.CheckForError(self._lib.Lines_Get_Bus2()))

    @Bus2.setter
    def Bus2(self, Value):
        if type(Value) is not bytes:
            Value = Value.encode(self._api_util.codec)

        self.CheckForError(self._lib.Lines_Set_Bus2(Value))

    @property
    def C0(self) -> float:
        '''Zero Sequence capacitance, nanofarads per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_C0())

    @C0.setter
    def C0(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_C0(Value))

    @property
    def C1(self) -> float:
        '''Positive Sequence capacitance, nanofarads per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_C1())

    @C1.setter
    def C1(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_C1(Value))

    @property
    def Cmatrix(self) -> Float64Array:
        self.CheckForError(self._lib.Lines_Get_Cmatrix_GR())
        return self._get_float64_gr_array()

    @Cmatrix.setter
    def Cmatrix(self, Value: Float64Array):
        Value, ValuePtr, ValueCount = self._prepare_float64_array(Value)
        self.CheckForError(self._lib.Lines_Set_Cmatrix(ValuePtr, ValueCount))

    @property
    def EmergAmps(self) -> float:
        '''Emergency (maximum) ampere rating of Line.'''
        return self.CheckForError(self._lib.Lines_Get_EmergAmps())

    @EmergAmps.setter
    def EmergAmps(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_EmergAmps(Value))

    @property
    def Geometry(self) -> str:
        '''Line geometry code'''
        return self._get_string(self.CheckForError(self._lib.Lines_Get_Geometry()))

    @Geometry.setter
    def Geometry(self, Value: AnyStr):
        if type(Value) is not bytes:
            Value = Value.encode(self._api_util.codec)

        self.CheckForError(self._lib.Lines_Set_Geometry(Value))

    @property
    def Length(self) -> float:
        '''Length of line section in units compatible with the LineCode definition.'''
        return self.CheckForError(self._lib.Lines_Get_Length())

    @Length.setter
    def Length(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_Length(Value))

    @property
    def LineCode(self) -> str:
        '''Name of LineCode object that defines the impedances.'''
        return self._get_string(self.CheckForError(self._lib.Lines_Get_LineCode()))

    @LineCode.setter
    def LineCode(self, Value: AnyStr):
        if type(Value) is not bytes:
            Value = Value.encode(self._api_util.codec)

        self.CheckForError(self._lib.Lines_Set_LineCode(Value))

    @property
    def NormAmps(self) -> float:
        '''Normal ampere rating of Line.'''
        return self.CheckForError(self._lib.Lines_Get_NormAmps())

    @NormAmps.setter
    def NormAmps(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_NormAmps(Value))

    @property
    def NumCust(self) -> int:
        '''(read-only) Number of customers on this line section.'''
        return self.CheckForError(self._lib.Lines_Get_NumCust())

    @property
    def Parent(self) -> int:
        '''(read-only) Sets Parent of the active Line to be the active line. Returns 0 if no parent or action fails.'''
        return self.CheckForError(self._lib.Lines_Get_Parent())

    @property
    def Phases(self) -> int:
        '''Number of Phases, this Line element.'''
        return self.CheckForError(self._lib.Lines_Get_Phases())

    @Phases.setter
    def Phases(self, Value: int):
        self.CheckForError(self._lib.Lines_Set_Phases(Value))

    @property
    def R0(self) -> float:
        '''Zero Sequence resistance, ohms per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_R0())

    @R0.setter
    def R0(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_R0(Value))

    @property
    def R1(self) -> float:
        '''Positive Sequence resistance, ohms per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_R1())

    @R1.setter
    def R1(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_R1(Value))

    @property
    def Rg(self) -> float:
        '''Earth return resistance value used to compute line impedances at power frequency'''
        return self.CheckForError(self._lib.Lines_Get_Rg())

    @Rg.setter
    def Rg(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_Rg(Value))

    @property
    def Rho(self) -> float:
        '''Earth Resistivity, m-ohms'''
        return self.CheckForError(self._lib.Lines_Get_Rho())

    @Rho.setter
    def Rho(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_Rho(Value))

    @property
    def Rmatrix(self) -> Float64Array:
        '''Resistance matrix (full), ohms per unit length. Array of doubles.'''
        self.CheckForError(self._lib.Lines_Get_Rmatrix_GR())
        return self._get_float64_gr_array()

    @Rmatrix.setter
    def Rmatrix(self, Value: float):
        Value, ValuePtr, ValueCount = self._prepare_float64_array(Value)
        self.CheckForError(self._lib.Lines_Set_Rmatrix(ValuePtr, ValueCount))

    @property
    def Spacing(self) -> str:
        '''Line spacing code'''
        return self._get_string(self.CheckForError(self._lib.Lines_Get_Spacing()))

    @Spacing.setter
    def Spacing(self, Value: AnyStr):
        if type(Value) is not bytes:
            Value = Value.encode(self._api_util.codec)

        self.CheckForError(self._lib.Lines_Set_Spacing(Value))

    @property
    def TotalCust(self) -> int:
        '''(read-only) Total Number of customers served from this line section.'''
        return self.CheckForError(self._lib.Lines_Get_TotalCust())

    @property
    def Units(self) -> int:
        return self.CheckForError(self._lib.Lines_Get_Units()) #TODO: use enum

    @Units.setter
    def Units(self, Value: int):
        self.CheckForError(self._lib.Lines_Set_Units(Value))

    @property
    def X0(self) -> float:
        '''Zero Sequence reactance ohms per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_X0())

    @X0.setter
    def X0(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_X0(Value))

    @property
    def X1(self) -> float:
        '''Positive Sequence reactance, ohms per unit length.'''
        return self.CheckForError(self._lib.Lines_Get_X1())

    @X1.setter
    def X1(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_X1(Value))

    @property
    def Xg(self) -> float:
        '''Earth return reactance value used to compute line impedances at power frequency'''
        return self.CheckForError(self._lib.Lines_Get_Xg())

    @Xg.setter
    def Xg(self, Value: float):
        self.CheckForError(self._lib.Lines_Set_Xg(Value))

    @property
    def Xmatrix(self) -> Float64Array:
        '''Reactance matrix (full), ohms per unit length. Array of doubles.'''
        self.CheckForError(self._lib.Lines_Get_Xmatrix_GR())
        return self._get_float64_gr_array()

    @Xmatrix.setter
    def Xmatrix(self, Value: Float64Array):
        Value, ValuePtr, ValueCount = self._prepare_float64_array(Value)
        self.CheckForError(self._lib.Lines_Set_Xmatrix(ValuePtr, ValueCount))

    @property
    def Yprim(self) -> Float64Array:
        '''Yprimitive for the active line object.'''
        self.CheckForError(self._lib.Lines_Get_Yprim_GR())
        return self._get_float64_gr_array()

    @Yprim.setter
    def Yprim(self, Value: Float64Array):
        Value, ValuePtr, ValueCount = self._prepare_float64_array(Value)
        self.CheckForError(self._lib.Lines_Set_Yprim(ValuePtr, ValueCount))

    @property
    def SeasonRating(self) -> float:
        '''Delivers the rating for the current season (in Amps)  if the "SeasonalRatings" option is active'''
        return self.CheckForError(self._lib.Lines_Get_SeasonRating())

    @property
    def IsSwitch(self) -> bool:
        '''Sets/gets the Line element switch status. Setting it has side-effects to the line parameters.'''
        return self.CheckForError(self._lib.Lines_Get_IsSwitch()) != 0
        
    @IsSwitch.setter
    def IsSwitch(self, Value: bool):
        self.CheckForError(self._lib.Lines_Set_IsSwitch(Value))

