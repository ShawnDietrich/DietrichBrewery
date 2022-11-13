
ACTION PowerControl: 

	IF Proc.TempCtrl.PWM.Active THEN
		
		IF pbUp THEN
			Proc.setPower := Proc.setPower + 5;
			pbUp := FALSE;
		END_IF
	
		IF pbDown THEN 
			Proc.setPower := Proc.setPower - 5;
			pbDown := FALSE;
		END_IF
	END_IF
	
	
END_ACTION
