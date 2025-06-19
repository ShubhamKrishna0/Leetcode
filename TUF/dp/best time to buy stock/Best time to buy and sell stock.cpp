#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int stockBuySell (vector<int> &arr , int n ){
        int maxProfit = 0;
        int mini = arr[0];
        for (int i = 0; i < n;i++){
            int curProfit = arr[i] - mini;
            maxProfit = max(maxProfit, curProfit);
            mini = min(mini, arr[i]);
        }
        return maxProfit;
    }
};

int main() {
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    int n = 6;
    Solution sol;
    cout << "The Maximum profit of the seeling of the stock is" << sol.stockBuySell(Arr.6) << endl;
    return 0;

}