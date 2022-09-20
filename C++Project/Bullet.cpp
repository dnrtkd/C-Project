#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);
	key = "Bullet";
	Target = nullptr;

	enim = new Texture[2];

	damage = 0;
}

Bullet::~Bullet()
{
	Release();
}


void Bullet::Start()
{
	enim[0].intPutTexture ("*");

}

int  Bullet::Update()
{
	Info.Position.x += 4 * Info.Direction.x;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->RenderObj(enim[0], 
		Info.Position.x, Info.Position.y);
}

void Bullet::Release()
{
	//delete[] enim;
}
