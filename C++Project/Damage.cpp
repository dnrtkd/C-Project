#include "Damage.h"
#include "CursorManager.h"

void Damage::Start()
{

}

int Damage::Update()
{
    if (enimTimer + 50 < GetTickCount64())
    {
        enimTimer = GetTickCount64();
        Info.Position.y -= 1.0f;
        count++;
    }

    if (count >= 5)
        disapear = true;
    return 0;
}

void Damage::Render()
{
    CursorManager::GetInstance()->WriteBuffer(Info.Position, damage,12);
}

void Damage::Release()
{
}

Damage::Damage()
{
    count = 0;
    damage = 0;
}

Damage::~Damage()
{
}
