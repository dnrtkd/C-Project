#pragma once
#include "Object.h"

class MoveTeleport:public Object
{
	Texture* Enim; // �ؽ��� ����
	ULONGLONG EnimTime;// �ִϸ��̼� ����
	string NextMapName;

	int currEnim;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void setMapName(string str);
	string getNextMap() { return NextMapName; }

public:
	MoveTeleport();
	virtual ~MoveTeleport();
};

