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
	mapInfo->setSize(30, 7);
	mapInfo->setPosi(Vector3(110, 2));
	mapInfo->setTitle(ObjectManager::GetInstance()->getMapName());

	QuestTalkUi = new UI;
	QuestTalkUi->setSize(60, 25);
	QuestTalkUi->setPosi(Vector3(45,7));
	QuestTalkUi->setTitle("퀘스트 ");

	PlayerInfo = new UI;
	PlayerInfo->setSize(30, 12);
	PlayerInfo->setPosi(Vector3(0, 0));
	PlayerInfo->setTitle(ObjectManager::GetInstance()->getMapName());
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
	mapInfo->setTitle(Maps[ObjectManager::GetInstance()->getMapName()]->getKorName());

	
	PlayerInfo->setTitle("캐릭터 정보");
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	mapInfo->Render();
	PlayerInfo->Render();
	
	CursorManager::GetInstance()->WriteBuffer(Vector3(2, 3), "플레이어 레벨 : ");
	CursorManager::GetInstance()->WriteBuffer(Vector3(22, 3),dynamic_cast<Player*>(pPlayer)->playerLevel);

	CursorManager::GetInstance()->WriteBuffer(Vector3(2, 5), "골드 : ");
	CursorManager::GetInstance()->WriteBuffer(Vector3(18, 5), dynamic_cast<Player*>(pPlayer)->PlayerMoney);

	
	
}

void Stage::Release()
{

}

