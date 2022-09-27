#include "Moon.h"

void Moon::Start()
{
	enim->intPutTexture("    ,o888888o.     ");
	enim->intPutTexture(" . 8888     `88.   ");
	enim->intPutTexture(",8 8888       `8b  ");
	enim->intPutTexture("88 8888        `8b ");
	enim->intPutTexture("88 8888         88 ");
	enim->intPutTexture("88 8888         88 ");
	enim->intPutTexture("88 8888        ,8P ");
	enim->intPutTexture("`8 8888       ,8P  ");
	enim->intPutTexture(" ` 8888     ,88'   ");
	enim->intPutTexture("    `8888888P'     ");
	
	enim->color = 14;

	Info.Scale.x = enim->getXsize();
	Info.Scale.y = enim->getYsize();
}

int Moon::Update()
{
	return 0;
}

void Moon::Render()
{
	CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y, 2);
}

void Moon::Release()
{
}

Moon::Moon()
{
}

Moon::~Moon()
{
}
