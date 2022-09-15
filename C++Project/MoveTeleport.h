#pragma once
#include "Object.h"

class MoveTeleport:public Object
{
	Texture* Enim; // �ؽ��� ����
	ULONGLONG EnimTime;// �ִϸ��̼� ����
	string NextMapName;
	Vector3 NextPosi; // �÷��̾ �������� ��ġ

	int currEnim;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void setMapName(string str);
	string getNextMap() { return NextMapName; }
	void setNextPosi(Vector3 posi) { NextPosi = posi; }
	Vector3 getNextPosi() { return NextPosi; }

public:
	MoveTeleport();
	virtual ~MoveTeleport();
};

