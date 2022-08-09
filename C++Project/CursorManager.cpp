#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;

CursorManager::CursorManager() : BufferIndex(0),maxWidth(150),maxHeight(40)
,screenPosiX(0),screenPosiY(0)
{

}

CursorManager::~CursorManager()
{
	DestroyBuffer();
}

// ** 버퍼 생성
void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	// ** 커서를 안보이게 함.
	CursorInfo.bVisible = FALSE;
	CursorInfo.dwSize = 1;

	COORD Size = { SHORT(_Width - 1), SHORT(_Height - 1) };

	SMALL_RECT Rect = { 0, 0, SHORT(_Width), SHORT(_Height) };

	HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[0], Size);
	SetConsoleWindowInfo(HBuffer[0], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[0], &CursorInfo);

	HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[1], Size);
	SetConsoleWindowInfo(HBuffer[1], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[1], &CursorInfo);
}


// ** 버퍼에 쓰기
void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_x , (SHORT)_y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

// ** 버퍼에 쓰기
void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_Position.x , (SHORT)_Position.y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, int val, int _Color)
{
	COORD CursorPosition = { (SHORT)_Position.x , (SHORT)_Position.y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	char buff[128] = "";

	_itoa_s(val, buff, 10);

	DWORD dw;

	WriteFile(HBuffer[BufferIndex], buff, (DWORD)strlen(buff), &dw, NULL);
}

void CursorManager::RenderObj(const Texture& texture, int sizeY,int sizeX ,float _x, float _y)
{
	// 출력하고자 하는 오브젝트의 좌표값- 스크린 좌표값을 해줌으로서
	//스크린 좌표 이동을 구현할 수 있다.
	_x = _x - screenPosiX;
	_y = _y - screenPosiY;

	//출력하고자 하는 좌표가  행 0~150  열 0~40 범위 밖인 경우 출력 X
	if (_x >=  maxWidth ||
		_x + sizeX  <0  ||
		_y >= maxHeight ||
		_y + sizeY < 0) return;
	
	
	for (size_t i = 0; i < sizeY; i++)
	{
		char temp[128];

		int x = (int)_x;
		int y = (int)_y;

		if (x < 0)
		{
			int start = -x;
			for (size_t j = start; j < sizeX; j++)
			{
				temp[j - start] = texture.texture[i][j];
			}
			temp[sizeX - start] = '\0';
			x = 0;
		}
		else if (x + sizeX > maxWidth && x < maxWidth)
		{
			for (size_t j = 0; j < maxWidth - x; j++)
			{
				temp[j] = texture.texture[i][j];
			}
			temp[maxWidth - x] = '\0';
		}
		else
			strcpy_s(temp, texture.texture[i]);

		if (y + i < 40 && y + i >= 0)
		{
			//if (strlen(texture.texture[i])) //  해당 텍스쳐가 공백 문자열이 아니라면
				CursorManager::GetInstance()->WriteBuffer(x, y + i,temp);
		}
	}
}

// ** 버퍼 전환
void CursorManager::FlippingBuffer()
{
	// ** 선택된 버퍼를 보여줌.
	SetConsoleActiveScreenBuffer(HBuffer[BufferIndex]);

	// ** 버퍼 인덱스를 변경.
	BufferIndex = !BufferIndex;

	ClearBuffer();
}

// ** 버퍼 지우기
void CursorManager::ClearBuffer()
{
	COORD Coord = { 0, 0 };
	DWORD dw = 0;

	// ** 버퍼를 ' '라이는 빈 공백으로 채워줌.
	FillConsoleOutputCharacter(HBuffer[BufferIndex], ' ', 150 * 40, Coord, &dw);
}

// ** 버퍼 해제
void CursorManager::DestroyBuffer()
{
	CloseHandle(HBuffer[0]);
	CloseHandle(HBuffer[1]);
}

void CursorManager::SetColor(int _Color)
{
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = 기본 버퍼
	SetConsoleTextAttribute(HBuffer[BufferIndex], _Color);
}
