#pragma once
#include "Enemy.h"

class Stump :public Enemy
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual void hit(float damage, bool left) override;
public:
	Stump();
	virtual ~Stump();
};

