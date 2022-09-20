#pragma once
#include "Headers.h"
class UI
{
private:
	//제목
	string title;
	vector<string> contents; //내용

	vector<string> box;
	Vector3 StartP; // 시작점
	int Widht; 
	int height;
	
public:
	// UI를 키는 변수
	bool isTurnON;

public:
	void Start();
	void Render();
	void setTitle(string title);
	void setPosi(Vector3 posi) { StartP = posi; }

	void InputContents(string content);

	void drawRec(); //사각형을 그리는 함수
	void setSize(int Width,int Height);

public:
	UI();
	~UI();

};

