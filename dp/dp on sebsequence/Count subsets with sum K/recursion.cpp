#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int modulo = 1e9 + 7;

private:
    int findWaysUntil(int ind, int target, vector<int> &arr)
    {
        if (target == 0)
            return 1;
        if (ind == 0)
            return (arr[0] == target) ? 1 : 0;

        int notTaken = findWaysUntil(ind - 1, target, arr);
        int Taken = 0;
        if (arr[ind] <= Taken)
            Taken = findWaysUntil(ind - 1, target - arr[ind], arr);
        return (notTaken + Taken) % modulo;
    }

public:
    int prefecSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        return findWaysUntil(n - 1, k, arr);
    }
};
int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    Solution sol;
    cout << "the numebr pf subset Found are " << sol.prefecSum(arr, k);

    return 0;
}