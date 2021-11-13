
PROGRAM _INIT

END_PROGRAM

PROGRAM _CYCLIC


	
	CASE  Sequence OF
	
		Reset:
			
				
		FillTanks:
			
		
		PreHeat:

			Device(sys.Stat.Automatic, FALSE,FALSE,MashPump);

			
		Mash:
		
		Boil:
		
		
	END_CASE
	

END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

