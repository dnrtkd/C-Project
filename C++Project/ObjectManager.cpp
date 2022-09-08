#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "Ground.h"
#include "Worker.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{
	
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(Object* obj ,string mapName)
{
	//오브젝트의 키를 받아옴
	string key = obj->GetKey();

	auto iter1 = Objects.find(key);
	
	Objects[mapName][key].push_back(obj);
	
}

//void ObjectManager::CreateObject()
//{
//	for (int i = 0; i < 128; ++i)
//	{
//		if (pBullet[i] == nullptr)
//		{
//			pBullet[i] = new Bullet;
//			pBullet[i]->Start();
//			Vector3 vec = pPlayer->GetPosition();
//
//			pBullet[i]->SetDirection(pPlayer->GetTransform().Direction.x,0);
//			dynamic_cast<Bullet*> (pBullet[i])->setDamage(dynamic_cast<Player*>(pPlayer)->getDamage());
//
//			if(pPlayer->GetTransform().Direction.x==1)
//				pBullet[i]->SetPosition(vec.x+6,vec.y+2);
//			else
//				pBullet[i]->SetPosition(vec.x -1, vec.y + 2);
//			break;
//		}
//	}
//}

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();


	/*pGround[0]->SetPosition(0, 35);
	dynamic_cast<Ground*>(pGround[0])->setSize(150,5);

	pGround[1]->SetPosition(140, 30);
	dynamic_cast<Ground*>(pGround[1])->setSize(10, 5);

	pGround[2]->SetPosition(50, 25);
	dynamic_cast<Ground*>(pGround[2])->setSize(90, 5);
	*/
	
}

void ObjectManager::Update()
{
	pPlayer->Update();
	for (size_t i = 0; i < 16; i++)
	{
		if (pEnemy[i])
		{
			pEnemy[i]->Update();

			if (dynamic_cast<Enemy*>(pEnemy[i])->getState() == ObjState::DEAD)
			{
				delete pEnemy[i];
				pEnemy[i] = nullptr;
			}
		}
	}

	//가장 상위 : 맵에 속한 몬스터
	for (auto i : Objects)
	{
		for (auto j : i.second)
		{
			// 에너미 업데이트
			if (j.first == "Enemy")
			{
				for (auto iter = j.second.begin(); iter < j.second.end(); ++iter)
				{
					(*iter)->Update();

					if (dynamic_cast<Enemy*>((*iter))->getState() == ObjState::DEAD)
					{
						j.second.erase(iter);
					}
					
				}
			}
			

		}
	}

	for (size_t i = 0; i < 32; i++)
	{
		if (pGround[i])
		{
			if (pGround[i]->GetPosition().y > pPlayer->GetPosition().y&&
				CollisionManager::RectCollision( pGround[i]->GetTransform(), pPlayer->GetTransform()) )
			{
					dynamic_cast<Player*>(pPlayer)->isGround = true;
					dynamic_cast<Player*>(pPlayer)->setStepGround(pGround[i]);
					pPlayer->SetPosition(Vector3(pPlayer->GetPosition().x, 
						pGround[i]->GetPosition().y - pPlayer->GetTransform().Scale.y + 1));
			}

			for (size_t j = 0; j < 16; j++)
			{
				if (pEnemy[j])
				{
					if (pGround[i]->GetPosition().y > pEnemy[j]->GetPosition().y &&
						CollisionManager::RectCollision(pGround[i]->GetTransform(), pEnemy[j]->GetTransform()))
					{
						dynamic_cast<Enemy*>(pEnemy[j])->setStepGround(pGround[i]);
					}
				}
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
			
			for (size_t j = 0; j < 16; j++)
			{
				if (pEnemy[j])
				{
					//총알과 에너미의 충돌 부분
					if (CollisionManager::RectCollision(pBullet[i]->GetTransform(), pEnemy[j]->GetTransform()))
					{
						bool left = false;
						if (pPlayer->GetPosition().x < pEnemy[j]->GetPosition().x)
							left = true;
						dynamic_cast<Enemy*>(pEnemy[j])->hit(dynamic_cast<Bullet*>(pBullet[i])->getDamage(),left);
						result = 1;
					}
				}
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
	for (size_t i = 0; i < 32; i++)
	{
		if(pGround[i])
		pGround[i]->Render();
	}

	for (size_t i = 0; i < 16; i++)
	{
		if(pEnemy[i])
		pEnemy[i]->Render();
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}

	pPlayer->Render();
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