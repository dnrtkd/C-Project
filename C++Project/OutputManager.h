#pragma once
#include "CursorManager.h"

class OutputManager
{
public:

	static void OnDrawText(const Texture& texture,int sizeY,float _x, float _y)
	{
		for (size_t i = 0; i < sizeY; i++)
		{
			CursorManager::GetInstance()->WriteBuffer(_x, _y+i, (char *)texture.texture[i]);
		}
	}
};