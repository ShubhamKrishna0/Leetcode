#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val)  , left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    int kthSmallest(TreeNode* root , int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
    }
    int kthLargest(TreeNode* root , int k) {
        this->k = k;
        this->result = -1;
        reverse_inorder(root);
        return result;
    }

    vector<int> kLargesSmall(TreeNode* root , int k) {
        return {kthSmallest(root, k), kthLargest(root, k)};
    }

    private:
        int k;
        int result;


        void inorder(TreeNode* node) {
            if(node != nullptr) {
                inorder(node->left);
                if(--k == 0) {
                    result = node->data;
                    return;
                }
                inorder(node->right);
            }
        }

        void reverse_inorder(TreeNode* node) {
            if(node != nullptr) {
                reverse_inorder(node->right);
                if(--k == 0) {
                    result = node->data;
                    return;
                }
                reverse_inorder(node->left);
            }
        }
};