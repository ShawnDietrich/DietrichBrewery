(*Main Type*)

TYPE
	MashToHLT : 	STRUCT 
		Start : BOOL;
		HLTTemp : REAL;
	END_STRUCT;
	ProcControl : 	STRUCT 
		setPower : REAL;
		currPower : REAL;
		currTemp : REAL;
		SetTemp : REAL;
		TempCtrl : TempCont;
		State : ControlState;
		Status : SystemStatus;
		i : SystemInput;
	END_STRUCT;
END_TYPE

(*HMI Inputs and Status*)

TYPE
	SystemInput : 	STRUCT 
		ResetError : BOOL;
		EStop : BOOL;
		Auto : BOOL;
		Stop : BOOL;
		Pause : BOOL;
		Start : BOOL;
	END_STRUCT;
	SystemStatus : 	STRUCT 
		Automatic : BOOL;
		Manual : BOOL;
		Running : BOOL;
		Stopped : BOOL;
		Paused : BOOL;
		On : BOOL;
	END_STRUCT;
END_TYPE

(*Temp Controller Types*)

TYPE
	TempCont : 	STRUCT 
		Ctrl : MpTempController;
		Ptr : MpTempControllerParType;
		PWM : MTBasicsPWM;
	END_STRUCT;
END_TYPE

(*State Machines*)

TYPE
	ControlState : 
		(
		Stop,
		Manual,
		Automatic,
		SimManual,
		SimAuto
		);
END_TYPE
