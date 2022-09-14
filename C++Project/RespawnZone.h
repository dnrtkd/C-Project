#pragma once
#include"Object.h"
#include <list>
class RespawnZone:public Object
{
	float resTime;
	string monName;
	//해당 리스폰존이 생성할 수 있는 최대 몬스터 수
	int maxMonNum;
	ULONGLONG Timer;
	list<Object**> monL;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void setMonName(string n) { monName = n; }
	void setResTime(float a) { resTime = a; }
	void createMon(string mapName);
public:
	RespawnZone(float res,int maxMonNum,string monN);
	~RespawnZone();
};

