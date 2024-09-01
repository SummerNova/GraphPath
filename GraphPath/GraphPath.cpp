// GraphPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include "Graph.h"
#include "Pathfinder.h"
#include "Path.h"
#include <iostream>
using namespace std;

int main()
{
    Graph graph;
    cout << "please write the name of the file with the graph:" << endl;

    string input = "";

    cin >> input;

    graph.InitializeGraph(input);

    graph.printGraph();


    Pathfinder finder = Pathfinder(&graph);

    cout << "what path would you like to find?\nOrigin: ";

    string Origin = "";
    cin >> Origin;

    cout << "Destination: ";

    string Destination = "";
    cin >> Destination;

    if (finder.Validate(Origin, Destination)) {

        Path solution = finder.FindShortestRoute(Origin, Destination);

        if (solution.GetLength() == -1) {
            cout << "we're sorry, but it seems there is no path available";
        }
        else {
            cout << "the shortest route from " << Origin << " to " << Destination << " is:\n";
            cout << "the path is: ";
            for (int i = 0; i < solution.getRoute().size(); i++) {
                cout << solution.getRoute()[i] << " ";
            }
            cout << endl << "with a length of " << solution.GetLength();
        }
    }
    else {
        cout << "we're sorry, the Origin or Destination may not be present in the graph.";
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
