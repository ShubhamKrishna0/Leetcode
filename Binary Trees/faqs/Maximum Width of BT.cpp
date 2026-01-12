#include <bits/stdc++.h>
using namespace std;



  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long >> q;
        int maxWidth = 0 ;
        q.push({root , 0});

        while(q.size() > 0) {
            int currLVL = q.size() ;
            unsigned long long strIdx = q.front() .second;
            unsigned long long endIdx = q.back() .second;

            maxWidth = max(maxWidth , (int)(endIdx - strIdx + 1 ));

            for(int i = 0 ; i < currLVL ; i++) {
                auto curr = q.front() ;
                q.pop();
                if(curr.first-> left) {
                    q.push({curr.first->left , curr.second*2+1});
                }
                if(curr.first -> right) {
                    q.push({curr.first -> right , curr.second*2+2});
                }
            }
        }
        return maxWidth ;
    }
};

/*
Great, let’s **visualize and deeply break down** this `widthOfBinaryTree` code step by step. I’ll:

1. Explain what it does in plain English.
2. Show a tree example with **index visualization**.
3. Give a dry run for clarity.

---

### 🔍 What This Code Does

* This function calculates the **maximum width of a binary tree**.
* The **width** of a level is the number of nodes between the leftmost and rightmost non-null nodes (including null spaces in between).
* It uses a **queue with BFS** (Breadth-First Search) to traverse level by level.
* Each node is assigned a **position index** based on a "complete binary tree" representation:

  * If a node has index `i`, then:

    * Left child index: `2*i + 1`
    * Right child index: `2*i + 2`
* It tracks the **start and end indices** at every level and computes `endIdx - strIdx + 1`.
* Returns the maximum width found.

---

### 🖼 Example Binary Tree

Let's visualize this with a tree:

```
            1
          /   \
         3     2
        / \     \
       5   3     9
```

Assigning indices:

```
Index Representation:
Level 0:           1(0)
                 /       \
Level 1:      3(1)        2(2)
             /   \           \
Level 2:   5(3)  3(4)        9(6)
```

Widths:

* Level 0: indices \[0..0] → width = 1
* Level 1: indices \[1..2] → width = 2
* Level 2: indices \[3..6] → width = 4

So, **max width = 4**.

---

### 🔄 Dry Run Walkthrough

Let's trace **queue states** and variables:

#### Initialization:

```
q = [(1, 0)]    // Node 1 at index 0
maxWidth = 0
```

---

#### Level 0:

* `currLVL = 1`, `strIdx = 0`, `endIdx = 0`
* width = `0-0+1=1`, maxWidth=1
* Process node 1:

  * Push left child 3 at index `0*2+1=1`
  * Push right child 2 at index `0*2+2=2`

`q = [(3,1), (2,2)]`

---

#### Level 1:

* `currLVL = 2`, `strIdx = 1`, `endIdx = 2`
* width = `2-1+1=2`, maxWidth=2
* Process node 3:

  * Push left child 5 at index `1*2+1=3`
  * Push right child 3 at index `1*2+2=4`
* Process node 2:

  * Push right child 9 at index `2*2+2=6`

`q = [(5,3),(3,4),(9,6)]`

---

#### Level 2:

* `currLVL = 3`, `strIdx = 3`, `endIdx = 6`
* width = `6-3+1=4`, maxWidth=4
* Process node 5 → no children
* Process node 3 → no children
* Process node 9 → no children

Queue becomes empty → **Done**.

`return maxWidth = 4`.

---

### 📌 Visualization Table

| Level | Nodes in Queue | Indices  | Width Calculation | maxWidth |
| ----- | -------------- | -------- | ----------------- | -------- |
| 0     | \[1]           | \[0]     | 0-0+1=1           | 1        |
| 1     | \[3,2]         | \[1,2]   | 2-1+1=2           | 2        |
| 2     | \[5,3,9]       | \[3,4,6] | 6-3+1=4           | 4        |

---

### 🔑 Key Takeaways

* The algorithm **simulates array indexing of a binary tree** to handle missing nodes correctly.
* **Time Complexity:**

  * O(N), where N is number of nodes (each node visited once).
* **Space Complexity:**

  * O(N) for queue (in worst case with all nodes in last level).

---

Would you also like me to **draw a neat tree diagram with arrows and indices** for this visualization?
I can make it **image-based** so it’s easier to grasp.

*/