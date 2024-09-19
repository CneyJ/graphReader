#pragma once

#include <vector>
#include "edge.h"
#include "node.h"

using namespace std; 

class graph {
public: 
	void addNode(node n) {
		nodes.push_back(n);
		nodeCount++;
	}

	int numNodes() { return nodeCount; }

	string toString() {
		string retString = "Graph size: " + to_string(nodeCount) + "\n";

		for (int i = 0; i < nodeCount; i++) {
			retString += (nodes[i].toString()) + "\n";
		}

		return retString;
	}

	friend ostream& operator<< (ostream& output, node& n) {

		output << "Graph size: " << n.edgeCount() << endl;

		for (int i = 0; i < n.edgeCount(); i++) {
			output << (n[i].toString()) + "\n";
		}

		return output;
	}

private:
	int nodeCount = 0;
	vector <node> nodes;
};