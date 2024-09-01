#include "Graph.h"

int Graph::findIndexOf(string NodeName)
{
	for (int i = 0; i < AmountofNodes; i++) {
		if (key[i]._Equal(NodeName))
		{
			return i;
		}
	}
	return -1;
}

int Graph::AddNode(string NodeName)
{
	if (isInit) {
		cout << "Graph Initialized, Node cannot be added" << endl;
		return -1;
	}

	if (findIndexOf(NodeName) == -1)
	{
		key.push_back(NodeName);

		AmountofNodes++;
		return 0;
	}

	cout << NodeName << " was already Added";
	return -2;


}

int Graph::InitializeMatrix()
{
	isInit = true;
	for (int i = 0; i < AmountofNodes; i++) {
		graphmatrix.push_back({});
		for (int j = 0; j < AmountofNodes; j++) {
			graphmatrix[i].push_back(-1);
		}
	}
	return 0;
}

int Graph::SetEdge(string Node1, string Node2, int Cost)
{
	if (!isInit) {
		cout << "cannot add an edge to an uninitialized graph" << endl;
		return -1;
	}
	
	int index1 = findIndexOf(Node1);
	int index2 = findIndexOf(Node2);

	if (index1 == -1 or index2 == -1) {
		cout << "one or both of the requested of the edge do not exist" << endl;
		return -2;
	}

	if (index1 == index2) {
		cout << "the graph cannot support edges from the node to itself" << endl;
		return -3;
	}

	graphmatrix[index1][index2] = Cost;
	graphmatrix[index2][index1] = Cost;

	return 0;

}

int Graph::Reset()
{
	key = {};
	graphmatrix = {};
	AmountofNodes = 0;
	isInit = false;
	return 0;
}

int Graph::getAmoutofNodes()
{
	return AmountofNodes;
}

vector<string> Graph::getKeys()
{
	return key;
}

vector<Edge> Graph::GetAvailableEdgesOf(string NodeName)
{
	vector<Edge> output = {};
	int index = findIndexOf(NodeName);
	for (int i = 0; i < AmountofNodes; i++) {
		if (graphmatrix[index][i] >= 0) {
			output.push_back(Edge(graphmatrix[index][i], key[i]));
		}
	}
	return output;
}

int Graph::InitializeGraph(string inputFileURL)
{
	CSVReader inputFile;
	vector<vector<string>> Data = inputFile.ReadFile(inputFileURL);
	Reset();

	for (int i = 0; i < Data.size(); i++) {
		if (Data[i][0] == "Node") {
			AddNode(Data[i][1]);
		}
		else if (Data[i][0] == "#Edges") {
			InitializeMatrix();
		}
		else if (Data[i][0] == "Edge") {
			SetEdge(Data[i][1], Data[i][2], stoi(Data[i][3]));
		}
	}

	return 0;
}

int Graph::printGraph()
{
	if (!isInit) {
		cout << "cannot print an uninitialized graph" << endl;
		return -1;
	}
	for (int i = 0; i < AmountofNodes; i++) {
		cout << "    " << key[i];
	}
	cout << endl;

	for (int i = 0; i < AmountofNodes; i++) {
		cout << key[i];
		for (int j = 0; j < AmountofNodes; j++) {
			cout << "    " << graphmatrix[i][j];
		}
		cout << endl;
	}

}
