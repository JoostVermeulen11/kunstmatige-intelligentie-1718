#include "Vertex.h"



Vertex::Vertex(int xPos, int yPos) : xPos{ xPos }, yPos{yPos}
{
}

Vertex::~Vertex()
{
}

int Vertex::getX()
{
	return this->xPos;
}

int Vertex::getY()
{
	return this->yPos;
}

void Vertex::attachEdge(Edge * edge)
{
	this->connectedEdges.push_back(edge);
}

std::vector<Edge*> Vertex::getConnectedEgdes()
{
	return this->connectedEdges;
}
