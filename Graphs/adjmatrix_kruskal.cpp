#include <iostream>
#include <cstdlib>

using namespace std;

class Graph
{
protected:
    int value;
    int ** cost;
    int parent[]; 

public:
    Graph(int value)
    {
        this->value = value;
        cost = new int*[value];
        int k, j;
        for (k = 0; k < value; k++)
        {
            cost[k] = new int[value];
            for (j = 0; j < value; j++)
            {
                cost[k][j] = 0;
            }
            parent[k]=0;
        }
    }

    void newMatrix(int V)
    {
        cout<<"\n Enter the Matrix\n";
        for (int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
		    	cin>>cost[i][j];
            }
        }
    }

    void display()
    {
        int i, p;

        for (i = 0; i < value; i++)
        {
            for (p = 0; p < value; p++)
            {
                cout << cost[i][p] << "   ";
            }
            cout << endl;
        }
    }
    int find(int i) 
    { 
    	while (parent[i] != i) 
    		i = parent[i]; 
    	return i; 
    } 

    // Does union of i and j. It returns 
    // false if i and j are already in same 
    // set. 
    void union1(int i, int j) 
    { 
    	int a = find(i); 
    	int b = find(j); 
    	parent[a] = b; 
    } 

    // Finds MST using Kruskal's algorithm 
    void kruskalMST(int V) 
    { 
    	int mincost = 0; // Cost of min MST. 

    	// Initialize sets of disjoint sets. 
    	for (int i = 0; i < V; i++) 
    		parent[i] = i; 

    	// Include minimum weight edges one by one 
    	int edge_count = 0; 
    	while (edge_count < V - 1) { 
    		int min = __INT_MAX__, a = -1, b = -1; 
    		for (int i = 0; i < V; i++) { 
    			for (int j = 0; j < V; j++) { 
    				if (find(i) != find(j) && cost[i][j] < min) { 
    					min = cost[i][j]; 
    					a = i; 
    					b = j; 
    				} 
    			} 
    		} 

    		union1(a, b); 
    		// printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min); 
            cout<<"Edge"<<edge_count++<<"("<<a<<","<<b<<")"<<"\t cost:"<<min<<"\n";
    		mincost += min; 
    	} 
    	cout<<"\n Minimum cost="<<mincost<<"\n"; 
    } 

    };

int main()
{
    int vertex, numberOfEdges, i, head, end;
    cout << "Enter number of nodes: ";
    cin >> vertex;
    numberOfEdges = vertex * (vertex - 1);
    Graph g1(vertex);
    g1.newMatrix(vertex);
    cout<<"\nThe Input matrix is\n";
    g1.display();
    cout<<"\nAfter Kruskals algoritm\n";
    g1.kruskalMST(vertex);  
    cout << endl;
    return 0;
}