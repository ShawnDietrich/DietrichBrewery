
ACTION Displayclock: 

	//Kettle timer 
	KettleTmr.PT := DINT_TO_TIME(TimePre*60000);
	//Start Kettle Timer 
	KettleTmr.IN := StartKettle;
			
	//Calculate and display the remaining time
	TIME_TO_TIMEStructure((KettleTmr.PT - KettleTmr.ET), ADR(TmrDT));
	HrRe 	:= USINT_TO_STRING(TmrDT.hour);
	MinRe 	:= USINT_TO_STRING(TmrDT.minute);
	SecRe	:= USINT_TO_STRING(TmrDT.second);
	TmrRemain := CONCAT(HrRe, ':');
	TmrRemain := CONCAT(TmrRemain, MinRe);
	TmrRemain := CONCAT(TmrRemain,':');
	TmrRemain := CONCAT(TmrRemain, SecRe);
		
			
	//Kettle Time is Done Rest Everything
	IF KettleTmr.Q THEN
		StartKettle := FALSE;
		Proc.i.Start := FALSE;
		Buzzer := TRUE;
	END_IF
	
END_ACTION
