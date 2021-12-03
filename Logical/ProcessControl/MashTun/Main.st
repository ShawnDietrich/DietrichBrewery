
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

	//Turn off pump when switching auto and manual
	IF EDGENEG(mProc.i.Start) THEN
		pbMashPump 		:= FALSE;
		StartMash 		:= FALSE;
		MashTmr.IN		:= FALSE;
		mProc.i.Start 	:= FALSE;
	END_IF
	
	
	CASE mProc.State OF 
		
		SimManual:
			//Figure out how to simulate the temperature
			mProc.currTemp := rawMashTemp / 1000;
			PumpExp := pbMashPump;
			
		SimAuto:
			//Figure out how to simulate the temperature
			mProc.currTemp := rawMashTemp / 1000;
			FromMashCyc.HLTTemp := mProc.SetTemp + 15;
			pbMashPump := PumpExp;
			
			//Stop pump if the mash temp gets too high
			IF mProc.currTemp < mProc.SetTemp THEN
				PumpExp	:= TRUE;
			ELSE
				PumpExp	:= FALSE;
			END_IF 
			
			//Mash timer 
			MashTmr.PT := DINT_TO_TIME(TimePre*60000);
			//Start Mash Timer 
			MashTmr.IN := StartMash;
			
			//Calculate and display the remaining time
			TmrRe := TIME_TO_STRING(MashTmr.PT - MashTmr.ET);
			//Remove the T#
			TmrRemain := DELETE(TmrRe,2,1);
			// Find the first '_' in string
			TmrRemain := REPLACE(TmrRemain, ' ',1,FIND(TmrRemain,'_'));
			//Find the second '_' in string
			TmrRemain := REPLACE(TmrRemain, ' ',1,FIND(TmrRemain,'_'));
			//Remove everything after seconds
			TmrRemain := DELETE(TmrRemain,6,8);
			
			
			IF MashTmr.Q THEN
				StartMash := FALSE;
				mProc.i.Start := FALSE;
			END_IF
			
				
		Manual:
		
			mProc.currTemp := rawMashTemp / 1000;
		
	END_CASE 
		
	MashPump := PumpExp;
	
	MashTmr();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

