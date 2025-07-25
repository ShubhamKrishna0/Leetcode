#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>arr){
        int n = arr.size(); 
        //size of the array
        vector<int> ans(n);
        //to store the next greater elements
        stack<int> st;
        //stack to get elements in LIF Fasion

        for (int i = 2 * n - 1; i >= 0;i--){
            int ind = i % n;
            int currEle = arr[ind];
            while(!st.empty() && st.top() <= currEle){
                st.pop();
            }
            if(i<n) {
                if(st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }
            st.push(currEle);
        }
        return ans;
    }
};