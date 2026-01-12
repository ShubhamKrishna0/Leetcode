#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //Helper function to apply memoization
    int func(int n, vector<int> &dp) {
        // Base condition
        if (n <= 1) {
            return 1;
        }
        
        // Check if the subproblem is already solved
        if (dp[n] != -1) {
            return dp[n];
        }
        
        // Return the calculated value
        return dp[n] = func(n-1, dp) + func(n-2, dp);
    }
    
public:
    // Function to count total ways to reach nth stair
    int climbStairs(int n) {
        // Initialize dp vector with -1
        vector<int> dp(n + 1, -1); 
        
        return func(n, dp);
    }
};

int main() {
    int n = 5;
    
    // Create an instance of Solution class
    Solution sol;

    // Print the answer
    cout << "The total number of ways: " << sol.climbStairs(n) << endl;

    return 0;
}
