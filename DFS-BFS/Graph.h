#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

class graph {

private:
	int numofnodes;
	vector <vector<int>> mygraph;
	void DFSRec(int vertex, vector<bool>& visited);
public:
	graph(int );
	void addedge(int, int);
	void BFS();
	void DFS();
};



#endif


