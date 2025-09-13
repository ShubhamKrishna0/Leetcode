#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:

    bool func(int n , int target , vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n;i++) {
            dp[i][0] = true;    
        }
        if(arr[0] <= target) {
            dp[0][arr[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int i = 1; i <= target; i++) {
                bool notTaken = dp[ind - 1][i];

                bool taken = false;
                if(arr[ind] <= i){
                    taken = dp[ind - 1][i - arr[ind]];
                }
                dp[ind][i] = notTaken || taken;

            }
        }
        return dp[n - 1][target];
    }
    public:
    int isSubsetSum (vector<int> arr , int target) {
        return func(arr.size(), target, arr);
    }
};