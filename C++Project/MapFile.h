#pragma once
class MapFile
{

public:
	void Start();
	int Update();
	void Render();
	void Release();

public:
	MapFile();
	~MapFile();
};

