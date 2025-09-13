#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];

            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n; 
            //if st.empty() then for the last element the value is n
            st.push(i); 
        }
        return ans;
    }

        vector<int> findPSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i >= n-1; i++) {
            int currEle = arr[i];

            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1; 
            //if st.empty() then for the last element the value is n
            st.push(i); 
        }
        return ans;
    }
    public:
    int largestRectangleArea(vector<int> &heights) {

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int largestArea = 0;
        int area;

        for (int i = 0; i < heights.size(); i++) {
            area = heights[i] * (nse[i] - pse[i] - 1);

            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};
int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    Solution sol; 
    
 
    int ans = sol.largestRectangleArea(heights);
    
    cout << "The largest rectangle area is: " << ans;
    return 0;
}

/*
You're trying to understand how this code works, especially for visualizing how the **largest rectangle in a histogram** is calculated using **Next Smaller Element (NSE)** and **Previous Smaller Element (PSE)**.

---

### ✅ But first, let’s fix the **bug** in the `findPSE` function:

```cpp
for (int i = 0; i >= n-1; i++) {
```

This is wrong. It should be:

```cpp
for (int i = 0; i < n; i++) {
```

---

Now, let’s visualize this step-by-step.

---

## 🧱 Problem: Largest Rectangle in Histogram

Given:
`heights = {2, 1, 5, 6, 2, 3}`

Each number is a height of a bar in a histogram, and the width of each bar is `1`.

We want the area of the largest rectangle that can be formed using consecutive bars.

---

## 🔍 Step 1: Find NSE (Next Smaller Element)

For each bar, we want the index of the next bar that is **smaller**.

For example:

| Index | Height | Next Smaller to Right | NSE Index |
| ----- | ------ | --------------------- | --------- |
| 0     | 2      | 1                     | 1         |
| 1     | 1      | End of array          | 6         |
| 2     | 5      | 4                     | 4         |
| 3     | 6      | 4                     | 4         |
| 4     | 2      | 5                     | 5         |
| 5     | 3      | End of array          | 6         |

So, `nse = [1, 6, 4, 4, 5, 6]`

---

## 🔍 Step 2: Find PSE (Previous Smaller Element)

For each bar, we want the index of the previous bar that is **smaller**.

| Index | Height | Previous Smaller Left | PSE Index |
| ----- | ------ | --------------------- | --------- |
| 0     | 2      | None                  | -1        |
| 1     | 1      | None                  | -1        |
| 2     | 5      | 1                     | 1         |
| 3     | 6      | 2                     | 2         |
| 4     | 2      | 1                     | 1         |
| 5     | 3      | 4                     | 4         |

So, `pse = [-1, -1, 1, 2, 1, 4]`

---

## 🧮 Step 3: Calculate Area

For each index `i`:

```
area = height[i] * (nse[i] - pse[i] - 1)
```

Let’s compute:

| i | height | nse | pse | width = nse - pse - 1 | area = height \* width |
| - | ------ | --- | --- | --------------------- | ---------------------- |
| 0 | 2      | 1   | -1  | 1                     | 2                      |
| 1 | 1      | 6   | -1  | 6                     | 6                      |
| 2 | 5      | 4   | 1   | 2                     | 10                     |
| 3 | 6      | 4   | 2   | 1                     | 6                      |
| 4 | 2      | 5   | 1   | 3                     | 6                      |
| 5 | 3      | 6   | 4   | 1                     | 3                      |

---

## ✅ Final Answer:

The **maximum area** is **10**, formed by the rectangle at index `2` with height `5` and width `2`.

---

## 📊 Visual Aid:

```
Index:      0  1  2  3  4  5
Heights:    2  1  5  6  2  3

Bar Chart:
         _
        | |     _
     _  | |  _ | |
    | | | | | || |
    | || || ||| |
    ------------------
     0  1  2  3  4  5
```

The largest rectangle is formed by bars at index 2 and 3 (heights 5 and 6), but we take only height = 5 and width = 2, because 6 is not smaller than 5.

---

## ✅ TL;DR Visualization Summary:

* Use stacks to compute **Next Smaller** and **Previous Smaller** indices.
* The max area at each position is:

  ```cpp
  area = height[i] * (nse[i] - pse[i] - 1)
  ```
* Return the max of all such areas.

Would you like a **graphical diagram** of how the stack evolves at each step?

*/