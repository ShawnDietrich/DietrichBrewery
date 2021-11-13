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

#ifndef __AS__TYPE_Seq
#define __AS__TYPE_Seq
typedef enum Seq
{	Reset = 0,
	FillTanks = 1,
	PreHeat = 2,
	Mash = 3,
	Boil = 4,
} Seq;
#endif

#ifndef __AS__TYPE_SystemInput
#define __AS__TYPE_SystemInput
typedef struct SystemInput
{	plcbit EStop;
	plcbit Auto;
	plcbit Stop;
	plcbit Pause;
	plcbit Power;
} SystemInput;
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

#ifndef __AS__TYPE_System
#define __AS__TYPE_System
typedef struct System
{	SystemInput i;
	SystemStatus Stat;
} System;
#endif

_BUR_PUBLIC plcbit Device(plcbit AutoMode, plcbit pbExpected, plcbit AutoExpected, plcbit(* Output));
_BUR_LOCAL Seq Sequence;
_GLOBAL System sys;
_GLOBAL plcbit MashPump;
