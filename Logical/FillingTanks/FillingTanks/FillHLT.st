
ACTION FillHLT:
	//Start and stop logic
	IF AutoFillHLT.Start THEN
		AutoFillHLT.State := Automatic;
	ELSIF AutoFillHLT.Stop THEN
		AutoFillHLT.State := Stop;
	END_IF
	
	//Image animation
	IF AutoFillHLT.VolumePV > AutoFillHLT.VolumeSP / 4 AND (AutoFillHLT.VolumePV < AutoFillHLT.VolumeSP / 2) THEN
		HLTImgCont := 1;
	ELSIF AutoFillHLT.VolumePV >= AutoFillHLT.VolumeSP / 2 AND (AutoFillHLT.VolumePV < AutoFillHLT.VolumeSP ) THEN
		HLTImgCont := 2;
	ELSIF AutoFillHLT.VolumePV >= AutoFillHLT.VolumeSP THEN
		HLTImgCont := 3;
	ELSE 
		HLTImgCont := 0;
	END_IF
	
	
	CASE AutoFillHLT.State OF 
		
		Stop:
			AutoFillHLT.Valve	:= FALSE;
			AutoFillHLT.Stop	:= FALSE;
			AutoFillHLT.State 	:= Manual;
		
		Automatic: 
			
			IF AutoFillHLT.Start AND (AutoFillHLT.VolumePV < AutoFillHLT.VolumeSP) THEN
				AutoFillHLT.Valve 	:= TRUE;
			ELSE 
				AutoFillHLT.Start := FALSE;
				AutoFillHLT.State := Stop;
			END_IF
			
		Manual:
			//Manual Control of Valve
			IF AutoFillHLT.Reset THEN
				AutoFillHLT.Reset	:= FALSE;
				AutoFillHLT.VolumePV := 0.0;
			END_IF
			
	END_CASE

END_ACTION
