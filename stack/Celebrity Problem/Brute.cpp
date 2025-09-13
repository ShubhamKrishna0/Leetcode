#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        vector<int> knowMe(n,0);
        vector<int> Iknow(n, 0);

        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n;j++) {

                if(M[i][j] == 1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && Iknow[i]== 0) {
                return i; 
            }
        }
        return -1;

    }
};

