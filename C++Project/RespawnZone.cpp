#include "RespawnZone.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "CursorManager.h"


void RespawnZone::createMon()
{

    for (auto i = monList.begin(); i != monList.end();)
    {

        if (!(*i))
        {
            i=monList.erase(i);
        }
        else
            ++i;
    }
    if (Timer + 3000 * resTime <= GetTickCount64() && monList.size() < maxMonNum)
    {
        Timer = GetTickCount64();
        int rNum = maxMonNum - monList.size();
        for (int i = 0; i < rNum; ++i)
        {
            Object* temp=ObjectFactory::CreateObject(Vector3(respawnPosi.x+i*6,respawnPosi.y-4), 
                ObjectManager::GetInstance()->getMapName(),monName);
            monList.push_back(&temp);
           
        }
        
        
    }
    
}

RespawnZone::RespawnZone(float res, int _maxMonNum, string monN,Vector3 rPosi)
{
    resTime = res;
    monName = monN;
    Timer = GetTickCount64();
    maxMonNum = _maxMonNum;
    currMonNum = 0;
    respawnPosi = rPosi;
}

RespawnZone::~RespawnZone()
{
}
