#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Temp/Objects/Config1/X20CP0482/HLTControl/Mainst.h"
#line 1 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.nodebug"
#line 2 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

}}
#line 4 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.nodebug"
#line 6 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

((*(unsigned long*)&(Proc.TempCtrl.Ctrl.Parameters))=((unsigned long)(&Proc.TempCtrl.Ptr)));
((*(unsigned long*)&(Proc.TempCtrl.Ctrl.MpLink))=((unsigned long)(&Cfg_HLTTemp)));

(Proc.TempCtrl.Ctrl.Control=Proc.i.Start);
(Proc.TempCtrl.Ctrl.ErrorReset=Proc.i.ResetError);


if((FromMashCyc.Start&~Edge0000100000&1?((Edge0000100000=FromMashCyc.Start&1),1):((Edge0000100000=FromMashCyc.Start&1),0))){
(Proc.i.Auto=1);
(Proc.i.Start=1);
(Proc.SetTemp=FromMashCyc.HLTTemp);
}else if((~FromMashCyc.Start&Edge0000100001&1?((Edge0000100001=FromMashCyc.Start&1),1):((Edge0000100001=FromMashCyc.Start&1),0))){
(Proc.i.Auto=0);
(Proc.i.Start=0);
}


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
(Proc.TempCtrl.PWM.MinPulseWidth=(1.00000001490116119385E-01));
(Proc.TempCtrl.PWM.Period=(1.00000000000000000000E+00));

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
(Proc.TempCtrl.PWM.MinPulseWidth=(1.00000001490116119385E-01));
(Proc.TempCtrl.PWM.Period=(1.00000000000000000000E+00));
(Proc.currTemp=(rawHLTTemp*1000));

}break;}



MpTempController(&Proc.TempCtrl.Ctrl);
MTBasicsPWM(&Proc.TempCtrl.PWM);
}}
#line 83 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.nodebug"
#line 85 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 88 "G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10man/Acp10man.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SfDomain/SfDomain.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SfDomain/SfDomainError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTempAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.typ\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SfDomain/SfDomain.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.fun\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10par/Acp10par.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ViBase/ViBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsZip/AsZip.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsARCfg/AsARCfg.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/powerlnk/powerlnk.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsEPL/AsEPL.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIO/AsIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MTBasics/MTBasics.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SfDomain/SfDomain.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpTemp/MpTemp.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CoTrace/CoTrace.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/HLTControl/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ProcessControl/HLTControl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"G:/GitRepos/Brewery/AS Project/DietrichBrewery/Temp/Objects/Config1/X20CP0482/HLTControl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"G:/GitRepos/Brewery/AS Project/DietrichBrewery/Temp/Objects/Config1/X20CP0482/HLTControl/Main.st.c\\\" \\\"G:/GitRepos/Brewery/AS Project/DietrichBrewery/Logical/ProcessControl/HLTControl/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/X20CP0482/HLTControl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
