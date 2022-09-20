#include "Cloud.h"

void Cloud::Start()
{
    enim->intPutTexture("   (````````````)     ");
    enim->intPutTexture("  (          )    )   ");
    enim->intPutTexture(" (   (             )  ");
    enim->intPutTexture("(       (       )    )");
    enim->intPutTexture("~~~~~~~~~~~~~~~~~~~~~ ");

    Info.Scale.x = enim->getXsize();
    Info.Scale.y = enim->getYsize();
}

int Cloud::Update()
{
    
    return 0;
}

void Cloud::Render()
{
    CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y);
}

void Cloud::Release()
{
}

Cloud::Cloud()
{
    
}

Cloud::~Cloud()
{
}
