#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val)  , left(nullptr), right(nullptr){}
};

class Solution {
    public:
    TreeNode* bstFromPreorder(vector<int> &preorder) {

        if(preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> s;
        s.push(root);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *node = s.top();
            TreeNode *child = new TreeNode(preorder[i]);

            while(!s.empty() && s.top() -> data < preorder[i]) {
                node = s.top();
                s.pop();
            }
            if(node->data < preorder[i]){
                node->right = child;
            }else{
                node->left = child;
            }

            s.push(child);
        }
        return root;
    }
};

void inorderTransversal(TreeNode* root) {
    if(root != nullptr) {
        inorderTransversal(root->left);
        cout << root->data << " ";
        inorderTransversal(root->right);
    }
}

int main() {
    Solution solution;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = solution.bstFromPreorder(preorder);
    inorderTransversal(root);

    return 0;
}