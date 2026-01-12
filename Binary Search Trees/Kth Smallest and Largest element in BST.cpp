#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val ) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    void inorderTraversal(TreeNode* node , vector<int> &values) {
        if(node) {
            inorderTraversal(node->left, values);
            values.push_back(node->data);
            inorderTraversal(node->right, values);
        }
    }
    vector<int> kLargesSmall(TreeNode* root , int k) {
        vector<int> values;
        inorderTraversal(root, values);

        int k_small = values[k - 1];
        int k_largest = values[values.size() - 1];

    }
};