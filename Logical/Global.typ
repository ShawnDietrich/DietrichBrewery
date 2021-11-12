
TYPE
	TemperatureController : 	STRUCT 
		Automatic : BOOL;
		Start : BOOL;
		Running : BOOL;
		ErrorReset : BOOL;
		setPower : REAL;
		currPower : REAL;
	END_STRUCT;
	SystemOutput : 	STRUCT 
		Stop : BOOL;
		Pause : BOOL;
		Run : BOOL;
		Power : BOOL;
	END_STRUCT;
	SystemInput : 	STRUCT 
		EStop : BOOL;
	END_STRUCT;
	SystemStatus : 	STRUCT 
		Automatic : BOOL;
		Manual : BOOL;
		Running : BOOL;
		Stopped : BOOL;
		Paused : BOOL;
		On : BOOL;
	END_STRUCT;
	System : 	STRUCT 
		i : SystemInput;
		o : SystemOutput;
		Stat : SystemStatus;
	END_STRUCT;
END_TYPE
