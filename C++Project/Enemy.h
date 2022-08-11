#pragma once
#include "Object.h"

class Enemy : public Object
{
protected:
	float hp;
	float damage;
	int gold;
	int exp;

	Texture* Enim; //텍스쳐 모음
	ULONGLONG EnimTime;// 애니메이션 변수

public:
	Enemy();
	virtual ~Enemy();
};

