#include <stdio.h> 
#include <limits.h> 
#include <iostream>
using namespace std;


int minDistance(int dist[], bool sptSet[], int V) 
{ 
int min = INT_MAX, min_index; 
for (int v = 0; v < V; v++) 
	if (sptSet[v] == false && dist[v] <= min) 
		min = dist[v], min_index = v; 
return min_index; 
} 

int printSolution(int dist[], int n) 
{ 
cout<<"Vertex Distance from Source\n"; 
for (int i = 0; i < n; i++) 
	cout<<i<<"\t"<<dist[i]; 
} 

void dijkstra(int graph[10][10], int src, int V) 
{ 
	int dist[V];
	bool sptSet[V]; 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 
	dist[src] = 0; 
	for (int count = 0; count < V-1; count++) 
	{ 
	int u = minDistance(dist, sptSet, V); 
	sptSet[u] = true;  
	for (int v = 0; v < V; v++) 
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 
	printSolution(dist, V); 
} 

int main() 
{ 
    int V;
    cout << "Enter number of nodes: ";
    cin >> V;
    int graph[V][V];
    cout << "Enter the Matrix: ";
    for (int i = 0; i < V; i++){
        for (int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
	dijkstra(graph, 0, V); 
	return 0; 
} 