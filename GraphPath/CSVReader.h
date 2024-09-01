#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#pragma once
class CSVReader
{
private:
	string inputLine;
	ifstream inputFile;
	vector<string> lineData;
	vector<vector<string>> fileData;

public:
	vector<vector<string>> ReadFile(string URL);
};

