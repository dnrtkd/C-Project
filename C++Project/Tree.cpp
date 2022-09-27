#include "Tree.h"
#include "CursorManager.h"

void Tree::Start()
{
	enim->intPutTexture("     (```````````````````````` )   ");
	enim->intPutTexture("    (````````````````````````   )  ");
	enim->intPutTexture("   (````````````````````````     ) ");
	enim->intPutTexture("  (````````````````````````       )");
	enim->intPutTexture("     (````````````````````````   ) ");
	enim->intPutTexture("  (````````````````````````       )");
	enim->intPutTexture("    (````````````````````````   )  ");
	enim->intPutTexture("     (````````````````````````   ) ");
	enim->intPutTexture("      (````````````````````````   )");
	enim->intPutTexture("      (````````````````````````  ) ");
	enim->intPutTexture("      (```````````````````````` )  ");
	enim->intPutTexture("       (````````````````````````)  ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |      |       |  /    ");
	enim->intPutTexture("            |      |       | /     ");
	enim->intPutTexture("            |      |       |/      ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("         ___|              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");
	enim->intPutTexture("            |              |       ");


	

	Info.Scale.x = enim->getXsize();
	Info.Scale.y = enim->getYsize();
	
}

int Tree::Update()
{

	return 0;
}

void Tree::Render()
{
	CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y,1);
}

void Tree::Release()
{
}

Tree::Tree()
{
	enim->color = 5;
}

Tree::~Tree()
{
}
