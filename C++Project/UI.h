#pragma once
#include "Headers.h"
class UI
{
private:
	char* buf;

	Vector3 StartP; // 시작점
	int Widht; 
	int height;
	
public:
	// UI를 키는 변수
	bool isTurnON;

public:
	void start();
	void Render();
	void Update();
	void Release();

	void drawRec(); //사각형을 그리는 함수
public:
	UI();
	~UI();

};

