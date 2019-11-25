#pragma once
#include "essential.h"
#include "edge.h"
class graph
{
public:
	graph(const size_t& n = 0, const bool& dir = false);
	~graph();
	void pushEdge(const size_t&, const size_t&, const float& weight = 1.0f);
	void AllocateVertex(const size_t&);
	vector<vertex*>& GetVertexList();
	vector<edge*>& GetEdgeList();
	vertex* GetVertexById(const size_t&);

	void BFS(const size_t&);
	void DFS(const size_t&);

	void Dijkstra(const size_t&);
private:
	void clearEdge();
	void clearVertex();
	void ResetVertexIsVisitedStat();
	void BFS(vertex*);
	void BFS_Recursion(vertex*);
	void Dijkstra_BFS(vertex*, vector<float>&);
	bool isDirected;
	vector<vertex*> V;
	vector<edge*> E;
};
