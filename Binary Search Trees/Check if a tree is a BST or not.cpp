#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
  };

  class Solution {
    public:
    bool isBST (TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    private:
    bool validate (TreeNode* node , long min , long max) {

        if(node == nullptr)
            return true;
        
        if(node-> data <= min || node-> data  >= max)
            return false;

        bool leftIsValid = validate(node->left, min, node->data);

        bool rightIsValid = validate(node->right, node->data, max);

        return leftIsValid && rightIsValid;
    }
  };

  /*
          10   (-∞ , +∞)
       /  \
 (-∞,10)   (10,+∞)
     5
    / \
(-∞,5) (5,10)
   2     7


   Step-by-Step Execution

validate(10, -∞, +∞) ✅

Go left: validate(5, -∞, 10) ✅

Left of 5: validate(2, -∞, 5) ✅

Right of 5: validate(7, 5, 10) ✅

Go right: validate(15, 10, +∞) ✅

Right of 15: validate(20, 15, +∞) ✅
  */