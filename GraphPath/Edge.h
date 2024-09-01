#include <string>
using namespace std;

#pragma once
struct Edge
{
public: 
	int Length;
	string otherNode;

	Edge(int len, string node);
};

