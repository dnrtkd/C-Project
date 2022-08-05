#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}


void Stage::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0, 37, (char*)"----------------"
		"---------------------------------------------------------------------"
		"-------------------------------------------------------------");
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{

}

