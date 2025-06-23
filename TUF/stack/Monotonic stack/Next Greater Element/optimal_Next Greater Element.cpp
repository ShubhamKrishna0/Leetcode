#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> nextLargerElement(vector <int> arr) {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0;i--){
            int currEle = arr[i];

        while(!st.empty() && st.top() <= currEle) {
            st.pop();
        }
        if(st.empty())
            ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(currEle);
        }
        return ans;
    }
};

int main() {
    int n = 4;
    vector<int> arr = {1, 3, 2, 4};

    Solution sol;

    vector<int> ans = sol.nextLargerElement(arr);

    cout << "the next greatest elements are";

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
    
}