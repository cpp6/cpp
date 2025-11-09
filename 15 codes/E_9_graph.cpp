/*
E-9
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight takes to reach city B from A or the amount of fuel used for the journey. 
Represent this as a graph, The node can be represented by the airport name or name of the city. 
Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Check whether the graph is connected or not.
*/

#include <iostream>
using namespace std;

const int MAX = 10;
int graph[MAX][MAX]; 
bool visited[MAX];   

void DFS(int node, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n; 
    cout << "Enter number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int flights;
    cout << "Enter number of flights: ";
    cin >> flights;

    cout << "Enter flight details (source destination cost):\n";
    for (int i = 0; i < flights; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        graph[src][dest] = cost;
        graph[dest][src] = cost; 
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    DFS(0, n);

    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "\nThe graph is CONNECTED.\n";
    else
        cout << "\nThe graph is NOT CONNECTED.\n";

    return 0;
}

/*
input in terminal:
Enter number of cities: 4
Enter number of flights: 3
Enter flight details (source destination cost):
0 1 10
1 2 15
2 3 20
*/