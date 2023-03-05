/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1677961613_1_
#define _BUR_1677961613_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef enum ControlState
{	Stop,
	Manual,
	Automatic
} ControlState;

typedef struct MashToHLT
{	plcbit Start;
	float HLTTemp;
} MashToHLT;

typedef struct TempCont
{	struct MpTempController Ctrl;
	struct MpTempControllerParType Ptr;
	struct MTBasicsPWM PWM;
} TempCont;

typedef struct SystemStatus
{	plcbit Automatic;
	plcbit Manual;
	plcbit Running;
	plcbit Stopped;
	plcbit Paused;
	plcbit On;
} SystemStatus;

typedef struct SystemInput
{	plcbit ResetError;
	plcbit EStop;
	plcbit Auto;
	plcbit Stop;
	plcbit Pause;
	plcbit Start;
} SystemInput;

typedef struct ProcControl
{	float setPower;
	float currPower;
	float currTemp;
	float SetTemp;
	struct TempCont TempCtrl;
	enum ControlState State;
	struct SystemStatus Status;
	struct SystemInput i;
} ProcControl;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1677961613_1_ */

