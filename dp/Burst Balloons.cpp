#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int maxi = -1e9;
        int n = nums.size();
        for (int idx = i; idx <= j; idx++)
        {
            int a1 = (i == 0) ? 1 : nums[i - 1];
            int a2 = (j == nums.size() - 1) ? 1 : nums[j + 1];
            /*
Left neighbor = nums[i-1]
Right neighbor = nums[j+1]
            */
            int c = a1 * nums[idx] * a2 +
                    solve(i, idx - 1, nums, dp) +
                    solve(idx + 1, j, nums, dp);

            maxi = max(maxi, c);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // bottom-up dp :- start with the smallest subarray (length 1) and work up to the largest subarray
        for (int len = 1; len <= n; len++) // len is the length of the subarray
        {
            for (int i = 1; i <= n - len + 1; i++)
            { // i is the start index of the subarray
                /*
                2) int j = i + len - 1;
Why is the condition i <= n - len + 1?
Because if the subarray has length = len,
and starts at index i,
then it ends at:
j = i + len - 1
Because subarray length = (j - i + 1)
So:
j = i + len - 1
If i=2 and len=3:
j = 2 + 3 - 1 = 4
Subarray = [2, 3, 4] → length 3.
                */
                int j = i + len - 1;
                int maxi = 0;

                for (int idx = i; idx <= j; idx++)
                {
                    int a1 = nums[i - 1];
                    int a2 = nums[j + 2];
                    int coins = a1 * nums[idx] * a2 + dp[i][idx - 1] + dp[idx + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};