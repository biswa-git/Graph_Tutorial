#include "graph.h"

graph::graph(const size_t& n, const bool& dir) : isDirected(dir)
{
	if (n > 0) AllocateVertex(n);
}

graph::~graph()
{
	size_t vertexSize = V.size();
	if (vertexSize > 0)
	{
		vector<vertex*>::iterator it;
		for (it = V.begin(); it != V.end(); ++it)
		{
			delete* it;
			*it = nullptr;
		}
	}

	size_t edgeSize = E.size();
	if (edgeSize > 0)
	{
		vector<edge*>::iterator it;
		for (it = E.begin(); it != E.end(); ++it)
		{
			delete* it;
			*it = nullptr;
		}
	}
}

void graph::pushEdge(const size_t& startVertexId, const size_t& endVertexId, const float& weight)
{
	size_t vertSize = V.size();
	if (startVertexId < vertSize && endVertexId < vertSize)
	{
		edge* edgeAddress = new edge(V[startVertexId], V[endVertexId], weight);
		E.push_back(edgeAddress);
		
		if (!isDirected)
		{
			edge* edgeAddress = new edge(V[endVertexId], V[startVertexId], weight);
			E.push_back(edgeAddress);
		}
	}
	else
	{
		//warning message
	}
}

void graph::AllocateVertex(const size_t& n)
{
	clearEdge();
	clearVertex();
	vertex::vertexcount = 0;
	V.resize(n);
	vector<vertex*>::iterator it;
	for (it = V.begin(); it != V.end(); ++it)
	{
		*it = new vertex();
	}
}

vector<vertex*>& graph::GetVertexList()
{
	return this->V;
}

vector<edge*>& graph::GetEdgeList()
{
	return this->E;
}

vertex* graph::GetVertexById(const size_t& vertexId)
{
	size_t size = V.size();
	if (size > vertexId)
	{
		return V[vertexId];
	}
	else
	{
		//THROW error message TRY CATCH
		cout << "invalid vertex id" << endl;
	}
}

void graph::clearEdge()
{
	size_t size = E.size();
	if (size > 0)
	{
		vector<edge*>::iterator it;
		for (it = E.begin(); it != E.end(); ++it)
		{
			delete* it;
			*it = nullptr;
		}
		E.clear();
	}
}

void graph::clearVertex()
{
	size_t size = V.size();
	if (size > 0)
	{
		vector<vertex*>::iterator it;
		for (it = V.begin(); it != V.end(); ++it)
		{
			delete* it;
			*it = nullptr;
		}
		V.clear();
	}
}

void graph::BFS(const size_t& vertexId)
{
	vertex* begin = V.at(vertexId);
	BFS_Recursion(begin);
	ResetVertexIsVisitedStat();
}

void graph::DFS(const size_t& vertexId)
{
	vertex* begin = V.at(vertexId);
	stack<vertex*> priorityQueue;
	priorityQueue.push(begin);

	while (!priorityQueue.empty())
	{
		vertex* presentVertex = priorityQueue.top();
		if (!(presentVertex->GetIsVisitedStat()))
			cout << "DFS visited: " << presentVertex->GetVertexId() << endl;
		presentVertex->SetIsVisitedStat(true);
		priorityQueue.pop();

		map<vertex*, edge*>& neighbour = presentVertex->GetNeighbour();

		map<vertex*, edge*>::iterator it;
		for (it = neighbour.begin(); it != neighbour.end(); ++it)
		{
			vertex* currentNeighbour = it->first;
			if (currentNeighbour->GetIsVisitedStat() != true)
			{
				priorityQueue.push(currentNeighbour);
			}
		}
	}
	ResetVertexIsVisitedStat();
}

void graph::ResetVertexIsVisitedStat()
{
	vector<vertex*>::iterator it;
	for (it = V.begin(); it != V.end(); ++it)
	{
		(*it)->SetIsVisitedStat(false);
	}
}

void graph::BFS(vertex* begin)
{
	BFS_Recursion(begin);
	ResetVertexIsVisitedStat();
}

void graph::BFS_Recursion(vertex* begin)
{
	begin->SetIsVisitedStat(true);
	cout << "BFS visited: " << begin->GetVertexId() << endl;
	map<vertex*, edge*>& neighbour = begin->GetNeighbour();

	map<vertex*, edge*>::iterator it;
	for (it = neighbour.begin(); it != neighbour.end(); ++it)
	{
		vertex* currentNeighbour = it->first;
		if (currentNeighbour->GetIsVisitedStat() != true)
		{
			BFS_Recursion(currentNeighbour);
		}
	}
}

void graph::Dijkstra(const size_t& vertexId)
{
	float inf = 0.0f;
	if (numeric_limits<float>::has_infinity)
	{
		inf = numeric_limits<float>::infinity();
	}
	else
	{
		//throw error
		cout << "Warninginf isn't defined!" << endl;
		inf = 99999.0f;
	}

	size_t size = this->V.size();
	vector<float> distArray;
	distArray.resize(size, static_cast<float>(inf));
	queue<vertex*> priorityQueue; //priorityQueue
	//	we will use isVisited bool to store the stat of if the dist is finalized or not

	vertex* begin = V[vertexId];
	map<vertex*,edge*>& neighbour = begin->GetNeighbour();

	// setting the distance of source vertex to zero
	distArray[begin->GetVertexId()] = 0.0f;

	map<vertex*, edge*>::iterator it;
	for (it = neighbour.begin(); it != neighbour.end(); ++it)
	{
		size_t idOfCurrentNode = (it->first)->GetVertexId();
		distArray[idOfCurrentNode] = (it->second)->GetWeight();
		(it->first)->SetIsVisitedStat(true);
		priorityQueue.push(it->first);
	}

	while (!priorityQueue.empty())
	{
		vertex* present = priorityQueue.front();
		priorityQueue.pop();

		float presentDistance = distArray[present->GetVertexId()];

		map<vertex*, edge*>& neighbour = present->GetNeighbour();
		map<vertex*, edge*>::iterator it;
		for (it = neighbour.begin(); it != neighbour.end(); ++it)
		{
			if(!it->first->GetIsVisitedStat())
			{
				vertex* neighbourVertex = (it->first);
				edge* connectingEdge = (it->second);


				size_t idOfCurrentNode = neighbourVertex->GetVertexId();
				float distance = presentDistance + connectingEdge->GetWeight();
				if (distance < distArray[idOfCurrentNode])
				{
					distArray[idOfCurrentNode] = distance;
					map<vertex*, edge*>& neighbour = present->GetNeighbour();
					map<vertex*, edge*>::iterator itInner;
					for (itInner = neighbour.begin(); itInner != neighbour.end(); ++itInner)
					{
						itInner->first->SetIsVisitedStat(false);
						priorityQueue.push(itInner->first);
					}
				}
			}
		}
	}
	for (size_t i = 0; i < distArray.size(); i++)
	{
		cout << "vertID: " << i << ", dist: " << distArray[i] << endl;
	}
}

void graph::Dijkstra_BFS(vertex* V, vector<float>& distArray)
{

}