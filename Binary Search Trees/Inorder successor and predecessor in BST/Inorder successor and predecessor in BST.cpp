#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr){}
};

class Solution{
	public:
        vector<int> succPredBST(TreeNode* root,int key){
            vector<int> sortedList;
            //perform in-order traversal to get the sorted list of node values
            inorderTraversal(root, sortedList);

            int predecessor = -1;
            int successor = -1;

            int ind = binarySearch(sortedList, key);

            if(ind > 0 )
                predecessor = sortedList[ind - 1];
            if(ind < sortedList.size() - 1 )
                successor = sortedList[ind + 1];
            return {predecessor,successor};
        }

    private:
    void inorderTraversal(TreeNode* node , vector<int> &sortedList) {
        if(node== nullptr) {
            return;
        }
        // Traverse the left subtree
        inorderTraversal(node->left, sortedList);
        // Add the node's value to the sortedList
        sortedList.push_back(node->data);
        // Traverse the right subtree
        inorderTraversal(node->right, sortedList);
    }

    int binarySearch(vector<int> &arr , int key) {
        int low = 0, high = arr.size() - 1;
        int mid;

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(arr[mid] == key)
                return mid;
            else if(arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(12);
    
    Solution sol;
    vector<int> result = sol.succPredBST(root, 7);
    
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*

## 1. Tree Construction (main function)

We create this BST:

```
          5
        /   \
       2     10
      / \    / \
     1   4  7   12
```

* Root = 5
* Left subtree = {2,1,4}
* Right subtree = {10,7,12}

---

## 2. Call to `succPredBST(root, 7)`

The goal: find **predecessor** (largest smaller value) and **successor** (smallest larger value) of key `7` in the BST.

---

## 3. Inorder Traversal (`inorderTraversal`)

In-order traversal of a BST always gives sorted order.
Traversal steps:

* Visit left subtree of 5 → traverse 2 → traverse 1 → visit 1 → back to 2 → visit 2 → traverse 4 → visit 4.
* Visit root (5).
* Traverse right subtree of 5 → visit 7, then 10, then 12.

So sorted list =

```
[1, 2, 4, 5, 7, 10, 12]
```

---

## 4. Binary Search (`binarySearch(sortedList, 7)`)

We search key `7`:

* low = 0, high = 6 → mid = 3 → arr[3] = 5 (< 7), so search right half.
* low = 4, high = 6 → mid = 5 → arr[5] = 10 (> 7), so search left half.
* low = 4, high = 4 → mid = 4 → arr[4] = 7 ✅ found at index 4.

So `ind = 4`.

---

## 5. Predecessor & Successor Calculation

* If `ind > 0` → predecessor = `sortedList[ind-1] = sortedList[3] = 5`.
* If `ind < size-1` → successor = `sortedList[ind+1] = sortedList[5] = 10`.

So result = `{5, 10}`.

---

## 6. Output

The loop in `main` prints:

```
5 10
```

---

✅ **Final Visualization Flow**

1. Build BST.
2. Do in-order traversal → get sorted list `[1,2,4,5,7,10,12]`.
3. Binary search key `7` → found at index 4.
4. Predecessor = 5, Successor = 10.
5. Output = `5 10`.

*/