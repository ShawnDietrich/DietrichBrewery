
ACTION SimFlowMeter: 

	SimFlowMeterPulse.PT := T#100ms;
	IF (AutoFillHLT.Valve) THEN
		SimFlowMeterPulse.IN	:= TRUE;
		IF(SimFlowMeterPulse.Q) THEN
			SimFlowMeterPulse.IN := FALSE;
			//Simulated accumulated value
			SimFlowMeterVal := SimFlowMeterVal + 0.1;
		END_IF
	END_IF
	
	SimFlowMeterPulse();

END_ACTION
