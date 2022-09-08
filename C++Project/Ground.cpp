#include "Ground.h"
#include "OutputManager.h";

void Ground::Start()
{
	Info.Scale = { (float)Sprite.getXsize(),(float)Sprite.getYsize() };
}

int Ground::Update()
{
	return 0;
}

void Ground::Render()
{
	CursorManager::GetInstance()->RenderObj(Sprite,Info.Position.x, Info.Position.y);
	//OutputManager::OnDrawText(Sprite, 5, Info.Position.x, Info.Position.y);
}

void Ground::Release()
{
}

Ground::Ground()
{
	tag = ObjTag::Ground;
	Sprite.intPutTexture("");
	//Sprite.intPutTexture("=");
	//Sprite.intPutTexture("=");
	//Sprite.intPutTexture("=");
	//Sprite.intPutTexture("=");
}

Ground::~Ground()
{
}
