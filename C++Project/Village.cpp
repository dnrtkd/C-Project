#include "Village.h"

void Village::Start()
{
	ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);
	
	ObjectFactory::CreateGround(Vector3(50, 90), MapName, 100, 5);
	ObjectFactory::CreateGround(Vector3(55, 85), MapName, 90, 5);
	ObjectFactory::CreateGround(Vector3(60, 80), MapName, 80, 5);
	
	ObjectFactory::CreateTeleport(Vector3(185, 90), MapName, "BegginerHunt", Vector3(5, 90));

	//ObjectFactory::CreateObject(Vector3(30, 2), MapName, "Tree");
	
	ObjectFactory::CreateObject(Vector3(60,5 ), MapName, "Moon");

	ObjectFactory::CreateObject(Vector3(-5, 13), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(30, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(70, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(150, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(180, 12), MapName, "Cloud");

}

int Village::Update()
{
	return 0;
}

void Village::Render()
{
}

void Village::Release()
{
}

Village::Village()
{
	korName = "초보자 마을";
	MapName = "Village";
}

Village::~Village()
{
}
