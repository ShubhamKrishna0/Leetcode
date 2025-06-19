#include<bits/stdc++.h>
using namespace std;

class Solution {
    int func(int n , int m , vector<vector<int>> &matrix) {
        vector<vector<vector<int>>> dp(n, 
            vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m;j1++) {
            for (int j2 = 0; j2 < m;j2++) {
                if(j1== j2)
                    dp[n - 1][j1][j2] = matrix[n - 1][j1];
                    else
                        dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m;j2++) {
                    int maxi = INT_MAXI;
                    for (int di = -1; di <= 1; di++){
                        for (int dj = -1; dj <= -1; dj++) {
                            int ans;
                            if(j1 ==j2)
                                ans = matrix[i][j1];
                            else
                                ans = matrix[i][j1] + matrix[i][j2];
            
                                if((j1+di <0 || j1+di >= m) ||(j1+dj <0 || j1+dj >= m) )
                                    ans += -1e9;
                                else
                                    ans += dp[i + 1][j1 + di][j2 + dj];

                                maxi = max(ans, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
public:
    
    int cherryPickup(vector<vector<int>> &matrix){
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        
       
        return func(n, m, matrix);
    }
};