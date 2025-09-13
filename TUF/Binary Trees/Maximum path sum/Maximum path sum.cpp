#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) :data(val), left(nullptr) , right(nullptr) {}
};

class Solution { 
    public:
    int findMaxPathSum(TreeNode* root , int &maxi) {
        if(root == nullptr){
            return 0;
        }
        int leftMaxPath = std::max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = std::max(0, findMaxPathSum(root->right, maxi));
        maxi = std::max(maxi, leftMaxPath + rightMaxPath + root->data);
        return std::max(leftMaxPath, rightMaxPath) + root->data;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};

/*
Let's **visualize** and **understand** the code step-by-step with a diagram and explanation of the recursion.

---

### 🔍 **What This Code Does**

The code calculates the **maximum path sum** in a binary tree.
A **path** is any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path **must contain at least one node** and does **not need to go through the root**.

---

### 🌳 Sample Tree (from `main()`)

```plaintext
            1
          /   \
        2       3
       / \
      4   5
            \
             6
              \
               7
```

---

### 🔁 **How the Recursion Works**

At each node:

1. Compute max path sums from the **left** and **right** children.
2. Only include a child's path sum if it’s positive (i.e., `max(0, path)`).
3. Update the global max if the path **passes through this node** (`left + right + node.val`).
4. Return the best **single path** to propagate up (`node.val + max(left, right)`).

---

### 🔎 Step-by-Step Visualization

Let’s follow a few key steps of the recursion:

---

#### 💡 Leaf Node `7`

* `leftMaxPath = 0`, `rightMaxPath = 0`
* `maxi = max(INT_MIN, 0 + 0 + 7) → 7`
* Return `7`

---

#### 💡 Node `6`

* Right child returns `7`, so:
* `leftMaxPath = 0`, `rightMaxPath = 7`
* `maxi = max(7, 0 + 7 + 6) → 13`
* Return `13`

---

#### 💡 Node `5`

* Right child returns `13`
* `leftMaxPath = 0`, `rightMaxPath = 13`
* `maxi = max(13, 0 + 13 + 5) → 18`
* Return `18`

---

#### 💡 Node `4` (leaf)

* `leftMaxPath = rightMaxPath = 0`
* `maxi = max(18, 0 + 0 + 4) → 18`
* Return `4`

---

#### 💡 Node `2`

* Left returns `4`, right returns `18`
* `leftMaxPath = 4`, `rightMaxPath = 18`
* `maxi = max(18, 4 + 18 + 2) → 24`
* Return `20`

---

#### 💡 Node `3`

* Leaf: returns `3`
* `maxi = max(24, 0 + 0 + 3) → 24`

---

#### 💡 Root Node `1`

* Left returns `20`, right returns `3`
* `maxi = max(24, 20 + 3 + 1) → 24`
* Final return: `maxi = 24`

---

### ✅ Output

```cpp
Maximum Path Sum: 24
```

---

### 🔁 Recursive Function Flow Summary

Each call:

* Recursively goes down left and right
* At every node, it tries:

  * Taking only left
  * Taking only right
  * Taking both (if it's the "root" of a max path)
* Keeps updating the global `maxi`

---

### 🧠 Intuition: Why `max(0, ...)`?

Negative path sums decrease total value, so we skip them.

---

### 📊 Execution Stack Example (simplified):

```
find(7) → 7, maxi = 7
find(6) → 13, maxi = 13
find(5) → 18, maxi = 18
find(4) → 4,  maxi = 18
find(2) → 20, maxi = 24
find(3) → 3,  maxi = 24
find(1) → 21, maxi = 24
```

---

Would you like me to generate a **diagrammatic tree with path sums marked at each node** for better clarity?

*/