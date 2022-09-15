#pragma once
#include "Object.h"

class MoveTeleport:public Object
{
	Texture* Enim; // 텍스쳐 모음
	ULONGLONG EnimTime;// 애니메이션 변수
	string NextMapName;
	Vector3 NextPosi; // 플레이어가 리스폰될 위치

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

