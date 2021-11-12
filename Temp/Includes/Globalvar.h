/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1636568474_1_
#define _BUR_1636568474_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL signed short rawHLTTemp;
_GLOBAL signed short rawKettleTemp;
_GLOBAL struct TemperatureController contHLT;
_GLOBAL struct TemperatureController contKettle;
_GLOBAL plcbit KettleHeater;
_GLOBAL plcbit HLTHeater;
_GLOBAL plcbit MashPump;
_GLOBAL plcbit HLTPump;
_GLOBAL plcbit AutoMode;
_GLOBAL plcbit ManMode;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1636568474_1_ */

