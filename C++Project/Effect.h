#pragma once
#include "Object.h"

class Effect : public Object
{
protected:
	//����
	int currEnim;
	Texture* enim;
	ULONGLONG enimTimer;
	//�ð��̵Ǹ� �����
	bool disapear;

public:
	bool getDisapear() { return disapear; }
	
public:
	Effect();
	virtual ~Effect();
};

