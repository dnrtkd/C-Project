#include "BegginerHunt.h"

void BegginerHunt::Start()
{
	Object* temp = nullptr;

	 ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	 ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);

	 ObjectFactory::CreateGround(Vector3(50, 85), MapName, 50, 5);
	 temp=ObjectFactory::CreateGround(Vector3(50, 75), MapName, 50, 5);
	 dynamic_cast<Ground*>(temp)->setResZone(3, 4, "Worker");
	 temp=ObjectFactory::CreateGround(Vector3(50, 65), MapName, 50, 5);
	 dynamic_cast<Ground*>(temp)->setResZone(3, 4, "Worker");
	 temp= ObjectFactory::CreateGround(Vector3(50, 55), MapName, 50, 5);
	 dynamic_cast<Ground*>(temp)->setResZone(3, 4, "Worker");

	 ObjectFactory::CreateGround(Vector3(35, 90), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 80), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 70), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 60), MapName, 10, 5);

	 // �ڷ���Ʈ
	 ObjectFactory::CreateTeleport(Vector3(180, 90), MapName, "BegginerHunt2",Vector3(5,90));
	 ObjectFactory::CreateTeleport(Vector3(5, 90), MapName, "Village", Vector3(185, 90));

	 ObjectFactory::CreateObject(Vector3(0, 2), MapName, "MapBgi");
	 ObjectFactory::CreateObject(Vector3(-2, 14), MapName, "Tree");
	 ObjectFactory::CreateObject(Vector3(30, 15), MapName, "Tree");
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
	korName = "�ʺ��� �����";
	MapName = "BegginerHunt";
}

BegginerHunt::~BegginerHunt()
{
}
