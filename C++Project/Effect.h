#pragma once
#include "Object.h"

class Effect : public Object
{
protected:
	//현재
	int currEnim;
	Texture* enim;
	ULONGLONG enimTimer;
	//시간이되면 사라짐
	bool disapear;

public:
	bool getDisapear() { return disapear; }
	
public:
	Effect();
	virtual ~Effect();
};

