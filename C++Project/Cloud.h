#pragma once
#include"BgImage.h"
class Cloud:public BgImage
{
	ULONGLONG moveTimer;
	float moveValue;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Cloud();
	virtual ~Cloud();
};

