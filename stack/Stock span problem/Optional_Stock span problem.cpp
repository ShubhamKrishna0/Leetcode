#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    /*
    Function to find the indices of previous
    greater elements for each elemntsint the array......
    */
        vector<int> findPGE(vector<int> arr) {
            int n = arr.size();
            vector<int> ans(n);
            stack<int> st;
//start traversing from the front
            for (int i = 0; i < n; i++) {
                //get the current elements
                int currEle = arr[i];
                while(!st.empty() && arr[st.top()] <= currEle){
                    st.pop();
                }
                if(st.empty())
                    ans[i] = -1;
                else 
                    ans[i] = st.top();

                st.push(i);
            }
            return ans;
        }
        public:
        vector <int> stockSpan(vector<int> arr , int n) {
            vector<int> PGE = findPGE(arr);
            vector<int> ans(n);

            for (int i = 0; i < n;i++) {
                ans[i] = i - PGE[i];
            }
            return ans;
        }
};