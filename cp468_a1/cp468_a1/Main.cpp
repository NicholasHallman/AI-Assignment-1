#include<stdio.h>
#include"Graph.h"

int main(int argv, char ** argc) {
	Adjacent edges;
	edges.num = 2;
	edges.matrics = new int*[2];
	for (int i = 0; i < 2; i++) {
		edges.matrics[i] = new int[2];
	}
	Graph<int> * g = new Graph<int>();
	g->AddNode(0, 0);
	g->AddNode(1, 1);
	g->AddAdjacency(&edges);
	g->Print();
	char buff[20];
	fgets(buff, 20, stdin);
	return 0;
}
