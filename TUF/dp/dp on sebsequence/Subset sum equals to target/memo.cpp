#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool func(int ind , int target , vector<int> &arr , vector<vector<int>>& dp) {
        if(target == 0)
            return true;

        if(ind == 0)
            return arr[0] == target;

        if(dp[ind][target] !=-1) 
            return dp[ind][target];
        
        bool notTaken = func(ind - 1, target, arr, dp);
        bool taken = false;
        if(arr[ind]<= target) 
            taken = func(ind - 1, target - arr[ind],arr , dp);

        return dp[ind][target] = notTaken || taken;
    }
    public:
    bool isSubsetSum(vector<int>&arr , int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return func(arr.size() - 1, target, arr, dp);
    }
};

//tc:-O(N*target)
//sc:-O(n*target) + O(n)as we are using a resursive stack space o(n) and 2d array O(n*target)