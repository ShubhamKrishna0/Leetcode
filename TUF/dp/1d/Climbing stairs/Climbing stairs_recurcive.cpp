#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int climbStairs(int n) {
        // Base case
        if (n == 0) return 1;
        if (n == 1) return 1;
        
  
        int oneStep = climbStairs(n-1);
        
       
        int twoSteps = climbStairs(n-2);
        
      
        return oneStep + twoSteps;
    }
};

int main() {
    int n = 5;
    
 
    Solution sol;
    

    cout << "The total number of ways: " << sol.climbStairs(n) << endl;
    
    return 0;
}
