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

	void setSize(int w,int h)
	{
		for (int i = 0; i < h; i++)
		{
			Sprite.intPutTexture("");
			Info.Scale.y++;
		}
		for (int i = 0; i < w; i++)
		{
			Info.Scale.x++;
			for (int j = 0; j < Sprite.getYsize(); j++)
			{
				
				Sprite.texture[j].push_back('=');
			}
		}
	}

public:
	Ground();
	virtual ~Ground();
};

