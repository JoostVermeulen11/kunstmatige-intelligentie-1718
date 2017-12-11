#pragma once
#include "IGameObject.h"
#include "Vertex.h"


class Pill : public IGameObject {
public:
	Pill();
	~Pill();
	void Update(float deltaTime);
	void setStartPoint(Vertex *startPoint);
	Vertex* currentPoint();
	Vertex* currentVertex;
private:
	SDL_Texture *texture;
	float totalTime;
};

