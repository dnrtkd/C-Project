#include "BegginerHunt.h"
#include "Ground.h"
#include "ObjectFactory.h"

void BegginerHunt::Start()
{
	 ObjectFactory::CreateGround(Vector3(0, 95), MapName, 100, 5);
	 ObjectFactory::CreateGround(Vector3(100, 95), MapName, 100, 5);

	 ObjectFactory::CreateGround(Vector3(50, 85), MapName, 50, 5);
	 ObjectFactory::CreateGround(Vector3(50, 75), MapName, 50, 5);
	 ObjectFactory::CreateGround(Vector3(50, 65), MapName, 50, 5);
	 ObjectFactory::CreateGround(Vector3(50, 55), MapName, 50, 5);

	 ObjectFactory::CreateGround(Vector3(35, 90), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 80), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 70), MapName, 10, 5);
	 ObjectFactory::CreateGround(Vector3(35, 60), MapName, 10, 5);
	 
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
