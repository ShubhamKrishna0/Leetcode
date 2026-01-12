#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int frogJump (vector<int> & height , int k) {
        int ind = height.size();

        vector<int> dp(ind + 1, -1);
        dp[0] = 0;

        for (int i = 1; i < ind; i++) {
            int mmSteps = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if(i-j >= 0 ) {
                    int jump = dp[i - j] + abs(height[i] + height[i - j]);

                    mmSteps = min(jump, mmSteps);
                }
            }
            dp[i] = mmSteps;
        }
        return dp[ind - 1];   //Result is stored in the last element of dp
    }
};

int main() {
    vector<int> height = {15, 4, 1, 14, 15};
    int k = 3;
    Solution sol;
    cout << "Minimum Energy : " << sol.frogJump(height, k) << endl;
    return 0;

}