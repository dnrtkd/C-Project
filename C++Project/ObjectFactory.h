#pragma once
#include "Headers.h"
#include"Object.h"
#include"ObjectManager.h"
#include "Worker.h"
#include "Ground.h"
#include "MoveTeleport.h"

class ObjectFactory
{
public:
	static Object* CreateObject(Vector3 _position,string mapN,string monN)
	{
		Object* pObject = nullptr;
		if (monN == "Worker")
			pObject = new Worker;
		
		pObject->Start();
		pObject->SetPosition(_position);

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

		return pObject;
	}
	static Object* CreateGround(Vector3 _position, string mapN,int sizeW,int sizeH)
	{
		Object* pObject = new Ground;

		pObject->Start();
		pObject->SetPosition(_position);
		dynamic_cast<Ground*>(pObject)->setSize(sizeW, sizeH);

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

		return pObject;
	}
	static Object* CreateTeleport(Vector3 _position, string mapN, string NextMap)
	{
		Object* pObject = new MoveTeleport;
		dynamic_cast<MoveTeleport*>(pObject)->setMapName(NextMap);

		pObject->Start();
		pObject->SetPosition(_position);
	

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

		return pObject;
	}
};