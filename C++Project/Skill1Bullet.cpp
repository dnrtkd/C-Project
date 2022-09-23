#include "Skill1Bullet.h"
#include "ObjectManager.h"
#include "CursorManager.h"

void Skill1Bullet::Start()
{
	enim[0].intPutTexture("o");

	list<Object*> temp= ObjectManager::GetInstance()->FindAllMonsters();

	float min = 100.0f;
	float value = 0.0f;
	// 모든 적 오브젝트를 순회하여 가장 거리가 짧은 몬스터를 반환함
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (value=Info.Position.getDistance((*iter)->GetPosition()) < min)
		{
			min = value;
			Target = (*iter);
		}
	}
}

int Skill1Bullet::Update()
{
	Vector3 direction = { 0,0 };
	if (Target)
	{
		Vector3 targetPosition = Target->GetPosition();
	    direction = Info.Position.getDIrection(targetPosition);
	}

	Info.Position.x += 2 * direction.x;
	Info.Position.y += 2 * direction.y;

	if (Target)
	{
		CursorManager::GetInstance()->WriteBuffer(Vector3(0,0), direction.x*10);
		CursorManager::GetInstance()->WriteBuffer(Vector3(0,1), direction.y*10);
	}
	CursorManager::GetInstance()->WriteBuffer(Vector3(0,0), 500);
	CursorManager::GetInstance()->WriteBuffer(Vector3(0,1), 700);

	return 0;
}


void Skill1Bullet::Release()
{
	delete[] enim;
}

Skill1Bullet::Skill1Bullet()
{
	Info.Scale = Vector3(1.0f, 1.0f);
	
}

Skill1Bullet::~Skill1Bullet()
{
	Release();
}
