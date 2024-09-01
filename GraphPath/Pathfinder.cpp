#include "Pathfinder.h"

Pathfinder::Pathfinder(Graph* Ref)
{
	graph = Ref;
	for (int i = 0; i < graph->getAmoutofNodes(); i++) {
		shortestRoute.insert({ graph->getKeys()[i], -1 });
	}
}

bool Pathfinder::Validate(string Origin, string Destination)
{
	bool answer = false;
	if (shortestRoute.count(Origin) != 0 and shortestRoute.count(Destination) != 0) {
		answer = true;
	}
	return answer;
}

Path Pathfinder::FindShortestRoute(string Origin, string Destination)
{
	AvailablePaths = { Path({},0,Origin,0) };

	Path Solution = Path({},-1,"",0);
	bool searching = true;
	vector<Path> additions;


	while (AvailablePaths.size() > 0 and searching) {
		if (Solution.GetLength() == -1 or
			AvailablePaths[0].GetLength() < Solution.GetLength()) {
			
			additions = AvailablePaths[0].Step(graph->GetAvailableEdgesOf(
				AvailablePaths[0].getRoute()[AvailablePaths[0].getRoute().size() - 1]));

			for (int i = 0; i < additions.size(); i++) {
				if (additions[i].getRoute()[additions[i].getRoute().size() - 1] == Destination and
					(Solution.GetLength() < 0 or additions[i].GetLength() < Solution.GetLength())) {
					Solution = additions[i];
					shortestRoute[Destination] = additions[i].GetLength();

					cout << "stepped from " << additions[i].getRoute()[additions[i].getRoute().size() - 2] << " to "
						<< additions[i].getRoute()[additions[i].getRoute().size() - 1] << ". Found Possible Solution with a length of: "<< shortestRoute[Destination] << endl;
				}
				else if (shortestRoute[additions[i].getRoute()[additions[i].getRoute().size() - 1]] > additions[i].GetLength()
						or shortestRoute[additions[i].getRoute()[additions[i].getRoute().size() - 1]] == -1) {
						
					shortestRoute[additions[i].getRoute()[additions[i].getRoute().size() - 1]] = additions[i].GetLength();

					insertPath(additions[i]);

					cout << "stepped from " << additions[i].getRoute()[additions[i].getRoute().size() - 2] << " to "
						<< additions[i].getRoute()[additions[i].getRoute().size() - 1] << endl;
				}
			}

			AvailablePaths.erase(AvailablePaths.begin());


		}
		else {
			searching = false;
		}
	}


	return Solution;
}

int Pathfinder::insertPath(Path newpath)
{
	int index = 0;
	bool searching = true;

	while (index < AvailablePaths.size() and searching) {
		if (AvailablePaths[index].GetLength() > newpath.GetLength()) {
			AvailablePaths.insert(AvailablePaths.begin() + index, newpath);
			searching = false;
		}
		else if (AvailablePaths[index].GetLength() <= newpath.GetLength()
			and index == AvailablePaths.size() - 1) {
			AvailablePaths.insert(AvailablePaths.end(), newpath);
			searching = false;
		}
		else if (AvailablePaths[index].GetLength() == newpath.GetLength()
			and AvailablePaths[index + 1].GetLength() > newpath.GetLength()) {
			AvailablePaths.insert(AvailablePaths.begin() + index+1, newpath);
			searching = false;
		}
		else {
			index++;
		}
	}
	return 0;
}
