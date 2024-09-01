#include <vector>
#include <string>
#include <iostream>
#include "Edge.h"
using namespace std;


#pragma once
class Path
{
private:
	int Length = 0;
	vector<string> Route = {};



public:
	int GetLength();
	vector<string> getRoute();
	Path(vector<string> route, int startLen,
		string newNode, int addedLen);
	vector<Path> Step(vector<Edge> availableRoutes);
	

};

