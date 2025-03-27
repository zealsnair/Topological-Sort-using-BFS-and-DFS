#include <bits/stdc++.h> 
using namespace std;

// Function to perform topological sort using BFS (Kahn's Algorithm)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    // Building the adjacency list from edges
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Initialize indegree array
    vector<int> indegree(v, 0);

    // Calculate indegree of each vertex
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;

    // Add vertices with 0 indegree to the queue
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // BFS process
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        // Reduce the indegree of neighbors
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;

            // If indegree of neighbor becomes 0, add it to the queue
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main() {
    int v, e;

    // Take input for the number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    // Take input for the edges (u, v) where there's a directed edge from u to v
    cout << "Enter the edges (u, v) where there is an edge from u to v:" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Call the topological sort function
    vector<int> result = topologicalSort(edges, v, e);

    // Print the topologically sorted order
    cout << "Topological Sort: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
