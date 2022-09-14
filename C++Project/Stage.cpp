#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "BegginerHunt.h"

Stage::Stage()
{
	currMapIndex = 0;
}

Stage::~Stage()
{
	

	Release();
}


void Stage::Start()
{
	Maps.push_back(new BegginerHunt);
	for (auto i : Maps)
		i->Start();
	ObjectManager::GetInstance()->setMapName("BegginerHunt");
	ObjectManager::GetInstance()->Start();
	CursorManager::GetInstance()->setScreen(0, 60);
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	CursorManager::GetInstance()->WriteBuffer(10, 2,(char*) Maps[currMapIndex]->getKorName().c_str());
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{

}

