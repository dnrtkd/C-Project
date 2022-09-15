#pragma once
#include "Headers.h"
#include"Object.h"
#include"ObjectManager.h"
#include "Worker.h"
#include "Ground.h"
#include "MoveTeleport.h"
#include "Bullet.h"

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
	static Object* CreateBullet(Vector3 _position, string mapN,float damage,Vector3 _direction)
	{
		Object* pObject = new Bullet;

		dynamic_cast<Bullet*>(pObject)->setDamage(damage);
		pObject->Start();
		pObject->SetDirection(_direction.x, 0);
		if (_direction.x == 1)
			pObject->SetPosition(_position.x + 6, _position.y + 2);
		else
			pObject->SetPosition(_position.x - 1, _position.y + 2);

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

	

		//			Vector3 vec = pPlayer->GetPosition();
		//
		//			pBullet[i]->SetDirection(pPlayer->GetTransform().Direction.x,0);
		//			dynamic_cast<Bullet*> (pBullet[i])->setDamage(dynamic_cast<Player*>(pPlayer)->getDamage());
		//
		//			if(pPlayer->GetTransform().Direction.x==1)
		//				pBullet[i]->SetPosition(vec.x+6,vec.y+2);
		//			else
		//				pBullet[i]->SetPosition(vec.x -1, vec.y + 2);
		//			break;




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
	static Object* CreateTeleport(Vector3 _position, string mapN, string NextMap ,Vector3 NextResPawn)
	{
		Object* pObject = new MoveTeleport;
		dynamic_cast<MoveTeleport*>(pObject)->setMapName(NextMap);
		dynamic_cast<MoveTeleport*>(pObject)->setNextPosi(NextResPawn);
		pObject->Start();
		pObject->SetPosition(_position);
	

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

		return pObject;
	}
};