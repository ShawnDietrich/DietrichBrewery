#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/MashTun/Mainst.h"
#line 1 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.nodebug"
#line 2 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.nodebug"
#line 7 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


(mProc.Status.Automatic=mProc.i.Start);
(mProc.Status.Manual=(mProc.i.Start^1));
(FromMashCyc.Start=mProc.i.Start);


if((DiagCpuIsARsim()|DiagCpuIsSimulated())){
if(mProc.Status.Automatic){
(mProc.State=3);
}else if(mProc.Status.Manual){
(mProc.State=2);
}
}


if((~mProc.i.Start&Edge0000100000&1?((Edge0000100000=mProc.i.Start&1),1):((Edge0000100000=mProc.i.Start&1),0))){
(pbMashPump=0);
(StartMash=0);
(MashTmr.IN=0);
(mProc.i.Start=0);
}


switch(mProc.State){

case 2:{

(mProc.currTemp=(((signed long)(rawMashTemp))/((signed long)(1000))));
(PumpExp=pbMashPump);

}break;case 3:{

(mProc.currTemp=(((signed long)(rawMashTemp))/((signed long)(1000))));
(FromMashCyc.HLTTemp=(mProc.SetTemp+15));
(pbMashPump=PumpExp);


if(((mProc.currTemp<mProc.SetTemp))){
(PumpExp=1);
}else{
(PumpExp=0);
}


(MashTmr.PT=(plctime)(TimePre*60000));

(MashTmr.IN=StartMash);


time2str((MashTmr.PT-MashTmr.ET),TmrRe,81);

{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)DELETE(TmrRe,2,1); for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};

{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)REPLACE(TmrRemain," ",1,FIND(TmrRemain,"_")); for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};

{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)REPLACE(TmrRemain," ",1,FIND(TmrRemain,"_")); for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};

{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)DELETE(TmrRemain,6,8); for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};


if(MashTmr.Q){
(StartMash=0);
(mProc.i.Start=0);
}


}break;case 0:{

(mProc.currTemp=(((signed long)(rawMashTemp))/((signed long)(1000))));

}break;}

(MashPump=PumpExp);

TON(&MashTmr);
}}
#line 84 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.nodebug"
#line 86 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 89 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Types.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Functions.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Includes/AS_TempDecl/Config1/GlobalComponents/MpComponents.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Constants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/MashTun/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/MashTun/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/MashTun/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/MashTun/Main.st.c\\\" \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/MashTun/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/X20CP0482/MashTun/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
