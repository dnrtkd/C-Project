#pragma once
#include "Object.h"
class Bow:public Object
{
	Texture* Enim; // 텍스쳐 모음
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Bow();
	virtual ~Bow();
};

