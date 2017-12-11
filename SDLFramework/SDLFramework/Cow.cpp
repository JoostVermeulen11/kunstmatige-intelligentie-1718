#include "cow.h"
#include <SDL_render.h>

Cow::Cow() {
	texture = mApplication->LoadTexture("lemmling_Cartoon_cow.png");
	this->SetTexture(texture);
	this->SetSize(40, 40);
	mApplication->AddRenderable(this);

	//when the cow is created, he has no pill yet
	this->hasPill = false;
}

Cow::~Cow() {
	SDL_DestroyTexture(texture);
}

void Cow::Update(float deltaTime) {
	totalTime += deltaTime;

	//if (!route_.empty()) {
	//	Edge* direction = this->route_.top();
	//	std::cout << "Edge weight:" << direction->getWeight() << ", edge color: " << direction->getColorName() << std::endl;
	//	route_.pop();
	//	this->currentVertex = direction->getOtherVertex(this->currentVertex);
	//}
	//this->SetOffset(currentVertex->getX(), currentVertex->getY());
	
	if (totalTime > 0.4) {
		currentState->Execute(this);
		totalTime = 0;
	}
}

void Cow::ChangeState(IState * newState)
{
	//exit the current state
	if(this->currentState != nullptr)
		this->currentState->Exit(this);
	//set new current state
	this->currentState = newState;
	//enter the new current state
	this->currentState->Enter(this);
}

void Cow::setStartPoint(Vertex * startPoint)
{
	std::cout << "Startpoint KOE X: " << startPoint->getX() << " Y: " << startPoint->getY() << std::endl;
	this->SetOffset(startPoint->getX(), startPoint->getY());
	this->currentVertex = startPoint;
}

Vertex* Cow::currentPoint()
{
	return this->currentVertex;
}

void Cow::findRabbit(Vertex * position)
{
	AStar astar;
	route_ = astar.shortest_path(this->currentVertex, position);
}

void Cow::moveToRabbit(Vertex * position)
{
	this->SetOffset(position->getX(), position->getY());
	this->currentVertex = position;
}

void Cow::Wander()
{
	this->currentVertex = this->currentVertex->Move();
	this->SetOffset(currentVertex->getX(), currentVertex->getY());


}

bool Cow::HasPill()
{
	return this->hasPill;
}
