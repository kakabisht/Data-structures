#include<bits/stdc++.h> 
using namespace std; 
typedef pair<int, int> iPair; 

struct Graph 
{ 
	int V, E; 
	vector< pair<int, iPair> > edges; 
	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 
	void addEdge(int v1, int v2, int w) 
	{ 
		edges.push_back({w, {v1, v2}}); 
	} 
	int kruskalMST(); 
}; 

struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 

	DisjointSets(int n) 
	{  
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 
		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 
			parent[i] = i; 
		} 
	} 
	int find(int v1) 
	{ 
		if (v1 != parent[v1]) 
			parent[v1] = find(parent[v1]); 
		return parent[v1]; 
	} 
	void merge(int x, int y) 
	{ 
		x = find(x), y = find(y); 
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else 
			parent[x] = y; 
		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
	} 
    
}; 

int Graph::kruskalMST() 
{ 
	int mst_wt = 0;
	sort(edges.begin(), edges.end()); 
	DisjointSets ds(V);  
	vector< pair<int, iPair> >::iterator it; 
	for (it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int v1 = it->second.first; 
		int v2 = it->second.second; 
		int set_u = ds.find(v1); 
		int set_v = ds.find(v2); 
		if (set_u != set_v) 
		{
			cout << v1 << " - " << v2 << endl;  
			mst_wt += it->first; 
			ds.merge(set_u, set_v); 
		} 
	} 
	return mst_wt; 
} 

int main() 
{  
    int V, E, i,v1,v2,weight;
    cout << "Enter number of nodes: ";
    cin >> V;
    E = V * (V - 1);
	Graph g(V, E); 
    cout <<"Enter edges ex.V1 V2 W (-1 -1 -1 to exit): \n";
	for (int i = 0; i < E; ++i) {
        cin>>v1>>v2>>weight;
        if ((v1 == -1) && (v2 == -1) && (weight ==-1))
        {
            break;
        }
        g.addEdge(v1,v2,weight);
    }
	cout << "Edges of MST are \n"; 
	int mst_wt = g.kruskalMST(); 
	cout << "\nWeight of MST is " << mst_wt<<"\n"; 
	return 0; 
} 