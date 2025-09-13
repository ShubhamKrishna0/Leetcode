#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:

    //function to check if there is a subset array with sum equal to target using recursion
    bool func(int ind , int target , vector<int>& arr) {
        if(target == 0) 
            return true;
        if(ind == 0)
            return arr[0] == target;

        bool notTaken = func(ind - 1, target, arr);
        bool taken = false;
        if(arr[ind] <= target)
            taken = func(ind - 1, target - arr[ind], arr);

        return notTaken || taken;
    }
    public:
    bool isSubsetSum(vector<int> &arr , int target) {
        return func(arr.size() - 1, target, arr);
    }
};


//time:- O(2^N) where N is the length of the the array as for each 
//index there are two possible option 
//
//space:- O(N) for the recursive stack space