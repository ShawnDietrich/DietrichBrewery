
PROGRAM _INIT
	ValveTmr.PT := T#2s;
END_PROGRAM

PROGRAM _CYCLIC

	//Start and stop logic
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		SimFlowMeter;
	END_IF
	
	//Fill tank programs
	FillHLT;
	FillMash;
	
	//Control Selector Relay
	IF AutoFillHLT.Valve THEN
		ValveSelector := TRUE;
	END_IF
	

	//Open or close valve
	IF EDGEPOS(AutoFillHLT.Valve OR AutoFillMash.Valve) THEN
		ValveOn := TRUE;
		ValveTmr.IN := TRUE;
	ELSIF EDGENEG(AutoFillHLT.Valve OR AutoFillMash.Valve) THEN
		ValveOff := TRUE; 
		ValveTmr.IN := TRUE;
	END_IF
	
	IF ValveTmr.Q THEN
		ValveOn := FALSE;
		ValveOff := FALSE; 
		ValveTmr.IN := FALSE;
		ValveSelector := FALSE;
	END_IF
	

	
	ValveTmr();
END_PROGRAM

PROGRAM _EXIT
	
	
	 
END_PROGRAM

