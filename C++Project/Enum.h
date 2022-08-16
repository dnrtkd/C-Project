#pragma once

// enum class : ������, [ ��� & ���� ], namespace �� ����
enum class SCENEID
{
	LOGO,
	MENU,
	STAGE,
	EXIT,
};

enum class ObjState
{
	IDLE,
	MOVE,
	DASH,
	hit,
	ATTACK,
	JUMP,
	DEAD
};

enum class ObjTag
{
	Ground,
	Enemy,
	Player
};