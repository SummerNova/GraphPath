#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include "CSVReader.h"
#include "Edge.h"
using namespace std;

#pragma once
class Graph
{
private:
	vector<string> key = {};
	vector<vector<int>> graphmatrix = {};
	int AmountofNodes = 0;
	bool isInit = false;

	int findIndexOf(string NodeName);
	int AddNode(string NodeName);
	int InitializeMatrix();
	int SetEdge(string Node1, string Node2, int Cost);
	int Reset();


public:
	vector<Edge> GetAvailableEdgesOf(string NodeName);
	int InitializeGraph(string inputFileURL);
	int printGraph();

};

