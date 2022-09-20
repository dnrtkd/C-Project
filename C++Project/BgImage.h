#pragma once
#include "Object.h"
#include "CursorManager.h"

class BgImage : public Object
{
protected:
	Texture* enim;
	
public:
	BgImage();
	virtual ~BgImage();
};

