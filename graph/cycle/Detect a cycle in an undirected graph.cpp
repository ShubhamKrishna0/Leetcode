#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    // Function to perform BFS to detect cycle in an undirected graph
    bool bfs(int start, vector<int> adj[], vector<bool> &visited) {

        // Queue will store {node, parent}
        queue<pair<int, int>> q;

        // Push starting node with parent = -1
        q.push({start, -1});
        visited[start] = true;

        // Process until queue becomes empty
        while (!q.empty()) {

            // Get current node and its parent
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all adjacent nodes
            for (auto neighbour : adj[node]) {

                // If neighbour is not visited → visit it
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, node});
                }

                // If neighbour is already visited and it's NOT the parent
                // then an undirected cycle is detected
                else if (neighbour != parent) {
                    return true;
                }
            }
        }
        return false;  // No cycle found via BFS
    }

public:
    bool isCycle(int V, vector<int> adj[]) {

        // Visited array
        vector<bool> visited(V, false);

        // Check every component (in case graph is disconnected)
        for (int i = 0; i < V; i++) {

            // Run BFS only on unvisited nodes
            if (!visited[i]) {

                // If BFS detects a cycle → return true
                if (bfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false; // No cycle in any component
    }
};


int main()
{

    int V = 6;
    vector<int> adj[V] = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 5},
        {2, 4}};

    Solution sol;

    bool ans = sol.isCycle(V, adj);

    // Output
    if (ans)
        cout << "The given graph contains a cycle.";
    else
        cout << "The given graph does not contain a cycle.";

    return 0;
}