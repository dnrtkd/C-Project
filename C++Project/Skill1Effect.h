#pragma once
#include "Effect.h"
class Skill1Effect :public Effect
{
	int count;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	
public:
	Skill1Effect();
	virtual ~Skill1Effect();
};

