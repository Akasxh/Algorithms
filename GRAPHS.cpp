// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 100;  // Adjust the size as needed

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;  // Initialize all cells to 0 (no edges)
        }
    }
}

void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

void addEdge(int from, int to) {
    graph[from][to] = 1;
    // If the graph is undirected, you might also set graph[to][from] = 1;
}

void dfs(int vertex, int vertices) {
    cout << vertex << " ";  // Process the current vertex
    visited[vertex] = true;  // Mark the current vertex as visited

    // Traverse all adjacent vertices
    for (int i = 0; i < vertices; ++i) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            // If there's an edge to an unvisited vertex, recursively call DFS
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices = 5;
    initializeGraph(vertices);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    // Initialize the visited array to false
    for (int i = 0; i < vertices; ++i) {
        visited[i] = false;
    }

    // Start DFS from the first vertex
    cout << "DFS starting from vertex 0: ";
    dfs(0, vertices);

    return 0;
}
