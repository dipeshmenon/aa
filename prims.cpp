
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int selectMinVertex(vector<int>& value, vector<bool>& setMST) {
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < value.size(); i++) {
        if (setMST[i] == false && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void Findmst(vector<vector<int> >& graph) {
    int V = graph.size();
    int parent[V];
    vector<int> value(V, INT_MAX);
    vector<bool> setMST(V, false);

    parent[0] = -1;
    value[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int U = selectMinVertex(value, setMST);
        setMST[U] = true;

        for (int j = 0; j < V; j++) {
            if (graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j]) {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    int sum = 0;
    for (int k = 1; k < V; k++) {
        cout << "U->V: " << parent[k] << "->" << k << " wt = " << graph[parent[k]][k] << "\n";
        sum += graph[parent[k]][k];
    }
    cout << "Minimum cost is: " << sum;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int> > graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    Findmst(graph);

    return 0;
}
