#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<int> price1;
    vector<vector<int>> special1;
    unordered_map<string, int> memo;

    // convert needs vector to string key for memo
    string encode(const vector<int> &needs)
    {
        string key;
        for (int x : needs)
        {
            key += to_string(x) + "#";
        }
        return key;
    }

    //
    int dfs(vector<int> &needs)
    {
        string key = encode(needs);

        // If already computed, return stored answer
        if (memo.count(key))
        {
            return memo[key];
        }

        // :1 Buy everything at normal price
        int minCost = 0;
        for (int i = 0; i < n; i++)
        {
            minCost += needs[i] * price1[i];
        }

        // :2 Try each special offer
        for (auto &offer : special1)
        {
            vector<int> nextNeeds(needs);
            bool valid = true;

            // check if offers can be applied
            for (int i = 0; i < n; i++)
            {
                if (offer[i] > nextNeeds[i])
                {
                    valid = false;
                    break;
                }
                nextNeeds[i] -= offer[i];
            }

            if (valid)
            {
                minCost = min(
                    minCost,
                    offer[n] + dfs(nextNeeds));
            }
        }
        return memo[key] = minCost;
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        price1 = price;
        special1 = special;
        n = price.size();
        return dfs(needs);
    }
};