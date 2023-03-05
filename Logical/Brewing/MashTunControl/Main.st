
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
	
	IF mProc.Status.Automatic THEN
		mProc.State := Automatic;
	ELSIF mProc.Status.Manual THEN
		mProc.State := Manual;
	END_IF
	
	//Simulate Values
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		mProc.currTemp := mProc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
		mProc.TempCtrl.Ctrl.Simulate := TRUE;
		mProc.TempCtrl.PWM.Enable := FALSE;
		mProc.TempCtrl.Ctrl.Enable := TRUE;
		mProc.TempCtrl.Ctrl.SetTemperature := mProc.SetTemp;
		mProc.TempCtrl.Ctrl.Control := mProc.i.Start;
	ELSE 
		mProc.currTemp := rawMashTemp / 1000;
		mProc.TempCtrl.Ctrl.Simulate := FALSE;
	END_IF 

	//Turn off pump when switching auto and manual
	IF EDGENEG(mProc.i.Start) THEN
		pbMashPump 		:= FALSE;
		StartMash 		:= FALSE;
		MashTmr.IN		:= FALSE;
		mProc.i.Start 	:= FALSE;
	END_IF
	
	
	CASE mProc.State OF 
		
		Manual:
			//Figure out how to simulate the temperature
			mProc.currTemp := rawMashTemp / 1000;
			PumpExp := pbMashPump;
			
		Automatic:

			//Set parameters
			FromMashCyc.HLTTemp := mProc.SetTemp + 3;
			pbMashPump := PumpExp;
			
			//Stop pump if the mash temp gets too high
			IF mProc.currTemp > (mProc.SetTemp * 1.10) THEN
				PumpExp	:= FALSE;
			ELSE
				PumpExp	:= TRUE;
			END_IF 
		
	END_CASE 
	
	//Mash timer 
	MashTmr.PT := DINT_TO_TIME(TimePre*60000);
	MashTmr.IN := StartMash;
	
	//Mash Time is Done Rest Everything
	IF MashTmr.Q THEN
		StartMash := FALSE;
		mProc.i.Start := FALSE;
		Buzzer := TRUE;
	END_IF
	
	//Calculate and display the remaining time
	TIME_TO_TIMEStructure((MashTmr.PT - MashTmr.ET), ADR(TmrDT));
	HrRe 	:= USINT_TO_STRING(TmrDT.hour);
	MinRe 	:= USINT_TO_STRING(TmrDT.minute);
	SecRe	:= USINT_TO_STRING(TmrDT.second);
	TmrRemain := CONCAT(HrRe, ':');
	TmrRemain := CONCAT(TmrRemain, MinRe);
	TmrRemain := CONCAT(TmrRemain,':');
	TmrRemain := CONCAT(TmrRemain, SecRe);
	
	//HMI Control
	MashPump := PumpExp;
	
	//Call Function Blocks
	MashTmr();
	
	//call simulated FUB
	mProc.TempCtrl.Ctrl();
	mProc.TempCtrl.PWM();
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

