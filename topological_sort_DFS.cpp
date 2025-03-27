#include <bits/stdc++.h> 
using namespace std;

// Helper function to perform DFS and store the topological sort in the stack
void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj) {
    visited[node] = 1;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, st, adj);
        }
    }

    st.push(node); // Push the node into stack once all its neighbors are processed
}

// Function to perform topological sort on the directed graph
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // Building the adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v, false); // To track visited nodes
    stack<int> st; // To store the topological sort

    // Performing DFS on each unvisited node
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    vector<int> ans;
    // Pop elements from stack to get the topological order
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main() {
    int v, e;

    // Taking input for the number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    // Taking input for the edges
    cout << "Enter the edges (u, v) where there is an edge from u to v:" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Calling the topological sort function
    vector<int> result = topologicalSort(edges, v, e);

    // Printing the topological order
    cout << "Topological Sort: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
