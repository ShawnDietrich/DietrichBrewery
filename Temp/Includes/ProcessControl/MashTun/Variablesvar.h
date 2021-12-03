/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1638546225_1_
#define _BUR_1638546225_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL signed short NumStart;
_BUR_LOCAL signed short MillNumPos;
_BUR_LOCAL signed short CharNumPos;
_BUR_LOCAL plcstring TmrRemain[81];
_BUR_LOCAL plcstring TmrRe[81];
_BUR_LOCAL plcstring MashACC[81];
_BUR_LOCAL signed long TimePre;
_BUR_LOCAL plcbit StartMash;
_BUR_LOCAL plcbit PumpExp;
_BUR_LOCAL plcbit pbMashPump;
_BUR_LOCAL struct ProcControl mProc;
_BUR_LOCAL struct TON MashTmr;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/MashTun/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1638546225_1_ */

