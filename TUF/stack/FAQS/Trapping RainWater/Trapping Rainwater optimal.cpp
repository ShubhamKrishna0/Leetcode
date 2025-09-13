#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    int trap(vector<int> &height) {
        int n = height.size();
        int total = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1;

        while(left < right) {
            if(height[left] <=height[right ]){
                if(leftMax >height[left]){
                    total += leftMax - height[left];
                }else
                    leftMax = height[left];
                left = left + 1;
            }else {
                if( rightMax > height[right]){
                    total += rightMax - height[right];
                }else
                    rightMax = height[right];
                right = right - 1;
            }
        }
        return total;
    }
};
int main() {
    vector<int> heights = {4, 2, 0, 3, 2, 5};
    
    Solution sol; 
    
    int ans = sol.trap(heights);
    
    cout << "The trapped rainwater is: " << ans;
    return 0;
}