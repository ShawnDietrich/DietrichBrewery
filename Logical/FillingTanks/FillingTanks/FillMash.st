
ACTION FillMash: 
	
	//Start and stop logic
	IF(AutoFillMash.Start) THEN
		AutoFillMash.State := Automatic;
	ELSIF AutoFillMash.Stop THEN
		AutoFillMash.State := Stop;
	END_IF
	
	
	//Image animation
	IF AutoFillMash.VolumePV > AutoFillMash.VolumeSP / 4 AND (AutoFillMash.VolumePV < AutoFillMash.VolumeSP / 2) THEN
		MashImgCont := 1;
	ELSIF AutoFillMash.VolumePV >= AutoFillMash.VolumeSP / 2 AND (AutoFillMash.VolumePV < AutoFillMash.VolumeSP ) THEN
		MashImgCont := 2;
	ELSIF AutoFillMash.VolumePV >= AutoFillMash.VolumeSP THEN
		MashImgCont := 3;
	ELSE 
		MashImgCont := 0;
	END_IF
	
	
	
	CASE AutoFillMash.State OF 
		
		Stop:
			AutoFillMash.Valve	:= FALSE;
			AutoFillMash.Stop	:= FALSE;
			AutoFillMash.State 	:= Manual;
		
		Automatic: 
			
			IF AutoFillMash.Start AND (AutoFillMash.VolumePV < AutoFillMash.VolumeSP) THEN
				AutoFillMash.Valve 	:= TRUE;
			ELSE 
				AutoFillMash.Start := FALSE;
				AutoFillMash.State := Stop;
			END_IF
			
		Manual:
			
			IF AutoFillMash.Reset THEN
				AutoFillMash.VolumePV := 0.0;
				AutoFillMash.Reset	:= FALSE;
			END_IF
		
	END_CASE

END_ACTION
