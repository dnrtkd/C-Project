#pragma once
// ** Framework v9.0    DoubleBuffer
#include "MainUpdate.h"


int main(void)
{


	system("title 홍길동 : 게임이름");
	system("mode con cols=150 lines=40");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time+50 <= GetTickCount64())
		{
			//system("cls");

			Main.Update();
			Main.Render();

			Time = GetTickCount64();
		}
	}

	return 0;
}