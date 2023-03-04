struct R_TRIG
{	plcbit CLK;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void R_TRIG(struct R_TRIG* inst);
#ifndef __AS__TYPE_ControlState
#define __AS__TYPE_ControlState
typedef enum ControlState
{	Stop = 0,
	Manual = 1,
	Automatic = 2,
	SimManual = 3,
	SimAuto = 4,
} ControlState;
#endif

#ifndef __AS__TYPE_ValveControl
#define __AS__TYPE_ValveControl
typedef struct ValveControl
{	plcbit Reset;
	plcbit Stop;
	plcbit Start;
	struct R_TRIG ValveR;
	plcbit Valve;
	float VolumePV;
	float VolumeSP;
	ControlState State;
} ValveControl;
#endif

struct TON
{	plctime PT;
	plctime ET;
	plctime StartTime;
	unsigned long Restart;
	plcbit IN;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void TON(struct TON* inst);
_BUR_LOCAL ValveControl AutoFillMash;
_BUR_LOCAL ValveControl AutoFillHLT;
_BUR_LOCAL signed short MashImgCont;
_BUR_LOCAL signed short HLTImgCont;
_BUR_LOCAL struct TON SimFlowMeterPulse;
_BUR_LOCAL float SimFlowMeterVal;
