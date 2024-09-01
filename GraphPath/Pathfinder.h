#include <string>
#include <map>
#include <vector>
#include "Edge.h"
#include "Path.h"
#include "Graph.h"
using namespace std;

#pragma once
class Pathfinder
{
private:
	Graph* graph;
	vector<Path> AvailablePaths = {};
	map<string, int> shortestRoute;

public:
	Pathfinder(Graph* Ref);

	bool Validate(string Origin, string Destination);
	
	Path FindShortestRoute(string Origin, string Destination);

	int insertPath(Path newpath);


};

