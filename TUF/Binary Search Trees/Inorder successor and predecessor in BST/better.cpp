#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : data(x), left(nullptr) , right(nullptr) {}
};

class Solution  {
    public:
    vector <int> succPredBST(TreeNode* root , int key) {
        int predecessor = -1,
        successor = -1;

        TreeNode *prev = nullptr;
        inorderTraversal(root, key, predecessor, successor, prev);
        return {predecessor, successor};
    }
    private:
    void inorderTraversal(TreeNode* node , int key , int &pred, int &succ , TreeNode* &prev){
        if(!node)
            return;
        inorderTraversal(node->left, key, pred, succ, prev);

        if(prev && prev-> data < key) {
            pred = prev->data;
        }
        if(succ == -1 && node-> data > key) {
            succ = node->data;
        }
        prev = node;
        inorderTraversal(node->right, key, pred, succ, prev);
    }
};

/*
Got it 👍 Let’s **visualize the flow of this code step by step** with the given input tree and key = `4`.

---

### 🔹 Step 1: Tree Construction

The `main` builds this Binary Search Tree (BST):

```
           5
         /   \
        3     8
       / \   / \
      2   4 6   9
```

---

### 🔹 Step 2: Goal

We want to find:

* **Predecessor** of key = 4 → the largest value **smaller than 4**.
* **Successor** of key = 4 → the smallest value **greater than 4**.

---

### 🔹 Step 3: Inorder Traversal Logic

`inorderTraversal` goes **Left → Node → Right** (which gives sorted order in BST).

We maintain:

* `pred` (predecessor, initialized `-1`)
* `succ` (successor, initialized `-1`)
* `prev` (the previously visited node)

Rules inside traversal:

1. If `prev->data < key`, then `pred = prev->data`.
2. If `succ == -1 && node->data > key`, then `succ = node->data`.
   (This ensures we record the **first** bigger element as successor.)

---

### 🔹 Step 4: Dry Run with Key = 4

Traversal order of nodes: `[2, 3, 4, 5, 6, 8, 9]`.

* Start at `2`:

  * `prev = nullptr → pred = -1, succ = -1`
  * Update: `prev = 2`.

* At `3`:

  * `prev = 2`, and `2 < 4 → pred = 2`.
  * `succ` still `-1` because `3` is not greater than 4.
  * Update: `prev = 3`.

* At `4`:

  * `prev = 3`, and `3 < 4 → pred = 3`.
  * `succ` still `-1` because `4` is not greater than 4.
  * Update: `prev = 4`.

* At `5`:

  * `prev = 4`, and `4 < 4` is false, so predecessor not updated.
  * `succ == -1` and `5 > 4 → succ = 5`.
  * Update: `prev = 5`.

* Remaining nodes `[6, 8, 9]` won’t change anything because successor is already found.

Final result:

```
Predecessor = 3
Successor = 5
```

---

### 🔹 Step 5: Output

The `main` prints:

```
[3, 5]
```

---

✅ **Visualization Summary**

* Inorder traversal produces sorted sequence.
* Predecessor is the **last smaller value before key**.
* Successor is the **first greater value after key**.

So for key `4`, result = `[3, 5]`.

---

Do you want me to also **draw the traversal path (recursive calls stack expansion)**, so you can see *exactly how the recursion unfolds* in memory?


*/