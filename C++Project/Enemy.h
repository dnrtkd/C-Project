#pragma once
#include "Object.h"

class Enemy : public Object
{
protected:
	float hp;
	float damage;
	int gold;
	int exp;

	Texture* Enim; //�ؽ��� ����
	ULONGLONG EnimTime;// �ִϸ��̼� ����

public:
	Enemy();
	virtual ~Enemy();
};

