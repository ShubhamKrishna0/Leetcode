#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : data(val), left(nullptr) , right(nullptr){}
};

class Solution {
        public:
        vector<int> floorceilOfBST(TreeNode* root , int key) {
            int floor = -1;
            int ceil = -1;

            TreeNode *current = root;
            while(current) {
                if(current-> data == key) {
                    floor = current->data;
                    break;
                }else if(current-> data < key){
                    floor = current->data;
                    current = current->right;
                }else{
                    current = current->left;
                }
            }

            current = root;
            while(current) {
                if(current -> data == key) {
                    ceil = current->data;
                    break;
                }else if (current-> data > key) {
                    ceil = current->data;
                }else{
                    current = current->right;
                }
            }
            return {floor, ceil};
        }
};
TreeNode* insert(TreeNode* node , int key) {
    if(node == nullptr)
        return new TreeNode(key);
    if(key < node-> data) {
        node->left = insert(node->left, key);
    
    }else if (key > node->data)
            node->right = insert(node->right, key);
    return node ;
}