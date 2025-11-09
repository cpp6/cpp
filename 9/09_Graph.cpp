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
OUTPUT:
Enter number of cities: 4
Enter number of flights: 3
Enter flight details (source destination cost):
0 1 10
1 2 15
2 3 20
Adjacency Matrix:
0 10 0 0 
10 0 15 0 
0 15 0 20 
0 0 20 0 
The graph is CONNECTED.
*/