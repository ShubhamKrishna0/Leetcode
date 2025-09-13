#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();

                int idx = leftToRight ? i : (levelSize - 1 - i);

                level[idx] = node->data;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
void printResult(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    printResult(result);

    return 0;
}













































/*
Let’s walk through and **visualize** the entire code in **detailed steps**, both conceptually and with an **execution trace** on the given binary tree.

---

## 🔧 Code Overview

This code implements a **Zigzag (Spiral) Level Order Traversal** of a binary tree using BFS (Breadth-First Search) and alternates the direction at each level.

---

### 🧱 Step-by-Step Components

---

### 1. **TreeNode Definition**

```cpp
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

This defines a basic binary tree node with:

* An integer value `data`
* A left child pointer
* A right child pointer

---

### 2. **Class Solution and zigzagLevelOrder Function**

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
```

This function returns a 2D vector, where each inner vector is one level of the binary tree, traversed in **zigzag order**:

* Level 0: left to right
* Level 1: right to left
* Level 2: left to right
* ...

---

### 3. **Base Case Check**

```cpp
if (!root) return {};
```

If the tree is empty, return an empty result.

---

### 4. **BFS Traversal Setup**

```cpp
vector<vector<int>> result;
queue<TreeNode*> q;
q.push(root);
bool leftToRight = true;
```

* `result`: to store the final answer
* `q`: queue for level-order traversal
* `leftToRight`: boolean flag toggled after each level to reverse direction

---

### 5. **Level-by-Level BFS Traversal**

#### ❗ Key Idea:

We use the index `i` differently depending on the direction:

* If going **left to right**, fill `level[i]`
* If going **right to left**, fill `level[levelSize - 1 - i]`

```cpp
while (!q.empty()) {
    int levelSize = q.size();
    vector<int> level(levelSize);

    for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = q.front(); q.pop();
        
        int idx = leftToRight ? i : (levelSize - 1 - i);
        level[idx] = node->data;

        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }

    result.push_back(level);
    leftToRight = !leftToRight;
}
```

---

## 🌳 Visualization of the Tree

The tree is:

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

---

## 🔄 Traversal Trace

### 📦 Level 0 (left-to-right)

* `queue`: \[1]
* `levelSize = 1`
* Initialize `level = [0]`
* Process:

  * pop 1, `idx = 0`, `level[0] = 1`
  * push children: 2, 3
* Result: `[[1]]`
* Toggle direction: `leftToRight = false`

---

### 🔁 Level 1 (right-to-left)

* `queue`: \[2, 3]
* `levelSize = 2`
* Initialize `level = [0, 0]`
* Process:

  * pop 2, `idx = 1`, `level[1] = 2`, push 4, 5
  * pop 3, `idx = 0`, `level[0] = 3`, push 6, 7
* `level = [3, 2]`
* Result: `[[1], [3, 2]]`
* Toggle: `leftToRight = true`

---

### 🔁 Level 2 (left-to-right)

* `queue`: \[4, 5, 6, 7]
* `levelSize = 4`
* Initialize `level = [0, 0, 0, 0]`
* Process:

  * pop 4, `idx = 0`, `level[0] = 4`
  * pop 5, `idx = 1`, `level[1] = 5`
  * pop 6, `idx = 2`, `level[2] = 6`
  * pop 7, `idx = 3`, `level[3] = 7`
* `level = [4, 5, 6, 7]`
* Result: `[[1], [3, 2], [4, 5, 6, 7]]`
* Toggle: `leftToRight = false`

Now the queue is empty.

---

## ✅ Final Output

```cpp
[[1], [3, 2], [4, 5, 6, 7]]
```

---

## 📤 Output in Main

```cpp
printResult(result);
```

This will print:

```
1
3 2
4 5 6 7
```

---

## 🔚 Summary of Concepts

| Concept           | How It’s Used                           |
| ----------------- | --------------------------------------- |
| BFS               | Traversing level-by-level using a queue |
| Zigzag order      | Controlled by `leftToRight` flag        |
| Vector index swap | Using index `i` or `levelSize - 1 - i`  |
| Queue             | For processing nodes in FIFO order      |

---

Would you like a **diagram of this traversal** or an **animation-style step-by-step drawing** to further enhance your understanding?

*/