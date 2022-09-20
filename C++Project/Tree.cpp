#include "Tree.h"

void Tree::Start()
{
	enim->intPutTexture("                (````)               ");
	enim->intPutTexture("               (``````)              ");
	enim->intPutTexture("              (````````)             ");
	enim->intPutTexture("             (``````````)            ");
	enim->intPutTexture("            (````````````)           ");
	enim->intPutTexture("           (```           )          ");
	enim->intPutTexture("          (````            )         ");
	enim->intPutTexture("         (````              )        ");
	enim->intPutTexture("        (````````````````    )       ");
	enim->intPutTexture("       (``````````````````    )      ");
	enim->intPutTexture("      (`````````````````````   )     ");
	enim->intPutTexture("     (````````````````````````  )    ");
	enim->intPutTexture("    (``````````````````````````` )   ");
	enim->intPutTexture("   (````````````````````````````  )  ");
	enim->intPutTexture("  (``````````````````````````````  ) ");
	enim->intPutTexture(" (____ 0                        ____)");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |      |       |  /      ");
	enim->intPutTexture("            |      |       | /       ");
	enim->intPutTexture("            |      |       |/        ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("         ___|              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |           |  |         ");
	enim->intPutTexture("            |           |  |         ");
	enim->intPutTexture("            |           |  |  /      ");
	enim->intPutTexture("            |              | /       ");
	enim->intPutTexture("            |              |/        ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	enim->intPutTexture("            |              |         ");
	

	Info.Scale.x = enim->getXsize();
	Info.Scale.y = enim->getYsize();
	
}

int Tree::Update()
{
	return 0;
}

void Tree::Render()
{
	CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y,true);
}

void Tree::Release()
{
}

Tree::Tree()
{
}

Tree::~Tree()
{
}
