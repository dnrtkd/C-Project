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
	//���� �ܺ��� ���ڿ��� ���� �̸�
	//������ ���ڿ��� ������ Ÿ���� ��Ÿ����.
	map<string, map<short,list<Object*>>> Objects;
	//������ ���̸�. ���� �ʸ� ������ �ؾ���
	string currMapName;
	//�ڷ���Ʈ �����ð�
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
	//���� ���� �ִ� ��� ���͵��� ��ȯ�ϴ� �Լ�
	list<Object*>& FindAllMonsters() { return Objects[currMapName][ENEMY]; }
	Object* getPlayer() { return pPlayer; }
private:
	ObjectManager();
public:
	~ObjectManager();
};

