#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    // Constructor initializes the iterator on the root of the BST
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
    int next()
    {
        TreeNode *temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->data;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            myStack.push(node);
            node = node->left;
        }
    }
};