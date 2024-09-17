#pragma once


#include <vector>
#include <string>
#include "edge.h"

class node {
public:
	// Constructors
	node() { setID(-1); }
	node(int newID) { setID(newID); }

	// Utilities
	int getID() { return ID; }
	edge getEdge(int index) { return edges[index]; }
	edge operator[] (int index) { return edges[index]; }
	int edgeCount() { return int(edges.size()); }
	void addEdge(edge newEdge) { edges.push_back(newEdge); };
	void setID(int newID) { ID = newID; }

	string toString() {
		//toString() presents the data in an easy for humans to read format. This was very useful for debugging.
		//Example:
		//	Node: 0
		//		to: 1    weight: 8.0
		//		to: 2	 weight: 5.0
		string retString = "Node: " + to_string(getID()) + "\n";

		for (int i = 0; i < edges.size(); i++) {
			retString += " " + to_string(edges[i].getD()) + " " + to_string(edges[i].getW());
		}

		return retString;
	}

	friend ostream& operator<< (ostream& output, node& n) {


		/*output << "[" << e.getO() << "] <---" << fixed << setprecision(2) << e.getW() << "---> [" << e.getD() << "]";*/

		output << "Node: " << n.getID() << endl;

		for (int i = 0; i < n.edgeCount(); i++) {
			output << "    to: " << n.getEdge(i).getD() << "    weight: " << fixed << setprecision(2) << n.getEdge(i).getW() << endl;
			//output << i << endl;
		}

		return output;
	}

private:
	int ID;
	vector<edge> edges;
};