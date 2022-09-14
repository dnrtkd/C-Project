#pragma once
#include "Headers.h"
#include "RespawnZone.h"
class MapFile
{
protected:
	string MapName;
	vector<RespawnZone> resZone;
	string korName;

public:
	virtual void Start() = 0;
	virtual int Update() = 0;
	virtual void Render()=0;
	virtual void Release()=0;
	string getKorName() { return korName; }
public:
	MapFile();
	virtual ~MapFile();
};

