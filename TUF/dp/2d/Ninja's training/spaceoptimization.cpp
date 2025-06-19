#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int ninjaTraining(vector<vector<int>> &matrix) {
        int n = matrix.size();

        vector<int> prev(4, 0);

        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1],matrix[0][2]));

        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            for (int task = 0; task <= 2; task++) {
                temp[last] = 0;
                for (int last = 0; task <= 2; task++) {
                    if(task!= last){
                        temp[last] = max(temp[last], matrix[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;

        }
        return prev[3];
    }
};