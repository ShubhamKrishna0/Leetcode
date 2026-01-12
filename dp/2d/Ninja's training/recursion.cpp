#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int func(int day , int last , vector<vector<int>> &points){
        if(day == 0){
            int maxi = 0;
        /*calculate the maximum points for the first day 
        by choosing an activity different from last one*/
        for (int i = 0; i <= 2; i++) {
            if(i!=last )
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i <= 2; i++){
        if(i!= last) {
            /*
            calculate the points for the current activity and 
            add it to the maximum points obtained so far
            */
            int activity = points[day][i] + func(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
    }
    public:
    int ninjaTraining(vector<vector<int>> & matrix) {
        int day = matrix.size() - 1;
        int last = 3;
        return func(day, last, matrix);
    }
};

int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    Solution sol;
    cout << sol.ninjaTraining(points);
}