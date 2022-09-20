#pragma once
#include"MapFile.h"
class Village :public MapFile
{
public:
	virtual void Start() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	Village();
	virtual ~Village();
};

