#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/FillingTan/Mainst.h"
#line 1 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{
(ValveTmr.PT=(2000));
}}
#line 4 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 6 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


if((DiagCpuIsARsim()|DiagCpuIsSimulated())){
__AS__Action__SimFlowMeter();
}


__AS__Action__FillHLT();
__AS__Action__FillMash();


if(AutoFillHLT.Valve){
(ValveSelector=1);
}



if(((AutoFillHLT.Valve|AutoFillMash.Valve)&~Edge0000400000&1?((Edge0000400000=(AutoFillHLT.Valve|AutoFillMash.Valve)&1),1):((Edge0000400000=(AutoFillHLT.Valve|AutoFillMash.Valve)&1),0))){
(ValveOn=1);
(ValveTmr.IN=1);
}else if((~(AutoFillHLT.Valve|AutoFillMash.Valve)&Edge0000400001&1?((Edge0000400001=(AutoFillHLT.Valve|AutoFillMash.Valve)&1),1):((Edge0000400001=(AutoFillHLT.Valve|AutoFillMash.Valve)&1),0))){
(ValveOff=1);
(ValveTmr.IN=1);
}

if(ValveTmr.Q){
(ValveOn=0);
(ValveOff=0);
(ValveTmr.IN=0);
(ValveSelector=0);
}



TON(&ValveTmr);
}}
#line 42 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 44 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{



}}
#line 48 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/SimFlowMeter.st"
static void __AS__Action__SimFlowMeter(void){
{
(SimFlowMeterPulse.PT=(100));
if(AutoFillHLT.Valve){
(SimFlowMeterPulse.IN=1);
if(SimFlowMeterPulse.Q){
(SimFlowMeterPulse.IN=0);

(SimFlowMeterVal=(SimFlowMeterVal+(1.00000001490116119385E-01)));
}
}

TON(&SimFlowMeterPulse);

}}
#line 50 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/FillHLT.st"
static void __AS__Action__FillHLT(void){
{
if(AutoFillHLT.Start){
(AutoFillHLT.State=2);
}else if(AutoFillHLT.Stop){
(AutoFillHLT.State=0);
}


if((((AutoFillHLT.VolumePV>(AutoFillHLT.VolumeSP/4)))&((AutoFillHLT.VolumePV<(AutoFillHLT.VolumeSP/2))))){
(HLTImgCont=1);
}else if((((AutoFillHLT.VolumePV>=(AutoFillHLT.VolumeSP/2)))&((AutoFillHLT.VolumePV<AutoFillHLT.VolumeSP)))){
(HLTImgCont=2);
}else if(((AutoFillHLT.VolumePV>=AutoFillHLT.VolumeSP))){
(HLTImgCont=3);
}else{
(HLTImgCont=0);
}


switch(AutoFillHLT.State){

case 0:{
(AutoFillHLT.Valve=0);
(AutoFillHLT.Stop=0);
(AutoFillHLT.State=1);

}break;case 2:{

if((AutoFillHLT.Start&((AutoFillHLT.VolumePV<AutoFillHLT.VolumeSP)))){
(AutoFillHLT.Valve=1);
}else{
(AutoFillHLT.Start=0);
(AutoFillHLT.State=0);
}

}break;case 1:{

if(AutoFillHLT.Reset){
(AutoFillHLT.Reset=0);
(AutoFillHLT.VolumePV=(0.00000000000000000000E+00));
}

}break;}

}imp16385_case2_2:imp16385_endcase2_0:;}
#line 50 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"
#line 2 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/FillMash.st"
static void __AS__Action__FillMash(void){
{

if(AutoFillMash.Start){
(AutoFillMash.State=2);
}else if(AutoFillMash.Stop){
(AutoFillMash.State=0);
}



if((((AutoFillMash.VolumePV>(AutoFillMash.VolumeSP/4)))&((AutoFillMash.VolumePV<(AutoFillMash.VolumeSP/2))))){
(MashImgCont=1);
}else if((((AutoFillMash.VolumePV>=(AutoFillMash.VolumeSP/2)))&((AutoFillMash.VolumePV<AutoFillMash.VolumeSP)))){
(MashImgCont=2);
}else if(((AutoFillMash.VolumePV>=AutoFillMash.VolumeSP))){
(MashImgCont=3);
}else{
(MashImgCont=0);
}



switch(AutoFillMash.State){

case 0:{
(AutoFillMash.Valve=0);
(AutoFillMash.Stop=0);
(AutoFillMash.State=1);

}break;case 2:{

if((AutoFillMash.Start&((AutoFillMash.VolumePV<AutoFillMash.VolumeSP)))){
(AutoFillMash.Valve=1);
}else{
(AutoFillMash.Start=0);
(AutoFillMash.State=0);
}

}break;case 1:{

if(AutoFillMash.Reset){
(AutoFillMash.VolumePV=(0.00000000000000000000E+00));
(AutoFillMash.Reset=0);
}

}break;}

}imp16386_case2_2:imp16386_endcase2_0:;}
#line 50 "C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/FillingTanks/FillingTanks/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/FillingTanks/FillingTanks/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/FillingTan/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Temp/Objects/Config1/X20CP0482/FillingTan/Main.st.c\\\" \\\"C:/Repos/DietrichBrewery/DietrichBrewery/Logical/FillingTanks/FillingTanks/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/X20CP0482/FillingTan/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
