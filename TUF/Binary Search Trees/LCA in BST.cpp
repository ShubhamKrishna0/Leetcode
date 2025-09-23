#include<bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr)  , right(nullptr){}
};

class Solution  {
    public:
    bool getPath(TreeNode* root , vector<int> &path , int x) {

        //base case if the current node is null then return false
        if(!root) {
            return false;
        }
        // add the current node value to the apth vector
        path.push_back(root->data);
        
        //
        if(root-> data  == x) {
            return true;
        }
        if(getPath(root -> left , path , x) || getPath(root->right , path , x)){
            return true;
        }
        //if the target value 'x' is not found in the current path , backtrack
        path.pop_back();
        return false;
    }

    TreeNode* lca (TreeNode* root , int p , int q) {
        vector<int> path1, path2;

        if(!getPath(root , path1 , p) || !getPath(root , path2 , q)){
            return nullptr;
        }
        int i = 0;
        while(i < path1.size() && i < path2.size() && path1[i]== path2[i]) {
            i++;
        }
        return new TreeNode(path1[i - 1]);
    }
};

/*

Got it 👍 You want to **visualize step by step what this code is doing**.
Let’s carefully unpack it and walk through with an **example tree**.

---

## 🔎 Code Purpose

The code finds the **Lowest Common Ancestor (LCA)** of two nodes `p` and `q` in a binary tree using **root-to-node paths**.

---

## 🔨 Step 1: What does `getPath` do?

### Function behavior:

* It tries to find a path from the **root** to a **target value x**.
* If it finds `x`, it returns `true` and keeps the path stored in the vector.
* If it doesn’t, it backtracks (removes the last node from the path).

---

### Visualization of `getPath`

Suppose we have this tree:

```
          5
         / \
        3   8
       / \   \
      2   4   9
```

Let’s say we call:

```cpp
getPath(root, path, 4);
```

**Steps**:

1. Start at root = `5`.
   → Add `5` to path → `path = [5]`
   → `5 != 4`, continue left and right.

2. Go left to `3`.
   → Add `3` → `path = [5, 3]`
   → `3 != 4`, continue left and right.

3. Go left to `2`.
   → Add `2` → `path = [5, 3, 2]`
   → `2 != 4`, and no children.
   → Backtrack → remove `2`.
   → `path = [5, 3]`.

4. Go right to `4`.
   → Add `4` → `path = [5, 3, 4]`.
   → Found target ✅ return true.

Final `path = [5, 3, 4]`.

---

## 🔨 Step 2: What does `lca` do?

It finds the **paths of p and q**, then compares them element by element until they diverge.

---

### Example

Let’s find LCA(2, 4) in the above tree.

1. Path to `2`: `path1 = [5, 3, 2]`
2. Path to `4`: `path2 = [5, 3, 4]`

Now compare:

```
path1: [5, 3, 2]
path2: [5, 3, 4]
```

* index 0: both `5 ✅`
* index 1: both `3 ✅`
* index 2: mismatch (`2 != 4`) ❌

So the last common was `3`.
LCA = `3`.

---

## 🔄 Step 3: Why return `new TreeNode(path1[i-1])`?

Currently, it creates a **new node** with the LCA’s value.
So the function doesn’t return the *actual node* in the tree, but a new copy.

✅ Works fine if you just need the value.
⚠️ But in real interview scenarios, we usually return the actual pointer.

---

## 📊 Visualization Summary

* `getPath`: builds a vector step by step, adding nodes when going down, popping when backtracking.
* `lca`: compares two paths element-by-element until they diverge, last equal element is the LCA.

---

## 🌳 Dry Run Walkthrough (Finding LCA of 2 and 9 in same tree)

Tree:

```
          5
         / \
        3   8
       / \    \
      2   4    9
```

* Path to `2`: `[5, 3, 2]`
* Path to `9`: `[5, 8, 9]`

Compare:

* index 0: `5 == 5` ✅
* index 1: `3 != 8` ❌

→ LCA = `5`.

---

👉 Do you want me to **draw recursion tree diagrams** showing exactly how `getPath` pushes and pops values at each step (like a DFS visualization)?

*/