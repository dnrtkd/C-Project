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


void ObjectManager::CreateObject()
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			Vector3 vec = pPlayer->GetPosition();

			pBullet[i]->SetDirection(pPlayer->GetTransform().Direction.x,0);

			if(pPlayer->GetTransform().Direction.x==1)
				pBullet[i]->SetPosition(vec.x+6,vec.y+2);
			else
				pBullet[i]->SetPosition(vec.x -1, vec.y + 2);
			break;
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();


	for (size_t i = 0; i < 32; i++)
	{
		pGround[i] = new Ground;
		pGround[i]->Start();
	}

	pGround[0]->SetPosition(0, 35);
	pGround[1]->SetPosition(50, 35);
	pGround[2]->SetPosition(100, 35);
	pGround[3]->SetPosition(150, 35);
	pGround[4]->SetPosition(200, 35);
	pGround[5]->SetPosition(250, 35);
	
}

void ObjectManager::Update()
{
	pPlayer->Update();

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

			float scrX = CursorManager::GetInstance()->getScrPosiX();
			if (pBullet[i]->GetPosition().x - scrX < 0 || pBullet[i]->GetPosition().x - scrX>150)
			{
				result = 1;
			}
			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다.");
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