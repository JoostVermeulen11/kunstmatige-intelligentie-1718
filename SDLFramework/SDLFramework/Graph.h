#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "FWApplication.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Pill.h"
#include "Weapon.h"
#include "AStar.h"
#include "CowWanderingState.h"

#include <time.h>
#include <list>

class Graph
{
private:
	const int WEIGHT_NORMAL = 1000;
	const int WEIGHT_WATER = 2000;
	const int WEIGHT_LANE = 3000;

	std::vector<Edge> edges;
	std::vector<Vertex*> vertexes;
	AStar* AStar;

	FWApplication* application;
public:
	Graph();
	~Graph();
	void addVertex(Vertex* vertex);
	void addEdge(Edge* edge);
	void createGraph();
	void draw();
	void shortestPath();
	Vertex* getRandomVertex(); 

	Cow* cow;
	Rabbit* rabbit;
	Pill* pill;
	Weapon* weapon;
};

