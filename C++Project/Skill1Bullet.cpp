#include "Skill1Bullet.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectFactory.h"
#include "Enemy.h"
void Skill1Bullet::Start()
{
	enim[0].intPutTexture("oo");
	enim[0].intPutTexture("oo");
	

	list<Object*> temp= ObjectManager::GetInstance()->FindAllMonsters();

	float min = 500.0f;
	float value = 0.0f;
	// 모든 적 오브젝트를 순회하여 가장 거리가 짧은 몬스터를 반환함
	/*for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (value=Vector3::GetDistance((*iter)->GetPosition(),Info.Position) < min)
		{
			min = value;
			Target = (*iter);

			Vector3 dir = Vector3::GetDirection(Info.Position, Target->GetPosition());
			if (abs(dir.y - dir.x) > 0.02f)
			{
				Target = nullptr;
				min = 500.0f;
			}
				
		}
	}*/
}

int Skill1Bullet::Update()
{
	if (Target)
	{
		Vector3 targetPosition = Target->GetPosition();
		Info.Direction = Vector3::GetDirection(Info.Position, Target->GetPosition());
	}

	Info.Position.x += 6 * Info.Direction.x;
	Info.Position.y += 6 * Info.Direction.y;

	return 0;
}


void Skill1Bullet::Release()
{
	ObjectFactory::CreateObject(Vector3(Info.Position.x - 3, Info.Position.y), 
		ObjectManager::GetInstance()->getMapName(), "Skill1Effect");

	Info.Position = Vector3(Info.Position.x - 9.0f, Info.Position.y);
	Info.Scale = Vector3(18.0f, 2.0f);
	list<Object*> temp = ObjectManager::GetInstance()->FindAllMonsters();

	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (CollisionManager::RectCollision((*iter)->GetTransform(), Info))
		{
			dynamic_cast<Enemy*>((*iter))->hit(30.0f, true);

			Object* temp = ObjectFactory::CreateObject(Vector3((*iter)->GetPosition().x + 2,
				(*iter)->GetPosition().y - 2), ObjectManager::GetInstance()->getMapName(), "Damage");

			dynamic_cast<Damage*>(temp)->setDamageText(30.0f);
		}
	}

	delete[] enim;
}

Skill1Bullet::Skill1Bullet()
{
	Info.Scale = Vector3(2.0f, 2.0f);
}

Skill1Bullet::~Skill1Bullet()
{
	Release();
}
