// RedesDeFluxo.cpp : define o ponto de entrada para o aplicativo do console.
#include "stdafx.h"
#include<Windows.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include<vector>
#include"Persistencia.h"
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int& s, int& t, vector<int>& parent, int& V)
{
	vector<bool> visited;
	for (int i = 0; i < V; i++)
		visited.push_back(0);
	queue <int> q;
	q.push(s);
	visited.at(s) = true;
	parent.at(s) = -1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++)
		{
			if (visited.at(v) == false && rGraph.at(u).at(v) > 0) {

				q.push(v);
				parent.at(v) = u;
				visited.at(v) = true;
			}

		}
	}
	return visited.at(t) == true;

}
// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>>& graph, int s, int t, int V){
	int u, v;
	vector<vector<int>> rGraph;
	
	for each (vector<int> linha in graph)
	{
		vector<int> linha_adicionada;
		for each (int x in linha)
		{
			linha_adicionada.push_back(x);
		}
		rGraph.push_back(linha);
	}

	vector<int> parent;

	for (int i = 0; i < V; i++)
		parent.push_back(0);

	int max_flow = 0;  // There is no flow initially

	while (bfs(rGraph, s, t, parent, V)) {

		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent.at(v))
		{
			u = parent.at(v);
			path_flow = min(path_flow, rGraph.at(u).at(v));
		}

		for (v = t; v != s; v = parent.at(v))
		{
			u = parent.at(v);
			rGraph.at(u).at(v) -= path_flow;
			rGraph.at(v).at(u) += path_flow;
		}
		max_flow += path_flow;

	}
	return max_flow;

}

int main()
{

	
	int dim;
	vector<vector<int>> matriz = Persistencia::retorna_grafo(dim);
	cout << endl << endl << dim<<endl;
	
	for each (vector<int> linha in matriz)
	{
		for each (int var in linha)
		{
			cout << var << " ";
		}
		cout << endl;
	}

	cout <<endl <<fordFulkerson(matriz, 0, 5, 6);




/*
	vector<int> v1 = { 0, 16, 13, 0, 0, 0 };
	vector<int> v2 = { 0, 0, 10, 12, 0, 0 };
	vector<int> v3 = { 0, 4, 0, 0, 14, 0 };
	vector<int> v4 = { 0, 0, 9, 0, 0, 20 };
	vector<int> v5 = { 0, 0, 0, 7, 0, 4 };
	vector<int> v6 = { 0, 0, 0, 0, 0, 0 };

	vector<vector<int>> matriz;
	matriz.push_back(v1);
	matriz.push_back(v2);
	matriz.push_back(v3);
	matriz.push_back(v4);
	matriz.push_back(v5);
	matriz.push_back(v6);

	cout << fordFulkerson(matriz, 0, 5, 6);

	*/system("PAUSE");
	return 0;
}	