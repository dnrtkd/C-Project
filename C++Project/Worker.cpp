#include "Worker.h"

void Worker::Start()
{
	Enim[0].texture[0] = "-----";
	Enim[0].texture[1] = "| + |";
	Enim[0].texture[2] = "|   |";
	Enim[0].texture[3] = "-----";
	
}

int Worker::Update()
{
	return 0;
}

void Worker::Render()
{
}

void Worker::Release()
{
}

Worker::Worker()
{
	Enim = new Texture[6];
}

Worker::~Worker()
{
}
