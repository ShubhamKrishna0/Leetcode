#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> finOrder(int num, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(num, vector<int>());
        vector<int> indegree(num);
        for (vector<int> &ans : prerequisites)
        {
            graph[ans[1]].push_back(ans[0]);
            indegree[ans[0]]++;
        }
        queue<int> zero;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
                zero.push(i);
        }
        vector<int> ans;
        int visited = 0;
        while (!zero.empty())
        {
            int u = zero.front();
            zero.pop();
            ans.push_back(u);
            visited++;
            for (int v : graph[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    zero.push(v);
                }
            }
        }
        if (visited == num)
        {
            return ans;
        }
        return {};
    }
};