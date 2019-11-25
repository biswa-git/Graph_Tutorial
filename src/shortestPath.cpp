#include"graph.h"
int main(int argc, char* argv[])
{
	unique_ptr<graph> G(new graph(64, true));
	
	//MINIMUM NUMBER OF MOVE TO REACH A LOCATION ON CHESS BOARD FOR A KNIGHT FROM A INITIAL LOCATION
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			size_t iLoc, jLoc;
			iLoc = i - 2;
			jLoc = j - 1;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i - 1;
			jLoc = j - 2;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i - 2;
			jLoc = j + 1;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i - 1;
			jLoc = j + 2;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}

			iLoc = i + 2;
			jLoc = j - 1;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i + 1;
			jLoc = j - 2;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i + 2;
			jLoc = j + 1;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
			iLoc = i + 1;
			jLoc = j + 2;
			if (iLoc >= 0 && iLoc <= 8 && jLoc>=0 && jLoc <=8)
			{
				G->pushEdge(8 * j + i, 8 * jLoc + iLoc);
			}
		}
	}

	//INITIAL LOC: (4,4) = 3*8+3 = 27
	G->Dijkstra(27);

	return 0;
}
