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

    srand(time(0) * (int)this);
    moveValue = (rand() % 50 + 50) * 0.01f;
}

int Cloud::Update()
{
    if (moveTimer + 1000 < GetTickCount64())
    {
        moveTimer = GetTickCount64();
        Info.Position.x += moveValue;
    }
    
    if ( Info.Position.x>200)
        Info.Position.x = -24.0f;

    return 0;
}

void Cloud::Render()
{
    CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y,1);
}

void Cloud::Release()
{
}

Cloud::Cloud()
{
    enim->color = 7;

    moveTimer = GetTickCount64();
    moveValue = 0.0f;
}

Cloud::~Cloud()
{
}
