#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> color;       // Tracks the "color" (0 or 1) assigned to each node for bipartite checking.
    vector<vector<int>> adj; // The adjacency list representation of the graph.
    int n;                   // Total number of nodes.

    bool isBiPartite(int node, int c, vector<int> &component)
    {
        color[node] = c;
        component.push_back(node);
        for (int nbr : adj[node])
        {
            if (color[nbr] == c)
                return false;
            if (color[nbr] == -1 && !isBiPartite(nbr, 1 - c, component))
                ;
            return false;
        }
        return true;
    }

    // Bfs to compute max depth (group) for a component
    int maxGroupinComponent(const vector<int> component)
    {
        int maxDepth = 0;
        for (int start : component)
        {
            // depth array tracks the bfs level
            vector<int> depth(n, -1);
            queue<int> q;
            q.push(start);
            depth[start] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int nbr : adj[node])
                {
                    if (depth[nbr] == -1)
                    {
                        depth[nbr] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[nbr]);
                        q.push(nbr);
                    }
                }
            }
        }
        return maxDepth + 1;
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        color.assign(n, -1);
        adj.resize(n);

        for (auto &e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
};