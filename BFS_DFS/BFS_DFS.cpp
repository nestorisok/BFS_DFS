#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;




void BFS(vector<vector<int>>& adjList, int vertex, vector<bool>& visited);
void DFS(vector<vector<int>>& adjList,int vertex, vector<bool>& visited);


int main() {

	//cout << "test" << endl;

	int dimensions = 10; //

	vector<vector<int>> adjListBFS(dimensions);
	vector<bool> visited(dimensions, false); // making sure everything in our visited is false

	// vertex begins at 0
	adjListBFS[0].push_back(1); // 0 leads to 1
	adjListBFS[0].push_back(2); // 0 leads to 2
	adjListBFS[1].push_back(3); // 1 leads to 3
	adjListBFS[1].push_back(4); // 1 leads to 4
	adjListBFS[2].push_back(5); // 2 leads to 5

	/*   ^^^^^
	
	0 -> 1 -> 3
	|	  \
	v		-> 4
	2
	|
	v
	5
	
	*/

	
	cout << "Breadth-First search: ";
	BFS(adjListBFS, 0, visited);


	return 0;
}


void BFS(vector<vector<int>>& adjList, int vertex, vector<bool>& visited) {
	int curNode;


	queue<int> myQ; // creating a queue
	visited[vertex] = true; // marking vertex as true and pushing
	myQ.push(vertex);
	
	while (!myQ.empty()) { // keeps going while its not empty
		curNode = myQ.front(); // gets the front-most node
		myQ.pop();				// removes front-most element from queue
		cout << curNode << ", ";


		

		for (int neighbors : adjList[curNode]) {
			if (!visited[neighbors]) { // if it has not been visited (no value)
				visited[neighbors] = true; // mark as true and push to queue
				myQ.push(neighbors);
				
			}

		}

	}

	cout << "\b\b"; // clears last comma
}

void DFS(vector<vector<int>>& myGraph,int vertex, vector<bool>& visited) {
	
	stack <int> myStack;
	myStack.push(vertex);
	visited[vertex] = true;	
	cout << vertex << ", ";
	myStack.pop();
	vector<int>::iterator ITR;
	for (ITR = myGraph[vertex].begin(); ITR != myGraph[vertex].end(); ITR++) {
		if (!visited[*ITR]) {
			DFS(myGraph, *ITR, visited);
		}
	}


}