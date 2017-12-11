#pragma once
#include "IGameObject.h"
#include "Vertex.h"

class Rabbit : public IGameObject
{
public:
	Rabbit();
	~Rabbit();
	void Update(float deltaTime);
	void setStartPoint(Vertex *startPoint);
	Vertex* currentPoint();
	Vertex* currentVertex;
private:
	SDL_Texture *texture;	
	float totalTime;
};

