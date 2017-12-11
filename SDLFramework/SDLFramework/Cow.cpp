#include "cow.h"
#include <SDL_render.h>

Cow::Cow() {
	texture = mApplication->LoadTexture("lemmling_Cartoon_cow.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
	mApplication->AddRenderable(this);
}

Cow::~Cow() {
	SDL_DestroyTexture(texture);
}

void Cow::Update(float deltaTime) {
	totalTime += deltaTime;

	if (totalTime > 0.4) {
		if (!route_.empty()) {
			Edge* direction = this->route_.top();
			std::cout << "Edge weight:" << direction->getWeight() << ", edge color: " << direction->getColorName() << std::endl;
			route_.pop();
			this->currentVertex = direction->getOtherVertex(this->currentVertex);
		}
		this->SetOffset(currentVertex->getX(), currentVertex->getY());
	}
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
