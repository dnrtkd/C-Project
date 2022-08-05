#pragma once
#include "Object.h"


class Player : public Object
{
	Texture* Enim; // 텍스쳐 모음
	ULONGLONG EnimTime;// 애니메이션 변수
	
	int currEnim; //현재 선택된 텍스쳐
	ObjState PlayerState; //현재 플레이어 상태

	float gravityAccel; //중력 가속도
	Vector3 speed;

    Object* stepGround;

	bool isJump;
public:
	bool isGround;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void move();

	void setStepGround( Object* ground)
	{
		stepGround = ground;
	}
public:
	Player();
	virtual ~Player();
};

