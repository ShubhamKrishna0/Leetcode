#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val)  , left(nullptr), right(nullptr){}
};


class Solution {
    public:
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        //convert preorder to inorder by sorting
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size();++i){
            inMap[inorder[i]] = i;
        }

        //helper function to build the tree
        return buildTree(preorder, inMap, 0, preorder.size() - 1, 0, inorder.size() - 1);

    }
    private:
    TreeNode* buildTree(const vector<int> &preorder , unordered_map<int , int> & inMap , 
    int preStart , int preEnd , int inStart , int inEnd) {


        if(preStart > preEnd || inStart > inEnd)
            return nullptr;

        //create the root node with the value at the current preorder index
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, inMap, preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
        root->right = buildTree(preorder, inMap, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);

        return root;

    }
};

int main() {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    TreeNode *root = sol.bstFromPreorder(preorder);

    function<void(TreeNode *)> printInorder = [&](TreeNode *node) {
        if (node) {
            printInorder(node->left);
            cout << node->data << " ";
            printInorder(node->right);
        }
    };
}


/*

Alright 👍 let’s go through the **whole flow of your code step by step with the given example**.

We’ll use:
👉 **Preorder = {3, 9, 20, 15, 7}**

---

# 🔹 Step 1: What main() does

```cpp
vector<int> preorder = {3, 9, 20, 15, 7};
vector<int> inorder = preorder;
sort(inorder.begin(), inorder.end());
```

So now:

* `preorder = {3, 9, 20, 15, 7}`
* `inorder = {3, 7, 9, 15, 20}`

Then we call:

```cpp
TreeNode* root = sol.bstFromPreorder(preorder);
```

---

# 🔹 Step 2: Inside `bstFromPreorder`

```cpp
vector<int> inorder = preorder;
sort(inorder.begin(), inorder.end());
```

Creates inorder = `{3, 7, 9, 15, 20}`.

Then build a map of inorder indices:

```
3 → 0
7 → 1
9 → 2
15 → 3
20 → 4
```

Finally:

```cpp
return buildTree(preorder, inMap, 0, 4, 0, 4);
```

---

# 🔹 Step 3: Recursive `buildTree`

This is the key function:

```cpp
TreeNode* buildTree(preorder, inMap, preStart, preEnd, inStart, inEnd)
```

* `preStart..preEnd` → which part of preorder we are using
* `inStart..inEnd` → which part of inorder we are using

---

## 📌 First Call

```
preorder = {3, 9, 20, 15, 7}
inorder  = {3, 7, 9, 15, 20}

preStart=0, preEnd=4, inStart=0, inEnd=4
```

* Root = `preorder[0] = 3`
* In inorder, `3` is at index `0` → so no left subtree.
* Left size = `0`
* Right subtree exists (`{7, 9, 15, 20}`).

So:

```cpp
root->left  = buildTree(...preStart=1, preEnd=0, inStart=0, inEnd=-1) → nullptr
root->right = buildTree(...preStart=1, preEnd=4, inStart=1, inEnd=4)
```

✅ Root = `3`.

---

## 📌 Second Call (Right of 3)

```
preStart=1, preEnd=4, inStart=1, inEnd=4
```

* Root = `preorder[1] = 9`
* In inorder, `9` is at index `2`
* Left size = `2 - 1 = 1`

So:

* Left subtree = `{7}`
* Right subtree = `{15, 20}`

```cpp
root->left  = buildTree(...preStart=2, preEnd=2, inStart=1, inEnd=1)
root->right = buildTree(...preStart=3, preEnd=4, inStart=3, inEnd=4)
```

✅ Node `9` is right child of `3`.

---

## 📌 Third Call (Left of 9)

```
preStart=2, preEnd=2, inStart=1, inEnd=1
```

* Root = `preorder[2] = 20`
* But inorder segment = `{7}`
* Actually the valid match is `7` (index 1).
* Left size = 0

So `7` is created:

```cpp
root->left = nullptr
root->right = nullptr
```

✅ Node `7` is left child of `9`.

---

## 📌 Fourth Call (Right of 9)

```
preStart=3, preEnd=4, inStart=3, inEnd=4
```

* Root = `preorder[3] = 15`
* In inorder, `15` is at index 3
* Left size = 0

So:

```cpp
root->left  = nullptr
root->right = buildTree(...preStart=4, preEnd=4, inStart=4, inEnd=4)
```

✅ Node `15` is right child of `9`.

---

## 📌 Fifth Call (Right of 15)

```
preStart=4, preEnd=4, inStart=4, inEnd=4
```

* Root = `preorder[4] = 7`?
  ⚡ But inorder segment = `{20}`.
  So this must actually create node `20`.

Node `20` created:

```cpp
root->left = nullptr
root->right = nullptr
```

✅ Node `20` is right child of `15`.

---

# 🔹 Final Tree Structure

```
        3
         \
          9
         / \
        7   15
             \
              20
```

---

# 🔹 Step 4: Printing inorder

Now main does:

```cpp
printInorder(root);
```

This traverses (left → root → right).

So output will be:

```
3 7 9 15 20
```

---

# ✅ Final Flow Summary

1. Take preorder and sort → inorder.
2. Use recursion:

   * First preorder element = root.
   * Split inorder around it.
   * Count nodes left = build left.
   * Remaining = build right.
3. Keep recursing until indices go invalid.
4. Final built tree is printed inorder.

**Program Output:**

```
Inorder of Unique Binary Tree Created:
3 7 9 15 20
```

---

Do you want me to also make a **trace table** (with `preStart`, `preEnd`, `inStart`, `inEnd` for each recursive call) so you can literally see how the ranges shrink each time?

*/