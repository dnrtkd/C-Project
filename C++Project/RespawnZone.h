#pragma once
#include"Headers.h"
#include<list>
#include"Object.h"
class RespawnZone
{
	float resTime;
	Vector3 respawnPosi;
	string monName;
	//해당 리스폰존이 생성할 수 있는 최대 몬스터 수
	int maxMonNum;
	int currMonNum;
	ULONGLONG Timer;
	
public:
	void setMonName(string n) { monName = n; }
	void setResTime(float a) { resTime = a; }
	void createMon();
	void setCurrMon(int num) { currMonNum = num; }
public:
	RespawnZone(float res,int maxMonNum,string monN, Vector3 rPosi);
	~RespawnZone();
};

