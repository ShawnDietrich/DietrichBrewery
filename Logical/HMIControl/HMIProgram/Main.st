
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC

	//Outputs are driven from the HMI when not in auto
	IF NOT AutoMode THEN
		Device(AutoMode, pbMashPump, FALSE, MashPump);
	END_IF
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

