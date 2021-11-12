/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1636652907_1_
#define _BUR_1636652907_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct TemperatureController
{	plcbit Automatic;
	plcbit Start;
	plcbit Running;
	plcbit ErrorReset;
	float setPower;
	float currPower;
} TemperatureController;

typedef struct SystemOutput
{	plcbit Stop;
	plcbit Pause;
	plcbit Run;
	plcbit Power;
} SystemOutput;

typedef struct SystemInput
{	plcbit EStop;
} SystemInput;

typedef struct SystemStatus
{	plcbit Automatic;
	plcbit Manual;
	plcbit Running;
	plcbit Stopped;
	plcbit Paused;
	plcbit On;
} SystemStatus;

typedef struct System
{	struct SystemInput i;
	struct SystemOutput o;
	struct SystemStatus Stat;
} System;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1636652907_1_ */

