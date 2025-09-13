#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if(intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    stack<vector<int>> st;
    st.push(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i){
        vector<int> top = st.top();

        //if the current interval overlaps with top of the stack
        if(intervals[i][0] <= top[1]){
            top[1] = max(top[1], intervals[i][1]);
            st.pop();
            st.push(top);
        }else{
            st.push(intervals[i]);
        }
    }
    vector<vector<int>> merged;
    while(!st.empty()) {
        merged.push_back(st.top());
        st.pop();
    }
    reverse(merged.begin(), merged.end());
    return merged;

}
int main () {
    vector<vector<int>> intervals ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);

    cout << "Merged Intervals: ";
    for (auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

/*
Let's **visualize** this loop with the input:

```cpp
vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
```

---

### 🔢 After Sorting:

```cpp
{{1,3}, {2,6}, {8,10}, {15,18}}
```

---

### 🔁 Iteration with Stack Visualization

We'll simulate the `for` loop and show how the stack (`st`) changes at each step.

---

#### ✅ **Initial State:**

```cpp
st = [ {1,3} ] // First interval pushed manually before the loop
```

---

### 🔄 **Loop Iteration:**

#### 🧩 i = 1 → interval = {2,6}

```cpp
top = st.top() = {1,3}
intervals[1][0] = 2 <= top[1] = 3 → overlap ✅
Merged = {1, max(3,6)} = {1,6}

Stack after pop and push:
st = [ {1,6} ]
```

---

#### 🧩 i = 2 → interval = {8,10}

```cpp
top = st.top() = {1,6}
intervals[2][0] = 8 > 6 → no overlap ❌

Push {8,10}:
st = [ {1,6}, {8,10} ]
```

---

#### 🧩 i = 3 → interval = {15,18}

```cpp
top = st.top() = {8,10}
intervals[3][0] = 15 > 10 → no overlap ❌

Push {15,18}:
st = [ {1,6}, {8,10}, {15,18} ]
```

---

### 📦 Final Stack:

```
[ {1,6}, {8,10}, {15,18} ]
```

Then we pop from the stack into a result vector and **reverse it** to get:

```
Result: [ {1,6}, {8,10}, {15,18} ]
```

---

### 🖼️ Summary Table:

| i | Current Interval | Top of Stack | Overlap? | Action Taken   | Stack State                 |
| - | ---------------- | ------------ | -------- | -------------- | --------------------------- |
| 0 | {1,3}            | -            | -        | Push first     | \[ {1,3} ]                  |
| 1 | {2,6}            | {1,3}        | ✅        | Merge to {1,6} | \[ {1,6} ]                  |
| 2 | {8,10}           | {1,6}        | ❌        | Push           | \[ {1,6}, {8,10} ]          |
| 3 | {15,18}          | {8,10}       | ❌        | Push           | \[ {1,6}, {8,10}, {15,18} ] |

---

Let me know if you'd like a **graphical diagram** of this too — I can generate that.

*/