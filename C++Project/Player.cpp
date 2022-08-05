#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "OutputManager.h"


Player::Player()
{
	Enim = new Texture[8];
	EnimTime = GetTickCount64();
	PlayerState = ObjState::IDLE;
	currEnim = 0;
	gravityAccel = -0.3;
	speed = { 0,0 };
	isJump = false;
	isGround = false;
}

Player::~Player()
{
}

void Player::move()
{
	speed.y += gravityAccel;

	Info.Position += Vector3(speed.x * Info.Direction.x, speed.y * Info.Direction.y);
}

void Player::Start()
{
	Info.Position = Vector3(74.0f, 35.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(strlen(" 0 "), 5.0f);
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
		Info.Position.y--;

	if (dwKey & KEY_DOWN)
	{
		Info.Position.y++;
	}
		
	

	if (dwKey & KEY_LEFT)
	{
		PlayerState = ObjState::MOVE;
		Info.Direction.x = -1;
		speed.x = 2;
	}
		
	if (dwKey & KEY_RIGHT)
	{
		PlayerState = ObjState::MOVE;
		Info.Direction.x = 1;
		speed.x = 2;
	}
		

	if (dwKey & KEY_SPACE )
	{
		if (!isJump && isGround)
		{
			isJump = true;
			isGround = false;
			Info.Direction.y = -1;
			speed.y = 2.0;
		}
	}

	move();

	if (isJump && isGround)
	{
		isJump = false;
		Info.Direction.y = 0;
	}
	
	
		

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
	
	OutputManager::OnDrawText(Enim[currEnim], Info.Scale.y, Info.Position.x, Info.Position.y);
}

void Player::Release()
{

}