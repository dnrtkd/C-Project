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

// ** ���� ����
void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	// ** Ŀ���� �Ⱥ��̰� ��.
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


// ** ���ۿ� ����
void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_x , (SHORT)_y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

// ** ���ۿ� ����
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
	// ����ϰ��� �ϴ� ������Ʈ�� ��ǥ��- ��ũ�� ��ǥ���� �������μ�
	//��ũ�� ��ǥ �̵��� ������ �� �ִ�.
	_x = _x - screenPosiX;
	_y = _y - screenPosiY;

	//����ϰ��� �ϴ� ��ǥ��  �� 0~150  �� 0~40 ���� ���� ��� ��� X
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
			//if (strlen(texture.texture[i])) //  �ش� �ؽ��İ� ���� ���ڿ��� �ƴ϶��
				CursorManager::GetInstance()->WriteBuffer(x, y + i,temp);
		}
	}
}

// ** ���� ��ȯ
void CursorManager::FlippingBuffer()
{
	// ** ���õ� ���۸� ������.
	SetConsoleActiveScreenBuffer(HBuffer[BufferIndex]);

	// ** ���� �ε����� ����.
	BufferIndex = !BufferIndex;

	ClearBuffer();
}

// ** ���� �����
void CursorManager::ClearBuffer()
{
	COORD Coord = { 0, 0 };
	DWORD dw = 0;

	// ** ���۸� ' '���̴� �� �������� ä����.
	FillConsoleOutputCharacter(HBuffer[BufferIndex], ' ', 150 * 40, Coord, &dw);
}

// ** ���� ����
void CursorManager::DestroyBuffer()
{
	CloseHandle(HBuffer[0]);
	CloseHandle(HBuffer[1]);
}

void CursorManager::SetColor(int _Color)
{
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = �⺻ ����
	SetConsoleTextAttribute(HBuffer[BufferIndex], _Color);
}
