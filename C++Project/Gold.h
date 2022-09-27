#pragma once
#include "Object.h"

class Gold : public Object
{
	int count;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Gold();
	virtual ~Gold();
};

