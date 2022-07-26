#pragma once
#include "Headers.h"
#include "Object.h"

class CursorManager
{
private:
	int maxWidth; //콘솔화면의 최대 가로 크기
	int maxHeight; // 콘솔 화면의 최대 세로 크기

	float screenPosiX; // 스크린 x좌표
	float screenPosiY;// 스크린 y좌표

private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;
		return Instance;
	}
private:
	int BufferIndex;
	HANDLE HBuffer[2];
public:
	void CreateBuffer(const int& _Width, const int& _Height);
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);
	void WriteBuffer(Vector3 _Position, char* _str, int _Color = 15);
	void WriteBuffer(Vector3 _Position,int val, int _Color = 15);
	void WriteBuffer(Vector3 _Position, string _str, int _Color=15);
	void RenderObj(const Texture& texture,float _x, float _y, int screen=0);
	void addScreenPosiX(float x)
	{ 
		screenPosiX += x; 
		if (screenPosiX < 0)
			screenPosiX = 0;

		if (screenPosiX > 50)
			screenPosiX = 50;
	}
	void addScreenPosiY(float y) 
	{ 
		screenPosiY += y; 
		if (screenPosiY < 0 )
			screenPosiY = 0;

		if (screenPosiY > 60)
			screenPosiY = 60;
	}
	void setScreen(float x, float y) 
	{ 
		screenPosiX = x; 
		screenPosiY = y;

		if (screenPosiX < 0)
			screenPosiX = 0;

		if (screenPosiX > 50)
			screenPosiX = 50;

		if (screenPosiY < 0)
			screenPosiY = 0;

		if (screenPosiY > 60)
			screenPosiY = 60;
	}
	float getScrPosiX() { return screenPosiX; }
	float getScrPosiY() { return screenPosiY; }

	void FlippingBuffer();
private:
	void ClearBuffer();
	void DestroyBuffer();
	void SetColor(int _Color);
private:
	CursorManager();
public:
	~CursorManager();
};