
PROGRAM _INIT

END_PROGRAM

PROGRAM _CYCLIC
	//Initilize Temp Controller FB
	Proc.TempCtrl.Ctrl.Parameters := ADR(Proc.TempCtrl.Ptr);
	Proc.TempCtrl.Ctrl.MpLink := ADR(Cfg_HLTTemp);
	
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
	
	//Map Variables
	Proc.TempCtrl.Ctrl.Control := Proc.i.Start;
	Proc.TempCtrl.Ctrl.ErrorReset := Proc.i.ResetError;
	Proc.TempCtrl.Ctrl.SetTemperature := Proc.SetTemp;
	
	IF Proc.Status.Automatic THEN
		Proc.State := Automatic;
	ELSIF Proc.Status.Manual THEN
		Proc.State := Manual;
	END_IF
	
	//Set the state machine
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		Proc.currTemp := Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
		Proc.currPower := Proc.TempCtrl.Ctrl.Info.Simulation.HeatValue;
		Proc.TempCtrl.Ctrl.Simulate := TRUE;
	ELSE
		Proc.TempCtrl.Ctrl.ActualTemperature := rawHLTTemp * 1000;
		
		Proc.currTemp	:= rawHLTTemp * 1000;
		Proc.TempCtrl.Ctrl.Simulate := FALSE;
	END_IF
	
	//Temperature controller state machine
	CASE Proc.State OF 
			
		Automatic:
			//Temperature control parameters
			Proc.TempCtrl.PWM.Enable 	:= FALSE;
			Proc.TempCtrl.Ctrl.Enable 	:= TRUE;
			
			//HMI Variables
			HLTHeater := Proc.TempCtrl.Ctrl.Heat;
			Proc.currPower 	:= Proc.TempCtrl.Ctrl.HeatValue;
			
		Manual:
			//Temperature control parmeters
			Proc.TempCtrl.PWM.Enable 	:= Proc.i.Start;
			Proc.TempCtrl.Ctrl.Enable 	:= FALSE;
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period := 1.0;
			
			//HMI Variables
			HLTHeater := Proc.TempCtrl.PWM.Out;
			IF Proc.TempCtrl.PWM.Active THEN
				Proc.currPower := Proc.TempCtrl.PWM.DutyCycle;
			ELSE 
				Proc.currPower := 0;
			END_IF
		
	END_CASE
	
	
	//Call FB's
	Proc.TempCtrl.Ctrl();
	Proc.TempCtrl.PWM();
	
	//Set pump output
	HLTPump := PumpExp;
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

