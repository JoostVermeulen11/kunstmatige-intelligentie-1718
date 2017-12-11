#include "Weapon.h"

Weapon::Weapon()
{
	texture = mApplication->LoadTexture("blaster.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
	mApplication->AddRenderable(this);
}

Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{
}

void Weapon::setStartPoint(Vertex * startPoint)
{
}

Vertex * Weapon::currentPoint()
{
	return nullptr;
}
