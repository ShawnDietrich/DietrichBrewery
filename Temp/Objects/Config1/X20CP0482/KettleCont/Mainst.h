#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_MpComInternalDataType
#define __AS__TYPE_MpComInternalDataType
typedef struct MpComInternalDataType
{	unsigned long pObject;
	unsigned long State;
} MpComInternalDataType;
#endif

#ifndef __AS__TYPE_MpTempTuningStateEnum
#define __AS__TYPE_MpTempTuningStateEnum
typedef enum MpTempTuningStateEnum
{	mpTEMP_TUNING_STATE_IDLE = 0,
	mpTEMP_TUNING_STATE_INIT = 1,
	mpTEMP_TUNING_STATE_SYSTEM_CHECK = 2,
	mpTEMP_TUNING_STATE_DELAY_TIME = 3,
	mpTEMP_TUNING_STATE_IDENT = 4,
	mpTEMP_TUNING_STATE_PREDICTION = 5,
	mpTEMP_TUNING_STATE_IN_SETPOINT = 6,
	mpTEMP_TUNING_STATE_ERROR = 99,
	mpTEMP_TUNING_STATE_ABORTED = 100,
} MpTempTuningStateEnum;
#endif

#ifndef __AS__TYPE_MpTempPIDParType
#define __AS__TYPE_MpTempPIDParType
typedef struct MpTempPIDParType
{	float ProportionalGain;
	float IntegrationTime;
	float DerivativeTime;
	float FilterTime;
} MpTempPIDParType;
#endif

#ifndef __AS__TYPE_MpTempPIDType
#define __AS__TYPE_MpTempPIDType
typedef struct MpTempPIDType
{	MpTempPIDParType Heat;
	MpTempPIDParType Cool;
	float IntegratorPreloading;
} MpTempPIDType;
#endif

#ifndef __AS__TYPE_MpTempSystemParType
#define __AS__TYPE_MpTempSystemParType
typedef struct MpTempSystemParType
{	float Gain;
	float TimeConstant1;
	float TimeConstant2;
	float DelayTime;
} MpTempSystemParType;
#endif

#ifndef __AS__TYPE_MpTempSystemType
#define __AS__TYPE_MpTempSystemType
typedef struct MpTempSystemType
{	MpTempSystemParType Heat;
	MpTempSystemParType Cool;
} MpTempSystemType;
#endif

#ifndef __AS__TYPE_MpTempProfileParType
#define __AS__TYPE_MpTempProfileParType
typedef struct MpTempProfileParType
{	float SlewRate;
	float FilterTime;
	float DelayTime;
	plcbit QuickStart;
} MpTempProfileParType;
#endif

#ifndef __AS__TYPE_MpTempProfileType
#define __AS__TYPE_MpTempProfileType
typedef struct MpTempProfileType
{	MpTempProfileParType Heat;
	MpTempProfileParType Cool;
} MpTempProfileType;
#endif

#ifndef __AS__TYPE_MpTempTuningQualityType
#define __AS__TYPE_MpTempTuningQualityType
typedef struct MpTempTuningQualityType
{	unsigned char Heat;
	unsigned char Cool;
} MpTempTuningQualityType;
#endif

#ifndef __AS__TYPE_MpTempTuningFilterType
#define __AS__TYPE_MpTempTuningFilterType
typedef struct MpTempTuningFilterType
{	float NoiseReduction;
} MpTempTuningFilterType;
#endif

#ifndef __AS__TYPE_MpTempSystemTypeEnum
#define __AS__TYPE_MpTempSystemTypeEnum
typedef enum MpTempSystemTypeEnum
{	mpTEMP_SYSTEM_TYPE_PT2 = 0,
	mpTEMP_SYSTEM_TYPE_IT1 = 1,
	mpTEMP_SYSTEM_TYPE_NONE = 3,
} MpTempSystemTypeEnum;
#endif

#ifndef __AS__TYPE_MpTempSystemCharacteristicsType
#define __AS__TYPE_MpTempSystemCharacteristicsType
typedef struct MpTempSystemCharacteristicsType
{	MpTempSystemTypeEnum Heat;
	MpTempSystemTypeEnum Cool;
} MpTempSystemCharacteristicsType;
#endif

