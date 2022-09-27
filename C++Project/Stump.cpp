#include "Stump.h"
#include "ObjectFactory.h"

void Stump::Start()
{
	Enim[0].intPutTexture("~~~~~");
	Enim[0].intPutTexture("|+.+|");
	Enim[0].intPutTexture("<   >");
	Enim[0].intPutTexture("*###*");


	Enim[1].intPutTexture("~~~~~");
	Enim[1].intPutTexture("|!.!|");
	Enim[1].intPutTexture("<   >");
	Enim[1].intPutTexture("*###*");

	Enim[2].intPutTexture("~~~~~");
	Enim[2].intPutTexture("|=,=|");
	Enim[2].intPutTexture("<   >");
	Enim[2].intPutTexture("*###*");

	Enim[3].intPutTexture("~~~~~");
	Enim[3].intPutTexture("|o,o|");
	Enim[3].intPutTexture(" | | ");
	Enim[3].intPutTexture("*###*");

	Enim[4].intPutTexture("     ");
	Enim[4].intPutTexture("~~~~~");
	Enim[4].intPutTexture("|o,o|");
	Enim[4].intPutTexture("*###*");

	Enim[5].intPutTexture("     ");
	Enim[5].intPutTexture("     ");
	Enim[5].intPutTexture("|  /|");
	Enim[5].intPutTexture("*###*");


	Enim->color = 13;
	Enim[1].color = 12;
	Enim[2].color = 15;
	Enim[3].color = 15;
	Enim[4].color = 15;
	Enim[5].color = 15;

	Info.Position = Vector3(120, 20);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(strlen("-----"), 4.0f);
	Info.Direction = Vector3(0.0f, 0.0f);
	speed.x = -1;
	gold = 5;

	name = (char*)"ÀÏ²Û";
}

int Stump::Update()
{
	if (eState == ObjState::DEAD)
	{
		Info.Scale = Vector3(0, 0);

		if (deadCount == 0)
			currEnim = 2;
		else if (deadCount == 8)
			currEnim = 3;
		else if (deadCount == 10)
			currEnim = 4;
		else if (deadCount == 12)
			currEnim = 5;
		else if (deadCount == 30)
			dead = true;

		deadCount++;
	}
	else if (eState == ObjState::hit)
	{
		currEnim = 1;
		hitCount++;
		if (hitCount == 8)
		{
			eState = ObjState::IDLE;
			hitCount = 0;
		}
	}
	else if (eState == ObjState::IDLE)
	{
		currEnim = 0;
	}
	if (!(eState == ObjState::DEAD))
	{
		isGround();
		if (!(eState == ObjState::hit))
		{
			currEnim = 0;
			move(0.1f);
		}
	}

	return 0;
}

void Stump::Render()
{
	CursorManager::GetInstance()->RenderObj(Enim[currEnim], Info.Position.x, Info.Position.y);

}

void Stump::Release()
{
}

void Stump::hit(float damage, bool left)
{
	if (eState == ObjState::DEAD) return;

	hp -= damage;

	if (eState != ObjState::hit)
		eState = ObjState::hit;

	if (left)
		Info.Position.x += 2;
	else
		Info.Position.x -= 2;


	//CursorManager::GetInstance()->WriteBuffer(Vector3(Info.Position.x+2,Info.Position.y-2), -damage, 12);
	if (hp <= 0)
	{
		hp = 0;
		eState = ObjState::DEAD;
	}
}

Stump::Stump()
{
	Enim = new Texture[6];
	maxHp = 70.0f;
	hp = maxHp;
	damage = 5.0f;
}

Stump::~Stump()
{
}

