
//Set device on or off with HMI or sequence
FUNCTION Device
	
	IF NOT AutoMode THEN
		
		//Manual Operation
		IF pbExpected  THEN
			Expected  := TRUE;
		ELSIF NOT pbExpected THEN
			Expected  := FALSE;
		END_IF
	
	ELSE
		//Auto operation
		IF AutoExpected THEN
			Expected:= TRUE;
		ELSIF NOT AutoExpected THEN
			Expected := FALSE;
		END_IF
	END_IF
	
	
	
	//Set output of function
	Output := Expected;
END_FUNCTION
