#include <bits/stdc++.h>
using namespace std;

const int MAX_DEPTH = 12;
int n, s;
vector<int> a;
set<tuple<int, int, int>> visited; // (index, sum_so_far, depth)

// Brute-force DFS to simulate Alice's movements
bool dfs(int i, int sum, int depth) {
    if (depth > MAX_DEPTH) return false;
    if (i < 0 || i >= n) return false;

    sum += a[i];
    if (sum > s) return false;
    if (i == n - 1 && sum == s) return true;

    auto state = make_tuple(i, sum, depth);
    if (visited.count(state)) return false;
    visited.insert(state);

    return dfs(i - 1, sum, depth + 1) || dfs(i + 1, sum, depth + 1);
}

// Wrapper for checker
bool alice_can_win(const vector<int>& arr, int target_sum) {
    a = arr;
    n = a.size();
    s = target_sum;
    visited.clear();
    return dfs(0, 0, 0); // Start from index 0 (which is 1 in 1-based)
}

void solve() {
    cin >> n >> s;
    vector<int> arr(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    // Only try to block Alice if this condition allows it
    if (s == total + 1 || s < total) {
        // Apply your sorting trick: sort by (3 - x) % 3
        sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
            return (3 - lhs) % 3 < (3 - rhs) % 3;
        });

        // Validate using DFS brute-force
        if (!alice_can_win(arr, s)) {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " \n"[i == n - 1];
            return;
        }

        // Try reversed version as backup
        reverse(arr.begin(), arr.end());
        if (!alice_can_win(arr, s)) {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " \n"[i == n - 1];
            return;
        }
    }

    // Cannot block Alice
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}




