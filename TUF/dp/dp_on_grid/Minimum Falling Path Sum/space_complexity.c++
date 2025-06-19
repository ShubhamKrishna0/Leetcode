#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minFallingPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0);
        vector<int> cur(m, 0);

        for (int j = 0; j < m;j++) {
            prev[j] = matrix[0][j] ;
        }
        for (int i = 1; i < n;i++) {
            for (int j = 0; j < m;j++){
                int up = matrix[i][j] + prev[j];
                int leftDiagonal = j - 1 > 0 ? matrix[i][j] + prev[j - 1] : 1e9;
                int rightDiagonal = j + 1 < m ? matrix[i][j] + prev[j + 1] : 1e9;
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }
            prev = cur;
        }
        int mini = INT_MAX;
        for (int j = 0; j < m;j++) {
            mini = min(mini, prev[j]);
        }
        return mini;

    }
};

int main() {
    vector<vector<int>> matrix{
        {4, 3, 4},
        {4, 5, 1},
        {4, 6, 2},
        {4, 1, 4}};
    Solution sol;
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;

}