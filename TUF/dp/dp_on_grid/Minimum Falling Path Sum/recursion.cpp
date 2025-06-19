    #include<bits/stdc++.h>
    using namespace std;

    class Solution {
        private:
        int func(int i , int j  , int m , vector<vector<int>>&matrix){
            if(j<0||j>=m )
                return 1e9;

            if(i==0)
                return matrix[0][j];

            int up = matrix[i][j] + func(i - 1, j, m, matrix);
            int leftDiagonal = matrix[i][j] + func(i - 1, j - 1, m, matrix);
            int rightDiagonal = matrix[i][j] + func(i - 1, j + 1, m, matrix);

            return min(up, min(leftDiagonal, rightDiagonal));
        }
        public:
        int minFallingPathSum(vector<vector<int>> &matrix){
            int n = matrix.size();
            int m = matrix[0].size();
            int mini = INT_MAX;

            for (int j = 0; j < m; j++) {
                int ans = func(n - 1, j, m, matrix);
                mini = min(mini, ans);
            }
            return mini;
        }
    };

    /*
    | Step         | Cell (i,j) | Value |
    | ------------ | ---------- | ----- |
    | Start        | (0,0)      | 1     |
    | bottom-right | (1,1)      | 3     |
    | bottom       | (2,1)      | 1     |
    | bottom-left  | (3,0)      | 1     |
    |              | **Total**  | **6** |

    */