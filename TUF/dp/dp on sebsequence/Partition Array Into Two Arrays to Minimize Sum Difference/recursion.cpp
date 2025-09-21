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

     int mini = 1e9;
     for (int i = 0; i <= totalSum; i++){
     bool dummy = func(n - 1, i, arr);
     if (dummy == true)
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

/*
Step B: Try all possible subset sums i = 0..10
i = 0:

Can we make sum 0? ✅ (empty set).

Subset1 = 0, Subset2 = 10 → difference = 10. (mini = 10)

i = 1:

Can we make sum 1? ✅ (take {1}).

Subset1 = 1, Subset2 = 9 → difference = 8. (mini = 8)

i = 2:

Possible? ✅ ({2}).

Subset1 = 2, Subset2 = 8 → diff = 6. (mini = 6)

i = 3:

Possible? ✅ ({3} or {1,2}).

Subset1 = 3, Subset2 = 7 → diff = 4. (mini = 4)

i = 4:

Possible? ✅ ({4} or {1,3}).

Subset1 = 4, Subset2 = 6 → diff = 2. (mini = 2)

i = 5:

Possible? ✅ ({1,4} or {2,3}).

Subset1 = 5, Subset2 = 5 → diff = 0. (mini = 0 ✅ Best possible)

Once we hit 0 difference, we can’t do better (perfect partition).

So final result = 0.
*/