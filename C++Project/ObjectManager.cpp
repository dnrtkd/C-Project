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
	//map<string, deque<Object*>> t;
	//deque<Object*> t2;
	//t.insert(make_pair("Ground", t2));
	//Objects.insert(make_pair("BegginerHunt", t));
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(Object* obj ,string mapName)
{
	//오브젝트의 키를 받아옴
	string key = obj->GetKey();
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
	CursorManager::GetInstance()->WriteBuffer(Vector3(140, 2), Objects["BegginerHunt"]["Ground"].size());
	pPlayer->Update();
	/*
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
	}*/

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
						delete (*iter);
						(*iter) = nullptr;
						j.second.erase(iter);
					}
					
				}
			}
			if (j.first == "Ground")
			{
				for (auto iter = j.second.begin(); iter < j.second.end(); ++iter)
				{
					if ((*iter)->GetPosition().y > pPlayer->GetPosition().y &&
						CollisionManager::RectCollision((*iter)->GetTransform(), pPlayer->GetTransform()))
					{
						dynamic_cast<Player*>(pPlayer)->isGround = true;
						dynamic_cast<Player*>(pPlayer)->setStepGround((*iter));
						pPlayer->SetPosition(Vector3(pPlayer->GetPosition().x,
							(*iter)->GetPosition().y - pPlayer->GetTransform().Scale.y + 1));
					}
					for (auto enemy : i.second["Enemy"])
					{
						if ((*iter)->GetPosition().y > enemy->GetPosition().y &&
							CollisionManager::RectCollision((*iter)->GetTransform(), enemy->GetTransform()))
						{
							dynamic_cast<Enemy*>(enemy)->setStepGround((*iter));
						}
					}
				}
			}
			if (j.first == "Enemy")
			{
				int result = 0;
				for (auto iter = j.second.begin(); iter < j.second.end(); ++iter)
				{
					result = (*iter)->Update();

					float scrX = CursorManager::GetInstance()->getScrPosiX();
					if ((*iter)->GetPosition().x - scrX < 0 || (*iter)->GetPosition().x - scrX>150)
					{
						result = 1;
					}

					for (auto enemy : i.second["Enemy"])
					{
						//총알과 에너미의 충돌 부분
						if (CollisionManager::RectCollision((*iter)->GetTransform(), enemy->GetTransform()))
						{
							bool left = false;
							if (pPlayer->GetPosition().x < enemy->GetPosition().x)
								left = true;
							dynamic_cast<Enemy*>(enemy)->hit(dynamic_cast<Bullet*>((*iter))->getDamage(), left);
							result = 1;
						}
					}
					if (result == 1)
					{
						delete (*iter);
						j.second.erase(iter);
					}
				}
			}
		}
	}

	/*for (size_t i = 0; i < 32; i++)
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
	}*/

	

	//int result = 0;
	//for (int i = 0; i < 128; ++i)
	//{
	//	if (pBullet[i])
	//	{
	//		result = pBullet[i]->Update();

	//		float scrX = CursorManager::GetInstance()->getScrPosiX();
	//		if (pBullet[i]->GetPosition().x - scrX < 0 || pBullet[i]->GetPosition().x - scrX>150)
	//		{
	//			result = 1;
	//		}
	//		
	//		for (size_t j = 0; j < 16; j++)
	//		{
	//			if (pEnemy[j])
	//			{
	//				//총알과 에너미의 충돌 부분
	//				if (CollisionManager::RectCollision(pBullet[i]->GetTransform(), pEnemy[j]->GetTransform()))
	//				{
	//					bool left = false;
	//					if (pPlayer->GetPosition().x < pEnemy[j]->GetPosition().x)
	//						left = true;
	//					dynamic_cast<Enemy*>(pEnemy[j])->hit(dynamic_cast<Bullet*>(pBullet[i])->getDamage(),left);
	//					result = 1;
	//				}
	//			}
	//		}


	//	}

	//	if (result == 1)
	//	{
	//		delete pBullet[i];
	//		pBullet[i] = nullptr;
	//	}
	//}

	
}

void ObjectManager::Render()
{
	for (auto i : Objects)
	{
		if (i.first == currMapName)
		{
			for (auto j : i.second)
			{
				for (auto k : j.second)
					k->Render();
			}
		}
	}
	pPlayer->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;


	/*for (int i = 0; i < 128; ++i)
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
	}*/
}