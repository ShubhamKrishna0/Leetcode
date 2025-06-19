#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int nonAdjacent(vectro<int> &nums) {
        int ind = nums.size();
        vector<int> dp(ind, 0);

        dp[0] = nums[0];
        for (int i = 1, i < ind; i++) {

            int pick = nums[i];
            if(i > 1)
                pick += dp[i - 2];
            int nonPick = dp[i - 1];

            dp[i] = max(pick, nonPick);
        }
        return dp[ind - 1];
    }
};

int main() {
    vector<int> arr{2, 1, 4, 9};
    Solution sol;
    cout << sol.nonAdjacent(arr);
    return 0;

}

/*

Alright! Let’s walk through **your code** and **your given array `{2,1,4,9}`** 
**step-by-step** to show the flow of the algorithm:

---

You have:

```cpp
arr = {2, 1, 4, 9}
```

---

**Initialization:**

- `dp[0] = arr[0] = 2`
- So `dp = {2, 0, 0, 0}` initially.

---

**Now loop i from 1 to 3:**

---

**Step 1: i = 1**

- `pick = arr[1] = 1`
- `i > 1` is **false**, so we **don't** add `dp[i-2]`.
- `nonPick = dp[i-1] = dp[0] = 2`
- Now:
  ```
  dp[1] = max(pick, nonPick) = max(1,2) = 2
  ```
- So `dp = {2, 2, 0, 0}`

---

**Step 2: i = 2**

- `pick = arr[2] = 4`
- `i > 1` is **true**, so:
  - `pick += dp[i-2] = 4 + dp[0] = 4 + 2 = 6`
- `nonPick = dp[i-1] = dp[1] = 2`
- Now:
  ```
  dp[2] = max(pick, nonPick) = max(6, 2) = 6
  ```
- So `dp = {2, 2, 6, 0}`

---

**Step 3: i = 3**

- `pick = arr[3] = 9`
- `i > 1` is **true**, so:
  - `pick += dp[i-2] = 9 + dp[1] = 9 + 2 = 11`
- `nonPick = dp[i-1] = dp[2] = 6`
- Now:
  ```
  dp[3] = max(pick, nonPick) = max(11, 6) = 11
  ```
- So `dp = {2, 2, 6, 11}`

---

**Final Answer:**

- `dp[n-1] = dp[3] = 11`

✅ So the maximum sum of non-adjacent elements is **`11`**.

---

**Quick Visualization Table:**

| i | arr[i] | pick                        | nonPick | dp[i] |
|---|--------|------------------------------|---------|-------|
| 0 | 2      | 2                            | N/A     | 2     |
| 1 | 1      | 1                            | 2       | 2     |
| 2 | 4      | 4 + 2 = 6                    | 2       | 6     |
| 3 | 9      | 9 + 2 = 11                   | 6       | 11    |

---

Would you also like me to show you how this would look if we optimize it to **O(1)** space? 🚀  
(Instead of using a full dp array!)

*/