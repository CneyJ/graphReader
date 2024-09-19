#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "edge.h"
#include "node.h"
#include "graph.h"

using namespace std;

void testEdgeClass();
void testNodeClass();

void main(int argc, char* argv[]) {

	string fileName = "VM_TestData_M7_p40.txt";
	graph theGraph;

	// Open File
	ifstream inFile(fileName);

	// Read in the graph data
	string entireLine = "";
	while (getline(inFile, entireLine)) { // Grab entire line from text file (includes origin node, and each destination node with weights)

		stringstream sstream(entireLine); // Makes things easier to parse. 

		string origin = "";
		getline(sstream, origin, ' '); // Read in origin node
		node tempNode(stoi(origin));   // Create temporary node with origin as ID

		string destination = "";
		while (getline(sstream, destination, ' ')) { // Read in destination node number

			string weight = "";
			getline(sstream, weight, ' '); // Read in weight of edge between origin and destination

			tempNode.addEdge(edge(stoi(origin), stoi(destination), stod(weight))); // Add edge info into the node
		}
		theGraph.addNode(tempNode);
	}
		cout << theGraph.toString();
		cout << endl;

}

void testNodeClass() {
	// Just filler numbers, (often generates multiple paths to the same nodes). 
	node nodeArr[5];

	for (int i = 0; i < 5; i++) {
		nodeArr[i] = node(i);
	}

	srand(time(0));
	
	for (int i = 0; i < 5; i++) {
		int numEdges = (rand() % 4) + 1;
		while (nodeArr[i].edgeCount() < numEdges) {
			nodeArr[i].addEdge(edge((int(rand()%5) + 1), int((rand() % 5) + 1), double(rand())/500));
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << nodeArr[i];
	}
}

void testEdgeClass() {
	// Used to test/demonstrate the capabilities of edge class
	edge first(1, 2, 84.5);
	edge second(3, 8, 22.2);
	edge third(5,6,22.2);
	edge fourth(1,2, 84.5);

	cout << "First edge:  " << first << endl;
	cout << "Second edge: " << second << endl;
	cout << "Third edge:  " << third << endl;
	cout << "Fourth edge: " << fourth << endl;

	cout << endl << endl;

	cout << "Testing < operator... " << endl;
	cout << "   Is First smaller than Second? " << ((first < second) ? ("--Yes--") : ("[No]"));
	cout << endl << endl;

	cout << "Testing > operator..." << endl;
	cout << "   Is First larger than Second? " << ((first > second) ? ("[Yes]") : ("--No--"));
	cout << endl << endl;

	cout << "Testing == operator..." << endl;
	cout << "   Is First the same as Second? " << ((first == second) ? ("--Yes--") : ("[No]"));
	cout << endl;
	cout << "   Is Second the same as Third? " << ((second == third) ? ("--Yes--") : ("[No]"));
	cout << endl;
	cout << "   Is First the same as Fourth? " << ((first == fourth) ? ("[Yes]") : ("--No--"));
	cout << endl;
	cout << "   Is Second weight equal to 22.2? " << ((second == 22.2) ? ("[Yes]") : ("--No--"));
	cout << endl << endl;

	cout << "Testing != operator..." << endl;
	cout << "   Is Second not the same as Third? " << ((second == 22.2) ? ("[Yes]") : ("--No--"));
	cout << endl << endl;

	cout << "Testing = operator..." << endl;
	cout << "   Setting all edges to (69, 420, 8008.5)";
	cout << endl;
	first = edge(69, 420, 8008.5);
	second = edge(69, 420, 8008.5);
	third = edge(69, 420, 8008.5);
	fourth = edge(69, 420, 8008.5);
	cout << "   First edge:  " << first << endl;
	cout << "   Second edge: " << second << endl;
	cout << "   Third edge:  " << third << endl;
	cout << "   Fourth edge: " << fourth << endl;
	cout << endl << endl;
}