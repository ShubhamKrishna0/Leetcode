#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr){}
};

class Solution {
    public:
    vector<int> postorder (TreeNode* root){
        vector<int> result; ///to  store th result 
        stack<TreeNode *> nodeStack; // stack to process the nodes
        nodeStack.push(root);//push the root initially

        while(!nodeStack.empty()){
            TreeNode *node = nodeStack.top();   //get the top  node
            nodeStack.pop();
            result.push_back(node->data); // add it to the list
            if(node -> left)
                nodeStack.push(node->left);
            if(node -> right)
                nodeStack.push(node->right);    
        }
        reverse(result.begin(), result.end());
        return result;
    }
};