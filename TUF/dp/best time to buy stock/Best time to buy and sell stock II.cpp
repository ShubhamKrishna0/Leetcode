#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int func(int ind, int buy, int n, vector<int> &arr , vector<vector<int>> &dp) {
       
        if (ind == n) {
            return 0;
        }

        if(dp[ind][buy]!=-1) {
            return dp[ind][buy];
        }

        int profit = 0;
        
        if (buy == 0) { 
            profit = max(0 + func(ind + 1, 0, n, arr,dp), (-1)*arr[ind] + func(ind + 1, 1, n, arr,dp));
        }
        
        if (buy == 1) { 
            profit = max(0 + func(ind + 1, 1, n, arr, dp), arr[ind] + func(ind + 1, 0, n, arr, dp));
        }

        return dp[ind][buy] =  profit;
    }
public:
    
    int stockBuySell(vector<int> &arr, int n) {
        if (n == 0) 
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = func(0, 0, n, arr,dp);
        
        return ans;
    }
};