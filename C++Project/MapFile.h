#pragma once
#include "Headers.h"
#include "RespawnZone.h"
#include "Ground.h"
#include "ObjectFactory.h"
class MapFile
{
protected:
	string MapName;
	vector<RespawnZone> resZone;
	string korName;
	//∏  ªÁ¿Ã¡Ó
	Vector3 mapSize;
public:
	virtual void Start() = 0;
	virtual int Update() = 0;
	virtual void Render()=0;
	virtual void Release()=0;
	string getKorName() { return korName; }
	string getName() { return MapName; }
public:
	MapFile();
	virtual ~MapFile();
};

