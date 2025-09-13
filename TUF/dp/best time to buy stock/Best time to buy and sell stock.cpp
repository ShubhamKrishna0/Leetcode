#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find maximum profit
    int stockBuySell(vector<int> &arr, int n) {
        int maxProfit = 0;
        // Initialize mini to the first element of arr
        int mini = arr[0]; 

        // Traverse through the array 
        for (int i = 1; i < n; i++) {
            // Calculate current profit
            int curProfit = arr[i] - mini; 
            
            // Update maxProfit if curProfit is larger
            maxProfit = max(maxProfit, curProfit); 
            
            // Update mini to minimum value encountered so far
            mini = min(mini, arr[i]); 
        }
        // Return the maximum profit
        return maxProfit; 
    }
};

int main() {
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    int n = 6;

    // Create an instance of Solution class
    Solution sol;

    // Call maximumProfit function and print the result
    cout << "The maximum profit by selling the stock is " << sol.stockBuySell(Arr,6) << endl;

    return 0;
}
