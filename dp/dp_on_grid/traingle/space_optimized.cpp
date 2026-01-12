#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(vector<vector<int>> &traingle , int n) {

        vector<int> front(n, 0);
        vector<int> cur(n, 0);

        for (int j = 0; j < n; j++)
        {
            front[j] = traingle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--){
            for (int j = i; j >= 0;j--){
                int down = traingle[i][j] + front[j];
                int diagonal = traingle[i][j] + front[j + 1];
                cur[j] = min(down, diagonal);
            }
             front = cur;
        }
        return front[0];
    }
    public:
    int minTraingleSum(vector<vector<int>> &traingle){
        int n = traingle.size();
        return func(traingle, n);
    }
};
int main() {
     vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};
     Solution sol;
     cout << sol.minTraingleSum(triangle);

     return 0;

}