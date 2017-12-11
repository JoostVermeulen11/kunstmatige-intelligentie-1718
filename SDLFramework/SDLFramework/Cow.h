#pragma once

#include "IGameObject.h"
#include "BaseGameEntity.h"
#include "IState.h"
#include "Vertex.h"
#include "AStar.h"
#include <stack>
#include <iostream>
#include <string>

class IState;

class Cow : public IGameObject {
public:
	Cow();
	~Cow();
	void Update(float deltaTime);
	void ChangeState(IState* newState);
	void setStartPoint(Vertex *startPoint);
	Vertex* currentPoint();
	Vertex* currentVertex;
	void findRabbit(Vertex* vertex);
	void moveToRabbit(Vertex* position);
	void Wander();
	bool HasPill();
private:
	SDL_Texture *texture;
	float totalTime;
	std::stack<Edge*> route_;
	IState* currentState;
	bool hasPill;
};