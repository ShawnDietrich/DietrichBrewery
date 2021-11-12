
//Set device on or off with HMI or sequence
FUNCTION Device
	
	IF NOT AutoMode AND NOT AutoExpected THEN
		
		//Manual Operation
		IF pbExpected  THEN
			Expected  := TRUE;
		ELSIF NOT pbExpected THEN
			Expected  := FALSE;
		END_IF
	
	ELSE
		//Auto operation
		IF AutoExpected AND NOT pbExpected THEN
			Expected:= TRUE;
		ELSIF NOT AutoExpected AND NOT pbExpected THEN
			Expected := FALSE;
		END_IF
	END_IF
	
	
	
	//Set output of function
	Output := Expected;
END_FUNCTION
