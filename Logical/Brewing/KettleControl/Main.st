
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
	
	IF Proc.Status.Automatic THEN
		Proc.State := Automatic;
	ELSIF Proc.Status.Manual THEN
		Proc.State := Manual;
	ELSE
	;
	END_IF
	
	
	//Set the state machine
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		Proc.TempCtrl.Ctrl.Enable	:= TRUE;
		Proc.TempCtrl.Ctrl.Simulate := TRUE;
		Proc.currTemp := Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature;
	ELSE
		Proc.currTemp := rawHLTTemp * 1000;
	END_IF
	
	//Temperature controller state machine
	CASE Proc.State OF 
			
		Manual:
			//PWM control
			Proc.TempCtrl.PWM.Enable 	:= Proc.i.Start;
			
			//PWM Parameters
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period 		:= 1.0;
			KettleHeater := Proc.TempCtrl.PWM.Out;
			
			//HMI Variables
			IF Proc.TempCtrl.PWM.Active THEN
				Proc.currPower := Proc.TempCtrl.PWM.DutyCycle;
			ELSE
				Proc.currPower := 0;
			END_IF
			
		Automatic:
			//Not Used
			
			
			
	END_CASE
	
	//Power Control
	IF pbUp AND Proc.setPower < 100 THEN
		Proc.setPower := Proc.setPower + 1;
		pbUp := FALSE;
	ELSIF  pbDown AND Proc.setPower > 0 THEN
		Proc.setPower := Proc.setPower - 1;
		pbDown := FALSE;
	END_IF
	
	IF pbFastUp AND Proc.setPower < 100 THEN 
		Proc.setPower := Proc.setPower + 10;
		pbFastUp := FALSE;
	ELSIF pbFastDown AND Proc.setPower > 0 THEN
		Proc.setPower := Proc.setPower - 10;
		pbFastDown := FALSE;
	END_IF
	
	//Call Action Files
	Displayclock;
	HopControl;
	
	//Call FB's
	Proc.TempCtrl.Ctrl();
	Proc.TempCtrl.PWM();
	KettleTmr();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

