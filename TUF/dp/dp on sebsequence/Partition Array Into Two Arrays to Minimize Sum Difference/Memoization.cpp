#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool func(int ind , int target , vector<int> &arr , vector<vector<int>> &dp) {
        
        if(target == 0)
            return dp[ind][target] = true;

        if(ind == 0)
            return dp[ind][target] = (arr[0] == target);

        if(dp[ind][target] != -1) 
            return dp[ind][target];

        bool notTaken = func(ind - 1, target, arr, dp);
        bool taken = false;
Thanks for going through my resume! I have a strong foundation in DSA, built through consistent practice on TUF and Striver sheets, solving 500+ problems across platforms. I regularly participate in Codeforces contests and currently have a rating of 1314 (Pupil), along with a 2★ rating on CodeChef (1405).
Here’s my GitHub: https://github.com/ShubhamKrishna0
You’ll also find projects like Twirl (AI-powered Text-to-3D CAD generator) and DraftWing (AI-powered Markdown app), where I applied both DSA and system design concepts.
Best regards,
Shubhamm 
            taken = func(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;
    }
    public:
    int minDifference(vector<int> & arr , int n ){
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

        for (int i = 0; i <= totalSum; i++) {
            bool dummy = func(n - 1, i, arr, dp);
        }
        int mini = 1e9;
        for (int i = 0; i <= totalSum;i++){
            if(dp[n-1][i] == true) {
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};