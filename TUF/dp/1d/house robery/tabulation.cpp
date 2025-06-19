#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(vector<int> &nums){
        int ind = nums.size();
        vector<int> dp(ind, 0);
  
        dp[0] = nums[0];

        for (int i = 1; i < ind; i++) {
            
         
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int nonPick = dp[i - 1];
            dp[i] = max(pick, nonPick);
        }

        return dp[ind-1];
    }
public:
  
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> arr1;
        vector<int> arr2;
       
      
        if(n==1)
           return money[0];
        
        for(int i=0; i<n; i++){
            
            if(i!=n-1) arr1.push_back(money[i]);
            
            
            if(i!=0) arr2.push_back(money[i]);
        }
        int ans1 = func(arr1);
        
        int ans2 = func(arr2);
    
      
        return max(ans1,ans2);
    }
};

int main() {
    vector<int> arr{1, 5, 1, 2, 6};

    Solution sol;

    cout << sol.houseRobber(arr);
}