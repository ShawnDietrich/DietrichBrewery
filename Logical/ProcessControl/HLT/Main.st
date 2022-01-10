
PROGRAM _INIT

END_PROGRAM

PROGRAM _CYCLIC
	//Initilize Temp Controller FB
	Proc.TempCtrl.Ctrl.Parameters := ADR(Proc.TempCtrl.Ptr);
	Proc.TempCtrl.Ctrl.MpLink := ADR(Cfg_HLTTemp);
	//Map Variables
	Proc.TempCtrl.Ctrl.Control := Proc.i.Start;
	Proc.TempCtrl.Ctrl.ErrorReset := Proc.i.ResetError;
	
	//Mash cycle variables
	IF EDGEPOS(FromMashCyc.Start) THEN
		Proc.i.Auto 	:= TRUE;
		Proc.i.Start 	:= TRUE;
		Proc.SetTemp 	:= FromMashCyc.HLTTemp;
	ELSIF EDGENEG(FromMashCyc.Start) THEN
		Proc.i.Auto 	:= FALSE;
		Proc.i.Start 	:= FALSE;
	END_IF
	
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
	
	
	//Call FB's
	Proc.TempCtrl.Ctrl();
	Proc.TempCtrl.PWM();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