/*

Sure Shubham — let me walk you through the **entire code line-by-line**, using **examples and explanations** to make each part crystal clear. This is a complete solver for the "Pathless" problem, which checks if you can rearrange an array to prevent Alice from finding a path of a given sum `s`.

---

## 🧠 PROBLEM IDEA RECAP

* You’re given an array `a` with values `{0, 1, 2}`.
* Alice starts at index `1` (0-based index `0`) and can move **left or right**.
* She wants to reach the **last index** with the sum of the visited elements equal to `s`.

Your job: rearrange `a` in such a way that Alice **cannot** find any such path.

---

## 🧩 LINE-BY-LINE EXPLANATION

```cpp
#include <bits/stdc++.h>
using namespace std;
```

Standard header that imports everything from STL.

---

### CONSTANTS + GLOBALS

```cpp
const int MAX_DEPTH = 12;
int n, s;
vector<int> a;
set<tuple<int, int, int>> visited; // (index, sum_so_far, depth)
```

* `MAX_DEPTH = 12` limits the depth of DFS recursion to prevent infinite loops.
* `n` = size of array
* `s` = required sum
* `a` = current rearranged version of the array
* `visited` = memoization to prevent revisiting the same `(position, sum, depth)` triple

---

### 🔁 DFS TO SIMULATE ALICE'S MOVES

```cpp
bool dfs(int i, int sum, int depth) {
    if (depth > MAX_DEPTH) return false;
    if (i < 0 || i >= n) return false;
```

* If we've gone too deep or outside the array, we stop.

```cpp
    sum += a[i];
    if (sum > s) return false;
```

* If the current sum already exceeds `s`, no point going further.

```cpp
    if (i == n - 1 && sum == s) return true;
```

* If we’ve reached the **last index** with **exactly the desired sum**, Alice wins!

```cpp
    auto state = make_tuple(i, sum, depth);
    if (visited.count(state)) return false;
    visited.insert(state);
```

* We remember each `(i, sum, depth)` to avoid recomputation.

```cpp
    return dfs(i - 1, sum, depth + 1) || dfs(i + 1, sum, depth + 1);
}
```

* Try **both directions**: left and right.
* If **any** path reaches the goal, we return true.

---

### 🧪 ALICE'S CHECKER

```cpp
bool alice_can_win(const vector<int>& arr, int target_sum) {
    a = arr;
    n = a.size();
    s = target_sum;
    visited.clear();
    return dfs(0, 0, 0); // Start from index 0 with sum 0, depth 0
}
```

This function calls DFS to check:

> **"Can Alice win with this version of the array?"**

---

### 🧷 MAIN SOLVER FUNCTION

```cpp
void solve() {
    cin >> n >> s;
    vector<int> arr(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
```

We read input and calculate the total sum of array elements.

```cpp
    if (s == total + 1 || s < total) {
```

This is a key **optimization**:
We only try to block Alice when it's even *possible* to block her.
If `s > total`, then no way Alice can ever reach `s`, so we just return `-1` later.

---

### 🔀 YOUR SORTING TRICK

```cpp
        sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
            return (3 - lhs) % 3 < (3 - rhs) % 3;
        });
```

* This is a **custom sort** to try a "bad" ordering for Alice.
* It tends to push **larger values like 2** earlier to make the sum explode faster.

Example:
Input `a = [0, 1, 2]` becomes `a = [0, 2, 1]` — encourages early growth in sum.

---

### 🧪 CHECK THAT ALICE **CANNOT WIN**

```cpp
        if (!alice_can_win(arr, s)) {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " \n"[i == n - 1];
            return;
        }
```

If Alice **cannot** find any path that gives sum `s`, then we've succeeded!
We print the arrangement and return.

---

### 🪃 BACKUP PLAN: REVERSE ORDER

```cpp
        reverse(arr.begin(), arr.end());
        if (!alice_can_win(arr, s)) {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " \n"[i == n - 1];
            return;
        }
```

If the initial order fails, try the reverse ordering as a **backup trap**.

---

### ❌ IF ALL FAILS

```cpp
    cout << "-1\n";
}
```

If no rearrangement can block Alice, then return `-1`.

---

### 🧮 MAIN FUNCTION

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```


Let’s fully **explain how Alice gets blocked** in this test case:

---

## 🧪 Test Case:

```
n = 3, s = 4  
a = [0, 1, 2]
```

We **rearranged** this to:

```
a = [0, 2, 1]
```

Let’s simulate **Alice’s movement** step by step.

---

## 🎯 Alice's Goal:

* Start at index `1` (0-based index = 0)
* End at index `3` (0-based index = 2)
* Sum of values along her path must be **exactly `4`**
* She can go **left/right by 1** unit each time

---

## 📌 Rearranged Array:

```
Index:      0   1   2
Value:      0   2   1
```

---

## 🔍 Try All Paths from index 0 to index 2 with total sum = 4

### ✅ Path must:

* Start at index `0`
* End at index `2`
* Total sum = 4
* Allowed moves: left or right (only step size = 1)
* You can **visit indices more than once** (i.e., loop)

---

Let’s try **all possible DFS paths** within reasonable depth (e.g., `MAX_DEPTH = 5`):

### 🔁 All attempts (starting at index 0):

#### 1. `0 → 1 → 2`

* Values = `0 + 2 + 1 = 3` ❌

#### 2. `0 → 1 → 2 → 1`

* Values = `0 + 2 + 1 + 2 = 5` ❌ (too much)

#### 3. `0 → 1 → 0 → 1 → 2`

* Values = `0 + 2 + 0 + 2 + 1 = 5` ❌

#### 4. `0 → 1 → 0 → 1 → 0 → 1 → 2` (looping)

* Repeated `2`s add up fast ⇒ **overflows sum**

#### 5. `0 → 2`

* Values = `0 + 1 = 1` ❌ too small

#### 6. `0 → 2 → 1`

* Values = `0 + 1 + 2 = 3` ❌

---

## 🔐 Important observation

No matter how Alice walks, the **value at index 1 (middle)** is `2`, and it's surrounded by `0` and `1`, so any path going through index 1 will repeatedly **add 2** which pushes the sum **beyond 4**.

Also, **starting from 0** means she needs to accumulate **4 total** by walking to 2 and picking values — but there just isn’t a way to land on `4` **while ending at index 2**.

---

## ✅ Why this works:

* You rearranged values so that **the highest-value (`2`) is early**
* Alice is tempted to go to `2` at index 1 early
* But doing that causes the sum to grow too fast
* Any attempt to loop just **adds more 2’s or repeats the 1**
* She either overshoots `s = 4` or never reaches it

---

## 📌 Summary

* Original: `[0, 1, 2]` ⇒ Alice could walk `0 → 1 → 2` = `3`

  * Loop back: `0 → 1 → 2 → 1` = `3 + 1 = 4` ✅ (Alice wins here!)

* Rearranged: `[0, 2, 1]`

  * Any such looping or ping-pong ends up with **sum > 4**
  * Alice cannot reach `sum = 4` **ending at last index**

✅ Thus, rearranged version **blocks all valid paths**, and Alice **cannot win**.

---

Would you like a visual diagram of all paths attempted by DFS on this array?






Absolutely! Let's break down this line of C++ code step by step:

```cpp
return (3 - lhs) % 3 < (3 - rhs) % 3;
```

This is used as a **custom comparator function** inside the `sort()` function to sort the array `a[]`:

---

## 🔧 Purpose of This Comparator

It reorders the array by applying a transformation to each element:

```cpp
x ↦ (3 - x) % 3
```

Then it compares the transformed values to decide the sort order.

---

## 🧠 Let’s Understand the Expression:

### 🎯 Expression:

```cpp
(3 - x) % 3
```

This maps each element `x` (which is either `0`, `1`, or `2`) to:

| `x` | `(3 - x) % 3`           |
| --- | ----------------------- |
| 0   | (3 - 0) % 3 = 3 % 3 = 0 |
| 1   | (3 - 1) % 3 = 2 % 3 = 2 |
| 2   | (3 - 2) % 3 = 1 % 3 = 1 |

So effectively:

```cpp
x → sort_value:
0 → 0
1 → 2
2 → 1
```

This leads to the sorting priority:

### 🔢 Final Order:

**0 first**, **2 second**, **1 last**

---

## 🔁 Practical Example:

Given:

```cpp
a = {0, 1, 2}
```

Sort with:

```cpp
sort(a.begin(), a.end(), [&](int lhs, int rhs) {
    return (3 - lhs) % 3 < (3 - rhs) % 3;
});
```

Will result in:

```cpp
[0, 2, 1]
```

Because:

* `(3 - 0) % 3 = 0` (comes first)
* `(3 - 2) % 3 = 1` (second)
* `(3 - 1) % 3 = 2` (last)

---

## 💡 Why This Order?

This specific ordering is **experimentally chosen** to **try to block Alice** from reaching her target sum. It's not magical — just a clever ordering that *in many cases* (but not all!) makes it harder for Alice to reach sum `s`.

---

## ✅ Summary

This line:

```cpp
(3 - x) % 3
```

* Transforms values to a different order.
* It gives a sorting priority of:
  `0` (first) → `2` (second) → `1` (last)
* The goal is to **rearrange `a` in a way that may block Alice**.

Let me know if you'd like to test it with a few arrays or see how it works for a specific case.


*/