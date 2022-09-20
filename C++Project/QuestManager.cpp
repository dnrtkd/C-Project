#include "QuestManager.h"

QuestManager* QuestManager::Instance = nullptr;

void QuestManager::Start()
{
	questList.push_back(new Quest(0,0));
}

QuestManager::QuestManager()
{
}

void QuestManager::Update()
{
}

QuestManager::~QuestManager()
{
}
