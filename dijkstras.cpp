
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int INF = 1e9; // Represents infinity

// Function to find the vertex with minimum distance
int minDistance(vector<int>& dist, vector<bool>& visited, int V) {
    int minDist = INF, minIndex = -1;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print shortest path from source to destination
void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int> > >& graph, int source) {
    int V = graph.size(); // Number of vertices

    // Create a vector for distances and initialize all distances as infinite (INF)
    vector<int> dist(V, INF);

    // Create a vector to keep track of visited vertices
    vector<bool> visited(V, false);

    // Create a vector to store parent vertices for each vertex in the shortest path tree
    vector<int> parent(V, -1);

    // Distance from source to itself is 0
    dist[source] = 0;

    // Loop to do the processing of all the vertices
    for (int count = 0; count < V - 1; ++count) {
        // Find the vertex with the minimum distance
        int u = minDistance(dist, visited, V);

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update distance value of the adjacent vertices of the selected vertex.
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Print shortest paths from source to all other vertices
    cout << "Vertex   Distance   Path\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << (dist[i] == INF ? -1 : dist[i]) << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create a graph representation using adjacency list
    vector<vector<pair<int, int> > > graph(V);

    // Input the graph edges
    cout << "Enter edges and their weights (format: from to weight):\n";
    for (int i = 0; i < E; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
    }

    // Input the source vertex
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Call Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
