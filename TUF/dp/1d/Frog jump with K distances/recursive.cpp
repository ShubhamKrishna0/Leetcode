#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int func(int ind, vector<int> &heights, int k){
        //Base case
        if(ind == 0){
            return 0;
        }

        int mmStep = INT_MAX;
        
        for(int j = 1; j <= k; j++){
            
            if(ind-j >= 0){
                int jump = func(ind-j, heights, k) +
                 abs(heights[ind] - heights[ind-j]);
                
                mmStep = min(jump, mmStep);
            }
        }
   
        return mmStep;
    }
public:

    int frogJump(vector<int> &heights, int k) {
        int ind = heights.size()-1;
        
        return func(ind, heights, k);
    }
};

int main () {
    vector<int> height{15, 4, 1, 14, 15};
    int k = 3;
    Solution sol;
    cout << "Minimum Energy :" << sol.frogJump(height, k) << endl;
    return 0;

}
/*as there we have n step there for we have k way therefore the 
time complexity is given by o(N)*K
space complexity is given by o(n)


*/