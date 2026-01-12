#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

class Solution {
    public:
    bool isSameTree(TreeNode* p , TreeNode* q){
        if(p == nullptr && q == nullptr) {
            return true;
        }
        if(p == nullptr || q== nullptr){
             return false;
            }
            return isSameTree(p->left, q->left) && isSameTree(p->right, p->right);
    }
};

