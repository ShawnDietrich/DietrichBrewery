#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/KettleCont/Mainst.h"
#line 1 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"
#line 7 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

((*(unsigned long*)&(Proc.TempCtrl.Ctrl.Parameters))=((unsigned long)(&Proc.TempCtrl.Ptr)));
((*(unsigned long*)&(Proc.TempCtrl.Ctrl.MpLink))=((unsigned long)(&Cfg_KettleTemp)));

(Proc.TempCtrl.Ctrl.Control=Proc.i.Start);
(Proc.TempCtrl.Ctrl.ErrorReset=Proc.i.ResetError);




(Proc.Status.Automatic=Proc.i.Auto);
(Proc.Status.Manual=(Proc.i.Auto^1));


if((DiagCpuIsARsim()|DiagCpuIsSimulated())){
if(Proc.Status.Automatic){
(Proc.State=4);
}else if(Proc.Status.Manual){
(Proc.State=3);
}
}


switch(Proc.State){

case 4:{


}break;case 3:{
(Proc.TempCtrl.PWM.Enable=Proc.i.Start);
(Proc.TempCtrl.Ctrl.Enable=0);

(Proc.TempCtrl.PWM.DutyCycle=Proc.setPower);
(Proc.TempCtrl.PWM.MinPulseWidth=(1.00000001490116119385E-01));
(Proc.TempCtrl.PWM.Period=(1.00000000000000000000E+00));
(Proc.currPower=Proc.TempCtrl.PWM.DutyCycle);
(KettleHeater=Proc.TempCtrl.PWM.Out);

}break;case 2:{


}break;case 1:{
(Proc.TempCtrl.PWM.Enable=Proc.i.Start);
(Proc.TempCtrl.Ctrl.Enable=1);

(Proc.TempCtrl.PWM.DutyCycle=Proc.setPower);
(Proc.TempCtrl.PWM.MinPulseWidth=(1.00000001490116119385E-01));
(Proc.TempCtrl.PWM.Period=(1.00000000000000000000E+00));
(Proc.currTemp=(rawHLTTemp*1000));

}break;}


__AS__Action__Displayclock();
__AS__Action__PowerControl();


MpTempController(&Proc.TempCtrl.Ctrl);
MTBasicsPWM(&Proc.TempCtrl.PWM);
TON(&KettleTmr);
}}
#line 68 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"
#line 70 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 73 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Displayclock.st"
static void __AS__Action__Displayclock(void){int __AS__Local0_00000;plcstring* __AS__Local3_00000;plcstring* __AS__Local4_00000;
{

(KettleTmr.PT=(plctime)(TimePre*60000));

(KettleTmr.IN=StartKettle);


TIME_TO_TIMEStructure((KettleTmr.PT-KettleTmr.ET),((unsigned long)(&TmrDT)));
usint2str(TmrDT.hour,HrRe,5);
usint2str(TmrDT.minute,MinRe,5);
usint2str(TmrDT.second,SecRe,5);
__AS__Local3_00000=(plcstring*)TmrRemain; __AS__Local4_00000=(plcstring*)CONCAT(HrRe,":"); for(__AS__Local0_00000=0; __AS__Local0_00000<10l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)TmrRemain; __AS__Local4_00000=(plcstring*)CONCAT(TmrRemain,MinRe); for(__AS__Local0_00000=0; __AS__Local0_00000<10l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)TmrRemain; __AS__Local4_00000=(plcstring*)CONCAT(TmrRemain,":"); for(__AS__Local0_00000=0; __AS__Local0_00000<10l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;
__AS__Local3_00000=(plcstring*)TmrRemain; __AS__Local4_00000=(plcstring*)CONCAT(TmrRemain,SecRe); for(__AS__Local0_00000=0; __AS__Local0_00000<10l && __AS__Local4_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local3_00000[__AS__Local0_00000] = __AS__Local4_00000[__AS__Local0_00000]; __AS__Local3_00000[__AS__Local0_00000] = 0;



if(KettleTmr.Q){
(StartKettle=0);
(Proc.i.Start=0);
}

}imp16385_else0_0:imp16385_end0_0:;}
#line 75 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/PowerControl.st"
static void __AS__Action__PowerControl(void){
{
if(Proc.TempCtrl.PWM.Active){

if(pbUp){
(Proc.setPower=(Proc.setPower+5));
(pbUp=0);
}

if(pbDown){
(Proc.setPower=(Proc.setPower-5));
(pbDown=0);
}
}


}imp16386_else2_0:imp16386_end2_0:imp16386_else0_0:imp16386_end0_0:;}
#line 75 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Types.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10man/Acp10man.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmX.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmXError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Functions.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmX.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Includes/AS_TempDecl/Config1/GlobalComponents/MpComponents.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTTypes/MTTypes.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Functions/Constants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIODiag/AsIODiag.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10par/Acp10par.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Brewing/KettleControl/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Brewing/KettleControl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/KettleCont/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/KettleCont/Main.st.c\\\" \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Logical/Brewing/KettleControl/Main.st\\\"\\n\"");
__asm__(".previous");