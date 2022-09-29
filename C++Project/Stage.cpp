#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "BegginerHunt.h"
#include "BegginerHunt2.h"
#include "Village.h"
#include "UI.h"
#include "Player.h"

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
	pPlayer = ObjectManager::GetInstance()->getPlayer();
	mapInfo = new UI;
	mapInfo->setSize(20, 5);
	mapInfo->setPosi(Vector3(110, 2));
	mapInfo->setTitle(ObjectManager::GetInstance()->getMapName());

	PlayerInfo = new UI;
	PlayerInfo->setTitle("미션! 500원 모으기");
	PlayerInfo->setSize(26, 8);
	PlayerInfo->setPosi(Vector3(0, 0));
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
	mapInfo->setTitle(Maps[ObjectManager::GetInstance()->getMapName()]->getKorName());

	
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	mapInfo->Render();
	PlayerInfo->Render();
	
	CursorManager::GetInstance()->WriteBuffer(Vector3(2, 5), "현재 골드 : ");
	CursorManager::GetInstance()->WriteBuffer(Vector3(18, 5), dynamic_cast<Player*>(pPlayer)->PlayerMoney);

	
	
}

void Stage::Release()
{

}

