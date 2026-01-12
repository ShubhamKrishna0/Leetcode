#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:
    int func(int ind , vector<int> &arr , vector<int> &dp) {

        if(ind == 0 )
            return arr[ind];

            if(ind <0 )
                return 0;

            if(dp[ind] != -1) {
                return dp[ind];
            }

            int pick = arr[ind] + func(ind - 2,arr , dp);
            int nonpick = 0 + func(ind - 1, arr, dp);

            return dp[ind] = max(pick, nonpick);

    }
    public:
    int nonAdjacent (vector<int> &nums) {
        int ind = nums.size() - 1;
        vector<int> dp(ind + 1, -1);

        return func(ind, nums, dp);
    }
};

int main () {
    vector<int> arr{2, 1, 4, 9};

    Solution sol;
    cout << sol.nonAdjacent(arr);

    return 0;
    
}