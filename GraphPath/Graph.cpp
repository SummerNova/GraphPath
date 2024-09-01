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
			graphmatrix[i].push_back(0);
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

	graphmatrix[index1][index2] = Cost;
	graphmatrix[index1][index2] = Cost;

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
