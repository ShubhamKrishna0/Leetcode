#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> stockSpan(vector<int> arr , int n) {
        vector<int> ans(n);
        for (int i = 0; i < n;i++){
            int currSpan = 0;
            for (int j = i; j >= 0;j--) {
                if(arr[j] <= arr[i]){
                    currSpan++;
                }
                else break;
            }
            ans[i] = currSpan;
        }
        return ans;
    }
};
