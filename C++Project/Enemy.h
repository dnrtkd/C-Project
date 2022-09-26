#pragma once
#include "Object.h"
#include "CursorManager.h"
#include "CollisionManager.h"
class Enemy : public Object
{
public:
	bool _isGround;
protected:
	float hp;
	float maxHp;
	float damage;
	char* name;

public:
	int gold;
	int exp;

	ObjState eState; //현재 플레이어 상태

	Texture* Enim; //텍스쳐 모음
	int currEnim; //현재 선택된 텍스쳐
	ULONGLONG EnimTime;// 애니메이션 변수
	ULONGLONG MoveTime; // 움직임을 바꿀때 필요한 타이머
	ULONGLONG hitTime;

	float gravityAccel; //중력 가속도
	Vector3 speed;

	Object* stepGround;
protected:
	void move(float delay);
	void isGround();

public:
	//히트된 방향 체크
	virtual void hit(float damage,bool left) = 0;
	ObjState getState() { return eState; }
	void setStepGround(Object* ground)
	{
		stepGround = ground;
	}
	Enemy();
	virtual ~Enemy();
};

