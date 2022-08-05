#pragma once
#include "Object.h"


class Player : public Object
{
	Texture* Enim; // �ؽ��� ����
	ULONGLONG EnimTime;// �ִϸ��̼� ����
	
	int currEnim; //���� ���õ� �ؽ���
	ObjState PlayerState; //���� �÷��̾� ����

	float gravityAccel; //�߷� ���ӵ�
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

