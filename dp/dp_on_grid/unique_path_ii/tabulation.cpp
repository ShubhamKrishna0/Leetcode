#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(int m,int n , vector<vector<int>> &matrix ,vector<vector<int>> &dp){
        for (int i = 0; i < m;i++) {
            for (int j = 0; j < n; j++){
                if(matrix[i][j] == 1)
                  {  
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;

                if(i > 0)
                    up = dp[i - 1][j];
                if(j>0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
    public:
    int uniquePathsWithObstacles(vector<vector<int>>&matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        return func(m, n, matrix, dp);
    }
};

int main () {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    Solution sol;
    cout << "Number of path with Obstacles" << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}