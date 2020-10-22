#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

int main()
{
	int vertices, edges, v1, v2, weight;
	
	cout<<"Enter the Number of Vertices -\n";
    cin>>vertices;
	
    edges = vertices * (vertices - 1);

	vector< list< pair<int, int> > > adjacencyList(vertices + 1);
	
    cout <<"Enter edges ex.V1 V2 W (-1 -1 -1 to exit): \n";

	
	for (int i = 0; i < edges; ++i) {
        cin>>v1>>v2>>weight;
        if ((v1 == -1) && (v2 == -1) && (weight ==-1))
        {
            break;
        }
		// Adding Edges to the Graph
		adjacencyList[v1].push_back(make_pair(v2, weight));
		adjacencyList[v2].push_back(make_pair(v1, weight));
	}
	
	cout<<"\nThe Adjacency List-\n";
	// Printing Adjacency List
	for (int i = 1; i < adjacencyList.size(); ++i) {
        cout<<"AdjacencyList at "<< i<<"\t";
		
		list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
		
		while (itr != adjacencyList[i].end()) {
			cout<<" -> "<<(*itr).first<<"("<<(*itr).second<<")";
			++itr;
		}
		cout<<"\n";
	}
	
	return 0;
}