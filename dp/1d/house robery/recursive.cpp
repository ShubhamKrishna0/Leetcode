#include<bits/stdc++.h>
using namespace std;

class Solution {
    private :
    int func(int ind , vector<int> &arr) {

        if(ind == 0) 
            return arr[ind];

            if(ind< 0 ) 
                return 0;

            int pick = arr[ind] + func(ind - 2, arr);
            int nonpick = 0+func(ind - 1, arr);

            return max(pick, nonpick);
    }
    public:
    int houseRobber(vector<int> &money) {
        int n = money.size();
        vector<int> arr1;
        vector<int> arr2;


        if(n==1)
            return money[0];

        for (int i = 0; i < n; i++) {
            if(i!= n-1)
                arr1.push_back(money[i]);

            if(i!=0)
                arr2.push_back(money[i]);
        }

        int ans1 = func(arr1.size() - 1, arr1);
        int ans2 = func(arr2.size() - 1, arr2);

        return max(ans1, ans2);
    }
};

int main() {
    vector<int> arr{1, 5, 1, 2, 6};
    Solution sol;
    cout << sol.houseRobber(arr);
}
//T.c = O(2^N) + O(2^N) where N is the given size of the array . this is the becuase each cell braches 
//into two cells leading to exponential growth , in the number of calls and the recursive 
// function is called twice 

