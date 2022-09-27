#pragma once
#include "Scene.h"
#include "MapFile.h"
#include "UI.h"
class Stage : public Scene
{
	map<string,MapFile*> Maps;
	string currMap;
	UI* mapInfo;
	UI* QuestTalkUi;
	UI* PlayerInfo;
	void pushMap(MapFile* map);
	Object* pPlayer;



public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};

