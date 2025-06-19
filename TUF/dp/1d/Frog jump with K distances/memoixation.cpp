#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int func(int ind, vector<int> &heights, int k, vector<int> &dp){
        //Base case
        if(ind == 0){
            return 0;
        }
//dp
        if(dp[ind]!= -1)
            return dp[ind];

        int mmStep = INT_MAX;
        
        for(int j = 1; j <= k; j++){
            
            if(ind-j >= 0){
                //dp
                int jump = func(ind-j, heights, k, dp) +
                 abs(heights[ind] - heights[ind-j]);
                
                mmStep = min(jump, mmStep);
            }
        }
   //dp
        return 
        dp[ind] = mmStep;
    }
public:

    int frogJump(vector<int> &heights, int k) {
        int ind = heights.size()-1;
//dp
        vector<int> dp(ind + 1, -1);
        return func(ind, heights, k, dp);
    }
};

int main () {
    vector<int> height{15, 4, 1, 14, 15};
    int k = 3;
    Solution sol;
    cout << "Minimum Energy :" << sol.frogJump(height, k) << endl;
    return 0;

}

// t.c= O(k*n)
// s.c= O(N)+O(N) we are using recursive stack space O(N) and an array again O(N)...so total space complexity we have O(N)