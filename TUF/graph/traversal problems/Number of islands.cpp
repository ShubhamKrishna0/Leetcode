#include <bits/stdc++.h>
using namespace std;

class solution
{
private:
    bool isValid(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;

        return true;
    }
    void bfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int column = cell.second;

            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delColumn = -1; delColumn <= 1; delColumn++)
                {
                    int newRow = row + delrow;
                    int newColumn = column + delColumn;

                    if (isValid(newRow, newColumn, n, m) && grid[newRow][newColumn] == '1' &&
                        !vis[newRow][newColumn])
                    {
                        vis[newRow][newColumn] = true;
                        q.push({newRow, newColumn});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

/*

Perfect 👍 Let's **visualize** this C++ code step-by-step.
This is a classic **“Number of Islands”** problem (LeetCode 200 / GFG version).
The goal: count how many disconnected “islands” (groups of ‘1’s) exist in a 2D grid.

---

## 🧩 High-Level Visualization

Imagine a **grid of cells**, where:

* `'1'` = land 🌴
* `'0'` = water 🌊

Cells are connected in **8 directions** (up, down, left, right, and diagonals).
Each **connected group of '1's** forms one **island**.

---

### Example Grid

```
[
  ['1','1','0','0'],
  ['0','1','0','1'],
  ['1','0','0','1'],
  ['0','0','1','1']
]
```

We'll explore this grid using **BFS (Breadth-First Search)**.

---

## 🔍 Step-by-Step Visualization

### Step 1: Initialize

We start from the top-left and move cell by cell.

```
count = 0
vis[][] = all false initially
```

We’ll visit every cell `(i, j)`:

* If it's `'1'` and **not visited**, that means we found a **new island!**
* Increase `count++`
* Then, call **bfs()** to mark all cells of this island as visited.

---

### Step 2: Found First Island

At `(0,0)` → `'1'`, not visited → start BFS.

🟩 BFS starts with queue = `{(0,0)}`

```
vis[0][0] = true
```

---

### Step 3: BFS Expands

Now we pop `(0,0)` → explore **all 8 directions**.

Directions checked:
`(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)`

Only `(0,1)` and `(1,1)` are `'1'` and unvisited.

✅ Add `(0,1)` and `(1,1)` to the queue.
Mark them as visited.

Queue = `{(0,1), (1,1)}`
Visited cells = {(0,0), (0,1), (1,1)}

---

### Step 4: Continue BFS

Take `(0,1)`:

* Explore all 8 directions again.
* Finds `(1,1)` already visited → skip.
* No new ‘1’s found.

Next `(1,1)`:

* Explore → might find `(2,0)` (diagonally connected).

Add `(2,0)` to queue.

Queue = `{(2,0)}`
Visited = {(0,0), (0,1), (1,1), (2,0)}

---

### Step 5: Finish Island

Process `(2,0)` — no new adjacent land.

Queue empty → BFS ends.

✅ First island fully discovered.
Count = 1

---

### Step 6: Continue Grid

Keep scanning grid:

* (0,2), (0,3): water
* (1,3): unvisited ‘1’ → start new BFS → new island found.
  Count = 2
* BFS covers (1,3), (2,3), (3,2), (3,3)
  Count = 2 islands total.

---

## 🧠 Internal Structure Visualization

```
Main Grid     Visited Matrix (After BFS 1)
1 1 0 0       T T F F
0 1 0 1       F T F F
1 0 0 1  →    T F F F
0 0 1 1       F F F F

After BFS 2:
Visited:
T T F F
F T F T
T F F T
F F T T
```

Total Islands = **2**

---

## ⚙️ How Each Function Works

### `isValid(i, j, n, m)`

Checks if cell `(i, j)` is inside the grid boundaries.

### `bfs(i, j, vis, grid)`

Marks all connected ‘1’s from `(i, j)` using **BFS**:

* Starts from `(i, j)`
* Uses a `queue<pair<int,int>>`
* Checks all 8 directions for connected land
* Marks each visited

### `numIslands(grid)`

Traverses all cells:

* When finds unvisited ‘1’ → starts a BFS
* Increments island count

---

## 🧭 Visualization Flow Diagram

```
numIslands()
   ↓
 for each cell (i,j)
   ↓
  if grid[i][j] == '1' && not vis[i][j]
       ↑
       |→ count++
       |→ bfs(i,j)
              ↓
         queue = [(i,j)]
         while queue not empty:
             (r,c) = queue.front()
             explore all 8 directions
             if valid land → mark visited + push to queue
```

---

## 🧮 Time and Space Complexity

| Operation | Complexity | Reason                        |
| --------- | ---------- | ----------------------------- |
| Time      | **O(N×M)** | Each cell visited once        |
| Space     | **O(N×M)** | For `visited[][]` + BFS queue |

---

## 🌈 Visual Summary

Think of BFS as a **paint bucket tool 🪣** in MS Paint:

* You click on a land cell (`'1'`)
* It spreads to all **connected** `'1'` cells (8 directions)
* Marks the whole connected region as one “island”

The loop keeps repeating this **paint-fill** process for every unvisited land, counting how many separate blobs exist.

---

Would you like me to generate a **visual animation (step-by-step grid images)** to show BFS expansion for one island?
*/