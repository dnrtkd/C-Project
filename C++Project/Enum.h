#pragma once

// enum class : 열거형, [ 상수 & 정수 ], namespace 로 접근
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

enum class MonName
{
	Worker,
	solider
};

enum class MapName
{
	viliage,
	startHunt
};