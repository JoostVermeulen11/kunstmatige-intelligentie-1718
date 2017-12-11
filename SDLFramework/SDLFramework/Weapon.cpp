#include "Weapon.h"

Weapon::Weapon()
{
	texture = mApplication->LoadTexture("blaster.png");
	this->SetTexture(texture);
	this->SetSize(40, 40);
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
	std::cout << "Startpoint WEAPON X: " << startPoint->getX() << " Y: " << startPoint->getY() << std::endl;
	this->SetOffset(startPoint->getX(), startPoint->getY());
	this->currentVertex = startPoint;
}

Vertex * Weapon::currentPoint()
{
	return this->currentVertex;
}
