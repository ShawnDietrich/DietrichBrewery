
TYPE
	ValveControl : 	STRUCT 
		Reset : BOOL;
		Stop : BOOL;
		Start : BOOL;
		ValveR : R_TRIG;
		Valve : BOOL;
		VolumePV : REAL;
		VolumeSP : REAL;
		State : ControlState;
	END_STRUCT;
END_TYPE
