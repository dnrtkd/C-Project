#pragma once
#include "Headers.h"
class UI
{
private:
	char* buf;

	Vector3 StartP; // ������
	int Widht; 
	int height;
	
public:
	// UI�� Ű�� ����
	bool isTurnON;

public:
	void start();
	void Render();
	void Update();
	void Release();

	void drawRec(); //�簢���� �׸��� �Լ�
public:
	UI();
	~UI();

};

