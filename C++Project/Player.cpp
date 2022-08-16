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
		ObjectManager::GetInstance()->CreateObject();
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
	delay = 0.2f; //0.2ÃÊ
	hp = 50.0f;
	damage = 5.0f;
	fireTime = GetTickCount64();
}

Player::~Player()
{

}

void Player::move()
{

	speed.y += gravityAccel;

	if (Info.Position.x - CursorManager::GetInstance()->getScrPosiX() > 90)
		CursorManager::GetInstance()->addScreenPosiX(speed.x);

	Info.Position += Vector3(speed.x , speed.y );
}

void Player::skill_1()
{
	
}

void Player::Start()
{
	Info.Position = Vector3(50.0f, 30.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(strlen(" 0  "), 5.0f);
	Info.Direction = Vector3(0.0f, 0.0f);
	Target = nullptr;

	Enim[0].texture[0] = " 0  ";
	Enim[0].texture[1] = "(|o ";
	Enim[0].texture[2] = " ^  ";
	Enim[0].texture[3] = "_.._";
	Enim[0].texture[4] = "    ";

	Enim[1].texture[0] = " 0  ";
	Enim[1].texture[1] = "(|o ";
	Enim[1].texture[2] = " ^  ";
	Enim[1].texture[3] = "- ._";
	Enim[1].texture[4] = "    ";

	Enim[2].texture[0] = " 0  ";
	Enim[2].texture[1] = "(|o ";
	Enim[2].texture[2] = " ^  ";
	Enim[2].texture[3] = "_. -";
	Enim[2].texture[4] = "    ";
	
	Enim[3].texture[0] = " 0  ";
	Enim[3].texture[1] = "(|o ";
	Enim[3].texture[2] = "|^| ";
	Enim[3].texture[3] = "    ";
	Enim[3].texture[4] = "    ";

	Enim[4].texture[0] = " 0  ";
	Enim[4].texture[1] = "o|) ";
	Enim[4].texture[2] = " ^  ";
	Enim[4].texture[3] = "_.._";
	Enim[4].texture[4] = "    ";

	Enim[5].texture[0] = " 0  ";
	Enim[5].texture[1] = "o|) ";
	Enim[5].texture[2] = " ^  ";
	Enim[5].texture[3] = "_. -";
	Enim[5].texture[4] = "    ";

	Enim[6].texture[0] = " 0  ";
	Enim[6].texture[1] = "o|) ";
	Enim[6].texture[2] = " ^  ";
	Enim[6].texture[3] = "- ._";
	Enim[6].texture[4] = "    ";

	Enim[7].texture[0] = " 0  ";
	Enim[7].texture[1] = "o|) ";
	Enim[7].texture[2] = "|^| ";
	Enim[7].texture[3] = "    ";
	Enim[7].texture[4] = "    ";
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	PlayerState = ObjState::IDLE;
	speed.x = 0;
	
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
		CursorManager::GetInstance()->WriteBuffer(142, 3, (char*)"is ground");
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
	CursorManager::GetInstance()->RenderObj(Enim[currEnim], Info.Scale.y, (int)Info.Scale.x, (int)Info.Position.x, Info.Position.y);
	
}

void Player::Release()
{

}