#pragma once
#include"BgImage.h"
class MapBgi2 :public BgImage
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	MapBgi2();
	virtual ~MapBgi2();
};

