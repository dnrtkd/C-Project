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

	bool isJump; //점프 했는지 체크
	
	float damage; //데미지
	float hp;
	float delay; //공격 대기시간
public:
	bool isGround;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void move();
	//objectManager에서 내가 밟고 있는 땅의 포인터를 가져옴
	void setStepGround( Object* ground)
	{
		stepGround = ground;
	}
	void basicAttack();
public:
	Player();
	virtual ~Player();
};

