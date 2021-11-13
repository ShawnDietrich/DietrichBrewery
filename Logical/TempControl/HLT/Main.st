
PROGRAM _INIT

END_PROGRAM

PROGRAM _CYCLIC
	//Initilize Temp Controller FB
	Proc.TempCont.Parameters := ADR(Proc.TempPram);
	Proc.TempCont.MpLink := ADR(Cfg_HLTTemp);
	//Map Variables 
	Proc.TempCont.Control := contHLT.Start;
	Proc.TempCont.ErrorReset := contHLT.ErrorReset;
	contHLT.Running := Proc.TempCont.ControlActive;
	
	//Set the state machine
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		IF sys.Stat.Automatic THEN
			Proc.State := SimAuto;
		ELSIF sys.Stat.Manual THEN
			Proc.State := SimManual;
		END_IF
	END_IF
	
	CASE Proc.State OF 
		
		SimAuto:
			Proc.ManPWM.Enable := FALSE;
			Proc.TempCont.Enable := TRUE;
			Proc.TempCont.Simulate := TRUE;
			//Simulated Values
			Proc.TempCont.ActualTemperature := Proc.TempCont.Info.Simulation.ActualTemperature;
			Proc.TempCont.SetTemperature := contHLT.SetTemp;
			Proc.TempCont.Control := contHLT.Start;
			contHLT.Temperature := Proc.TempCont.Info.Simulation.ActualTemperature;
			contHLT.currPower := Proc.TempCont.Info.Simulation.HeatValue;
			
		SimManual:
			Proc.ManPWM.Enable := TRUE;
			Proc.TempCont.Enable := FALSE;
			//Proc.ManPWM Variables
			Proc.ManPWM.DutyCycle := contHLT.setPower;
			Proc.ManPWM.MinPulseWidth := 0.1;
			Proc.ManPWM.Period := 1.0;
			//contHLT.Temperature := contHLT.Temperature + 0.1;
			
		Automatic:
			Proc.ManPWM.Enable := TRUE;
			Proc.TempCont.Enable := FALSE;
			Proc.TempCont.ActualTemperature := rawHLTTemp * 1000;
			contHLT.currPower := Proc.TempCont.HeatValue;
			contHLT.Temperature := rawHLTTemp * 1000;
		Manual:
			Proc.ManPWM.Enable := FALSE;
			Proc.TempCont.Enable := TRUE;
			//Proc.ManPWM Variables
			Proc.ManPWM.DutyCycle := contHLT.setPower;
			Proc.ManPWM.MinPulseWidth := 0.1;
			Proc.ManPWM.Period := 1.0;
			contHLT.Temperature := rawHLTTemp * 1000;
			
	END_CASE
	
	
	//Call FB's
	Proc.TempCont();
	Proc.ManPWM();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

