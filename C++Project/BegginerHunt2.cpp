#include "BegginerHunt2.h"

void BegginerHunt2::Start()
{
	// ∏« πÿ ∂•
	ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);

	ObjectFactory::CreateGround(Vector3(30, 85), MapName, 50, 5);
	ObjectFactory::CreateGround(Vector3(30, 75), MapName, 50, 5);
	ObjectFactory::CreateGround(Vector3(30, 65), MapName, 50, 5);
	ObjectFactory::CreateGround(Vector3(30, 55), MapName, 50, 5);

	ObjectFactory::CreateGround(Vector3(85, 90), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 80), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 70), MapName, 10, 5);
	ObjectFactory::CreateGround(Vector3(85, 60), MapName, 10, 5);

	ObjectFactory::CreateTeleport(Vector3(5, 90), MapName, "BegginerHunt", Vector3(180, 90));
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