#ifndef __AS__TYPE_MpTempTuningInfoType
#define __AS__TYPE_MpTempTuningInfoType
typedef struct MpTempTuningInfoType
{	MpTempTuningStateEnum State;
	MpTempPIDType PIDParameters;
	MpTempSystemType SystemParameters;
	MpTempProfileType ProfileParameters;
	MpTempTuningQualityType Quality;
	MpTempTuningFilterType TemperatureFilter;
	MpTempSystemCharacteristicsType SystemType;
} MpTempTuningInfoType;
#endif

#ifndef __AS__TYPE_MpTempControllerProfileInfoType
#define __AS__TYPE_MpTempControllerProfileInfoType
typedef struct MpTempControllerProfileInfoType
{	plcbit Active;
	plcbit InSetPoint;
} MpTempControllerProfileInfoType;
#endif

#ifndef __AS__TYPE_MpTempControlInfoType
#define __AS__TYPE_MpTempControlInfoType
typedef struct MpTempControlInfoType
{	float ControlError;
	float ProportionalPart;
	float IntegrationPart;
	float DerivativePart;
	float ActualTemperatureFiltered;
	float ActualTemperatureDerivative;
	plcbit TemperatureFilterUsed;
} MpTempControlInfoType;
#endif

#ifndef __AS__TYPE_MpTempSimulationInfoType
#define __AS__TYPE_MpTempSimulationInfoType
typedef struct MpTempSimulationInfoType
{	float HeatValue;
	float CoolValue;
	float ActualTemperature;
	plcbit Heat;
	plcbit Cool;
	MpTempSystemCharacteristicsType SystemType;
} MpTempSimulationInfoType;
#endif

#ifndef __AS__TYPE_MpTempErrorEnum
#define __AS__TYPE_MpTempErrorEnum
typedef enum MpTempErrorEnum
{	mpTEMP_NO_ERROR = 0,
	mpTEMP_ERR_ACTIVATION = -1064239103,
	mpTEMP_ERR_MPLINK_NULL = -1064239102,
	mpTEMP_ERR_MPLINK_INVALID = -1064239101,
	mpTEMP_ERR_MPLINK_CHANGED = -1064239100,
	mpTEMP_ERR_MPLINK_CORRUPT = -1064239099,
	mpTEMP_ERR_MPLINK_IN_USE = -1064239098,
	mpTEMP_ERR_PAR_NULL = -1064239097,
	mpTEMP_ERR_CONFIG_NULL = -1064239096,
	mpTEMP_ERR_CONFIG_NO_PV = -1064239095,
	mpTEMP_ERR_CONFIG_LOAD = -1064239094,
	mpTEMP_WRN_CONFIG_LOAD = -2137980917,
	mpTEMP_ERR_CONFIG_SAVE = -1064239092,
	mpTEMP_ERR_CONFIG_INVALID = -1064239091,
	mpTEMP_ERR_PID_PAR_INVALID = -1063980032,
	mpTEMP_ERR_TUNING_PAR_INVALID = -1063980031,
	mpTEMP_ERR_PROFILE_PAR_INVALID = -1063980030,
	mpTEMP_ERR_TOLERANCE_BAND = -1063980029,
	mpTEMP_ERR_TUNING = -1063980028,
	mpTEMP_ERR_PROFILE = -1063980027,
	mpTEMP_WRN_TUNING = -2137721850,
	mpTEMP_WRN_PROFILE = -2137721849,
	mpTEMP_ERR_COMMAND_INVALID = -1063980024,
	mpTEMP_ERR_CONTROLLER = -1063980023,
	mpTEMP_ERR_CONFIG_PAR_INVALID = -1063980022,
	mpTEMP_ERR_NO_LINKED_COMPONENTS = -1063980021,
	mpTEMP_INF_PROFILE_NOT_SUITABLE = 1083503628,
	mpTEMP_ERR_TUNING_ABORTED = -1063980019,
	mpTEMP_INF_COMPONENT_DISABLED = 1083503630,
	mpTEMP_ERR_PWM = -1063980017,
	mpTEMP_ERR_SIMULATION = -1063980016,
	mpTEMP_ERR_AVG_CURRENT_OUTSIDE = -1063980015,
	mpTEMP_ERR_MAX_CURRENT_EXCEEDED = -1063980014,
	mpTEMP_WRN_LINKED_CTRL_WARNING = -2137721837,
	mpTEMP_ERR_LINKED_CTRL_ERROR = -1063980012,
	mpTEMP_WRN_ACT_CURRENT_OUTSIDE = -2137721835,
	mpTEMP_ERR_HYSTERESIS_INVALID = -1063980010,
	mpTEMP_WRN_CONFIG_PAR_INVALID = -2137721833,
	mpTEMP_ERR_HCM_NOT_USED = -1063980008,
} MpTempErrorEnum;
#endif

