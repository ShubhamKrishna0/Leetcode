#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val ) :data(val), left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        map<int, int> mpp;
        queue<pair<TreeNode *, int>> q; // queue for bfs transversal each elements 
        //is a pair containing nodes and the vertex

        q.push({root, 0});

          //bfs transversal
           while(!q.empty()){
            //retrive the node and its vertical possition fron the front of the queue
           auto it = q.front();  // q stores: pair<TreeNode*, int>
           q.pop();

           TreeNode *node = it.first;  // first part of the pair → pointer to the tree node
           int line = it.second;       // second part of the pair → vertical line number


            if (mpp.find(line) == mpp.end()){
                /*
                Checks: "Has this vertical line been seen before?"
                If not seen → we add this node's value into the map.
                */
                mpp[line] = node->data;
            }
            if (node->left != nullptr){
                q.push({node->left, line - 1});
            }
             if (node->right != nullptr){
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


/*
Got it — you want to **visualize** how this code works step by step, not just explain it in text.
We’ll walk through **what’s in the queue**, **what’s in the map**, and **how the result builds** while running BFS for the given tree.

---

## 1️⃣ The Binary Tree Structure from `main`

The tree you create looks like this:

```
           1
         /   \
        2     3
       / \   / \
      4  10 9  10
       \
        5
         \
          6
```

---

## 2️⃣ Key Concept — **Top View**

* **line** = vertical position (root = 0, left = -1, right = +1)
* **map\<int, int> mpp** → stores first node’s value seen at each vertical line.
* BFS ensures **topmost node** for each line is the first one stored.

---

## 3️⃣ Step-by-Step BFS Simulation

| Step | Queue Content (`node, line`)    | Map `mpp` (line → value)   | Action Taken                                  |
| ---- | ------------------------------- | -------------------------- | --------------------------------------------- |
| 1    | `(1,0)`                         | `{}`                       | Add line 0 → 1; push left(2,-1), right(3,1)   |
| 2    | `(2,-1), (3,1)`                 | `{0:1}`                    | Add line -1 → 2; push left(4,-2), right(10,0) |
| 3    | `(3,1), (4,-2), (10,0)`         | `{-1:2, 0:1}`              | Add line 1 → 3; push left(9,0), right(10,2)   |
| 4    | `(4,-2), (10,0), (9,0), (10,2)` | `{-1:2, 0:1, 1:3}`         | Add line -2 → 4; push right(5,-1)             |
| 5    | `(10,0), (9,0), (10,2), (5,-1)` | `{-2:4, -1:2, 0:1, 1:3}`   | Skip (0 already in map)                       |
| 6    | `(9,0), (10,2), (5,-1)`         | same                       | Skip (0 already in map)                       |
| 7    | `(10,2), (5,-1)`                | same                       | Add line 2 → 10                               |
| 8    | `(5,-1)`                        | `{-2:4,-1:2,0:1,1:3,2:10}` | Skip (-1 already in map); push right(6,0)     |
| 9    | `(6,0)`                         | same                       | Skip (0 already in map)                       |

---

## 4️⃣ Final `mpp`

```
-2 → 4
-1 → 2
 0 → 1
 1 → 3
 2 → 10
```

Sorted by key → `4 2 1 3 10`

---

## 5️⃣ Visualization with BFS Layers

```
Level 0:   (line 0)           [ 1 ]
Level 1:  (line -1) [ 2 ]     (line 1) [ 3 ]
Level 2: (line -2) [ 4 ] (line 0) [10, 9]  (line 2) [10]
Level 3:  (line -1) [ 5 ]
Level 4:  (line 0) [ 6 ]
```

**First seen in each column** (vertical line) is taken for the top view.

---

## 6️⃣ Output

```
Top View Traversal:
4 2 1 3 10
```

---

If you want, I can also give you a **C++ debug-visualizer version** of your code that actually prints the **queue** and **map state** after each BFS step so you can watch it live while running.
Do you want me to make that version?

*/