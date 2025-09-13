#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> insert (vector<vector<int>> &intervals , vector<int> &newintervals){
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    while(i<n && intervals[i][1] < newintervals[0]){
        result.push_back(intervals[i++]);
    }
    while(i< n  && intervals[i][0] <= newintervals[1]){
        newintervals[0] = min(newintervals[0], intervals[i][0]);
        newintervals[1] = max(newintervals[1], intervals[i][1]);
        i++;
    }
    result.push_back(newintervals);
    while(i < n) {
        result.push_back(intervals[i++]);
    }
    return result;
}

/*

| Step | i | `intervals[i]` | `newInterval` | Action                                                                     |
| ---- | - | -------------- | ------------- | -------------------------------------------------------------------------- |
| 1    | 0 | \[1,2]         | \[4,8]        | No overlap (`2 < 4`) → add `[1,2]` to result                               |
| 2    | 1 | \[3,5]         | \[4,8]        | Overlaps (`3 ≤ 8`) → merge: `newInterval = [min(3,4), max(5,8)]` = `[3,8]` |
| 3    | 2 | \[6,7]         | \[3,8]        | Overlaps (`6 ≤ 8`) → merge again → `[3,8]` stays same (no expand)          |
| 4    | 3 | \[8,10]        | \[3,8]        | Overlaps (`8 ≤ 8`) → merge: `newInterval = [3, max(10,8)] = [3,10]`        |
| 5    | 4 | \[12,16]       | \[3,10]       | No overlap (`12 > 10`) → add `[3,10]`, then add `[12,16]`                  |

*/