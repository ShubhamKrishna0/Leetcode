#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int ind , vector<int> &dp) {

        if (ind == 0) return 0;

        if(dp[ind] !=-1 )
            return dp[ind];

        int jumpOne = frogJump(heights, ind - 1,dp) + abs(heights[ind] - heights[ind - 1]);
        
        int jumpTwo = INT_MAX;
        
        if (ind > 1) {
            jumpTwo = frogJump(heights, ind - 2,dp) + abs(heights[ind] - heights[ind - 2]);
        }
    
        return 
        dp[ind] =min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n + 1, -1);
        return frogJump(heights, n - 1, dp);
    }
};

int main() {
    Solution sol;
    vector<int> heights = {3, 10, 3, 11, 3};
    int result = sol.frogJump(heights);
    cout << "Minimum energy required: " << result << endl;
    return 0;
}