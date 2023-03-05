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
_BUR_LOCAL plcbit TestBuzzer;
_BUR_LOCAL struct TON FlashOn;
_BUR_LOCAL struct TON FlashOff;
_BUR_LOCAL plcbit SlienceVis;
_BUR_LOCAL plcbit SlienceBtn;
