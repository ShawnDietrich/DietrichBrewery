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
_BUR_LOCAL struct TON HeatTime;
_BUR_LOCAL Seq Sequence;
_BUR_LOCAL plcbit pbMashPump;