#ifndef __AS__TYPE_MpComSeveritiesEnum
#define __AS__TYPE_MpComSeveritiesEnum
typedef enum MpComSeveritiesEnum
{	mpCOM_SEV_SUCCESS = 0,
	mpCOM_SEV_INFORMATIONAL = 1,
	mpCOM_SEV_WARNING = 2,
	mpCOM_SEV_ERROR = 3,
} MpComSeveritiesEnum;
#endif

#ifndef __AS__TYPE_MpTempStatusIDType
#define __AS__TYPE_MpTempStatusIDType
typedef struct MpTempStatusIDType
{	MpTempErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpTempStatusIDType;
#endif

#ifndef __AS__TYPE_MpTempDiagType
#define __AS__TYPE_MpTempDiagType
typedef struct MpTempDiagType
{	MpTempStatusIDType StatusID;
} MpTempDiagType;
#endif

#ifndef __AS__TYPE_MpTempControllerHCMInfoType
#define __AS__TYPE_MpTempControllerHCMInfoType
typedef struct MpTempControllerHCMInfoType
{	float AverageCurrentL1;
	float AverageCurrentL2;
	float AverageCurrentL3;
} MpTempControllerHCMInfoType;
#endif

#ifndef __AS__TYPE_MpTempSoftStartStateEnum
#define __AS__TYPE_MpTempSoftStartStateEnum
typedef enum MpTempSoftStartStateEnum
{	mpTEMP_SOFTSTART_HEATING = 0,
	mpTEMP_SOFTSTART_HOLD_TEMP = 1,
	mpTEMP_SOFTSTART_REACHED_TEMP = 2,
	mpTEMP_SOFTSTART_FINISHED = 3,
	mpTEMP_SOFTSTART_EXCLUDED = 4,
	mpTEMP_SOFTSTART_SKIPPED = 5,
	mpTEMP_SOFTSTART_OFF = 6,
} MpTempSoftStartStateEnum;
#endif

#ifndef __AS__TYPE_MpTempSoftStartCtrlInfoType
#define __AS__TYPE_MpTempSoftStartCtrlInfoType
typedef struct MpTempSoftStartCtrlInfoType
{	MpTempSoftStartStateEnum State;
} MpTempSoftStartCtrlInfoType;
#endif

#ifndef __AS__TYPE_MpTempSystemInfoType
#define __AS__TYPE_MpTempSystemInfoType
typedef struct MpTempSystemInfoType
{	MpTempSystemType Parameters;
	MpTempSystemCharacteristicsType Type;
} MpTempSystemInfoType;
#endif

#ifndef __AS__TYPE_MpTempControllerFilterType
#define __AS__TYPE_MpTempControllerFilterType
typedef struct MpTempControllerFilterType
{	plcbit Enable;
	float NoiseReduction;
} MpTempControllerFilterType;
#endif

#ifndef __AS__TYPE_MpTempParameterizationInfoType
#define __AS__TYPE_MpTempParameterizationInfoType
typedef struct MpTempParameterizationInfoType
{	MpTempPIDType Controller;
	MpTempSystemInfoType System;
	MpTempProfileType Profile;
	MpTempControllerFilterType KalmanFilter;
} MpTempParameterizationInfoType;
#endif

#ifndef __AS__TYPE_MpTempControllerInfoType
#define __AS__TYPE_MpTempControllerInfoType
typedef struct MpTempControllerInfoType
{	float SetTemperature;
	float FeedForwardHeat;
	float FeedForwardCool;
	plcbit InTolerance;
	MpTempTuningInfoType Tuning;
	MpTempControllerProfileInfoType Profile;
	MpTempControlInfoType Control;
	MpTempSimulationInfoType Simulation;
	MpTempDiagType Diag;
	MpTempControllerHCMInfoType HCM;
	MpTempSoftStartCtrlInfoType SoftStart;
	MpTempParameterizationInfoType Parameterization;
} MpTempControllerInfoType;
#endif

struct MpTempController
{	struct MpComIdentType(* MpLink);
	struct MpTempControllerParType(* Parameters);
	float SetTemperature;
	float ActualTemperature;
	signed long StatusID;
	float HeatValue;
	float CoolValue;
	MpTempControllerInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Control;
	plcbit Tune;
	plcbit Simulate;
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit Heat;
	plcbit Cool;
	plcbit ControlActive;
	plcbit TuningActive;
	plcbit TuningDone;
	plcbit Simulation;
};
_BUR_PUBLIC void MpTempController(struct MpTempController* inst);
#ifndef __AS__TYPE_MpTempTuningModeEnum
#define __AS__TYPE_MpTempTuningModeEnum
typedef enum MpTempTuningModeEnum
{	mpTEMP_TUNING_MODE_OFF = 0,
	mpTEMP_TUNING_MODE_HEAT = 1,
	mpTEMP_TUNING_MODE_HEAT_COOL = 2,
	mpTEMP_TUNING_MODE_OSC_HEAT = 3,
	mpTEMP_TUNING_MODE_OSC_HEAT_COOL = 4,
	mpTEMP_TUNING_MODE_OSC_COOL = 5,
} MpTempTuningModeEnum;
#endif

#ifndef __AS__TYPE_MpTempTuningType
#define __AS__TYPE_MpTempTuningType
typedef struct MpTempTuningType
{	MpTempTuningModeEnum Mode;
	float SetPointHeat;
	float SetPointCool;
} MpTempTuningType;
#endif

#ifndef __AS__TYPE_MpTempControllerProfileType
#define __AS__TYPE_MpTempControllerProfileType
typedef struct MpTempControllerProfileType
{	MpTempProfileParType Heat;
	MpTempProfileParType Cool;
	float AttenuationFactor;
	float OvershootReduction;
} MpTempControllerProfileType;
#endif

#ifndef __AS__TYPE_MpTempToleranceBandType
#define __AS__TYPE_MpTempToleranceBandType
typedef struct MpTempToleranceBandType
{	float Lower;
	float Upper;
} MpTempToleranceBandType;
#endif

#ifndef __AS__TYPE_MpTempHysteresisModeEnum
#define __AS__TYPE_MpTempHysteresisModeEnum
typedef enum MpTempHysteresisModeEnum
{	mpTEMP_HYSTERESIS_ON = 0,
	mpTEMP_HYSTERESIS_OFF_HEAT_ONLY = 1,
	mpTEMP_HYSTERESIS_OFF_COOL_ONLY = 2,
} MpTempHysteresisModeEnum;
#endif

#ifndef __AS__TYPE_MpTempHysteresisBand
#define __AS__TYPE_MpTempHysteresisBand
typedef struct MpTempHysteresisBand
{	float HeatToCool;
	float CoolToHeat;
} MpTempHysteresisBand;
#endif

#ifndef __AS__TYPE_MpTempHysteresisType
#define __AS__TYPE_MpTempHysteresisType
typedef struct MpTempHysteresisType
{	MpTempHysteresisModeEnum Mode;
	MpTempHysteresisBand Band;
} MpTempHysteresisType;
#endif

#ifndef __AS__TYPE_MpTempControllerParType
#define __AS__TYPE_MpTempControllerParType
typedef struct MpTempControllerParType
{	MpTempPIDType PID;
	MpTempTuningType Tuning;
	MpTempControllerProfileType Profile;
	MpTempToleranceBandType ToleranceBand;
	MpTempHysteresisType Hysteresis;
} MpTempControllerParType;
#endif

#ifndef __AS__TYPE_MTBasicsPWMModeEnum
#define __AS__TYPE_MTBasicsPWMModeEnum
typedef enum MTBasicsPWMModeEnum
{	mtBASICS_PULSE_BEGINNING = 0,
	mtBASICS_PULSE_MIDDLE = 1,
} MTBasicsPWMModeEnum;
#endif

#ifndef __AS__TYPE_MTBasicsPWMInternalType
#define __AS__TYPE_MTBasicsPWMInternalType
typedef struct MTBasicsPWMInternalType
{	float CycleTime;
	plcbit ParametersValid;
	MTBasicsPWMModeEnum Mode;
	float MinPulseWidth;
	float Period;
	float In;
	float OnTime;
	float OffTime;
	float PeriodCounter;
	float OnTimeCounter;
	plcbit UpdateOld;
	plcbit EnableOld;
} MTBasicsPWMInternalType;
#endif

struct MTBasicsPWM
{	MTBasicsPWMModeEnum Mode;
	float MinPulseWidth;
	float Period;
	float DutyCycle;
	signed long StatusID;
	MTBasicsPWMInternalType Internal;
	plcbit Enable;
	plcbit Update;
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit Out;
};
_BUR_PUBLIC void MTBasicsPWM(struct MTBasicsPWM* inst);
#ifndef __AS__TYPE_TempCont
#define __AS__TYPE_TempCont
typedef struct TempCont
{	struct MpTempController Ctrl;
	MpTempControllerParType Ptr;
	struct MTBasicsPWM PWM;
} TempCont;
#endif

#ifndef __AS__TYPE_ControlState
#define __AS__TYPE_ControlState
typedef enum ControlState
{	Manual = 0,
	Automatic = 1,
	SimManual = 2,
	SimAuto = 3,
} ControlState;
#endif

#ifndef __AS__TYPE_SystemStatus
#define __AS__TYPE_SystemStatus
typedef struct SystemStatus
{	plcbit Automatic;
	plcbit Manual;
	plcbit Running;
	plcbit Stopped;
	plcbit Paused;
	plcbit On;
} SystemStatus;
#endif

#ifndef __AS__TYPE_SystemInput
#define __AS__TYPE_SystemInput
typedef struct SystemInput
{	plcbit ResetError;
	plcbit EStop;
	plcbit Auto;
	plcbit Stop;
	plcbit Pause;
	plcbit Start;
} SystemInput;
#endif

#ifndef __AS__TYPE_ProcControl
#define __AS__TYPE_ProcControl
typedef struct ProcControl
{	float setPower;
	float currPower;
	float currTemp;
	float SetTemp;
	TempCont TempCtrl;
	ControlState State;
	SystemStatus Status;
	SystemInput i;
} ProcControl;
#endif

#ifndef __AS__TYPE_TIMEStructure
#define __AS__TYPE_TIMEStructure
typedef struct TIMEStructure
{	signed char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned short millisec;
	unsigned short microsec;
} TIMEStructure;
#endif

#ifndef __AS__TYPE_MpComIdentType
#define __AS__TYPE_MpComIdentType
typedef struct MpComIdentType
{	unsigned long Internal[2];
} MpComIdentType;
#endif

_BUR_PUBLIC unsigned long TIME_TO_TIMEStructure(plctime TIME1, unsigned long pTIMEStructure);
_BUR_PUBLIC plcstring* usint2str(unsigned char IN, plcstring pStr[81], unsigned long len);
struct TON
{	plctime PT;
	plctime ET;
	plctime StartTime;
	unsigned long Restart;
	plcbit IN;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void TON(struct TON* inst);
_BUR_PUBLIC plcstring* CONCAT(plcstring IN1[32768], plcstring IN2[32768]);
_BUR_PUBLIC plcbit DiagCpuIsSimulated(void);
_BUR_PUBLIC plcbit DiagCpuIsARsim(void);
_BUR_LOCAL ProcControl Proc;
_BUR_LOCAL struct TON KettleTmr;
_BUR_LOCAL plctime TimePre;
_BUR_LOCAL plcbit StartKettle;
_BUR_LOCAL TIMEStructure TmrDT;
_BUR_LOCAL plcstring HrRe[5];
_BUR_LOCAL plcstring MinRe[5];
_BUR_LOCAL plcstring SecRe[5];
_BUR_LOCAL plcstring TmrRemain[11];
_BUR_LOCAL plcbit pbUp;
_BUR_LOCAL plcbit pbDown;
_GLOBAL plcbit KettleHeater;
_GLOBAL signed short rawHLTTemp;
_GLOBAL MpComIdentType Cfg_KettleTemp;
static void __AS__Action__Displayclock(void);
static void __AS__Action__PowerControl(void);
