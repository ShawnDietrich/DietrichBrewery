
PROGRAM _INIT
		//Initilize Temp Controller FB
	mProc.TempCtrl.Ctrl.Parameters := ADR(mProc.TempCtrl.Ptr);
	mProc.TempCtrl.Ctrl.MpLink := ADR(Cfg_MashTemp_simulated);
	 
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
			//mProc.currTemp := rawMashTemp / 1000;
			
			//Simulate temperature
			mProc.TempCtrl.PWM.Enable := FALSE;
			mProc.TempCtrl.Ctrl.Enable := TRUE;
			mProc.TempCtrl.Ctrl.Simulate := TRUE;
			mProc.currTemp := mProc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
			mProc.TempCtrl.Ctrl.SetTemperature := mProc.SetTemp;
			mProc.TempCtrl.Ctrl.Control := mProc.i.Start;
			//Set parameters
			FromMashCyc.HLTTemp := mProc.SetTemp + 3;
			pbMashPump := PumpExp;
			
			//Stop pump if the mash temp gets too high
			IF mProc.currTemp > (mProc.SetTemp * 1.10) THEN
				PumpExp	:= FALSE;
			ELSE
				PumpExp	:= TRUE;
			END_IF 
			
			//Mash timer 
			MashTmr.PT := DINT_TO_TIME(TimePre*60000);
			//Start Mash Timer 
			MashTmr.IN := StartMash;
			
			//Calculate and display the remaining time
			TIME_TO_TIMEStructure((MashTmr.PT - MashTmr.ET), ADR(TmrDT));
			HrRe 	:= USINT_TO_STRING(TmrDT.hour);
			MinRe 	:= USINT_TO_STRING(TmrDT.minute);
			SecRe	:= USINT_TO_STRING(TmrDT.second);
			TmrRemain := CONCAT(HrRe, ':');
			TmrRemain := CONCAT(TmrRemain, MinRe);
			TmrRemain := CONCAT(TmrRemain,':');
			TmrRemain := CONCAT(TmrRemain, SecRe);
		
			
			//Mash Time is Done Rest Everything
			IF MashTmr.Q THEN
				StartMash := FALSE;
				mProc.i.Start := FALSE;
			END_IF
			
			//call simulated FUB
			mProc.TempCtrl.Ctrl();
			mProc.TempCtrl.PWM();
				
		Manual:
		
			mProc.currTemp := rawMashTemp / 1000;
		
	END_CASE 
		
	MashPump := PumpExp;
	
	MashTmr();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

