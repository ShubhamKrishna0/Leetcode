#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int func(int i, int j , vector<vector<int>>&traingle, int n,
         vector<vector<int>>&dp  ){

            if(dp[i][j] !=-1)
                return dp[i][j];
            // represent i as row matrix
            // represent j as column matrix
            // n represnt the no of row
            if (i == n - 1)
                return traingle[i][j];

            int down = traingle[i][j] + func(i + 1, j, traingle, n, dp);
            int diagonal = traingle[i][j] + func(i + 1, j + 1, traingle, n, dp);
            return dp[i][j]= min(down, diagonal);
    }
    public:
    int minTraingleSum(vector<vector<int>>&traingle) {
        int n = traingle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, 0, traingle, n, dp);
    }
};

int main() {
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    Solution sol;
    cout << sol.minTraingleSum(triangle);
}