#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int ninjaTraining(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++){
            for (int last = 0; last < 4;  last++){
                dp[day][last] = 0;
                for (int task = 0; task <= 2; task++) {
                    if(task != last) {
                        int activity = matrix[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};
int main() {
    vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
                                
    Solution sol;
    
    cout << sol.ninjaTraining(points);
}

//tinme complexity :there are n*4 states and for  ever