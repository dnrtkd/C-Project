#pragma once
#include "Scene.h"
#include "MapFile.h"
class Stage : public Scene
{
	vector<MapFile*> Maps;
	int currMapIndex;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};

