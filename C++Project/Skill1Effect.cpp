#include "Skill1Effect.h"
#include "CursorManager.h"
void Skill1Effect::Start()
{
	enim = new Texture[10];
	enim[0].intPutTexture("       () ");
	enim[1].intPutTexture("       ( )");
	enim[2].intPutTexture("      (   )");
	enim[3].intPutTexture("      ( o )");
	enim[4].intPutTexture("     (  o  )");
	enim[5].intPutTexture("    (   o   )");
	enim[6].intPutTexture("   (    o    )");
	enim[7].intPutTexture("  (      o     )");
	enim[8].intPutTexture(" (       o      )");
	enim[9].intPutTexture("(        o       )");
}

int Skill1Effect::Update()
{
	if (count==0)
		currEnim = 0;
	else if (count == 1)
		currEnim = 1;
	else if (count == 2)
		currEnim = 2;
	else if (count == 3)
		currEnim = 3;
	else if (count == 4)
		currEnim = 4;
	else if (count == 5)
		currEnim = 5;
	else if (count == 6)
		currEnim = 6;
	else if (count == 7)
		currEnim = 7;
	else if (count == 8)
		currEnim = 8;
	else if (count == 9)
		currEnim = 9;
	else if (count == 10)
		disapear = true;

	count++;
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
