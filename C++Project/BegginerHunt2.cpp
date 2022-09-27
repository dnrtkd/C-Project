#include "BegginerHunt2.h"

void BegginerHunt2::Start()
{
	Object* temp = nullptr;
	// ∏« πÿ ∂•
	ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);
	
	temp=ObjectFactory::CreateGround(Vector3(30, 85), MapName, 80, 2);
	dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Stump");
	temp=ObjectFactory::CreateGround(Vector3(30, 75), MapName, 80, 2);
	dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Stump");
	temp=ObjectFactory::CreateGround(Vector3(30, 65), MapName, 80, 2);
	dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Stump");
	temp=ObjectFactory::CreateGround(Vector3(30, 55), MapName,80, 2);
	dynamic_cast<Ground*>(temp)->setResZone(10.0f, 6, "Stump");

	ObjectFactory::CreateGround(Vector3(85, 90), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 80), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 70), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 60), MapName, 10, 5);

	ObjectFactory::CreateTeleport(Vector3(5, 90), MapName, "BegginerHunt", Vector3(180, 90));

	ObjectFactory::CreateObject(Vector3(60, 5), MapName, "Moon");
	
	ObjectFactory::CreateObject(Vector3(-5, 14), MapName, "Tree");
	ObjectFactory::CreateObject(Vector3(35, 15), MapName, "Tree");
	ObjectFactory::CreateObject(Vector3(85, 16), MapName, "Tree");
	ObjectFactory::CreateObject(Vector3(130, 13), MapName, "Tree");

	ObjectFactory::CreateObject(Vector3(-5, 13), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(30, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(70, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(150, 12), MapName, "Cloud");
	ObjectFactory::CreateObject(Vector3(180, 12), MapName, "Cloud");
}

int BegginerHunt2::Update()
{
	return 0;
}

void BegginerHunt2::Render()
{
}

void BegginerHunt2::Release()
{
}

BegginerHunt2::BegginerHunt2()
{
	korName = "√ ∫∏¿⁄ ªÁ≥…≈Õ2";
	MapName = "BegginerHunt2";
}

BegginerHunt2::~BegginerHunt2()
{
}
