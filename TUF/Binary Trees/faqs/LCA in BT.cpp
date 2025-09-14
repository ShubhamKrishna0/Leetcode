#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(NULL), right(NULL){}
};

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode*root , TreeNode*p , TreeNode*q){
      if(root == NULL || root == p || root == q) {
          return root;
      }
      TreeNode *left = lowestCommonAncestor(root->left, p, q);
      TreeNode *right = lowestCommonAncestor(root->right, p, q);

      if(left == NULL) {
          return right;
      }else if(right == NULL) {
          return left;
      }else{
          return root;
      }
    }
};