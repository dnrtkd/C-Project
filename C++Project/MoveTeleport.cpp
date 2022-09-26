#include "MoveTeleport.h"
#include"CursorManager.h"

void MoveTeleport::Start()
{
	Enim = new Texture[4];

	Enim[0].intPutTexture(" |     | ");
	Enim[0].intPutTexture(" |  +  | ");
	Enim[0].intPutTexture(" |     | ");
	Enim[0].intPutTexture("||+  + ||");
	Enim[0].intPutTexture("+++++++++");

	Enim[1].intPutTexture(" |  +  | ");
	Enim[1].intPutTexture(" |     | ");
	Enim[1].intPutTexture(" |+    | ");
	Enim[1].intPutTexture("||   + ||");
	Enim[1].intPutTexture("+++++++++");

	Enim[2].intPutTexture(" |     | ");
	Enim[2].intPutTexture(" |+    | ");
	Enim[2].intPutTexture(" |   + | ");
	Enim[2].intPutTexture("|| +   ||");
	Enim[2].intPutTexture("+++++++++");

	Enim[3].intPutTexture(" |+    | ");
	Enim[3].intPutTexture(" |  +  | ");
	Enim[3].intPutTexture(" | +   | ");
	Enim[3].intPutTexture("||   + ||");
	Enim[3].intPutTexture("+++++++++");

	Info.Scale.x = strlen(" |+    | ");
	Info.Scale.y = 5;

}

int MoveTeleport::Update()
{
	if (EnimTime + 150 >= GetTickCount64())
		currEnim = 0;
	else if (EnimTime + 300 >= GetTickCount64())
		currEnim = 1;
	else if (EnimTime + 450 >= GetTickCount64())
		currEnim = 2;
	else if (EnimTime + 600 <= GetTickCount64())
		EnimTime = GetTickCount64();
	else
		currEnim = 3;

    return 0;
}

void MoveTeleport::Render()
{
	CursorManager::GetInstance()->RenderObj(Enim[currEnim], (int)Info.Position.x, Info.Position.y);
}

void MoveTeleport::Release()
{
}

void MoveTeleport::setMapName(string str)
{
	NextMapName = str;
}

MoveTeleport::MoveTeleport()
{
	currEnim = 0;
	Enim = nullptr;
	EnimTime = GetTickCount64();
	key = MOVE_TELEPORT;
	NextPosi = { 0,0 };
}

MoveTeleport::~MoveTeleport()
{
}
