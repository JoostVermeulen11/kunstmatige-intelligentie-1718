#pragma once
#include "IGameObject.h"
#include "Vertex.h"
#include <iostream>

class Weapon : public IGameObject {
public:
	Weapon();
	~Weapon();
	void Update(float deltaTime);
	void setStartPoint(Vertex *startPoint);
	Vertex* currentPoint();
	Vertex* currentVertex;
private:
	SDL_Texture *texture;
	float totalTime;
};

