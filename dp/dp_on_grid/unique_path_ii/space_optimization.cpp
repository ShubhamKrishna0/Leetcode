#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {//row
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {//column 
                if (matrix[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }

                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                int up = (i > 0) ? dp[j] : 0;
                int left = (j > 0) ? temp[j - 1] : 0;

                temp[j] = up + left;
            }
            dp = temp;
        }

        return dp[n - 1];
    }
};


int main () {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    Solution sol;
    cout << "Number Of Paths With Obstacles" << sol.uniquePathWithObsracles(maze) << endl;
    return 0 ;

}

/*
Here’s a **detailed description** of the space-optimized code using a single 1D array for solving the **Unique Paths with Obstacles** problem:

---

### 🚀 **Purpose of the Code**

To calculate the number of unique paths from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` in a 2D grid (`matrix`) that may contain obstacles (represented by `1`). The robot can only move **right** or **down**.

---

### 🧠 **Optimization Used**

Instead of using a full 2D `dp` array (`O(m * n)` space), the code uses a **1D array** (`dp[n]`) to store only the necessary information for the current and previous rows.
This reduces space complexity to **O(n)**.

---

### 📦 **Variables**

* `matrix`: Input grid (2D vector) where `1` is an obstacle and `0` is a free cell.
* `m`, `n`: Dimensions of the grid.
* `dp`: A 1D vector of size `n` to store the number of paths to each cell in the current row.
* `temp`: Temporary array used to compute the current row's paths using values from `dp` (previous row).

---

### 🔁 **Loop Explanation**

#### Outer Loop: `for (int i = 0; i < m; i++)`

* Iterates through each row of the grid.

#### Inner Loop: `for (int j = 0; j < n; j++)`

* Iterates through each column in the current row.

---

### 🔍 **Key Conditions**

1. **Obstacle Check**:

   ```cpp
   if (matrix[i][j] == 1)
   ```

   * If the cell is blocked, set the number of paths to `0`.

2. **Start Cell Check**:

   ```cpp
   if (i == 0 && j == 0)
   ```

   * Set the start cell to `1` path (there’s one way to "stay" at the start).

3. **Update Path Count**:

   ```cpp
   int up = (i > 0) ? dp[j] : 0;
   int left = (j > 0) ? temp[j - 1] : 0;
   temp[j] = up + left;
   ```

   * If not at the first row, add the path count from the cell **above**.
   * If not at the first column, add the path count from the cell **to the left**.
   * Total number of ways to reach the current cell is the **sum** of these.

4. **Update `dp`**:

   ```cpp
   dp = temp;
   ```

   * At the end of each row, copy the current row’s results into `dp` for the next iteration.

---

### ✅ **Final Return Value**

```cpp
return dp[n - 1];
```

* The bottom-right cell of the grid corresponds to `dp[n - 1]` in the last row.

---

### 💡 Summary

* **Time Complexity**: O(m \* n)
* **Space Complexity**: O(n)
* Smart use of a 1D array saves memory while maintaining logic integrity.

Sure! Let’s break down this key part of the DP update logic:

```cpp
int up = (i > 0) ? dp[j] : 0;
int left = (j > 0) ? temp[j - 1] : 0;
temp[j] = up + left;
```

This logic calculates the **number of unique paths to reach cell (i, j)** in the grid. Let's go line by line:

---

### 🔹 `int up = (i > 0) ? dp[j] : 0;`

* If we're **not on the first row** (`i > 0`), then the cell above `(i-1, j)` is valid.
* `dp[j]` holds the number of ways to reach the **cell above** the current one because `dp` is storing the previous row.
* If we **are on the first row**, there’s **no cell above**, so we set `up = 0`.

---

### 🔹 `int left = (j > 0) ? temp[j - 1] : 0;`

* If we're **not in the first column** (`j > 0`), then the cell to the left `(i, j-1)` is valid.
* `temp[j - 1]` holds the number of ways to reach the **left cell** in the current row.
* If we **are in the first column**, there’s **no left cell**, so we set `left = 0`.

---

### 🔹 `temp[j] = up + left;`

* The total number of ways to reach `(i, j)` is the **sum of the ways** to reach:

  * from **above** (move down)
  * from **left** (move right)

This line applies the main idea of the problem:

> To reach cell `(i, j)`, you must come either from `(i-1, j)` or `(i, j-1)` — assuming no obstacles.

---

### 📌 Example:

Suppose you're at cell `(2, 2)` and:

* There are 3 ways to get to the cell above `(1, 2)` → `up = 3`
* There are 2 ways to get to the cell to the left `(2, 1)` → `left = 2`

Then:

```cpp
temp[2] = 3 + 2 = 5
```

There are 5 ways to reach cell `(2, 2)`.

---

Let me know if you want a grid example or step-by-step simulation!

*/