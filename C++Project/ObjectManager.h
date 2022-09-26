#pragma once
#include "Headers.h"
#include <list>
class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	Object* pPlayer;
	//제일 외부의 문자열은 맵의 이름
	//내부의 문자열은 몬스터의 타입을 나타낸다.
	map<string, map<short,list<Object*>>> Objects;
	//현재의 맵이름. 현재 맵만 렌더링 해야함
	string currMapName;
	//텔레포트 지연시간
	ULONGLONG telpoTime;
public:
	void AddObject(Object* obj,string mapName);
	//void CreateObject();
	void Start();
	void Update();
	void Render();
	void Release();
	void setMapName(string mName) { currMapName = mName; }
	string getMapName() { return currMapName; }
	//현재 씬에 있는 모든 몬스터들을 반환하는 함수
	list<Object*>& FindAllMonsters() { return Objects[currMapName][ENEMY]; }
	Object* getPlayer() { return pPlayer; }
private:
	ObjectManager();
public:
	~ObjectManager();
};

