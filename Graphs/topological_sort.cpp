#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph { 
	int V; 
	// Pointer to an array containing adjacency listsList 
	list<int>* adj; 

	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack); 

public: 
	Graph(int V);  
	void addEdge(int v, int w); 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) 
{ 
	// Mark the current node as visited. 
	visited[v] = true; 

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 

	// Push current vertex to stack which stores result 
	Stack.push(v); 
} 

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
	stack<int> Stack; 

	// Mark all the vertices as not visited 
	bool* visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to store Topological 
	// Sort starting from all vertices one by one 
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			topologicalSortUtil(i, visited, Stack); 

	// Print contents of stack 
	while (Stack.empty() == false) { 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
    int vertex, numberOfEdges, i, head, end;
    cout << "Enter number of nodes: ";
    cin >> vertex;
    numberOfEdges = vertex * (vertex - 1);
    Graph g1(vertex);
    for (int i = 0; i < numberOfEdges; i++)
    {
        cout << "Enter edge ex.1 2 (-1 -1 to exit): \n";
        cin >> head >> end;
        if ((head == -1) && (end == -1))
        {
            break;
        }
        g1.addEdge(head, end);
    }
	cout << "Topological Sort of the given graph \n"; 
	g1.topologicalSort(); 

	return 0; 
} 
