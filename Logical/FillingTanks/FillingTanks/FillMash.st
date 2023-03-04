
ACTION FillMash: 
	
		//Start and stop logic
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		
		IF(AutoFillMash.Start) THEN
			AutoFillMash.State := SimAuto;
		ELSIF AutoFillMash.Stop THEN
			AutoFillMash.State := Stop;
		END_IF
		
	END_IF
	
	
	CASE AutoFillMash.State OF 
		
		Stop:
			AutoFillMash.Valve	:= FALSE;

			AutoFillMash.Stop	:= FALSE;
			AutoFillMash.State 	:=SimManual;
		
		SimAuto: 
			AutoFillMash.VolumePV := SimFlowMeterVal;
			IF AutoFillMash.Start AND (AutoFillMash.VolumePV <= AutoFillMash.VolumeSP) THEN
				AutoFillMash.Valve 	:= TRUE;
			ELSE 
				AutoFillMash.Start	:= FALSE;
				AutoFillMash.Valve	:= FALSE;
			END_IF
			
		SimManual:
			
			IF AutoFillMash.Reset THEN
				AutoFillMash.VolumePV := 0.0;
				AutoFillMash.Reset	:= FALSE;
			END_IF
		Automatic: 
			
	END_CASE

END_ACTION
