
PROGRAM _INIT
	(* Insert code here *)
	FlashOn.PT := T#1000ms;
	FlashOff.PT := T#500ms;
END_PROGRAM

PROGRAM _CYCLIC
	
	//Code Stored Here to Drive HMI Functions
	
	//Buzzer Slience Logic
	IF Buzzer THEN
		SlienceVis := FlashOn.IN;
	END_IF

	IF FlashOn.Q THEN
		FlashOn.IN := FALSE; 
		FlashOff.IN := TRUE;
	ELSIF FlashOff.Q OR EDGEPOS(Buzzer) THEN
		FlashOn.IN := TRUE;
		FlashOff.IN := FALSE;
	END_IF
	
	IF SlienceBtn THEN
		Buzzer := FALSE;
		FlashOff.IN := FALSE;
		FlashOn.IN := FALSE;
		SlienceVis := FALSE;
		SlienceBtn := FALSE;
	END_IF
	
		
	//Call Function Blocks
	FlashOn();
	FlashOff();
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

