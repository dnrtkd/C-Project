#include "RespawnZone.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "CursorManager.h"


void RespawnZone::createMon()
{
    if (Timer + 1000 * resTime <= GetTickCount64() && currMonNum < maxMonNum)
    {
        Timer = GetTickCount64();
        int rNum = maxMonNum - currMonNum;
        for (int i = 0; i < rNum; ++i)
        {
            Object* temp=ObjectFactory::CreateObject(Vector3(respawnPosi.x+i*10,respawnPosi.y-4), 
                ObjectManager::GetInstance()->getMapName(),monName);
        }
    }
    
}

RespawnZone::RespawnZone(float res, int _maxMonNum, string monN,Vector3 rPosi)
{
    resTime = res;
    monName = monN;
    Timer = GetTickCount64()-1000*resTime;
    maxMonNum = _maxMonNum;
    currMonNum = 0;
    respawnPosi = rPosi;
}

RespawnZone::~RespawnZone()
{
}
