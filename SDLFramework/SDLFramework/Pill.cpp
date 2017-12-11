#include "Pill.h"

Pill::Pill()
{
	texture = mApplication->LoadTexture("pill_2.png");
	this->SetTexture(texture);
	this->SetSize(40, 40);
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
	std::cout << "Startpoint PILL X: " << startPoint->getX() << " Y: " << startPoint->getY() << std::endl;
	this->SetOffset(startPoint->getX(), startPoint->getY());
	this->currentVertex = startPoint;
}

Vertex * Pill::currentPoint()
{
	return this->currentVertex;
}
