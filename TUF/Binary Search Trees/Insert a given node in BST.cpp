/*
given root = {4 2 7 1 3} val = 5
output:- { 4 2 7 1 3 5}

*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) : data(val) , left(nullptr) , right(nullptr){}
};

class Solution {
    private:
    TreeNode* solve (TreeNode* node , int val) {
        if(node == nullptr) {
            return new TreeNode(val);
        }
        if(val < node-> data) {
            node->left = solve(node->left, val);
        }else if(val > node -> data) {
            node->right = solve(node->right, val);
        }
        return node;
    }

    public:
    TreeNode* insertIntoBST(TreeNode* root , int val) {
        return solve(root, val);
    }
};

void printInOrder(TreeNode* root ) {
    if(root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    TreeNode *newRoot = solution.insertIntoBST(root, val);
    printInOrder(newRoot);

    return 0;
    
}