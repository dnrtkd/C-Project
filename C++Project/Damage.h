#pragma once
#include "Effect.h"
class Damage :public Effect
{
	float damage;
	int count;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void setDamageText(float d) { damage = d; }
public:
	Damage();
	virtual ~Damage();
};

