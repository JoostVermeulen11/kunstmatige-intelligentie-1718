#include "Rabbit.h"
#include <SDL_render.h>
#include <iostream>

Rabbit::Rabbit()
{
	texture = mApplication->LoadTexture("rabbit-2.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
	mApplication->AddRenderable(this);
}

Rabbit::~Rabbit()
{
	SDL_DestroyTexture(texture);
}

void Rabbit::Update(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime > 0.4) {
		this->SetOffset(currentVertex->getX(), currentVertex->getY());
	}
}

void Rabbit::setStartPoint(Vertex * startPoint)
{
	std::cout << "Startpoint KONIJN X: " << startPoint->getX() << " Y: " << startPoint->getY() << std::endl;
	this->SetOffset(startPoint->getX(), startPoint->getY());
	this->currentVertex = startPoint;
}

Vertex * Rabbit::currentPoint()
{
	return this->currentVertex;
}
