#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int modulo = 1e9 + 7;

private:
    int findWaysUntil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        if (ind == 0)
            return (arr[0] == target) ? 1 : 0;
        if (dp[ind][target] == -1)
            return dp[ind][target];
        int notTaken = findWaysUntil(ind - 1, target, arr, dp);
        int taken = 0;

        if (arr[ind] <= target)
            taken = findWaysUntil(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = (notTaken + taken) % modulo;
    }

public:
    int prefectSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return findWaysUntil(n - 1, k, arr, dp);
    }
};