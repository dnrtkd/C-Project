#pragma once
#include"Object.h"

class RespawnZone:public Object
{
	float resTime;
	string monName;

public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	RespawnZone();
	~RespawnZone();
};

