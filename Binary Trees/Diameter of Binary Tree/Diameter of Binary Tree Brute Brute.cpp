#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) :data(val) , left(nullptr), right(nullptr) {}
};

class Solution {
    private:
    int height(TreeNode* node) {
        if(node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int currentDiameter = leftHeight + rightHeight;
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};