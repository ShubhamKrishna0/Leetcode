
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int i, vector<vector<int>> &graph, vector<int> &set)
    {
        queue<int> q;
        q.push(i);
        set[i] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (set[it] == -1)
                {
                    set[it] = !set[node];
                    q.push(it);
                }
                else if (set[it] == set[node])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> set(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (set[i] == -1)
            {
                if (check(i, graph, set) == false)
                    return false;
            }
        }
        return true;
    }
};