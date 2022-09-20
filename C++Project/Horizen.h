#pragma once
#include"BgImage.h"
class Horizen :public BgImage
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Horizen();
	virtual ~Horizen();
};

