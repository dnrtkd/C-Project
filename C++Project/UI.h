#pragma once
#include "Headers.h"
class UI
{
private:
	//����
	string title;
	vector<string> contents; //����

	vector<string> box;
	Vector3 StartP; // ������
	int Widht; 
	int height;
	
public:
	// UI�� Ű�� ����
	bool isTurnON;

public:
	void Start();
	void Render();
	void setTitle(string title);
	void setPosi(Vector3 posi) { StartP = posi; }

	void InputContents(string content);

	void drawRec(); //�簢���� �׸��� �Լ�
	void setSize(int Width,int Height);

public:
	UI();
	~UI();

};

