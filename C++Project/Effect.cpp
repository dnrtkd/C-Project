#include "Effect.h"

Effect::Effect()
{
	enimTimer = GetTickCount64();
	currEnim = 0;
	disapear = false;
	key = "Effect";
}

Effect::~Effect()
{
}
