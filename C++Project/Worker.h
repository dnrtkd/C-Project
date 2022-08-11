#pragma once
#include "Enemy.h"

class Worker:public Enemy
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Worker();
	virtual ~Worker();
};

