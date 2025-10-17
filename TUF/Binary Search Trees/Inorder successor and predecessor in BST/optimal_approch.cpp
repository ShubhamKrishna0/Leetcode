#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x ) : data(x) , left(nullptr) , right(nullptr) {}
};

class Solution {
    public:
    vector<int> succPredBST(TreeNode* root , int key ) {
        TreeNode *predecessor = NULL;
        TreeNode *successor = NULL;
        TreeNode *curr = root;

        while(curr != NULL) {
            if(key > curr-> data) {
                predecessor = curr;
                curr = curr->right;

            }else if(key< curr-> data) {
                successor = curr;
                curr = curr->left;
            }else {
                if(curr-> left) {
                    TreeNode *temp = curr->left;
                    while(temp -> right)
                        temp = temp->right;
                    predecessor = temp;
                }
                if(curr-> right) {
                    TreeNode *temp = curr->right;
                    while(temp-> left)
                        temp = temp->left;
                    successor = temp;
                }
                break;

            }
        }
        int predVal = (predecessor ? predecessor->data : -1);
        int succval = (successor ? successor->data : -1);

        return {predVal, succval};
    }
};