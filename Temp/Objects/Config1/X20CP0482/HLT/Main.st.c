#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/projects/DietrichBrewing/Temp/Objects/Config1/X20CP0482/HLT/Mainst.h"
#line 1 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.nodebug"
#line 2 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

}}
#line 4 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.nodebug"
#line 6 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

((*(unsigned long*)&(Proc.TempCont.Parameters))=((unsigned long)(&Proc.TempPram)));
((*(unsigned long*)&(Proc.TempCont.MpLink))=((unsigned long)(&Cfg_HLTTemp)));

(Proc.TempCont.Control=contHLT.Start);
(Proc.TempCont.ErrorReset=contHLT.ErrorReset);
(contHLT.Running=Proc.TempCont.ControlActive);


if((DiagCpuIsARsim()|DiagCpuIsSimulated())){
if(sys.Stat.Automatic){
(Proc.State=3);
}else if(sys.Stat.Manual){
(Proc.State=2);
}
}

switch(Proc.State){

case 3:{
(Proc.ManPWM.Enable=0);
(Proc.TempCont.Enable=1);
(Proc.TempCont.Simulate=1);

(Proc.TempCont.ActualTemperature=Proc.TempCont.Info.Simulation.ActualTemperature);
(Proc.TempCont.SetTemperature=contHLT.SetTemp);
(Proc.TempCont.Control=contHLT.Start);
(contHLT.Temperature=Proc.TempCont.Info.Simulation.ActualTemperature);
(contHLT.currPower=Proc.TempCont.Info.Simulation.HeatValue);

}break;case 2:{
(Proc.ManPWM.Enable=1);
(Proc.TempCont.Enable=0);

(Proc.ManPWM.DutyCycle=contHLT.setPower);
(Proc.ManPWM.MinPulseWidth=1.00000001490116119385E-01);
(Proc.ManPWM.Period=1.00000000000000000000E+00);


}break;case 1:{
(Proc.ManPWM.Enable=1);
(Proc.TempCont.Enable=0);
(Proc.TempCont.ActualTemperature=(rawHLTTemp*1000));
(contHLT.currPower=Proc.TempCont.HeatValue);
(contHLT.Temperature=(rawHLTTemp*1000));
}break;case 0:{
(Proc.ManPWM.Enable=0);
(Proc.TempCont.Enable=1);

(Proc.ManPWM.DutyCycle=contHLT.setPower);
(Proc.ManPWM.MinPulseWidth=1.00000001490116119385E-01);
(Proc.ManPWM.Period=1.00000000000000000000E+00);
(contHLT.Temperature=(rawHLTTemp*1000));

}break;}



MpTempController(&Proc.TempCont);
MTBasicsPWM(&Proc.ManPWM);
}}
#line 67 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.nodebug"
#line 69 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 72 "C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/TempControl/HLT/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/TempControl/HLT/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/projects/DietrichBrewing/Temp/Objects/Config1/X20CP0482/HLT/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/projects/DietrichBrewing/Temp/Objects/Config1/X20CP0482/HLT/Main.st.c\\\" \\\"C:/projects/DietrichBrewing/Logical/TempControl/HLT/Main.st\\\"\\n\"");
__asm__(".previous");
