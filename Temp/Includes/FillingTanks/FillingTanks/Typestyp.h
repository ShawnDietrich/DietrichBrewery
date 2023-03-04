/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1677955200_12_
#define _BUR_1677955200_12_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
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






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/FillingTanks/FillingTanks/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1677955200_12_ */

