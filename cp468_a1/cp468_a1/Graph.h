#pragma once
#include"Adjacency.h"
#include<vector>

template<class T>
class Graph
{
public:
	struct Node;
	Graph<T>();
	void AddNode(T data, int h);
	void AddAdjacency(Adjacent * e);
	void Print();
	~Graph<T>();
private:
	Adjacent * edges;
	std::vector<Node *> nodes;
	Node * first;
};

template<class T>
struct Graph<T>::Node {
	T data;
	int h;
	std::vector<Node> * neighbors;
};

template<class T>
inline Graph<T>::Graph()
{
}

template<class T>
inline void Graph<T>::AddNode(T data, int h)
{
	Node * n = new Node;
	n->data = data;
	n->h = h;
	n->neighbors = new std::vector<Node>;
	nodes.push_back(n);
}

template<class T>
inline void Graph<T>::AddAdjacency(Adjacent * e)
{
	edges = e;
	for (int y = 0; y < edges->num; y++) {
		for (int x = 0; x < edges->num; x++) {
			if (e->matrics[x][y] != 0){
				Node * n = nodes.at(y);
				n->neighbors->push_back(*nodes.at(x));
			}
		}
	}
}

template<class T>
inline void Graph<T>::Print()
{
	for (int i = 0; i < edges->num; i++) {
		printf("Node number %d, data %d \n", i, nodes[i]->data);
		for (int j = 0; j < nodes[i]->neighbors->size(); j++) {
			printf("    Connected to Node with data = %d \n", (int)nodes[j]->neighbors->at(j).data);
		}
	}
}

template<class T>
inline Graph<T>::~Graph()
{
}

