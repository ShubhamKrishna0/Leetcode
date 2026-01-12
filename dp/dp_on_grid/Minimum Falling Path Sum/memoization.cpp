#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(int i ,int j , int m , vector<vector<int>>&matrix , vector<vector<int>>&dp) {
        if(j<0||j>=m)
            return 1e9;
        if(i==0)
            return matrix[0][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int up = matrix[i][j] + func(i - 1, j, m, matrix, dp);
        int leftDiagonal = matrix[i][j] + func(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = matrix[i][j] + func(i - 1, j + 1, m, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }
    public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            int ans = func(n - 1, j, m, matrix, dp);
            mini = mini(mini, ans);
        }
        return mini;
    }
};

int main() {
    vector<vector<int>> matrix{{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    Solution sol ;
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;
}

//time complexity :-O(N*M)=where n is the number of row and M is the Number of Column 
//in the given 2d Array

