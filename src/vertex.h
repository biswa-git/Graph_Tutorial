#pragma once
#include "essential.h"
#include "edge.h"

class edge;
class vertex
{
public:
	static size_t vertexcount;
	vertex();
	~vertex();
	void pushNeighbour(vertex*, edge*);
	map<vertex*, edge*>& GetNeighbour();
	size_t GetVertexId();
	void SetIsVisitedStat(const bool&);
	bool GetIsVisitedStat();


private:
	map<vertex*,edge*> neighbour;
	size_t vertexId;
	bool isVisited;

};
