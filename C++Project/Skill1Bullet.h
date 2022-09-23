#pragma once
#include"Bullet.h"
class Skill1Bullet:public Bullet
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Release()override;
public:
	Skill1Bullet();
	virtual ~Skill1Bullet();
	
};

