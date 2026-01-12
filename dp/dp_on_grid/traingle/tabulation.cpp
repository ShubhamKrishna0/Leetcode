#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(vector<vector<int>> &traingle , int n , vector<vector<int>> &dp) {
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = traingle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--){
            for (int j = i; j >= 0;j--){
                int down = traingle[i][j] + dp[i + 1][j];
                int diagonal = traingle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);

            }
        }
        return dp[0][0];
    }
    public:
    int minTraingleSum(vector<vector<int>> &traingle){
        int n = traingle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(traingle, n, dp);
    }
};
int main() {
     vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};
     Solution sol;
     cout << sol.minTraingleSum(triangle);

     return 0;

}