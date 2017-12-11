#include "Pill.h"

Pill::Pill()
{
	texture = mApplication->LoadTexture("pill_2.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
	mApplication->AddRenderable(this);
}

Pill::~Pill()
{
}

void Pill::Update(float deltaTime)
{
}

void Pill::setStartPoint(Vertex * startPoint)
{
}

Vertex * Pill::currentPoint()
{
	return nullptr;
}
