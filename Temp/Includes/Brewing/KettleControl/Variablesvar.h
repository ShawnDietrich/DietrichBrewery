/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1678031522_1_
#define _BUR_1678031522_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL signed long PrevHopTime;
_BUR_LOCAL signed long PrevSelection;
_BUR_LOCAL signed long HopSelection;
_BUR_LOCAL plcbit pbDown;
_BUR_LOCAL plcbit pbUp;
_BUR_LOCAL plcbit pbFastUp;
_BUR_LOCAL plcbit pbFastDown;
_BUR_LOCAL plcstring TmrRemain[11];
_BUR_LOCAL plcstring SecRe[5];
_BUR_LOCAL plcstring MinRe[5];
_BUR_LOCAL plcstring HrRe[5];
_BUR_LOCAL struct TIMEStructure TmrDT;
_BUR_LOCAL plcbit StartKettle;
_BUR_LOCAL plctime TimePre;
_BUR_LOCAL struct TON KettleTmr;
_BUR_LOCAL struct ProcControl Proc;
_BUR_LOCAL unsigned char remainTime;
_BUR_LOCAL signed short currHop;
_BUR_LOCAL signed short i;
_BUR_LOCAL unsigned char HopTime[6];
_BUR_LOCAL unsigned char SelectedHopTime;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Brewing/KettleControl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1678031522_1_ */

