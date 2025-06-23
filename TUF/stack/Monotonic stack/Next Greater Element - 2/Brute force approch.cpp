#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the next greater element
    for each element in the circular array */
    vector<int> nextGreaterElements(vector<int> arr) {
       
        int n = arr.size(); // size of array
        
        // To store the next greater elements
        vector<int> ans(n, -1);
        
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
             
            /* Nested loop to get the 
            next greater element */
            for(int j=1; j < n; j++) {
                
                // Getting the hypothetical index
                int ind = (j+i) % n;
                
                // If the next greater element is found
                if(arr[ind] > currEle) {
                    
                    // Store the next greater element
                    ans[i] = arr[ind];
                    
                    // Break from the loop
                    break;
                }    
            }
        }
       
        // Return the answer
        return ans;
    }
};

int main() {
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
   
    /* Creating an instance of 
    Solution class */
    Solution sol; 
   
    /* Function call to find the next greater element
    for each element in the circular array */
    vector<int> ans = sol.nextGreaterElements(arr);
   
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
   
    return 0;
}