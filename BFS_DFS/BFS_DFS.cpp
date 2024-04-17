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
	vector<bool> visitedBFS(dimensions, false); // making sure everything in our visited is false

	// vertex begins at 0
	adjListBFS[0].push_back(1); // 0 leads to 1
	adjListBFS[0].push_back(2); // 0 leads to 2
	adjListBFS[1].push_back(3); // 1 leads to 3
	adjListBFS[1].push_back(4); // 1 leads to 4
	adjListBFS[2].push_back(5); // 2 leads to 5

	
	cout << "\nBreadth-First search: ";
	BFS(adjListBFS, 0, visitedBFS);


	// int dimensions = 10; // from code above, to personally remember

	vector<vector<int>> adjListDFS(dimensions);
	vector<bool> visitedDFS(dimensions, false); // making sure everything in our visited is false

	// vertex begins at 0
	adjListDFS[0].push_back(1); // 0 leads to 1
	adjListDFS[0].push_back(2); // 0 leads to 2
	adjListDFS[1].push_back(3); // 1 leads to 3
	adjListDFS[1].push_back(4); // 1 leads to 4
	adjListDFS[2].push_back(5); // 2 leads to 5

	cout << "\n\nDepth-First search: ";
	DFS(adjListDFS, 0, visitedDFS);


	return 0;
}
/*** Graph for both BFS and DFS ***/

/*

0 -> 1 -> 3
|	  \
v		-> 4
2
|
v
5

*/

/*** Graph for both BFS and DFS ***/

void BFS(vector<vector<int>>& adjList, int vertex, vector<bool>& visited) {
	int curNode;


	queue<int> myQ; // creating a queue
	visited[vertex] = true; // marking vertex as true and pushing
	myQ.push(vertex);
	
	while (!myQ.empty()) { // keeps going while its not empty
		curNode = myQ.front(); // gets the front-most node
		myQ.pop();				// removes front-most element from queue
		cout << curNode << " ";


		

		for (int neighbor : adjList[curNode]) {
			if (!visited[neighbor]) { // if it has not been visited (no value)
				visited[neighbor] = true; // mark as true and push to queue
				myQ.push(neighbor);
				
			}

		}

	}


}

void DFS(vector<vector<int>>& adjList,int vertex, vector<bool>& visited) {
	int curNode;


	stack<int> myStack;
	myStack.push(vertex); // pushing vertex to stack
	visited[myStack.top()] = true;	// we want to make sure vertex it is marked as visited
	cout << myStack.top() << " ";

	while (!myStack.empty()) {
		curNode = myStack.top(); // curNode contains top of stack
		myStack.pop();

		for (int neighbor : adjList[curNode]) {
			if (!visited[neighbor]) { // if it has not been visited (no value)
				DFS(adjList, neighbor, visited);

			}
		}

	}

	}

/*

using an iterator

		vector<int>::iterator ITR; // we use an iterator to iterate through the vector
		for (ITR = adjList[vertex].begin(); ITR != adjList[vertex].end(); ITR++) {
			if (!visited[*ITR]) {
				DFS(adjList, *ITR, visited); //recursively called itself
			}

*/