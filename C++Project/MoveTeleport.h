#pragma once
#include "Object.h"

class MoveTeleport:public Object
{
	Texture* Enim; // 텍스쳐 모음
	ULONGLONG EnimTime;// 애니메이션 변수
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

