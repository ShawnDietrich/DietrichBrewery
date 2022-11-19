
ACTION FillHLT:
	
	IF  DiagCpuIsARsim() OR DiagCpuIsSimulated() THEN
		
		IF(AutoFillHLT.Start) THEN
			AutoFillHLT.State := SimAuto;
		ELSIF AutoFillHLT.Stop THEN
			AutoFillHLT.State := SimManual;
		END_IF
		
	END_IF
	
	
	CASE AutoFillHLT.State OF 
		
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
				AutoFillHLT.VolumePV := 0.0;
				AutoFillHLT.Valve	:= FALSE;
				AutoFillHLT.Reset	:= FALSE;
			END_IF
		Automatic: 
			
	END_CASE

END_ACTION
