#pragma once
#include <vector>
#include "RandomGenerator.h"
#include "Edge.h"

class Vertex
{
private:
	int xPos, yPos;
	std::vector<Edge*> connectedEdges;
public:
	Vertex(int xPos, int yPos);
	~Vertex();
	int getX();
	int getY();

	void attachEdge(Edge* edge);
	std::vector<Edge*> getConnectedEgdes();
	Vertex* Move();
};

