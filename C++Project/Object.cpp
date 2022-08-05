#include "Object.h"

Object::Object() : Target(nullptr)
{
	Info.Direction = { 0,0 };
	Info.Position = { 0,0 };
	Info.Rotation = { 0,0 };
	Info.Scale = { 0,0 };
}

Object::~Object()
{
}