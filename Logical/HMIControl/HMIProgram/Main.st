
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Code Stored Here to Drive HMI Functions
	
	//Map HMI inputs to system status, add conditions where required
	sys.Stat.On := sys.i.Power;
	sys.Stat.Automatic := sys.i.Auto;
	sys.Stat.Manual := NOT sys.i.Auto;
	sys.Stat.Paused := sys.i.Pause;
	sys.Stat.Stopped := sys.i.Stop;

	//Outputs are driven from the HMI when not in automatic
	IF sys.Stat.Manual THEN
		Device(sys.Stat.Automatic, pbMashPump, FALSE, MashPump);
		Device(sys.Stat.Automatic, pbHLTPump, FALSE, HLTPump);
		Device(sys.Stat.Automatic, pbCoolingPump, FALSE, CoolingPump);
		Device(sys.Stat.Automatic, pbKettleHeater, FALSE, KettleHeater);
		Device(sys.Stat.Automatic, pbHLTHeater, FALSE, HLTHeater);
		Device(sys.Stat.Automatic, pbSysPower, FALSE, SysPower);
	END_IF
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

