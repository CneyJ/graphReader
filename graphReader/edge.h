#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double INFINITYISH = 999999;

class edge {
public:
	edge() { createEdge(0, 0, INFINITYISH); }
	edge(int newU, int newV, double newW) { createEdge(newU, newV, newW); }
	
	// Getters
	int getO() { return o; }
	int getD() { return d; }
	double getW() { return w; }

	// Operator Overloads
	void operator = (edge e) {
		// I don't know if this is needed, but since I was doing the others, I included it

		setO(e.getO());
		setD(e.getD());
		setW(e.getW());
	}

	// Overloaded comparisons
	bool operator < (edge e) { return getW() < e.getW(); }
	bool operator > (edge e) { return getW() > e.getW(); }
	bool operator == (double otherW) { return getW() == otherW; }
	
	bool operator == (edge e) {
		if ((getO() == e.getO()) || (getO() == e.getD())) { // Is this edge's origin the same as the other's origin or destination
			if ((getD() == e.getO()) || (getD() == e.getD())) { // Is this edge's destination the same as the other's origin or destination
				return true;
			}
		}
		return false;
	}
	
	bool operator != (edge e) {
		if ((getO() == e.getO()) || (getO() == e.getD())) { // Is this edge's origin the same as the other's origin or destination
			if ((getD() == e.getO()) || (getD() == e.getD())) { // Is this edge's destination the same as the other's origin or destination
				return false;
			}
		}
		return true;
	}

	// Output
	string toString() {
		// Returns a string that represents each node and the traversal cost between them. V useful for troubleshooting
		// example:
		//	[0] <--- 8.0 ---> [1]
		return string("[") + to_string(getO()) + string("] <---") + to_string(getW()) + string("---> [") + to_string(getD()) + string("]");
	}

	friend ostream& operator<< (ostream &output, edge& e) {
		// Overload the << operator. 
		// Basically the same thing as toString, but I know how to set the precision for the double.
		// example:
		//	[0] <--- 8.0 ---> [1]

		output << "[" << e.getO() << "] <---" << fixed << setprecision(2) << e.getW() << "---> [" << e.getD() << "]";

		return output;
	}


private:

	// Setters
	void setO(int newO) { o = newO; }
	void setD(int newD) { d = newD; }
	void setW(double newW) { w = newW; }
	void createEdge(int newO, int newD, double newW) {
		setO(newO);
		setD(newD);
		setW(newW);
	}

	// Variables
	int o;		// origin
	int d;		// destination
	double w;	// weight



};