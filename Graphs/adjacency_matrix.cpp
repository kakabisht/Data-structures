#include <iostream>
#include <cstdlib>

using namespace std;

class Graph
{
protected:
    int value;
    int **graphm;

public:
    Graph(int value)
    {
        this->value = value;
        graphm = new int*[value];
        int k, j;
        for (k = 0; k < value; k++)
        {
            graphm[k] = new int[value];
            for (j = 0; j < value; j++)
            {
                graphm[k][j] = 0;
            }
        }
    }

    void newEdge(int head, int end)
    {
        if (head > value || end > value || head < 0 || end < 0)
        {
            cout << "Invalid edge!\n";
        }
        else
        {
            graphm[head - 1][end - 1] = 1;
            graphm[end - 1][head - 1] = 1;
        }
    }

    void display()
    {
        int i, p;

        for (i = 0; i < value; i++)
        {
            cout<<i+1<<"Row: \t";
            for (p = 0; p < value; p++)
            {
                cout <<p+1<<"Column:" << graphm[i][p] << "   ";
            }
            cout << endl;
        }
    }

};

int main()
{
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
        g1.newEdge(head, end);
    }
    cout<<"\n";
    g1.display();
    cout << endl;
    return 0;
}