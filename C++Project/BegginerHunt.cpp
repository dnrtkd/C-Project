#include "BegginerHunt.h"

void BegginerHunt::Start()
{
	Object* temp = nullptr;

	 ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	 ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);

	 temp=ObjectFactory::CreateGround(Vector3(50, 85), MapName, 70, 3);
	 dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Worker");
	 temp=ObjectFactory::CreateGround(Vector3(50, 75), MapName, 70, 3);
	 dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Worker");
	 temp=ObjectFactory::CreateGround(Vector3(50, 65), MapName, 70, 3);
	 dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Worker");
	 temp= ObjectFactory::CreateGround(Vector3(50, 55), MapName, 70, 3);
	 dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Worker");

	 ObjectFactory::CreateGround(Vector3(35, 90), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 80), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 70), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 60), MapName, 10, 5);

	 // 텔레포트
	 ObjectFactory::CreateTeleport(Vector3(180, 90), MapName, "BegginerHunt2",Vector3(5,90));
	 ObjectFactory::CreateTeleport(Vector3(5, 90), MapName, "Village", Vector3(185, 90));
	 ObjectFactory::CreateObject(Vector3(60, 5), MapName, "Moon");
	 //ObjectFactory::CreateObject(Vector3(0, 2), MapName, "MapBgi");
	 ObjectFactory::CreateObject(Vector3(-5, 14), MapName, "Tree");
	 ObjectFactory::CreateObject(Vector3(35, 15), MapName, "Tree");
	 ObjectFactory::CreateObject(Vector3(85, 16), MapName, "Tree");
	 ObjectFactory::CreateObject(Vector3(130,13), MapName, "Tree");

	 ObjectFactory::CreateObject(Vector3(-5,13), MapName, "Cloud");
	 ObjectFactory::CreateObject(Vector3(30,12), MapName, "Cloud");
	 ObjectFactory::CreateObject(Vector3(70,12), MapName, "Cloud");
	 ObjectFactory::CreateObject(Vector3(150,12), MapName, "Cloud");
	 ObjectFactory::CreateObject(Vector3(180,12), MapName, "Cloud");
	 
	 
}

int BegginerHunt::Update()
{
	return 0;
}

void BegginerHunt::Render()
{
}

void BegginerHunt::Release()
{
}

BegginerHunt::BegginerHunt()
{
	korName = "초보자 사냥터";
	MapName = "BegginerHunt";
}

BegginerHunt::~BegginerHunt()
{
}
