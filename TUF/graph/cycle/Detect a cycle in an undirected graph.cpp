#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to perform BFS traversal
    bool bfs(int i, vector<int> adj[],
             vector<bool> &visited)
    {

        // Queue to store {node, parent}
        queue<pair<int, int>> q;

        /* Push initial node in queue
        with no one as parent */
        q.push({i, -1});

        // Mark the node as visited
        visited[i] = true;

        // Until the queue is empty
        while (!q.empty())
        {

            // Get the node and its parent
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all the neighbors
            for (auto it : adj[node])
            {

                // If not visited
                if (!visited[it])
                {

                    // Mark the node as visited
                    visited[it] = true;

                    /* Push the new node in queue
                    with curr node as parent */
                    q.push({it, node});
                }

                /* Else if it is visited with some
                different parent a cycle is detected */
                else if (it != parent)
                    return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {

        // Visited array
        vector<bool> visited(V, false);

        /* Variable to store if
        there is a cycle detected */
        bool ans = false;

        // Start Traversal from every unvisited node
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {

                // Start BFS traversal and update result
                ans = bfs(i, adj, visited);

                // Break if a cycle is detected
                if (ans)
                    break;
            }
        }
        return ans;
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