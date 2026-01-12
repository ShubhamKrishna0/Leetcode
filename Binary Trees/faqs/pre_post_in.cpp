// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int data;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     vector<vector<int>> treeTransversal(TreeNode* root) {
//         vector<int> pre, in, post;
//         if (root == nullptr)
//             return {pre, in, post};

//         stack<pair<TreeNode*, int>> st;
//         st.push({root, 1});

//         while (!st.empty()) {
//             auto [node, state] = st.top();
//             st.pop();

//             if (state == 1) {
//                 pre.push_back(node->data);
//                 st.push({node, 2});
//                 if (node->left)
//                     st.push({node->left, 1});
//             }
//             else if (state == 2) {
//                 in.push_back(node->data);
//                 st.push({node, 3});
//                 if (node->right)
//                     st.push({node->right, 1});
//             }
//             else {
//                 post.push_back(node->data);
//             }
//         }

//         return {pre, in, post};
//     }
// };






////for upper c++ version like 
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> treeTransversal(TreeNode* root) {
        vector<int> pre, in, post;
        if (root == nullptr)
            return {pre, in, post};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            pair<TreeNode*, int> p = st.top();
            st.pop();

            TreeNode* node = p.first;
            int state = p.second;

            if (state == 1) {
                pre.push_back(node->data);
                st.push({node, 2});
                if (node->left)
                    st.push({node->left, 1});
            }
            else if (state == 2) {
                in.push_back(node->data);
                st.push({node, 3});
                if (node->right)
                    st.push({node->right, 1});
            }
            else {
                post.push_back(node->data);
            }
        }

        return {pre, in, post};
    }
};
