#pragma once
#include "Scene.h"
#include "MapFile.h"
#include "UI.h"
class Stage : public Scene
{
	map<string,MapFile*> Maps;
	string currMap;
	vector<UI*> Ui;
	UI* QuestTalkUi;
	UI* QuestNPC_Ui;
	void pushMap(MapFile* map);
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};

