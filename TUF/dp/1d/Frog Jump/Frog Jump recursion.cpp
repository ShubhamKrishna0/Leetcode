#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int ind) {

        if (ind == 0) return 0;
        
        int jumpOne = frogJump(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        
        int jumpTwo = INT_MAX;
        
        if (ind > 1) {
            jumpTwo = frogJump(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
        }
    
        return min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return frogJump(heights, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> heights = {3, 10, 3, 11, 3};
    int result = sol.frogJump(heights);
    cout << "Minimum energy required: " << result << endl;
    return 0;
}



/*
Time Complexity:O(2^N) where N is the number of stairs in each recursive call
space complexity : o(N) due to the recursion stack and the storage of intermidiate result .

Sure! Let's walk through the recursive flow of the program for the input:

```cpp
vector<int> heights = {3, 10, 3, 11, 3};
```

### Goal:
Frog starts at index `0` and needs to reach the last index (`4` in this case). At each step, the frog can jump either:
- To the next stone (`ind - 1`)
- Or skip one and jump to (`ind - 2`)

The energy cost of a jump is the absolute difference in height between the starting and destination stones.

---

## 🔄 Recursive Flow:

We'll denote:
- `f(i)` as the minimum energy to reach stone `i`.

And for your input: `heights = {3, 10, 3, 11, 3}`

### Starting from `f(4)`:

```
f(4) = min(
    f(3) + abs(heights[4] - heights[3]),  // jump from 3 -> 4
    f(2) + abs(heights[4] - heights[2])   // jump from 2 -> 4
)
```

#### Step-by-step Breakdown:

### 🔹 f(4):
- Jump from 3 ➝ 4: `f(3) + |3 - 11| = f(3) + 8`
- Jump from 2 ➝ 4: `f(2) + |3 - 3| = f(2) + 0`

So we need to compute `f(3)` and `f(2)`.

---

### 🔹 f(3):
- Jump from 2 ➝ 3: `f(2) + |11 - 3| = f(2) + 8`
- Jump from 1 ➝ 3: `f(1) + |11 - 10| = f(1) + 1`

---

### 🔹 f(2):
- Jump from 1 ➝ 2: `f(1) + |3 - 10| = f(1) + 7`
- Jump from 0 ➝ 2: `f(0) + |3 - 3| = f(0) + 0`

---

### 🔹 f(1):
- Jump from 0 ➝ 1: `f(0) + |10 - 3| = 0 + 7 = 7`

So,
- `f(1) = 7`

---

Now plug values back:

### 🔹 f(2):
- From 1 ➝ 2: `7 + 7 = 14`
- From 0 ➝ 2: `0 + 0 = 0`
➡️ `f(2) = 0`

---

### 🔹 f(3):
- From 2 ➝ 3: `0 + 8 = 8`
- From 1 ➝ 3: `7 + 1 = 8`
➡️ `f(3) = 8`

---

### 🔹 f(4):
- From 3 ➝ 4: `8 + 8 = 16`
- From 2 ➝ 4: `0 + 0 = 0`
➡️ `f(4) = 0`

---

## ✅ Final Answer:
```
Minimum energy required: 0
```

The frog chooses to jump:
- 0 ➝ 2 ➝ 4, each jump costing `0`, total cost `0`.

---

### 🧠 Optimization Tip:
This code uses **pure recursion**, which leads to **exponential time complexity**. You can improve it using **memoization (top-down)** or **tabulation (bottom-up)** to bring it down to **O(N)**.

Would you like me to show the optimized version with memoization or DP?

*/