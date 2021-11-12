
TYPE
	ControlState : 
		(
		Manual,
		Automatic,
		Simulation
		);
	Controller : 	STRUCT 
		ManPWM : MTBasicsPWM;
		State : ControlState;
		TempPram : MpTempControllerParType;
		TempCont : MpTempController;
	END_STRUCT;
END_TYPE
