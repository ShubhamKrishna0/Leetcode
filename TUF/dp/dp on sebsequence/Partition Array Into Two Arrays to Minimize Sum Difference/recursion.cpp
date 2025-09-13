#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool func(int ind , int target , vector<int> &arr) {

        //base case:- If the target sum is 0 , return true
        if(target == 0)
            return true;
            //base case:- if we have considered all 
            //elements and the target is still not 0 
        if(ind == 0)
            return (arr[0] == target);

        bool notTaken = func(ind - 1, target, arr);

        bool taken = false;
        if(arr[ind] <= target) {
            taken = func(ind - 1, target - arr[ind], arr);
        }
        return notTaken || taken;
    }



    public:
    int minDifference(vector<int> &arr , int n) {
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
 }

 for (int i = 0; i <= totalSum;i++) {
     bool dummy = func(n - 1, i, arr);
 }

     int mini = 1e9;
 for (int i = 0; i <= totalSum; i++){
     if (func(n - 1, i, arr) == true)
     {
         int diff = abs(i - (totalSum - i));
         mini = min(mini, diff);
     }
            }
            return mini;
       
    }
};

int main (){
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    Solution sol;
    cout << "The minimum absolute Difference is :" << sol.minDifference(arr, n);
    return 0;
}