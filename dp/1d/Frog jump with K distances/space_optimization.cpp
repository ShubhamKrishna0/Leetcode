#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int frogJump(vector<int> &heights , int k ) {
        int n = heights.size();
        vector<int> dp(k, 0);
        /*
✅ n = number of stairs.
✅ Create a small rolling vector dp of size k, initialized with zeros.
✅ dp[i % k] will store minimum energy to reach stair i, recycling space.
        */

        for (int i = 1; i < n; i++) {
            int mmSteps = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if(i-j >= 0){
                    int prevIndex = (i - j) % k;
                    int jump = dp[prevIndex] + abs(heights[i] - heights[i - j]);
                    mmSteps = min(mmSteps, jump);
                }
            }
            dp[i % k] = mmSteps;
        }
        return dp[(n - 1) % k];
    }
};

/*
Concept | Meaning
Rolling vector dp[k] | Only store last k dp values to save space
Modulus i % k | Find right index inside rolling dp vector
Reuse and overwrite old values | Because we only care about recent k jumps
Very memory efficient | Space = O(k), Time = O(n × k)
*/

/*
Awesome — now let's explain everything **again but fully with**  
your example `{15, 4, 1, 14, 15}` and `k = 3`,  
**step-by-step** using **rolling vector** and **modulus `%`** clearly!

---

We are solving for:  
`height = {15, 4, 1, 14, 15}`,  
`k = 3`

---

# Step 1: Initialize

- `n = 5` (number of stairs)
- `dp = [0, 0, 0]` (size = k = 3)

---

# Step 2: Start from stair 1

## i = 1

We want to reach stair `1`.

Possible jumps:

- From stair `0` ➔ stair `1`

### Jump from stair 0 ➔ 1:
- Previous index = `(1-1) % 3 = 0 % 3 = 0`
- Jump cost = `abs(4 - 15) = 11`
- Total energy = `dp[0] + 11 = 0 + 11 = 11`

`mmSteps = 11`

✅ Now store:
```cpp
dp[1 % 3] = dp[1] = 11
```

➡️ `dp = [0, 11, 0]`

---

# Step 3: Move to stair 2

## i = 2

We want to reach stair `2`.

Possible jumps:

- From stair `1` ➔ stair `2`
- From stair `0` ➔ stair `2`

### Jump from stair 1 ➔ 2:
- Previous index = `(2-1) % 3 = 1`
- Jump cost = `abs(1 - 4) = 3`
- Total energy = `dp[1] + 3 = 11 + 3 = 14`

### Jump from stair 0 ➔ 2:
- Previous index = `(2-2) % 3 = 0`
- Jump cost = `abs(1 - 15) = 14`
- Total energy = `dp[0] + 14 = 0 + 14 = 14`

✅ `mmSteps = min(14, 14) = 14`

Now store:
```cpp
dp[2 % 3] = dp[2] = 14
```

➡️ `dp = [0, 11, 14]`

---

# Step 4: Move to stair 3

## i = 3

We want to reach stair `3`.

Possible jumps:

- From stair `2` ➔ stair `3`
- From stair `1` ➔ stair `3`
- From stair `0` ➔ stair `3`

### Jump from stair 2 ➔ 3:
- Previous index = `(3-1) % 3 = 2`
- Jump cost = `abs(14 - 1) = 13`
- Total energy = `dp[2] + 13 = 14 + 13 = 27`

### Jump from stair 1 ➔ 3:
- Previous index = `(3-2) % 3 = 1`
- Jump cost = `abs(14 - 4) = 10`
- Total energy = `dp[1] + 10 = 11 + 10 = 21`

### Jump from stair 0 ➔ 3:
- Previous index = `(3-3) % 3 = 0`
- Jump cost = `abs(14 - 15) = 1`
- Total energy = `dp[0] + 1 = 0 + 1 = 1`

✅ `mmSteps = min(27, 21, 1) = 1`

Now store:
```cpp
dp[3 % 3] = dp[0] = 1
```
(overwrites the old dp[0])

➡️ `dp = [1, 11, 14]`

---

# Step 5: Move to stair 4

## i = 4

We want to reach stair `4`.

Possible jumps:

- From stair `3` ➔ stair `4`
- From stair `2` ➔ stair `4`
- From stair `1` ➔ stair `4`

### Jump from stair 3 ➔ 4:
- Previous index = `(4-1) % 3 = 3 % 3 = 0`
- Jump cost = `abs(15 - 14) = 1`
- Total energy = `dp[0] + 1 = 1 + 1 = 2`

### Jump from stair 2 ➔ 4:
- Previous index = `(4-2) % 3 = 2`
- Jump cost = `abs(15 - 1) = 14`
- Total energy = `dp[2] + 14 = 14 + 14 = 28`

### Jump from stair 1 ➔ 4:
- Previous index = `(4-3) % 3 = 1`
- Jump cost = `abs(15 - 4) = 11`
- Total energy = `dp[1] + 11 = 11 + 11 = 22`

✅ `mmSteps = min(2, 28, 22) = 2`

Now store:
```cpp
dp[4 % 3] = dp[1] = 2
```
(overwrites the old dp[1])

➡️ `dp = [1, 2, 14]`

---

# Step 6: Finish

✅ Frog is now at stair `4` (last stair).

✅ Minimum energy needed = `dp[(n-1)%k] = dp[(5-1)%3] = dp[4%3] = dp[1] = 2`

✅ **Final Answer = 2**

---

# 🎯 Full Summary Table (step-by-step)

| Stair (i) | From which | Energy | Total Energy | Store at (i%k) |
|:---------:|:----------:|:------:|:------------:|:-------------:|
| 1 | 0 ➔ 1 | 11 | 11 | dp[1] = 11 |
| 2 | 0 ➔ 2 | 14 | 14 | dp[2] = 14 |
| 3 | 0 ➔ 3 | 1 | 1 | dp[0] = 1 (overwrite) |
| 4 | 3 ➔ 4 | 1 | 2 | dp[1] = 2 (overwrite) |

✅ Rolling vector reuses small memory!  
✅ Modulus `%` cycles and overwrites old dp values.

---

# 🚀 Final important notes:
- **dp size is only `k = 3`**, not `n = 5` ➔ very memory efficient.
- **`i % k`** decides **where** to store the energy at every step.
- Old values automatically get overwritten once they are not needed!

---

Would you like me to draw a **rolling dp array** animation too? 📈📚 It will make this 100% crystal clear!  
(only 1 simple diagram!) 🔥🚀
*/

int main() {
    vector<int> height {15, 4, 1, 14, 15};
    int k = 3;

    // Create an instance of Solution class
    Solution sol;

    // Print the answer
    cout << "Minimum energy : " << sol.frogJump(height, k) << endl;

    return 0;
}