#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "Ground.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;

	for (size_t i = 0; i < 32; i++)
	{
		pGround[i] = nullptr;
	}
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			pBullet[i]->SetPosition(74.0f, 1.0f);

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = pPlayer->GetPosition() - pBullet[i]->GetPosition();
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 1:
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			}
			break;
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();

	pEnemy = new Enemy;
	pEnemy->Start();

	for (size_t i = 0; i < 32; i++)
	{
		pGround[i] = new Ground;
		pGround[i]->Start();
	}

	pGround[0]->SetPosition(0, 35);
	pGround[1]->SetPosition(10, 35);
	pGround[2]->SetPosition(20, 35);
	pGround[3]->SetPosition(30, 35);
	pGround[4]->SetPosition(40, 35);
	pGround[5]->SetPosition(50, 35);
	pGround[6]->SetPosition(60, 35);
	pGround[7]->SetPosition(70, 35);
	pGround[8]->SetPosition(80, 35);
	pGround[9]->SetPosition(90, 35);
	pGround[10]->SetPosition(100, 35);
	pGround[11]->SetPosition(100, 25);
	pGround[12]->SetPosition(110, 25);
	pGround[13]->SetPosition(120, 25);
	pGround[14]->SetPosition(130, 25);
	pGround[15]->SetPosition(100, 13);
	pGround[16]->SetPosition(90, 13);
}

void ObjectManager::Update()
{
	pPlayer->Update();
	pEnemy->Update();

	for (size_t i = 0; i < 32; i++)
	{
		if (pGround[i])
		{
			if (CollisionManager::RectCollision( pGround[i]->GetTransform(), pPlayer->GetTransform()))
			{
				dynamic_cast<Player*>(pPlayer)->isGround = true;
				dynamic_cast<Player*>(pPlayer)->setStepGround(pGround[i]);
				pPlayer->SetPosition(Vector3(pPlayer->GetPosition().x, pGround[i]->GetPosition().y - pPlayer->GetTransform().Scale.y+1));
				CursorManager::GetInstance()->WriteBuffer(130, 2, (char*)"dafsfssdfsa");
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			result = pBullet[i]->Update();

			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"�浹�Դϴ�.");
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}

	
}

void ObjectManager::Render()
{
	pPlayer->Render();
	pEnemy->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}

	for (size_t i = 0; i < 32; i++)
	{
		pGround[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}

	for (size_t i = 0; i < 32; i++)
	{
		delete pGround[i];
		pGround[i] = nullptr;
	}
}