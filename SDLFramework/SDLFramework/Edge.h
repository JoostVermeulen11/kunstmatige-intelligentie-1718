#pragma once
#include "FWApplication.h"

class Vertex;

class Edge
{
private:
	Vertex* vertexStart;
	Vertex* vertexEnd;
	int weight;
	int distance;
	std::string colorName;
	Color edgeColor;
public:
	Edge(Vertex* vertexStart, Vertex* vertexEnd, const int weight);
	~Edge();
	Vertex* getVertexEnd();
	Vertex* getVertexStart();
	Vertex* getOtherVertex(const Vertex* vertex) const;
	int getWeight() const;
	std::string getColorName() const;
	Color getEdgeColor();
};

