
TYPE
	TemperatureController : 	STRUCT 
		Temperature : REAL;
		Automatic : BOOL;
		Start : BOOL;
		Running : BOOL;
		ErrorReset : BOOL;
		setPower : REAL;
		currPower : REAL;
		SetTemp : REAL;
	END_STRUCT;
	SystemInput : 	STRUCT 
		EStop : BOOL;
		Auto : BOOL;
		Stop : BOOL;
		Pause : BOOL;
		Power : BOOL;
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
		Stat : SystemStatus;
	END_STRUCT;
END_TYPE
