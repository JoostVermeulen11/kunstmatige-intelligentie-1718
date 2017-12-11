#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <map>
#include <stack>
#include <iostream>

class AStar
{
private:
	std::map<Vertex*, int> realCosts_;
	std::map<Vertex*, int> estimateCosts_;
	std::map<Vertex*, Edge*> shortReverse_;
	std::vector<Vertex*> openSet_;
	std::vector<Vertex*> closedSet_;

	void CheckEdges(Vertex* vertex, Vertex* end);
	std::stack<Edge*> CalculateShortestPath(Vertex* start, Vertex* end);
public:
	AStar();
	~AStar();
	std::stack<Edge*> shortest_path(Vertex* start, Vertex* finish);
};

