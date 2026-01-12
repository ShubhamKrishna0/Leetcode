#include<bits/stdc++.h>
using namespace std;

class Solution{
        private:

        int func(int day , int last , vector<vector<int>> &points , 
        vector<vector<int>> &dp){

            //for memoization
            if(dp[day][last] != -1)
                return dp[day][last];

            if(day == 0){
                int maxi = 0;

                for (int i = 0; i <= 2; i++) {
                    if(i!= last )
                        maxi = max(maxi, points[0][i]);
                }
                return dp[day][last] = maxi;
            }
            int maxi = 0;

            for (int i = 0; i <= 2;i++){
                if(i!= last){
                    /*
                    Calculate the points for the current activity and 
                    add it ti the maximum point obtained so 
                    */
                    int activity = points[day][i] + func(day - 1, i, points, dp);
                    maxi = max(maxi, activity);
                }
            }
            return dp[day][last] = maxi;
        }
        public:
        int ninjatraining(vector<vector<int>> &matrix){
            int day = matrix.size();
            vector<vector<int>> dp(day, vector<int>(4, -1));
            int last = 3;
            return func(day-1, last, matrix, dp);
        }
};

int main() {
    vector<vector<int>> points = {
     {10, 40, 70},
     {20, 50, 80}, 
     {30, 60, 90}
    };

    Solution sol;
    cout << sol.ninjatraining(points);
}