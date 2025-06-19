#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    struct TrieNode {
        TrieNode *children[26] = {};
        string word = "";
    };

    void insert(TrieNode* root , string word) {
        TrieNode *node = root;
        for(char c : word) {
            if(!node -> children[c-'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->word = word;
    }
    void dfs(vector<vector<char>> &board , int i ,
         int j , TrieNode* node , vector<string> &res) {
        char c = board[i][j];
        if(c =='#'|| !node->children[c-'a'])
            return;

        node = node->children[c - 'a'];
        if(node )
    }
}