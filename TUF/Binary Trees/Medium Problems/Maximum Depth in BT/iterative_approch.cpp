#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x) , left(NULL) ,right(NULL) {}
};

class Solution {
    public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode *front = q.front();
                q.pop();

             if(front ->left != NULL) {
                 q.push(front->left);
             }
             if(front ->right != NULL) {
                 q.push(front->right);
             }
            }
            level++;
        }
        return level;
        
    }
};