/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1677975532_1_
#define _BUR_1677975532_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL float SimFlowMeterVal;
_BUR_LOCAL struct TON SimFlowMeterPulse;
_BUR_LOCAL signed short HLTImgCont;
_BUR_LOCAL signed short MashImgCont;
_BUR_LOCAL struct ValveControl AutoFillHLT;
_BUR_LOCAL struct ValveControl AutoFillMash;
_BUR_LOCAL struct TON ValveTmr;
_BUR_LOCAL float MashFillLevel;
_BUR_LOCAL float HLTFillLevel;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/FillingTanks/FillingTanks/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1677975532_1_ */

