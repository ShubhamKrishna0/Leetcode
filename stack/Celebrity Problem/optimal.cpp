#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int celebrity(vector<vector<int>> &M) {
        int n = M.size();
        int top = 0, down = n - 1;
        while(top < down) {
            if(M[top][down] == 1) {
                top = top + 1;
            }else if(M[down] [top] == 1) {
                down = down - 1;
            }
            else{
                top++;
                down--;
            }
        }
        if(top > down)
            return -1;
        for (int i = 0; i < n;i++) {
            if(i == top)
            continue;

            if(M[top][i]==1 ||M[i][top] == 0) {
                return -1;
            }
        }
        return top;
    }
};