#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int constrainedSubsetSum(vector<int> &nums , int k ) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = 0;

        for (int i = 1; i < nums.size(); i++){
            while(i-heap.top().second > k ) {
                heap.pop();
            }
            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
        }
        return ans;
    }
};


/*
Great — your C++ code uses a **max-heap (priority queue)** to maintain the maximum `dp[j]` in the last `k` steps. Let’s break it down **step-by-step with a visualization** so you can clearly see what your code is doing at each iteration.

---

### 🧠 **Concept Recap**

You’re solving the same DP recurrence:

> `dp[i] = nums[i] + max(0, dp[j]) for all j in [i - k, i - 1]`

But instead of a deque, you're using a **max-heap** to always keep track of the maximum `dp[j]` in the valid window.

---

### 📌 Let’s walk through your code with an example:

**Input:** `nums = [10, 2, -10, 5, 20], k = 2`

---

### 🧮 Initialization

```cpp
heap.push({nums[0], 0});  // dp[0] = 10
ans = 10
```

Max-heap = `[(10, 0)]`
`ans = 10`

---

### 🔁 i = 1

```cpp
while (1 - 0 > 2) → false
curr = max(0, 10) + 2 = 12
ans = max(10, 12) = 12
heap.push({12, 1})
```

Max-heap = `[(12, 1), (10, 0)]`
`ans = 12`

---

### 🔁 i = 2

```cpp
while (2 - 1 > 2) → false
curr = max(0, 12) + (-10) = 2
ans = max(12, 2) = 12
heap.push({2, 2})
```

Max-heap = `[(12, 1), (10, 0), (2, 2)]`
`ans = 12`

---

### 🔁 i = 3

```cpp
while (3 - 1 > 2) → false
curr = max(0, 12) + 5 = 17
ans = max(12, 17) = 17
heap.push({17, 3})
```

Max-heap = `[(17, 3), (12, 1), (2, 2), (10, 0)]`
`ans = 17`

---

### 🔁 i = 4

```cpp
while (4 - 3 > 2) → false
curr = max(0, 17) + 20 = 37
ans = max(17, 37) = 37
heap.push({37, 4})
```

Max-heap = `[(37, 4), (17, 3), (2, 2), (10, 0), (12, 1)]`
`ans = 37 ✅`

---

### ✅ Final Answer: `37`

---

### 📊 Visualization Table

| i | nums\[i] | top of heap (max dp in last k) | curr = nums\[i] + max(0, top) | ans | heap state                                 |
| - | -------- | ------------------------------ | ----------------------------- | --- | ------------------------------------------ |
| 0 | 10       | N/A                            | 10                            | 10  | (10, 0)                                    |
| 1 | 2        | 10                             | 12                            | 12  | (12, 1), (10, 0)                           |
| 2 | -10      | 12                             | 2                             | 12  | (12, 1), (10, 0), (2, 2)                   |
| 3 | 5        | 12                             | 17                            | 17  | (17, 3), (12, 1), (2, 2), (10, 0)          |
| 4 | 20       | 17                             | 37                            | 37  | (37, 4), (17, 3), (2, 2), (10, 0), (12, 1) |

---

### 🔍 How Heap Works Here

* It always keeps the **max `dp[j]` value** on top (with index ≤ `i - 1` and ≥ `i - k`)
* If the top of the heap is **out of range** (i.e., `j < i - k`), we **pop it**
* Then we use that top to compute `dp[i]`

---

### 💡 Would You Benefit From a Visual Graph?

If you'd like, I can generate a **step-by-step diagram** showing:

* Each `nums[i]`
* Arrows showing valid `k`-bounded connections
* Dynamic updates to the heap

Let me know if you want that!

*/