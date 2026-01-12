#include<bits/stdc++.h>
using namespace std;

class Solution {
    int func(int ind , vector<int> &arr , vector<int> &dp) {


        if(ind ==  0)
            return arr[ind];

        if(ind<0)
            return 0;
        
        if(dp[ind] != -1) {
            return dp[ind];
        }
            int pick = arr[ind] + func(ind - 2, arr, dp);
            int nonPick = 0 + func(ind - 1, arr, dp);

            return dp[ind] = max(pick, nonPick);
    }
    public:
    int houseRobber (vector<int> &money) {
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
        vector<int> dp(n, -1);
        int ans1 = func(arr1.size() - 1, arr1, dp);

        vector<int> dp1(n, -1);
        int ans2 = func(arr2.size() - 1, arr2, dp1);

        return max(ans1, ans2);
    }
};

int main () {
    vector<int> arr{1, 5, 1, 2, 6};
    Solution sol;

    cout << sol.houseRobber(arr);

}