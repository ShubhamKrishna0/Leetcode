#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int largestReactangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int largestArea = 0;
        int area;
        int nse, pse;
        for (int i = 0; i < n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int ind = st.top();
                st.pop();

                pse = st.empty() ? -1 : st.top();
                nse = i;
                area = heights[ind] * (nse - pse - 1);
                largestArea = max(largestArea, area);
            }
            st.push(i);
        }
        //for elements that are not popped from the stack
        while(!st.empty()){
            //nse for such elements is the size of array
            nse = n;
            //get the index of the top of the stack
            int ind = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            area = heights[ind] * (nse - pse - 1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};


int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    Solution sol; 
    

    int ans = sol.largestReactangleArea(heights);
    
    cout << "The largest rectangle area is: " << ans;
    return 0;
}


/*
To **visualize** how the `largestRectangleArea` function works, we’ll walk through it with this specific example:

```cpp
vector<int> heights = {2, 1, 5, 6, 2, 3};
```

---

### 🔍 **High-Level Idea:**

This is the classic **Largest Rectangle in Histogram** problem.

The goal is to find the largest area rectangle that can be formed by choosing contiguous bars (with heights given), where each bar has a width of 1.

We use a **monotonic increasing stack** to help us quickly find:

* **PSE (Previous Smaller Element)**
* **NSE (Next Smaller Element)**

---

### 🔢 **Step-by-step Walkthrough:**

Let's walk through the main loop line-by-line with visual explanations.

#### **Initial Array:**

```
Index:   0  1  2  3  4  5
Heights: 2  1  5  6  2  3
```

#### Initialize:

```cpp
stack<int> st;
int largestArea = 0;
```

---

### ✅ Step 1: i = 0, height = 2

* Stack is empty → push index `0`.
* Stack: `[0]`

---

### ✅ Step 2: i = 1, height = 1

* 1 < 2 → Pop index `0`.
* **ind = 0**, `heights[ind] = 2`
* `pse = -1` (stack is empty), `nse = 1`
* `width = 1 - (-1) - 1 = 1`
* `area = 2 * 1 = 2`
* `largestArea = max(0, 2) = 2`
* Push index `1`.
* Stack: `[1]`

---

### ✅ Step 3: i = 2, height = 5

* 5 > 1 → push index `2`.
* Stack: `[1, 2]`

---

### ✅ Step 4: i = 3, height = 6

* 6 > 5 → push index `3`.
* Stack: `[1, 2, 3]`

---

### ✅ Step 5: i = 4, height = 2

* 2 < 6 → pop index `3`

  * `ind = 3`, `heights[3] = 6`
  * `pse = 2`, `nse = 4`
  * `width = 4 - 2 - 1 = 1`
  * `area = 6 * 1 = 6`
  * `largestArea = max(2, 6) = 6`
* 2 < 5 → pop index `2`

  * `ind = 2`, `heights[2] = 5`
  * `pse = 1`, `nse = 4`
  * `width = 4 - 1 - 1 = 2`
  * `area = 5 * 2 = 10`
  * `largestArea = max(6, 10) = 10`
* 2 = 1 → not smaller → stop
* Push index `4`
* Stack: `[1, 4]`

---

### ✅ Step 6: i = 5, height = 3

* 3 > 2 → push index `5`
* Stack: `[1, 4, 5]`

---

### ✅ Step 7: End of loop (i = 6)

Now we process the remaining stack:

#### 🔁 Pop index `5`

* `ind = 5`, `heights[5] = 3`
* `pse = 4`, `nse = 6`
* `width = 6 - 4 - 1 = 1`
* `area = 3 * 1 = 3`
* `largestArea = max(10, 3) = 10`

#### 🔁 Pop index `4`

* `ind = 4`, `heights[4] = 2`
* `pse = 1`, `nse = 6`
* `width = 6 - 1 - 1 = 4`
* `area = 2 * 4 = 8`
* `largestArea = max(10, 8) = 10`

#### 🔁 Pop index `1`

* `ind = 1`, `heights[1] = 1`
* `pse = -1`, `nse = 6`
* `width = 6 - (-1) - 1 = 6`
* `area = 1 * 6 = 6`
* `largestArea = max(10, 6) = 10`

---

### 🎯 Final Answer: `10`

---

### 📊 Visual Rectangle Corresponding to Area 10:

It comes from bars:

```cpp
[5, 6] → indices 2 and 3
```

But width is expanded using height = 5, from index 2 to 3 (because height at 4 is smaller). So:

```
Height: 5
Width: 2 (indices 2 and 3)
Area: 5 * 2 = 10 ✅
```

---

### 🧠 Visual Tip:

Imagine you drop vertical sticks of different heights (like buildings). You want to fit the **widest possible rectangle** under the histogram such that all buildings under it are **equal or taller** than the rectangle height.

Use the **stack** to:

* Track **increasing** bars (we’re waiting to see how far they can extend).
* Once a smaller bar comes, process the previous ones using it as a **right boundary**.

---


*/