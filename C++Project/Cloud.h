#pragma once
#include"BgImage.h"
class Cloud:public BgImage
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Cloud();
	virtual ~Cloud();
};

