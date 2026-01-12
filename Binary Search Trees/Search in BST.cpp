//Given the root of a binary tree (BST) and an  interger val.

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
  };

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
        // Traverse the tree until we find the node 
        // with the given value or reach the end
        while (root != nullptr && root->data != val) {
            // Move to the left or right child 
           // depending on the value comparison
            root = (root->data > val) ? root->left : root->right;
        }
        // Return the found node or nullptr if not found
        return root; 
    }
};

int main() {
    // Creating a simple BST for demonstration
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(12);

    Solution sol;
    TreeNode* result = sol.searchBST(root, 2);
    if (result) {
        std::cout << "Node found with value: " << result->data << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    // Clean up memory (omitted for brevity)
    return 0;
}


//time complexity :- O(log2(N)) --> since the search space is halved at each step.
//space Complexity :- O(1) --> 