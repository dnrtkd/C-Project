#include "Worker.h"
#include "ObjectFactory.h"

void Worker::Start()
{
	Enim[0].intPutTexture("-----");
	Enim[0].intPutTexture("|+.+|");
	Enim[0].intPutTexture("|   |");
	Enim[0].intPutTexture("-----");
	

	Enim[1].intPutTexture("-----");
	Enim[1].intPutTexture("|!.!|");
	Enim[1].intPutTexture("|   |");
	Enim[1].intPutTexture("-----");
	
	
	Info.Position = Vector3(120, 20);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(strlen("-----"), 5.0f);
	Info.Direction = Vector3(0.0f, 0.0f);
	speed.x = -1;

	name = (char*)"¿œ≤€";
}

int Worker::Update()
{
	if (hitTime + 400 < GetTickCount64())
	{
		hitTime = GetTickCount64();
		eState = ObjState::IDLE;
	}

	isGround();
	if(!(eState==ObjState::hit))
	move(0.1f);

	if (eState == ObjState::hit)
		currEnim = 1;
	else
		currEnim = 0;
	return 0;
}

void Worker::Render()
{
	CursorManager::GetInstance()->RenderObj(Enim[currEnim], Info.Position.x, Info.Position.y);
	
}

void Worker::Release()
{
}

void Worker::hit(float damage,bool left)
{
	hp -= damage;

	hitTime = GetTickCount64();
	eState = ObjState::hit;

	if (left)
		Info.Position.x += 2;
	else
		Info.Position.x -= 2;

	
	//CursorManager::GetInstance()->WriteBuffer(Vector3(Info.Position.x+2,Info.Position.y-2), -damage, 12);
	if (hp < 0)
	{
		hp = 0;
		eState = ObjState::DEAD;
	}
}

Worker::Worker()
{
	Enim = new Texture[2];
	maxHp = 10.0f;
	hp = maxHp;
	damage = 5.0f;
}

Worker::~Worker()
{
}
