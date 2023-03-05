/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1677966969_1_
#define _BUR_1677966969_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL signed short rawHLTTemp;
_GLOBAL signed short rawKettleTemp;
_GLOBAL signed short rawMashTemp;
_GLOBAL plcbit KettleHeater;
_GLOBAL plcbit HLTHeater;
_GLOBAL plcbit CoolingPump;
_GLOBAL plcbit MashPump;
_GLOBAL plcbit HLTPump;
_GLOBAL plcbit SysPower;
_GLOBAL plcbit ValveOn;
_GLOBAL plcbit ValveOff;
_GLOBAL plcbit ValveSelector;
_GLOBAL plcbit Buzzer;
_GLOBAL struct MashToHLT FromMashCyc;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1677966969_1_ */

