
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
		//Automatic and manual conditions
	mProc.Status.Automatic 	:= mProc.i.Start;
	mProc.Status.Manual		:= NOT mProc.i.Start;
	FromMashCyc.Start := mProc.i.Start;
	
	//Set the state machine
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		IF mProc.Status.Automatic THEN
			mProc.State := SimAuto;
		ELSIF mProc.Status.Manual THEN
			mProc.State := SimManual;
		END_IF
	END_IF
	
	
	//Match the pump status with the state
	IF mProc.i.Start THEN
		pbMashPump := PumpExp;
	ELSE
		PumpExp := pbMashPump;
	END_IF
	
	
	CASE mProc.State OF 
		
		SimManual:
			//Figure out how to simulate the temperature
			mProc.currTemp := rawMashTemp / 1000;
			
		SimAuto:
			//Figure out how to simulate the temperature
			mProc.currTemp := rawMashTemp / 1000;
			FromMashCyc.HLTTemp := mProc.SetTemp;
			
			//Stop pump if the mash temp gets too high
			IF mProc.currTemp < mProc.SetTemp THEN
				PumpExp 	:= TRUE;
			ELSE
				PumpExp 	:= FALSE;
			END_IF
		
			MashTime := DINT_TO_TIME(TimePre);
			//Start Mash Timer 
			MashTmr(StartMash, MashTime);
				
		Manual:
		
			mProc.currTemp := rawMashTemp / 1000;
		
	END_CASE 
		
	MashPump := PumpExp;
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

