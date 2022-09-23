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

	bool isJump; //���� �ߴ��� üũ
	
	float damage; //������
	float hp; //���� ü��
	float delay; //���� ���ð�
	ULONGLONG fireTime;
	ULONGLONG skill1Timer;
public:
	bool isGround;
private:
	void move();
	void skill_1(); //�ټ� �� �˹� ȿ��

public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	float getDamage() { return damage; }
	//objectManager���� ���� ��� �ִ� ���� �����͸� ������
	void setStepGround( Object* ground)
	{
		stepGround = ground;
	}
	void basicAttack();
public:
	Player();
	virtual ~Player();
};

