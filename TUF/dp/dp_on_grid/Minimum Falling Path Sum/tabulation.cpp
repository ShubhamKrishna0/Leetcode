#include<bits/stdc++.h>
using namespace std;

class Solution {
    int  minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();//total column//2
        /*
[1, 2, 3]
[4, 5, 6]
        */
        int m = matrix[0].size();//total row//3

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
            //Copy the first row of the matrix into 
            //the dp table because that’s where all paths start.
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int leftDiagonal = j - 1 > 0 ? matrix[i][j] + dp[i - 1][j - 1] : 1e9;
                int rightDiagonal = j + 1 < m ? matrix[i][j] + dp[i - 1][j + 1] : 1e9;
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m;j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};
int main(){
    vector<vector<int>> matrix{{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    Solution sol;
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;

}

/*
Let’s go step-by-step and explain **how the final answer (7)** is obtained for this matrix:

```
[  1,   2, 10,  4]
[100,   3,  2,  1]
[  1,   1, 20,  2]
[  1,   2,  2,  1]
```

---

### ⚙️ Step 1: Initialization

We use a `dp` table to store the **minimum falling path sum** ending at each cell.

Initialize `dp[0]` with `matrix[0]` (the first row):

```
dp[0] = [1, 2, 10, 4]
```

---

### ⚙️ Step 2: Fill DP Row by Row

Now fill each row using the logic:

```cpp
dp[i][j] = matrix[i][j] + min(
    dp[i-1][j],        // from above
    dp[i-1][j-1],      // from top-left (if j > 0)
    dp[i-1][j+1]       // from top-right (if j < m - 1)
)
```

---

### ▶️ Row 1 (index 1):

| j | matrix\[1]\[j] | from up (`dp[0][j]`) | from left-diagonal | from right-diagonal | dp\[1]\[j] |
| - | -------------- | -------------------- | ------------------ | ------------------- | ---------- |
| 0 | 100            | 100+1 = 101          | —                  | 100+2 = 102         | **101**    |
| 1 | 3              | 3+2 = 5              | 3+1 = 4            | 3+10 = 13           | **4**      |
| 2 | 2              | 2+10 = 12            | 2+2 = 4            | 2+4 = 6             | **4**      |
| 3 | 1              | 1+4 = 5              | 1+10 = 11          | —                   | **5**      |

Resulting row:

```
dp[1] = [101, 4, 4, 5]
```

---

### ▶️ Row 2 (index 2):

| j | matrix\[2]\[j] | from up (`dp[1][j]`) | from left-diagonal | from right-diagonal | dp\[2]\[j] |
| - | -------------- | -------------------- | ------------------ | ------------------- | ---------- |
| 0 | 1              | 1+101 = 102          | —                  | 1+4 = 5             | **5**      |
| 1 | 1              | 1+4 = 5              | 1+101 = 102        | 1+4 = 5             | **5**      |
| 2 | 20             | 20+4 = 24            | 20+4 = 24          | 20+5 = 25           | **24**     |
| 3 | 2              | 2+5 = 7              | 2+4 = 6            | —                   | **6**      |

Resulting row:

```
dp[2] = [5, 5, 24, 6]
```

---

### ▶️ Row 3 (index 3):

| j | matrix\[3]\[j] | from up (`dp[2][j]`) | from left-diagonal | from right-diagonal | dp\[3]\[j] |
| - | -------------- | -------------------- | ------------------ | ------------------- | ---------- |
| 0 | 1              | 1+5 = 6              | —                  | 1+5 = 6             | **6**      |
| 1 | 2              | 2+5 = 7              | 2+5 = 7            | 2+24 = 26           | **7**      |
| 2 | 2              | 2+24 = 26            | 2+5 = 7            | 2+6 = 8             | **7**      |
| 3 | 1              | 1+6 = 7              | 1+24 = 25          | —                   | **7**      |

Resulting row:

```
dp[3] = [6, 7, 7, 7]
```

---

### ✅ Final Step: Take Min of Last Row

```
dp[3] = [6, 7, 7, 7]
```

**Minimum falling path sum = 6**

---

### 🧭 Final Answer: `6`

---

### 📌 One Example Path

Let’s trace the actual path that gives sum **6**:

* **matrix\[0]\[0] = 1**
* Go down-right to **matrix\[1]\[1] = 3**
* Go straight down to **matrix\[2]\[1] = 1**
* Go down-left to **matrix\[3]\[0] = 1**

So path: `1 → 3 → 1 → 1 = 6` ✅

Let me know if you want the path reconstruction logic too.

*/