#include "Edge.h"
#include "Vertex.h"


Edge::Edge(Vertex * vertexStart, Vertex * vertexEnd, int weight) : vertexStart{ vertexStart }, vertexEnd{ vertexEnd }, weight{ weight }
{
	if (weight == 1000) {
		//green
		this->edgeColor = Color(46, 204, 113, 255);
		this->colorName = "green";
	}
	else if (weight == 2000) {
		//yellow
		this->edgeColor = Color(241, 196, 15, 255);
		this->colorName = "yellow";
	}
	else if (weight == 3000) {
		//red
		this->edgeColor = Color(231, 76, 60, 255);
		this->colorName = "red";
	}
}

Edge::~Edge()
{
}

Vertex* Edge::getVertexEnd()
{
	return this->vertexEnd;
}

Vertex* Edge::getVertexStart()
{
	return this->vertexStart;
}

Vertex * Edge::getOtherVertex(const Vertex * vertex) const
{
	if (vertex == this->vertexStart)
		return this->vertexEnd;
	return this->vertexStart;
}

Vertex* Edge::Move(Vertex* vertex)
{
	if (this->vertexStart == vertex)
		return this->vertexEnd;
	return this->vertexStart;
}

int Edge::getWeight() const
{
	return this->weight;
}

std::string Edge::getColorName() const
{
	return this->colorName;
}

Color Edge::getEdgeColor()
{
	return edgeColor;
}
