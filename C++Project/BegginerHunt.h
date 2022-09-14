#pragma once
#include"MapFile.h"
class BegginerHunt:public MapFile
{
public:
	virtual void Start() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	BegginerHunt();
	virtual ~BegginerHunt();
};

