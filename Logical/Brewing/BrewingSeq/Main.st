
PROGRAM _INIT
	(* Insert code here *)
	 HeatTime.PT := T#5s;
END_PROGRAM

PROGRAM _CYCLIC

	IF EDGEPOS (AutoMode)  THEN
		ManMode := FALSE;
		Sequence := PreHeat;
	ELSIF EDGENEG (AutoMode) THEN
		ManMode := TRUE;
		Sequence := Reset;
	END_IF
	
	
	CASE  Sequence OF
	
		Reset:
				
		FillTanks:
		
		PreHeat:
			//Turn on Mash pump
			Device(TRUE, FALSE, TRUE, MashPump);
			HeatTime.IN := TRUE;
			IF HeatTime.Q THEN
				HeatTime.IN := FALSE;
				Device(AutoMode, FALSE,FALSE,MashPump);
				Sequence := Reset;
			END_IF
			
		Mash:
		
		Boil:
		
		
	END_CASE
	

	 
	HeatTime();
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

