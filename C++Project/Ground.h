#pragma once
#include "Object.h"
class Ground :public Object
{
	Texture Sprite;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Ground();
	virtual ~Ground();
};

