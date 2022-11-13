
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
			//Not Used
			
		SimManual:
			Proc.TempCtrl.PWM.Enable 	:= Proc.i.Start;
			Proc.TempCtrl.Ctrl.Enable	:= FALSE;
			//Proc.TempCtrl.PWM Variables
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period 		:= 1.0;
			Proc.currPower := Proc.TempCtrl.PWM.DutyCycle;
			KettleHeater := Proc.TempCtrl.PWM.Out;
			
		Automatic:
			//Not Used
			
		Manual:
			Proc.TempCtrl.PWM.Enable 	:= Proc.i.Start;
			Proc.TempCtrl.Ctrl.Enable 	:= TRUE;
			//Proc.TempCtrl.PWM Variables
			Proc.TempCtrl.PWM.DutyCycle := Proc.setPower;
			Proc.TempCtrl.PWM.MinPulseWidth := 0.1;
			Proc.TempCtrl.PWM.Period := 1.0;
			Proc.currTemp := rawHLTTemp * 1000;
			
	END_CASE
	
	//Call Action Files
	Displayclock;
	PowerControl;
	
	//Call FB's
	Proc.TempCtrl.Ctrl();
	Proc.TempCtrl.PWM();
	KettleTmr();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

