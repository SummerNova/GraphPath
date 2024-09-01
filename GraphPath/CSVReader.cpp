#include "CSVReader.h"
	

vector<vector<string>> CSVReader::ReadFile(string URL)
{
	inputFile.open("input.txt");

	int pos;
	int lineCounter = 0;
	while (getline(inputFile, inputLine)) {
		
		
		fileData.push_back({});


		while ((pos = inputLine.find(",")) != std::string::npos) {
			fileData[lineCounter].push_back(inputLine.substr(0, pos));

			inputLine.erase(0, pos + 1);
		}
		fileData[lineCounter].push_back(inputLine);
		
		
		lineCounter++;
	}

	inputFile.close();

	return fileData;
}
