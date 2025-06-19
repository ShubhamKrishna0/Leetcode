#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> nextLargestElements(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // to store next greater elements
        for (int i = 0; i < n; i++){
            //get the current elements
            int currEle = arr[i];
            for (int j = i + 1; j < n;j++) {
                if(arr[j] > currEle){
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n = 4;
    vector<int> arr = {1, 3, 2, 4};

    Solution sol; 
   
    vector<int> ans = sol.nextLargestElements(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}