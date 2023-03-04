
ACTION FillHLT:
	
	
	//Start and stop logic
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		
		IF(AutoFillHLT.Start) THEN
			AutoFillHLT.State := SimAuto;
		ELSIF AutoFillHLT.Stop THEN
			AutoFillHLT.State := Stop;
		END_IF
		
	END_IF
	
	
	CASE AutoFillHLT.State OF 
		
		Stop:
			AutoFillHLT.Valve	:= FALSE;

			AutoFillHLT.Stop	:= FALSE;
			AutoFillHLT.State 	:=SimManual;
		
		SimAuto: 
			AutoFillHLT.VolumePV := SimFlowMeterVal;
			IF AutoFillHLT.Start AND (AutoFillHLT.VolumePV <= AutoFillHLT.VolumeSP) THEN
				AutoFillHLT.Valve 	:= TRUE;
			ELSE 
				AutoFillHLT.Start	:= FALSE;
				AutoFillHLT.Valve	:= FALSE;
			END_IF
			
		SimManual:
			
			IF AutoFillHLT.Reset THEN
				AutoFillHLT.Reset	:= FALSE;
				AutoFillHLT.VolumePV := 0.0;
			END_IF
		Automatic: 
			
	END_CASE

END_ACTION
