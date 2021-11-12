
PROGRAM _INIT

END_PROGRAM

PROGRAM _CYCLIC
	//Initilize Temp Controller FB
	Proc.TempCont.Parameters := ADR(Mp_Parameters);
	Proc.TempCont.MpLink := ADR(Cfg_HLTTemp);
	//Map Variables 
	Mp_Controller.Control := contHLT.Start;
	Mp_Controller.ErrorReset := contHLT.ErrorReset;
	contHLT.Running := Mp_Controller.ControlActive;
	
	
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated(); THEN
		Proc.State := Simulate;
	END_IF
	
	CASE Proc.State OF 
		
		Simulate:
			//Simulated Values
			Mp_Controller.ActualTemperature := Mp_Controller.Info.Simulation.ActualTemperature;
			contHLT.currPower := Mp_Controller.Info.Simulation.HeatValue;
			
		Automatic:
			Mp_Controller.ActualTemperature := rawHLTTemp * 1000;
			contHLT.currPower := Mp_Controller.HeatValue;
			
		Manual:
			//PWM Variables
			PWM.DutyCycle := contHLT.setPower;
			PWM.MinPulseWidth := 0.1;
			PWM.Period := 1.0;
			
	END_CASE
	
	
	//Automatic control
	IF NOT contHLT.Automatic THEN
		PWM.Enable := TRUE;
		Mp_Controller.Enable := FALSE;
	ELSE
		PWM.Enable := FALSE;
		Mp_Controller.Enable := TRUE;
	END_IF
	

	
	
	//Call FB's
	Mp_Controller();
	PWM();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

