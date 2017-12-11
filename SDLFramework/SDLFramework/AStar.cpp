#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

std::stack<Edge*> AStar::shortest_path(Vertex * start, Vertex * finish)
{
	openSet_.push_back(start);
	realCosts_[start] = 0;
	estimateCosts_[start] = sqrt(pow(start->getX() + finish->getX(), 2) + pow(start->getY() + finish->getY(), 2));
	while(!openSet_.empty())
	{
		auto itvector = openSet_.begin();
		Vertex* vertex = *itvector;
		int cost = realCosts_[vertex];
		for (auto it = itvector + 1; it != openSet_.end(); it++)
		{
			if (realCosts_[*it] < cost)
			{
				itvector = it;
				vertex = *itvector;
				cost = realCosts_[vertex];
			}
		}
		openSet_.erase(itvector);
		CheckEdges(vertex, finish);
		closedSet_.push_back(vertex);
		if (vertex == finish)
			break;
	}
	return CalculateShortestPath(start, finish);
}

void AStar::CheckEdges(Vertex * vertex, Vertex * finish)
{
	std::vector<Edge*> edges = vertex->getConnectedEgdes();
	for each(Edge* edge in edges)
	{
		Vertex* otherVertex = edge->getOtherVertex(vertex);
		int cost = realCosts_[vertex] + edge->getWeight();
		if (find(closedSet_.begin(), closedSet_.end(), otherVertex) == closedSet_.end())
		{
			if (find(openSet_.begin(), openSet_.end(), otherVertex) != openSet_.end())
			{
				if (realCosts_[otherVertex] > cost)
				{
					realCosts_[otherVertex] = cost;
					shortReverse_[otherVertex] = edge;
				}
			}
			else
			{
				realCosts_[otherVertex] = cost;
				shortReverse_[otherVertex] = edge;
				estimateCosts_[otherVertex] = sqrt(pow(otherVertex->getX() + finish->getX(), 2) + pow(otherVertex->getY() + finish->getY(), 2));
				openSet_.push_back(otherVertex);
			}
		}
	}
}

std::stack<Edge*> AStar::CalculateShortestPath(Vertex * start, Vertex * finish)
{
	std::stack<Edge*> shortPath;
	Vertex* findVertex = finish;
	while (findVertex != start)
	{
		Edge* edge = shortReverse_[findVertex];
		shortPath.push(edge);
		findVertex = edge->getOtherVertex(findVertex);

	}
	return shortPath;
}
