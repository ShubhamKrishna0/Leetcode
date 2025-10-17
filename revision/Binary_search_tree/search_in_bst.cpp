#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    TreeNode* searchBst(TreeNode* root , int val) {
        while(root != nullptr && root -> data != val) {
            if(val < root -> data) {
                root= root-> left;
            }else {
                root = root->right;
            }
        }
        return root;
    }
};


int main () {
   TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    TreeNode* result = sol.searchBst(root, 2);
    if (result) {
        std::cout << "Node found with value: " << result->data << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    return 0;
}