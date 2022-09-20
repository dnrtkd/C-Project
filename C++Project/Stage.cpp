#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "BegginerHunt.h"
#include "BegginerHunt2.h"
#include "Village.h"
#include "UI.h"


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
	pushMap(new Village);
	currMap = "Village";

	ObjectManager::GetInstance()->setMapName(currMap);
	ObjectManager::GetInstance()->Start();
	CursorManager::GetInstance()->setScreen(0, 60);

	Ui.push_back(new UI);
	Ui[0]->setSize(30, 5);
	Ui[0]->setPosi(Vector3(10, 2));
	Ui[0]->setTitle(ObjectManager::GetInstance()->getMapName());

	QuestTalkUi = new UI;
	QuestTalkUi->setSize(60, 25);
	QuestTalkUi->setPosi(Vector3(45,7));
	QuestTalkUi->setTitle("Äù½ºÆ® ");
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
	Ui[0]->setTitle(Maps[ObjectManager::GetInstance()->getMapName()]->getKorName());
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	Ui[0]->Render();
	
}

void Stage::Release()
{

}

