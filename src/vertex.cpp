#include"vertex.h"

size_t vertex::vertexcount = 0;

vertex::vertex() : vertexId(vertexcount), isVisited(false)
{
	++vertexcount;
}

vertex::~vertex()
{
	--vertexcount;
}

void vertex::pushNeighbour(vertex* V, edge* E)
{
	this->neighbour.insert(pair<vertex*, edge*>(V, E));
}

map<vertex*, edge*>& vertex::GetNeighbour()
{
	return this->neighbour;
}

size_t vertex::GetVertexId()
{
	return this->vertexId;
}

void vertex::SetIsVisitedStat(const bool& stat)
{
	this->isVisited = stat;
}

bool vertex::GetIsVisitedStat()
{
	return this->isVisited;
}
