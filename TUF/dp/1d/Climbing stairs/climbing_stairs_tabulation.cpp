#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //function to count total ways to  reach nth stair
    int climbstairs(int n){
        //declear an dp array of size n+1
        vector<int> dp(n + 1, -1);

        dp[0]=1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

    }
};
int main(){
    int n = 3;
    Solution sol;
    cout << "The Total number of Ways " << sol.climbstairs(n) << endl;
    return 0;

}