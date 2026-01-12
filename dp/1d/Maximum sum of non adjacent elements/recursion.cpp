#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int func(int ind, vector<int>& arr) {
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;
    int pick = arr[ind] + func(ind - 2, arr);  
    int nonPick = 0 + func(ind - 1, arr);  
    return max(pick, nonPick);
}
public:
    int nonAdjacent(vector<int>& nums) {
        int ind = nums.size()-1;
        return func(ind, nums);
    }
};

int main() {
    vector<int> arr{2, 1, 4, 9};
    Solution sol;
    cout << sol.nonAdjacent(arr);

    return 0;
}


//Time Complexity : O(2^N) where N is the given size of array 