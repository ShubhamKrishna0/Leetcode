#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) :data(val),left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    bool isBalanced(TreeNode* root) {
        //if the tree is empty it is balanced
        if(root == nullptr) {
            return true;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(std::abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root ->left) &&
        isBalanced(root -> right)){
        return true;
    }
    return false;
    }
    private:
    int getHeight(TreeNode* root) {
        if(root == nullptr) {
            return 0; 
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return std::max(leftHeight, rightHeight) + 1;
    }
};