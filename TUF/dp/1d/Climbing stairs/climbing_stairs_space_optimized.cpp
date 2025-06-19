#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int climbStairs(int n){
        int prev2 = 1;
        int prev = 1;

        for (int i = 2; i <= n; i++){
            int cur_i = prev2 + prev;
            prev2 = prev;
            prev = cur_i;
        }
        return prev;

    }
};

int main() {
    int n = 3;

    // Create an instance of Solution class
    Solution sol;

    // Print the answer
    cout << "The total number of ways: " << sol.climbStairs(n) << endl;

    return 0;
}