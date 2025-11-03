#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------------
🧠 Problem Context:
We are given an undirected graph with n nodes (1-indexed).
We must divide all nodes into "groups" such that:
- Each edge connects nodes in consecutive groups.
- Within a connected component, we find the maximum number
  of such groups possible (like BFS levels).
Then we sum the maximum group counts for all components.

If any component is NOT bipartite (odd-length cycle),
then it's impossible → return -1.
-------------------------------------------------------------
*/

class Solution
{
    // ---------- Member Variables ----------
    vector<int> color;       // Stores bipartite color: -1 (unvisited), 0, or 1
    vector<vector<int>> adj; // Adjacency list of the graph
    int n;                   // Total number of nodes in the graph

    // -------------------------------------------------------
    // 🔍 Helper 1: Check if the connected component is bipartite
    // -------------------------------------------------------
    bool isBiPartite(int node, int c, vector<int> &component)
    {
        color[node] = c;           // Assign color 'c' to current node
        component.push_back(node); // Add node to the current component

        for (int nbr : adj[node]) // Check all neighbors
        {
            if (color[nbr] == c) // Same color neighbor → Not bipartite
                return false;

            // If unvisited neighbor → recursively color with opposite color
            if (color[nbr] == -1 && !isBiPartite(nbr, 1 - c, component))
                return false; // If deeper recursion fails, return false
        }
        return true; // All neighbors colored properly → Bipartite
    }

    // -------------------------------------------------------
    // ⚡ Helper 2: Find maximum possible groups in one component
    // -------------------------------------------------------
    int maxGroupinComponent(const vector<int> component)
    {
        int maxDepth = 0; // Tracks the largest BFS depth seen so far

        // Try BFS from every node in the component
        // because the graph might not be a tree (could be many equal-length paths)
        for (int start : component)
        {
            vector<int> depth(n, -1); // depth[i] = BFS level of node i
            queue<int> q;

            q.push(start);    // Start BFS from 'start'
            depth[start] = 0; // Start node has depth 0

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                // Visit all neighbors
                for (int nbr : adj[node])
                {
                    if (depth[nbr] == -1) // If neighbor not yet visited in this BFS
                    {
                        depth[nbr] = depth[node] + 1;         // Assign next level
                        maxDepth = max(maxDepth, depth[nbr]); // Track the farthest depth
                        q.push(nbr);
                    }
                }
            }
        }

        // Groups = max BFS depth + 1 (since depth starts from 0)
        return maxDepth + 1;
    }

    /*
    🧩 Example Walkthrough:
    Suppose edges form a chain: 1—2—3—4
    Adjacency list:
    1: [2]
    2: [1,3]
    3: [2,4]
    4: [3]

    BFS Depth from each start node:
    Start | Farthest | Distance | maxDepth
    -------|-----------|----------|---------
     1     | 4         | 3        | 3
     2     | 4         | 2        | 3
     3     | 1         | 2        | 3
     4     | 1         | 3        | 3

    => maxDepth = 3 → total groups = 3 + 1 = 4 ✅
    */

public:
    // -------------------------------------------------------
    // 🚀 Main Function: Magnificent Sets
    // -------------------------------------------------------
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        this->n = n; // Save n for helper functions

        color.assign(n, -1); // Initialize all nodes as uncolored
        adj.resize(n);       // Prepare adjacency list

        /*
        Build the graph:
        Input nodes are 1-indexed, convert to 0-indexed internally.
        Since the graph is undirected, add both directions.
        */
        for (auto &e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Store all connected components
        vector<vector<int>> components;

        // Identify each component using DFS + bipartite check
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1) // Unvisited node → new component
            {
                components.emplace_back(); // Add a new empty vector to store nodes of this component

                // If component is not bipartite → impossible to form groups
                if (!isBiPartite(i, 0, components.back()))
                    return -1;
            }
        }

        // Sum up the maximum possible group counts across all components
        int totalGroups = 0;
        for (auto &comp : components)
            totalGroups += maxGroupinComponent(comp);

        return totalGroups;
    }
};

/*
-------------------------------------------------------------
⏱️ Time Complexity:
- Building adjacency list: O(n + m)
- Bipartite check (DFS): O(n + m)
- BFS per node (to find maxDepth): O(n * (n + m)) worst-case per component
  → Acceptable for small constraints.
Overall ≈ O(n²) in worst case.

💾 Space Complexity:
- Adjacency list: O(n + m)
- Color + Depth arrays: O(n)
Total: O(n + m)

🧩 Edge Cases to Remember:
1. Disconnected graph (multiple components)
2. Single node (no edges) → 1 group
3. Odd-length cycle → return -1
4. Chain graph (like a path) → groups = number of nodes
5. Complete bipartite graph (Kₘ,ₙ) → groups = 2
-------------------------------------------------------------
*/
