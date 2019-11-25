#include "edge.h"

edge::edge(vertex* start, vertex* end, float w) :start(start), end(end), weight(w)
{
	(this->start)->pushNeighbour(this->end,this);
}

edge::~edge()
{
}

vertex* edge::GetStart()
{
	return start;
}

vertex* edge::GetEnd()
{
	return end;
}

void edge::SetWeight(const float& w)
{
	weight = w;
}

float edge::GetWeight()
{
	return weight;
}
