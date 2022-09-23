#pragma once
#include "Headers.h"
#include"Object.h"
#include"ObjectManager.h"
#include "Worker.h"
#include "Ground.h"
#include "MoveTeleport.h"
#include "Bullet.h"
#include "Cloud.h"
#include "Tree.h"
#include "Damage.h"
#include "MapBgi.h"
#include "Skill1Effect.h"
#include "Skill1Bullet.h"
class ObjectFactory
{
public:
	static Object* CreateObject(Vector3 _position,string mapN,string monN)
	{
		Object* pObject = nullptr;
		if (monN == "Worker")
			pObject = new Worker;
		if (monN == "Cloud")
			pObject = new Cloud;
		if (monN == "Tree")
			pObject = new Tree;
		if (monN == "Damage")
			pObject = new Damage;
		if (monN == "MapBgi")
			pObject = new MapBgi;
		if (monN == "Skill1Effect")
			pObject = new Skill1Effect;
		
		pObject->Start();
		pObject->SetPosition(_position);

		ObjectManager::GetInstance()->AddObject(pObject, mapN);

		return pObject;
	}
	static Object* CreateBullet(Vector3 _position, string mapN,float damage,Vector3 _direction,string bulletName="defalt")
	{
		Object* pObject = nullptr;
		if (bulletName == "defalt")
			 pObject = new Bullet;
		else if (bulletName == "Skill1")
			 pObject = new Skill1Bullet;

		dynamic_cast<Bullet*>(pObject)->setDamage(damage);
		pObject->Start();
		pObject->SetDirection(_direction.x, 0);
		if (_direction.x == 1)
			pObject->SetPosition(_position.x + 6, _position.y + 2);
		else
			pObject->SetPosition(_position.x - 2, _position.y + 2);

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