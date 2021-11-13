/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1636767375_3_
#define _BUR_1636767375_3_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef enum ControlState
{	Manual,
	Automatic,
	SimManual,
	SimAuto
} ControlState;

typedef struct Controller
{	struct MTBasicsPWM ManPWM;
	enum ControlState State;
	struct MpTempControllerParType TempPram;
	struct MpTempController TempCont;
} Controller;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/TempControl/HLT/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1636767375_3_ */

