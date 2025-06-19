#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int func(int i , int j) {
        if(i == 0 && j == 0)
            return 1;
        if(i<0 || j <0)
            return 0;

        int up = func(i - 1, j);
        int left = func(i, j - 1);

        return up + left;
    }
    public:
    int uniquePaths(int m , int n) {
        return func(m - 1, n - 1);
    }
};
