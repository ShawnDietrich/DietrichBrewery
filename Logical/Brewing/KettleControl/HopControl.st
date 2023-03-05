
ACTION HopControl: 
	
	
	
	//Detect Changed value
	IF SelectedHopTime <> PrevHopTime THEN
		HopTime[HopSelection] := SelectedHopTime;
		PrevHopTime := SelectedHopTime; 
	END_IF
	
	//Detect new selection
	IF HopSelection <> PrevSelection THEN
		SelectedHopTime := HopTime[HopSelection];
		PrevSelection := HopSelection;
	END_IF
	
	FOR i := 1 TO 5 DO
		IF KettleTmr.IN THEN
			//Determine current addition
			IF TmrDT.minute < HopTime[i] AND TmrDT.second = 0 THEN
				currHop := i;
				Buzzer := TRUE;
			END_IF
			
			//Determine time for next addition
			remainTime := TmrDT.minute - HopTime[currHop + 1] +1;
		ELSE 
			currHop := 0;
		END_IF	
	END_FOR;
	
	
END_ACTION
