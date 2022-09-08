#pragma once
#include "Headers.h"
#include"Object.h"

class ObjectFactory
{
public:
	template<typename T>
	static Object* CreateObject(Vector3 _position)
	{
		Object* pObject = new T;
		pObject->Start();
		pObject->SetPosition(_position);

		return pObject;
	}
};