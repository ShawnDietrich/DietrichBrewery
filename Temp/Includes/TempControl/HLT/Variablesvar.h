/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1636635507_1_
#define _BUR_1636635507_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL struct MpTempController Mp_Controller;
_BUR_LOCAL struct MpTempControllerParType Mp_Parameters;
_BUR_LOCAL struct MTBasicsPWM PWM;
_BUR_LOCAL signed long CycleCount;
_BUR_LOCAL struct TON CycleTime;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/TempControl/HLT/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1636635507_1_ */

