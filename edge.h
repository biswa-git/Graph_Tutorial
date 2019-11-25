#pragma once
#include "essential.h"
#include "vertex.h"

class vertex;
class edge
{
public:
	edge(vertex* s = nullptr, vertex* e = nullptr, float w = 1.0f);
	~edge();
	vertex* GetStart();
	vertex* GetEnd();
	void SetWeight(const float&);
	float GetWeight();
private:
	vertex* start;
	vertex* end;
	float weight;
};
