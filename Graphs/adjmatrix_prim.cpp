#include <iostream>
#include <cstdlib>

using namespace std;

class Graph
{
protected:
    int value;
    int ** cost;

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
    int min_Key(int key[], bool visited[], int V)  
    { 
        int min = 999, min_index;  // 999 represents an Infinite value

        for (int v = 0; v < V; v++) { 
            if (visited[v] == false && key[v] < min) { 
            	// vertex should not be visited
                min = key[v];
	    		min_index = v;  
            }
        }    
        return min_index;  
    }  

    // Function to print the final MST stored in parent[]  
    int print_MST(int parent[], int V)  
    {  
        int minCost=0;
    	cout<<"Edge \tWeight\n";  
        for (int i = 1; i< V; i++) {
    		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
    		minCost+=cost[i][parent[i]];
        }
    	cout<<"Total cost is"<<minCost;
    }  

    // Function to find the MST using adjacency cost matrix representation  
    void find_MST(int V)  
    {  
        int parent[V], key[V];
        bool visited[V];

        // Initialize all the arrays 
        for (int i = 0; i< V; i++) { 
            key[i] = 999;    // 99 represents an Infinite value
            visited[i] = false;
            parent[i]=-1;
        }    

        key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.  
        parent[0] = -1; // First node is always root of MST  

        // The MST will have maximum V-1 vertices  
        for (int x = 0; x < V - 1; x++) 
        {  
            // Finding the minimum key vertex from the 
            //set of vertices not yet included in MST  
            int u = min_Key(key, visited,V);  

            visited[u] = true;  // Add the minimum key vertex to the MST  

            // Update key and parent arrays
            for (int v = 0; v < V; v++)  
            {
                // cost[u][v] is non zero only for adjacent vertices of u  
                // visited[v] is false for vertices not yet included in MST  
                // key[] gets updated only if cost[u][v] is smaller than key[v]  
                if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
                {  
                    parent[v] = u;
                    key[v] = cost[u][v];  
                }        
            }
        }

        // print the final MST  
    	print_MST(parent,V);  
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
    cout<<"\nAfter Prim algoritm\n";
    g1.find_MST(vertex);  
    cout << endl;
    return 0;
}