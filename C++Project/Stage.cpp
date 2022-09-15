#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "BegginerHunt.h"
#include "BegginerHunt2.h"

Stage::Stage()
{
	
}

Stage::~Stage()
{
	

	Release();
}


void Stage::pushMap(MapFile* _map)
{
	MapFile* map = _map;
	map->Start();
	Maps[map->getName()] = map;
}

void Stage::Start()
{
	pushMap(new BegginerHunt);
	pushMap(new BegginerHunt2);
	currMap = "BegginerHunt";

	ObjectManager::GetInstance()->setMapName(currMap);
	ObjectManager::GetInstance()->Start();
	CursorManager::GetInstance()->setScreen(0, 60);
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
	
}

void Stage::Render()
{
	
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{

}

