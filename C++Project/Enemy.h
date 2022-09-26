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

	ObjState eState; //���� �÷��̾� ����

	Texture* Enim; //�ؽ��� ����
	int currEnim; //���� ���õ� �ؽ���
	ULONGLONG EnimTime;// �ִϸ��̼� ����
	ULONGLONG MoveTime; // �������� �ٲܶ� �ʿ��� Ÿ�̸�
	ULONGLONG hitTime;

	float gravityAccel; //�߷� ���ӵ�
	Vector3 speed;

	Object* stepGround;
protected:
	void move(float delay);
	void isGround();

public:
	//��Ʈ�� ���� üũ
	virtual void hit(float damage,bool left) = 0;
	ObjState getState() { return eState; }
	void setStepGround(Object* ground)
	{
		stepGround = ground;
	}
	Enemy();
	virtual ~Enemy();
};

