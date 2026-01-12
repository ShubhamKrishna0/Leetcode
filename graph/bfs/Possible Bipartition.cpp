
#include <bits/stdc++.h>  
// Include all standard C++ libraries - gives access to vector, function, etc.

using namespace std;       
// Use standard namespace - allows writing 'vector' instead of 'std::vector'

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n + 1);
        // vector<vector<int>> - 2D vector to store adjacency list
        // graph(n + 1) - creates n+1 empty vectors (1-indexed, ignore index 0)
        
        for (auto &d : dislikes)
        {
            // auto &d - automatically deduce type, reference to avoid copying
            // d is each dislike pair [person1, person2]
            
            graph[d[0]].push_back(d[1]); 
            // graph[d[0]] - access adjacency list of person d[0]
            // push_back(d[1]) - add person d[1] as neighbor of d[0]
            
            graph[d[1]].push_back(d[0]); 
            // graph[d[1]] - access adjacency list of person d[1]
            // push_back(d[0]) - add person d[0] as neighbor of d[1] (undirected graph)
        }
        
        vector<int> color(n + 1, 0);
        // vector<int> - 1D vector to store colors
        // color(n + 1, 0) - creates n+1 integers, all initialized to 0
        // 0=uncolored, 1=group1, -1=group2
        
        function<bool(int, int)> dfs = [&](int node, int c)
        // function<bool(int, int)> - wrapper that can store callable objects
        //   - Returns bool
        //   - Takes two int parameters
        // dfs - variable name for the function
        // [&] - lambda capture clause, captures all variables by reference
        //   - allows lambda to access color, graph, n variables
        // (int node, int c) - lambda parameters:
        //   - node: current node being processed
        //   - c: color to assign (1 or -1)
        // std::function wrapper needed because:
        //   - lambdas can't directly call themselves recursively
        //   - provides "name" that lambda can reference for recursion
        {
            color[node] = c; 
            // color[node] - access color array at index 'node'
            // = c - assign color 'c' to current node

            for (int nei : graph[node])
            // for (int nei : ...) - range-based for loop
            // graph[node] - get all neighbors of current node
            // nei - each neighbor in the adjacency list
            {
                if (color[nei] == c)
                // color[nei] - get color of neighbor
                // == c - check if neighbor has same color as current node
                    return false;
                // return false - bipartition impossible (adjacent nodes same color)
                    
                if (color[nei] == 0)
                // color[nei] == 0 - check if neighbor is uncolored
                {
                    if (!dfs(nei, -c))
                    // dfs(nei, -c) - recursively color neighbor with opposite color
                    // -c - if c=1 then -c=-1, if c=-1 then -c=1
                    // !dfs(...) - if recursive call returns false
                        return false;
                    // return false - propagate failure up the recursion
                }
            }
            return true; 
            // return true - successfully colored this node and all its neighbors
        };

        for (int i = 1; i <= n; i++)
        // for loop from 1 to n (1-indexed nodes)
        // i - current node being checked
        {
            if (color[i] == 0)
            // color[i] == 0 - check if node i is uncolored
            {
                if (!dfs(i, 1))
                // dfs(i, 1) - start DFS from node i with color 1
                // !dfs(...) - if DFS returns false
                    return false; 
                // return false - bipartition failed for this component
            }
        }
        return true; 
        // return true - all components successfully bipartitioned
    }
};