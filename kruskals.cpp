
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

// Comparator function to sort edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Find function for disjoint sets
int find(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Union function for disjoint sets
void Union(vector<int>& parent, int x, int y) {
    int x_set = find(parent, x);
    int y_set = find(parent, y);
    parent[x_set] = y_set;
}

void kruskalMST(vector<vector<int> >& graph, int V) {
    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != 0) {
                Edge edge;
                edge.source = i;
                edge.destination = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }

    // Sort edges based on their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V, -1);
    vector<Edge> mst;
    int mstWeight = 0;

    for (int i = 0; i < edges.size(); ++i) {
        int sourceParent = find(parent, edges[i].source);
        int destParent = find(parent, edges[i].destination);

        if (sourceParent != destParent) {
            mst.push_back(edges[i]);
            mstWeight += edges[i].weight;
            Union(parent, sourceParent, destParent);
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    for (int i = 0; i < mst.size(); ++i) {
        cout << mst[i].source << " - " << mst[i].destination << " : " << mst[i].weight << endl;
    }
    cout << "Total Weight of Minimum Spanning Tree: " << mstWeight << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int> > graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    kruskalMST(graph, V);

    return 0;
}
