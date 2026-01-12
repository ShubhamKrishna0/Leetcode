#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& arr, int n) {
        int TotalSum = 0;
        for (int i = 0; i < n; i++) {
            TotalSum += arr[i];
        }

        // DP table: dp[i][s] = whether we can make sum s using first i elements
        vector<vector<bool>> dp(n, vector<bool>(TotalSum + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Initialize with the first element
        if (arr[0] <= TotalSum)
            dp[0][arr[0]] = true;

        // Fill DP table
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= TotalSum; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = notTaken || taken;
            }
        }

        // Find minimum difference
        int mini = 1e9;
        for (int s1 = 0; s1 <= TotalSum; s1++) {
            if (dp[n - 1][s1]) {
                int diff = abs(s1 - (TotalSum - s1));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};
