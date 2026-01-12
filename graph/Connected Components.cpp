#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            for (auto adjNodes : adjLs[i])
            {
                if (vis[adjNodes] != 1)
                {
                    vis[adjNodes] = 1;
                    q.push(adjNodes);
                }
            }
        }
    }

    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges)
    {
        int E = edges.size();
        vector<int> adjLs[V];

        for (int i = 0; i < E; i++)
        {
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }

        int vis[V] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};