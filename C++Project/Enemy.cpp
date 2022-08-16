#include "Enemy.h"
#include "ObjectManager.h"

void Enemy::move(float delay)
{
	
	if (MoveTime + 1000 * delay < GetTickCount64() &&
		!(eState == ObjState::hit))
	{
		MoveTime = GetTickCount64();

		srand(time(0)*(int)this);
		int ran = rand() % 3;


		if (ran == 0)
		{
			eState = ObjState::IDLE;
			speed.x = 0.0f;
		}
		else if (ran == 1)
		{
			eState = ObjState::MOVE;
			speed.x = -1;
		}
		else if (ran == 2)
		{
			eState = ObjState::MOVE;
			speed.x = 1;
		}		
	}

	// 밟고 잇는 땅의 범위 안에서만 움직이도록함
	if (_isGround)
	{
		float gLPosiX = stepGround->GetPosition().x;
		float gRposiX = gLPosiX + stepGround->GetTransform().Scale.x;

		if (gLPosiX + 1 >= Info.Position.x ||
			gRposiX - 1 <= Info.Position.x + Info.Scale.x)
		{
			if((gLPosiX + 1 >= Info.Position.x && speed.x==-1) ||
				(gRposiX - 1 <= Info.Position.x + Info.Scale.x &&
					speed.x == 1))
				speed.x=0;
		}
		//땅을 밟고 있을 때 y의 스피드는 0
		speed.y = 0;
		Info.Position.y=stepGround->GetPosition().y - Info.Scale.y + 1;
	}
	else
	speed.y += gravityAccel;

	if (eState == ObjState::hit)
		Info.Position += Vector3(0, speed.y);
	else
	Info.Position += Vector3(speed.x, speed.y);
}

void Enemy::isGround()
{
	if (stepGround != nullptr && 
		CollisionManager::RectCollision(Info, stepGround->GetTransform()) && 
		stepGround->GetPosition().y>Info.Position.y)
		_isGround = true;
	else
		_isGround = false;
}



Enemy::Enemy():gravityAccel(0.3)
{
	_isGround = false;
	EnimTime = GetTickCount64();
	eState = ObjState::IDLE;
	currEnim = 0;
	gravityAccel = 0.3;
	speed = { 0,0 };
	stepGround = nullptr;
	maxHp = 0;
	MoveTime = GetTickCount64();
	hitTime = GetTickCount64();
}

Enemy::~Enemy()
{
}

