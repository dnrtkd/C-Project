#pragma once
#include "Headers.h"

class QuestManager
{
	bool questWindowOn ;
	int mainQuestIndex = 0;
	vector< Quest*> questList;
private:
	static QuestManager* Instance;
public:
	static QuestManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new QuestManager;
		return Instance;
	}
	bool isQuestWindowOn() { return questWindowOn; }

	void Start();
	void Update();
	

private:
	QuestManager() { questWindowOn = false; }
public:
	~QuestManager();  
};

