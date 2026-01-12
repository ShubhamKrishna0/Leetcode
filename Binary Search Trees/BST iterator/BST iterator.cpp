#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        inorderTraversal(root);
        index = -1;
    }
    bool hasNext()
    {
        return index + 1 < values.size();
    }
    int next()
    {
        return values[++index];
    }

private:
    vector<int> values;
    int index;

    void inorderTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        values.push_back(node->data);
        inorderTraversal(node->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *iterator = new BSTIterator(root);
    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }
    return 0;
}
