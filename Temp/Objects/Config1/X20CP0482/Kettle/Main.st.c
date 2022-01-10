#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/Kettle/Mainst.h"
#line 1 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.nodebug"
#line 2 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.nodebug"
#line 7 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

((*(unsigned long*)&(Proc.TempCtrl.Ctrl.Parameters))=((unsigned long)(&Proc.TempCtrl.Ptr)));
((*(unsigned long*)&(Proc.TempCtrl.Ctrl.MpLink))=((unsigned long)(&Cfg_KettleTemp)));

(Proc.TempCtrl.Ctrl.Control=Proc.i.Start);
(Proc.TempCtrl.Ctrl.ErrorReset=Proc.i.ResetError);




(Proc.Status.Automatic=Proc.i.Auto);
(Proc.Status.Manual=(Proc.i.Auto^1));


if((DiagCpuIsARsim()|DiagCpuIsSimulated())){
if(Proc.Status.Automatic){
(Proc.State=3);
}else if(Proc.Status.Manual){
(Proc.State=2);
}
}


switch(Proc.State){

case 3:{

(Proc.TempCtrl.PWM.Enable=0);
(Proc.TempCtrl.Ctrl.Enable=1);
(Proc.TempCtrl.Ctrl.Simulate=1);

(Proc.TempCtrl.Ctrl.ActualTemperature=Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature);
(Proc.TempCtrl.Ctrl.SetTemperature=Proc.SetTemp);
(Proc.TempCtrl.Ctrl.Control=Proc.i.Start);
(Proc.currTemp=Proc.TempCtrl.Ctrl.Info.Simulation.ActualTemperature);
(Proc.currPower=Proc.TempCtrl.Ctrl.Info.Simulation.HeatValue);
(HLTHeater=Proc.TempCtrl.Ctrl.Info.Simulation.Heat);

}break;case 2:{
(Proc.TempCtrl.PWM.Enable=1);
(Proc.TempCtrl.Ctrl.Enable=0);

(Proc.TempCtrl.PWM.DutyCycle=Proc.setPower);
(Proc.TempCtrl.PWM.MinPulseWidth=1.00000001490116119385E-01);
(Proc.TempCtrl.PWM.Period=1.00000000000000000000E+00);
(Proc.currPower=Proc.TempCtrl.PWM.DutyCycle);

}break;case 1:{
(Proc.TempCtrl.PWM.Enable=1);
(Proc.TempCtrl.Ctrl.Enable=0);
(Proc.TempCtrl.Ctrl.ActualTemperature=(rawHLTTemp*1000));
(Proc.currPower=Proc.TempCtrl.Ctrl.HeatValue);
(Proc.currTemp=(rawHLTTemp*1000));

}break;case 0:{
(Proc.TempCtrl.PWM.Enable=0);
(Proc.TempCtrl.Ctrl.Enable=1);

(Proc.TempCtrl.PWM.DutyCycle=Proc.setPower);
(Proc.TempCtrl.PWM.MinPulseWidth=1.00000001490116119385E-01);
(Proc.TempCtrl.PWM.Period=1.00000000000000000000E+00);
(Proc.currTemp=(rawHLTTemp*1000));

}break;}


(KettleTmr.PT=(plctime)(TimePre*60000));

(KettleTmr.IN=StartKettle);


TIME_TO_TIMEStructure((KettleTmr.PT-KettleTmr.ET),((unsigned long)(&TmrDT)));
usint2str(TmrDT.hour,HrRe,5);
usint2str(TmrDT.minute,MinRe,5);
usint2str(TmrDT.second,SecRe,5);
{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)CONCAT(HrRe,":"); for(zzIndex=0; zzIndex<10l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)CONCAT(TmrRemain,MinRe); for(zzIndex=0; zzIndex<10l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)CONCAT(TmrRemain,":"); for(zzIndex=0; zzIndex<10l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)TmrRemain; plcstring* zzRValue=(plcstring*)CONCAT(TmrRemain,SecRe); for(zzIndex=0; zzIndex<10l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};



if(KettleTmr.Q){
(StartKettle=0);
(Proc.i.Start=0);
}


MpTempController(&Proc.TempCtrl.Ctrl);
MTBasicsPWM(&Proc.TempCtrl.PWM);
TON(&KettleTmr);
}}
#line 99 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.nodebug"
#line 101 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 104 "C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/Kettle/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/Kettle/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/Kettle/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Temp/Objects/Config1/X20CP0482/Kettle/Main.st.c\\\" \\\"C:/projects/DietrichBrewing/DietrichBrewery-master/DietrichBrewery-master/Logical/ProcessControl/Kettle/Main.st\\\"\\n\"");
__asm__(".previous");
