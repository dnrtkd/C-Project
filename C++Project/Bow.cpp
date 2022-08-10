#include "Bow.h"
Bow::Bow()
{
	Enim = new Texture[8];
}

Bow::~Bow()
{
}
void Bow::Start()
{
	Enim[0].texture[1] = "   #";
	Enim[0].texture[2] = " /  |";
	Enim[0].texture[3] = " ¤§   |";
	Enim[0].texture[4] = " ¤¤ |";
	Enim[0].texture[5] = "   #";
}

int Bow::Update()
{
	return 0;
}

void Bow::Render()
{
}

void Bow::Release()
{
}


