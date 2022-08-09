#include "Ground.h"
#include "OutputManager.h";

void Ground::Start()
{
	Info.Scale = { (float)strlen(Sprite.texture[0]),5 };
}

int Ground::Update()
{
	return 0;
}

void Ground::Render()
{
	CursorManager::GetInstance()->RenderObj(Sprite, Info.Scale.y, Info.Scale.x, Info.Position.x, Info.Position.y);
	//OutputManager::OnDrawText(Sprite, 5, Info.Position.x, Info.Position.y);
}

void Ground::Release()
{
}

Ground::Ground()
{
	tag = ObjTag::Ground;
	Sprite.texture[0] = "==================================================";
	Sprite.texture[1] = "==================================================";
	Sprite.texture[2] = "==================================================";
	Sprite.texture[3] = "==================================================";
	Sprite.texture[4] = "==================================================";
}

Ground::~Ground()
{
}
