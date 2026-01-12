#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(int n, int diff, vector<int> &arr)
    {
        const int MOD = 1e9 + 7;

        // Step 1: Calculate total sum of array
        int total = accumulate(arr.begin(), arr.end(), 0);

        // Step 2: Check if (total + diff) can be split evenly
        // If not, it's impossible to form required partitions
        if ((total + diff) % 2 != 0)
            return 0;

        // Step 3: The target subset sum (S1) we need to count
        int target = (total + diff) / 2;

        // Step 4: DP array to count number of subsets with sum = target
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // Base case: one way to get sum 0 (empty subset)

        // Step 5: Standard subset sum count DP (0/1 knapsack style)
        for (int num : arr)
        {
            for (int j = target; j >= num; --j)
            {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }

        return dp[target];
    }
};

// ------------------ Example Test ------------------
int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout << sol.countPartitions(arr.size(), diff, arr) << endl; // Expected output: 3
}
/*
Excellent — you’re now at the **core heart** of the subset-sum logic ❤️
Let’s unpack **exactly what this double loop does**, **line-by-line**, **with example and reasoning**.

---

## 🧠 The Goal

We want to count how many subsets of `arr` have a **sum = target**.

We use a **1D DP array**, where:

```
dp[j] = number of ways to make sum j using elements seen so far
```

---

## 🧩 Code block under study

```cpp
for (int num : arr) {
    for (int j = target; j >= num; --j) {
        dp[j] = (dp[j] + dp[j - num]) % MOD;
    }
}
```

Let’s break it into **3 parts**:

---

### 🧱 1. Outer loop: `for (int num : arr)`

We’re iterating over every number in the array.

So we’re gradually **building** subset sums using the first few numbers.

Think of it like:

> “Now I add this number to my previous combinations — what new sums can I make?”

---

### 🔁 2. Inner loop: `for (int j = target; j >= num; --j)`

We loop **backward** (very important).
Why?
Because we’re using a **1D array** to store results for current and previous elements in the same `dp`.

If we went **forward**, the same number could be used multiple times (which is wrong for subset problems — that’s for unbounded knapsack).

So going backward ensures:

> Each element is used at most once.

---

### ⚙️ 3. DP update: `dp[j] = (dp[j] + dp[j - num]) % MOD;`

This is the magic line. Let’s understand it step-by-step.

* `dp[j]` = current number of ways to make sum `j` (without using current `num` yet)
* `dp[j - num]` = number of ways we could make sum `j - num` **before** considering current `num`

Now, every subset that made sum = `(j - num)`
→ can make sum = `j` **by adding `num`**.

So we add those new ways into `dp[j]`.

That’s why:

```
dp[j] = dp[j] + dp[j - num]
```

The modulo `% MOD` just keeps the number small (since result can be huge).

---

## 🔍 Step-by-Step Example

Let’s take the example you asked about:

```
arr = [1, 1, 2, 3]
target = 4
```

Initial:

```
dp = [1, 0, 0, 0, 0]   // dp[0] = 1 (one way to get sum 0 — empty set)
```

---

### ➤ Process num = 1

```
for j = 4 → 1
```

Only `j=1` is valid since `j >= num`.

```
dp[1] = dp[1] + dp[1 - 1] = dp[1] + dp[0] = 0 + 1 = 1
```

Now:

```
dp = [1, 1, 0, 0, 0]
```

Meaning:
1 way to make sum 0, 1 way to make sum 1.

---

### ➤ Process num = 1 (second one)

Loop j = 4 → 1

* j = 2 → `dp[2] += dp[2 - 1] = dp[2] + dp[1] = 0 + 1 = 1`
* j = 1 → `dp[1] += dp[0] = 1 + 1 = 2`

Now:

```
dp = [1, 2, 1, 0, 0]
```

Means:

* 2 ways to make sum 1 → {[first 1], [second 1]}
* 1 way to make sum 2 → {[1,1]}

---

### ➤ Process num = 2

Loop j = 4 → 2

* j = 4 → `dp[4] += dp[4 - 2] = dp[4] + dp[2] = 0 + 1 = 1`
* j = 3 → `dp[3] += dp[3 - 2] = dp[3] + dp[1] = 0 + 2 = 2`
* j = 2 → `dp[2] += dp[2 - 2] = dp[2] + dp[0] = 1 + 1 = 2`

Now:

```
dp = [1, 2, 2, 2, 1]
```

Interpretation:

* 2 ways to make sum 2 ([1,1], [2])
* 2 ways to make sum 3 ([1,2], [1,2])
* 1 way to make sum 4 ([1,1,2])

---

### ➤ Process num = 3

Loop j = 4 → 3

* j = 4 → `dp[4] += dp[4 - 3] = dp[4] + dp[1] = 1 + 2 = 3`
* j = 3 → `dp[3] += dp[3 - 3] = dp[3] + dp[0] = 2 + 1 = 3`

Now:

```
dp = [1, 2, 2, 3, 3]
```

✅ `dp[4] = 3`, which means:
There are 3 subsets that make sum = 4.

---

## 🧮 Concept Summary Table

| Symbol                 | Meaning                                        |
| ---------------------- | ---------------------------------------------- |
| `dp[j]`                | Number of subsets that make sum `j`            |
| Outer loop             | Iterate through each element                   |
| Backward inner loop    | Avoid reusing same element twice               |
| `dp[j] += dp[j - num]` | Add new ways formed by including current `num` |
| `% MOD`                | Keep result under large modulus                |
| `dp[target]`           | Final count of valid subsets (answer)          |

---

✅ **In plain words**:

> For each number in the array, we look at all possible target sums it could contribute to, and we update the count of ways to reach those sums using that number exactly once.

---

Would you like me to now show **how this same logic would look in a 2D DP table** (so you can see visually how this 1D version is derived)? That will deepen your logic understanding before you implement further optimization.

*/