#pragma once
#include"Headers.h"
#include<list>
#include"Object.h"
class RespawnZone
{
	float resTime;
	Vector3 respawnPosi;
	string monName;
	//�ش� ���������� ������ �� �ִ� �ִ� ���� ��
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

