#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // delrow and delcol for neighbors
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    // helper function to check if a pixel is within boundary
    bool isValid(int &i, int &j, int &n, int &m)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;

        return true;
    }

    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor)
    {
        ans[row][col] = newColor; // ans is the output image
        int n = image.size();     // no of rows
        int m = image[0].size();  // no is column

        for (int i = 0; i < 4; i++)
        {
            // coordinates of the new pixel
            int nrow = row + delRow[i];
            int ncol = row + delCol[i];

            /*check for the valid unvisited pixels having same initial color*/

            if (isValid(nrow, ncol, n, m) && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            /*
The neighbor is inside the image.
The neighbor has the same color as the starting pixel.
The neighbor is not already colored with newColor (to avoid infinite loops).
            */
            {
                dfs(nrow, ncol, ans, image, newColor, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // store the initial colour
        int iniColor = image[sr][sc];

        // store the updated image
        vector<vector<int>> ans = image;

        dfs(sr, sc, ans, image, newColor, iniColor);

        return ans;
    }
};

/*
Sure! Let’s go **step by step** and break down this C++ code for the flood fill problem. I’ll explain both **what each part does** and **why it works**.

---

## **Overview**

This code implements the **flood fill algorithm** using **Depth-First Search (DFS)**. The goal is to change the color of a starting pixel and all its connected pixels (4-directionally) that have the same original color.

---

## **1. Class and Member Variables**

```cpp
class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
```

* `delRow` and `delCol` define the **4-directional movement**:

  * Up: `(-1,0)`
  * Right: `(0,1)`
  * Down: `(1,0)`
  * Left: `(0,-1)`

They are used to traverse neighbors efficiently.

---

## **2. Validity Check Function**

```cpp
bool isValid(int &i, int &j, int &n, int &m) {
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    return true;
}
```

* Checks if `(i,j)` is **within the bounds of the image**.
* Returns `false` if the pixel is outside, `true` if valid.

---

## **3. DFS Function**

```cpp
void dfs(int row, int col, vector<vector<int>>& ans,
         vector<vector<int>>& image, int newColor,
         int iniColor) {
```

### **What it does:**

* Changes the color of `(row, col)` to `newColor`.
* Recursively explores its 4-directional neighbors that have the **same initial color**.

### **Step-by-Step Inside DFS**

```cpp
ans[row][col] = newColor; // Color current pixel
int n = image.size();
int m = image[0].size();
```

* `ans` is the output image (copy of the original image).
* `n` = number of rows, `m` = number of columns.

```cpp
for(int i=0; i < 4; i++) {
    int nrow = row + delRow[i];
    int ncol = col + delCol[i];
```

* Computes coordinates of the 4 neighbors.

```cpp
if(isValid(nrow, ncol, n, m) &&
   image[nrow][ncol] == iniColor
   && ans[nrow][ncol] != newColor) {

    dfs(nrow, ncol, ans, image, newColor, iniColor);
}
```

* Only recurse if:

  1. The neighbor is **inside the image**.
  2. The neighbor has the **same color as the starting pixel**.
  3. The neighbor is **not already colored with newColor** (to avoid infinite loops).

---

## **4. Flood Fill Function**

```cpp
vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc, int newColor) {
    int iniColor = image[sr][sc]; // Original color
    vector<vector<int>> ans = image; // Copy of image
    dfs(sr, sc, ans, image, newColor, iniColor);
    return ans;
}
```

* Stores the **initial color** of the starting pixel.
* Creates a **copy of the image** called `ans` to store the result.
* Calls `dfs` to fill all connected pixels.
* Returns the filled image.

---

## **5. Main Function**

```cpp
vector<vector<int>> image = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
};
int sr = 1, sc = 1;
int newColor = 2;
```

* Defines the input image and starting coordinates.
* Creates an instance of `Solution`.
* Calls `floodFill`.
* Prints the final image.

---

### **Output**

For the given example:

```
2 2 2
2 2 0
2 0 1
```

* Only the pixels **connected 4-directionally** to `(1,1)` with the original color `1` are changed to `2`.
* Bottom-right `1` is not changed because it’s **not connected 4-directionally**.

---

## **Key Points**

1. DFS is used to **explore connected components** of pixels with the same color.
2. `delRow` and `delCol` make **neighbor traversal concise**.
3. `ans[nrow][ncol] != newColor` avoids **infinite recursion**.
4. Works for **any rectangular image** and any starting point.

---

If you want, I can also **draw a step-by-step diagram showing how DFS fills the pixels**, which makes it very intuitive.

Do you want me to do that?

*/