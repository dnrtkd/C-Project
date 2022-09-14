#pragma once
#include"MapFile.h"
class BegginerHunt2 :public MapFile
{
public:
	virtual void Start() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	BegginerHunt2();
	virtual ~BegginerHunt2();
};

