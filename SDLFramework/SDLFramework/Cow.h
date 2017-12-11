#pragma once

#include "IGameObject.h"
#include "Vertex.h"
#include "AStar.h"
#include <stack>
#include <iostream>
#include <string>

class Cow : public IGameObject {
public:
	Cow();
	~Cow();
	void Update(float deltaTime);
	void setStartPoint(Vertex *startPoint);
	Vertex* currentPoint();
	Vertex* currentVertex;
	void findRabbit(Vertex* vertex);
	void moveToRabbit(Vertex* position);
private:
	SDL_Texture *texture;
	float totalTime;
	std::stack<Edge*> route_;
};