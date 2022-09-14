#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "OutputManager.h"
#include "CollisionManager.h"
#include "ObjectManager.h"

void Player::basicAttack()
{
	if (fireTime + delay * 1000 < GetTickCount64())
	{
		fireTime = GetTickCount64();
		//ObjectManager::GetInstance()->CreateObject();
	}
}

Player::Player()
{
	Enim = new Texture[8];
	EnimTime = GetTickCount64();
	PlayerState = ObjState::IDLE;
	currEnim = 0;
	gravityAccel = 0.3;
	speed = { 0,0 };
	isJump = false;
	isGround = false;
	stepGround = nullptr;
	delay = 0.2f; //0.2√ 
	hp = 50.0f;
	damage = 5.0f;
	fireTime = GetTickCount64();

	Enim[0].intPutTexture(" 0  ");
	Enim[0].intPutTexture("(|o ");
	Enim[0].intPutTexture(" ^  ");
	Enim[0].intPutTexture("_.._");
	

	Enim[1].intPutTexture(" 0  ");
	Enim[1].intPutTexture("(|o ");
	Enim[1].intPutTexture(" ^  ");
	Enim[1].intPutTexture("- ._");
	

	Enim[2].intPutTexture(" 0  ");
	Enim[2].intPutTexture("(|o ");
	Enim[2].intPutTexture(" ^  ");
	Enim[2].intPutTexture("_. -");
	

	Enim[3].intPutTexture(" 0  ");
	Enim[3].intPutTexture("(|o ");
	Enim[3].intPutTexture("|^| ");
	

	Enim[4].intPutTexture(" 0  ");
	Enim[4].intPutTexture("o|) ");
	Enim[4].intPutTexture(" ^  ");
	Enim[4].intPutTexture("_.._");
	

	Enim[5].intPutTexture(" 0  ");
	Enim[5].intPutTexture("o|) ");
	Enim[5].intPutTexture(" ^  ");
	Enim[5].intPutTexture("_. -");
	

	Enim[6].intPutTexture(" 0  ");
	Enim[6].intPutTexture("o|) ");
	Enim[6].intPutTexture(" ^  ");
	Enim[6].intPutTexture("- ._");
	

	Enim[7].intPutTexture(" 0  ");
	Enim[7].intPutTexture("o|) ");
	Enim[7].intPutTexture("|^| ");
	

	for (int i = 0; i < 8; ++i)
		Enim[i].color = 14;
}

Player::~Player()
{

}

void Player::move()
{
	speed.y += gravityAccel;

	if (speed.y > 0)
		Info.Direction.y = 1;

	if (Info.Position.x - CursorManager::GetInstance()->getScrPosiX() > 90 && Info.Direction.x==1)
		CursorManager::GetInstance()->addScreenPosiX(speed.x);

	if (Info.Position.x - CursorManager::GetInstance()->getScrPosiX() < 60 && Info.Direction.x == -1)
		CursorManager::GetInstance()->addScreenPosiX(speed.x);

	if (Info.Position.y - CursorManager::GetInstance()->getScrPosiY() < 16 && Info.Direction.y == -1)
		CursorManager::GetInstance()->addScreenPosiY(speed.y);

	if (Info.Position.y - CursorManager::GetInstance()->getScrPosiY() > 24 && Info.Direction.y == 1)
		CursorManager::GetInstance()->addScreenPosiY(speed.y);

	Info.Position += Vector3(speed.x , speed.y );
}

void Player::skill_1()
{
	
}

void Player::Start()
{
	Info.Position = Vector3(50.0f, 90.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(strlen(" 0  "), 5.0f);
	Info.Direction = Vector3(0.0f, 0.0f);
	Target = nullptr;

	
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	PlayerState = ObjState::IDLE;
	speed.x = 0;
	//Info.Direction.y = 0;

	if (dwKey & KEY_UP)
	{
		if (!isJump && isGround)
		{
			isJump = true;
			isGround = false;
			Info.Direction.y = -1;
			speed.y = -2.0;
		}
	}

	if (dwKey & KEY_DOWN)
	{
		Info.Position.y++;
	}
		
	

	if (dwKey & KEY_LEFT)
	{
		PlayerState = ObjState::MOVE;
		Info.Direction.x = -1;
		speed.x = -2;
	}
		
	if (dwKey & KEY_RIGHT)
	{
		PlayerState = ObjState::MOVE;
		Info.Direction.x = 1;
		speed.x = 2;
	}
		

	if (dwKey & KEY_SPACE )
	{
		basicAttack();
	}

	if (isJump && isGround)
		isJump = false;

	if (stepGround!=nullptr && !CollisionManager::RectCollision(Info, stepGround->GetTransform()))
		isGround = false;
	
	if (isGround)
	{
		speed.y = 0;
		CursorManager::GetInstance()->WriteBuffer(140, 3, (char*)"is ground");
	}
		

	move();

	

	//if (dwKey & KEY_ESCAPE)
		//Info.Position = Vector3(0.0f, 0.0f);

	if (PlayerState == ObjState::IDLE)
	{
		if (Info.Direction.x==1.0)
			currEnim = 0;
		else
			currEnim = 4;
	}
	else if (PlayerState == ObjState::MOVE)
	{
		if (Info.Direction.x == 1.0)
		{
			if (EnimTime + 300 >= GetTickCount64())
				currEnim = 1;
			else if (EnimTime + 600 <= GetTickCount64())
				EnimTime = GetTickCount64();
			else
				currEnim = 2;
		}
		else
		{
			if (EnimTime + 300 >= GetTickCount64())
				currEnim = 5;
			else if (EnimTime + 600 <= GetTickCount64())
				EnimTime = GetTickCount64();
			else
				currEnim = 6;
		}
		
	}
	   if (isJump)
	   {
		   if(Info.Direction.x==1.0f)
			   currEnim = 3;
		   else
			   currEnim=7;
	   }
		

	

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->RenderObj(Enim[currEnim],  (int)Info.Position.x, Info.Position.y);
	
}

void Player::Release()
{

}