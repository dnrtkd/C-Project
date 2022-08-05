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

	bool isJump;
public:
	bool isGround;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void move();
public:
	Player();
	virtual ~Player();
};

