
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	//Initilize Temp Controller FB
	Proc.TempCtrl.Ctrl.Parameters := ADR(Proc.TempCtrl.Ptr);
	Proc.TempCtrl.Ctrl.MpLink := ADR(Cfg_KettleTemp);
	//Map Variables
	Proc.TempCtrl.Ctrl.Control := Proc.i.Start;
	Proc.TempCtrl.Ctrl.ErrorReset := Proc.i.ResetError;
	

	
	//Automatic and manual conditions
	Proc.Status.Automatic 	:= Proc.i.Auto;
	Proc.Status.Manual		:= NOT Proc.i.Auto;
	
	//Set the state machine
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		IF Proc.Status.Automatic THEN
			Proc.State := SimAuto;
		ELSIF Proc.Status.Manual THEN
			Proc.State := SimManual;
		END_IF
	END_IF
	
	//Temperature controller state machine
	CASE Proc.State OF 
		
		SimAuto:
			//Setup variables
			Proc.TempCtrl.PWM.Enable := FALSE;
			Proc.TempCtrl.Ctrl.Enable := TRUE;
			Proc.TempCtrl.Ctrl.Simulate := TRUE;
			//Map Simulated Values
			Proc.TempCtrl.Ctrl.ActualTemperature := Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
			Proc.TempCtrl.Ctrl.SetTemperature := Proc.SetTemp;
			Proc.TempCtrl.Ctrl.Control := Proc.i.Start;
			Proc.currTemp := Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
			Proc.currPower := Proc.TempCtrl.Ctrl.Info.Simulation.HeatValue;
			HLTHeater := Proc.TempCtrl.Ctrl.Info.Simulation.Heat;
			
		SimManual:
			Proc.TempCtrl.PWM.Enable 	:= TRUE;
			Proc.TempCtrl.Ctrl.Enable	:= FALSE;
			//Proc.TempCtrl.PWM Variables
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period 		:= 1.0;
			Proc.currPower := Proc.TempCtrl.PWM.DutyCycle;
			
		Automatic:
			Proc.TempCtrl.PWM.Enable 	:= TRUE;
			Proc.TempCtrl.Ctrl.Enable 	:= FALSE;
			Proc.TempCtrl.Ctrl.ActualTemperature := rawHLTTemp * 1000;
			Proc.currPower 	:= Proc.TempCtrl.Ctrl.HeatValue;
			Proc.currTemp	:= rawHLTTemp * 1000;
			
		Manual:
			Proc.TempCtrl.PWM.Enable 	:= FALSE;
			Proc.TempCtrl.Ctrl.Enable 	:= TRUE;
			//Proc.TempCtrl.PWM Variables
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period := 1.0;
			Proc.currTemp := rawHLTTemp * 1000;
			
	END_CASE
	
	//Kettle timer 
	KettleTmr.PT := DINT_TO_TIME(TimePre*60000);
	//Start Kettle Timer 
	KettleTmr.IN := StartKettle;
			
	//Calculate and display the remaining time
	TIME_TO_TIMEStructure((KettleTmr.PT - KettleTmr.ET), ADR(TmrDT));
	HrRe 	:= USINT_TO_STRING(TmrDT.hour);
	MinRe 	:= USINT_TO_STRING(TmrDT.minute);
	SecRe	:= USINT_TO_STRING(TmrDT.second);
	TmrRemain := CONCAT(HrRe, ':');
	TmrRemain := CONCAT(TmrRemain, MinRe);
	TmrRemain := CONCAT(TmrRemain,':');
	TmrRemain := CONCAT(TmrRemain, SecRe);
		
			
	//Kettle Time is Done Rest Everything
	IF KettleTmr.Q THEN
		StartKettle := FALSE;
		Proc.i.Start := FALSE;
	END_IF

	 	//Call FB's
	Proc.TempCtrl.Ctrl();
	Proc.TempCtrl.PWM();
	KettleTmr();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

