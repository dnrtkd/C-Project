#pragma once
#include "Headers.h"
#include"Object.h"
#include"ObjectManager.h"

class ObjectFactory
{
public:
	template<typename T>
	static Object* CreateObject(Vector3 _position)
	{
		Object* pObject = new T;
		pObject->Start();
		pObject->SetPosition(_position);

		ObjectManager::GetInstance()->AddObject()

		return pObject;
	}
};