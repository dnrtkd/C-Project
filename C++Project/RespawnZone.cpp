#include "RespawnZone.h"
#include "ObjectFactory.h"

void RespawnZone::Start()
{
}

int RespawnZone::Update()
{
    for (auto iter = monL.begin(); iter != monL.end(); ++iter)
    {
        if ((*iter) == nullptr)
            monL.erase(iter);
    }

    return 0;
}

void RespawnZone::Render()
{
}

void RespawnZone::Release()
{
}

void RespawnZone::createMon(string mapName)
{
    if (Timer + 1000 * resTime <= GetTickCount64() && monL.size() <= maxMonNum)
    {
        Object* t= ObjectFactory::CreateObject(Info.Position, mapName, monName);
        monL.push_back(&t);
    }
    
}

RespawnZone::RespawnZone(float res, int _maxMonNum, string monN)
{
    resTime = res;
    monName = monN;
    Timer = GetTickCount64();
    maxMonNum = _maxMonNum;
}

RespawnZone::~RespawnZone()
{
}
