#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int nonAdjacent (vector<int> &nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int pick = nums[i];//Maximum Sum if we Pick current element 
            if(i > 1) {
                pick += prev2;
            }
            int nonPick = 0 + prev;

            int cur_i = max(pick, nonPick);

            prev2 = prev;
            prev = cur_i;  
        }
        return prev;

    }
};

int main() {
    vector<int> arr{2, 1, 4, 9};
    Solution sol;
    cout << sol.nonAdjacent(arr);
    return 0;

}