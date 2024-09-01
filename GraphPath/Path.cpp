#include "Path.h"

int Path::GetLength()
{
	return Length;
}

vector<string> Path::getRoute()
{
	return Route;
}

Path::Path(vector<string> route, int startLen, string newNode, int addedLen)
{
	for (int i = 0; i < route.size(); i++) {
		Route.push_back(route[i]);
	}
	Route.push_back(newNode);
	Length = startLen + addedLen;
}

vector<Path> Path::Step(vector<Edge> availableRoutes)
{
	vector<Path> options = {};
	for (int i = 0; i < availableRoutes.size(); i++)
	{
		options.push_back(Path(Route,Length,availableRoutes[i].otherNode,availableRoutes[i].Length));
	}
	return vector<Path>();
}
