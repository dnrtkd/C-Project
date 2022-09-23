#include "Skill1Effect.h"
#include "CursorManager.h"
void Skill1Effect::Start()
{
	enim = new Texture[8];
	enim[0].intPutTexture("      () ");
	enim[1].intPutTexture("     ( )");
	enim[2].intPutTexture("    (   )");
	enim[3].intPutTexture("    ( o )");
	enim[4].intPutTexture("   (  o  )");
	enim[5].intPutTexture("  (   o   )");
	enim[6].intPutTexture(" (    o    )");
	enim[7].intPutTexture("(     o      )");
}

int Skill1Effect::Update()
{
	if (enimTimer + 50 >= GetTickCount64())
		currEnim = 0;
	else if (enimTimer + 100 >= GetTickCount64())
		currEnim = 1;
	else if (enimTimer + 150 >= GetTickCount64())
		currEnim = 2;
	else if (enimTimer + 200 >= GetTickCount64())
		currEnim = 3;
	else if (enimTimer + 250 >= GetTickCount64())
		currEnim = 4;
	else if (enimTimer + 300 >= GetTickCount64())
		currEnim = 5;
	else if (enimTimer + 350 >= GetTickCount64())
		currEnim = 6;
	else if (enimTimer + 400 >= GetTickCount64())
		currEnim = 7;
	else if (enimTimer + 500 <= GetTickCount64())
		disapear = true;


	return 0;
}

void Skill1Effect::Render()
{
	CursorManager::GetInstance()->RenderObj(enim[currEnim], Info.Position.x, Info.Position.y);
}

void Skill1Effect::Release()
{
	delete[] enim;
}

Skill1Effect::Skill1Effect()
{
	count = 0;
}

Skill1Effect::~Skill1Effect()
{
	Release();
}
