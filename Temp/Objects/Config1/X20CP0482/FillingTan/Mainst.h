#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

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
_BUR_PUBLIC plcbit DiagCpuIsSimulated(void);
_BUR_PUBLIC plcbit DiagCpuIsARsim(void);
_BUR_LOCAL struct TON ValveTmr;
_BUR_LOCAL ValveControl AutoFillMash;
_BUR_LOCAL ValveControl AutoFillHLT;
_BUR_LOCAL signed short MashImgCont;
_BUR_LOCAL signed short HLTImgCont;
_BUR_LOCAL struct TON SimFlowMeterPulse;
_BUR_LOCAL float SimFlowMeterVal;
_GLOBAL plcbit ValveSelector;
_GLOBAL plcbit ValveOff;
_GLOBAL plcbit ValveOn;
_LOCAL plcbit Edge0000400000;
_LOCAL plcbit Edge0000400001;
static void __AS__Action__SimFlowMeter(void);
static void __AS__Action__FillHLT(void);
static void __AS__Action__FillMash(void);
