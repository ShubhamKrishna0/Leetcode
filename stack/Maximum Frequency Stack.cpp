//https://leetcode.com/problems/maximum-frequency-stack/description/

#include<bits/stdc++.h>
using namespace std;

class FreqStack{
    private:
        unordered_map<int, int> freq; // freq[val] = how many  time val is pushed
        unordered_map<int, stack<int>> group;// group[f] =a stack of all values with frequency f. 
        int maxFreq = 0;//current maximum frequency in the stack
    public:
        FreqStack(){
            //constructor initializes empty data structure
        }

        void push(int val) {
            freq[val]++; //increase frequency of val 
            int f = freq[val];//get new frequency 
            if(f> maxFreq)
                maxFreq = f;
            group[f].push(val);

        }

        int pop() {
            int val = group[maxFreq].top();
            group[maxFreq].pop();
            freq[val]--;
            if(group[maxFreq].empty()){
                maxFreq--;
            }
            return val;
        }
};

/*
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

| Step    | freq            | group                          | maxFreq | pop result |
| ------- | --------------- | ------------------------------ | ------- | ---------- |
| push(5) | {5:1}           | {1: \[5]}                      | 1       |            |
| push(7) | {5:1, 7:1}      | {1: \[5, 7]}                   | 1       |            |
| push(5) | {5:2, 7:1}      | {1: \[5, 7], 2: \[5]}          | 2       |            |
| push(7) | {5:2, 7:2}      | {1: \[5, 7], 2: \[5, 7]}       | 2       |            |
| push(4) | {5:2, 7:2, 4:1} | {1: \[5, 7, 4], 2: \[5, 7]}    | 2       |            |
| push(5) | {5:3, 7:2, 4:1} | {1: \[...], 2: \[...], 3:\[5]} | 3       |            |
| pop()   | {5:2,...}       | group\[3].pop() = 5            | 2       | 5          |
| pop()   | {5:2, 7:1,...}  | group\[2].pop() = 7            | 2       | 7          |
| pop()   | {5:1, 7:1,...}  | group\[2].pop() = 5            | 1       | 5          |
| pop()   | {5:1, 7:1, 4:0} | group\[1].pop() = 4            | 1       | 4          |


Sure Shubham! Let's **explain the `FreqStack` code step by step** so you can understand how everything works clearly.

---

## 🔄 Problem Summary
We need to simulate a **stack** that:
- Allows us to `push(val)`.
- When we `pop()`, it removes and returns the element with **highest frequency**.
- If two values have the same frequency, return the **most recently pushed** one.

---

## ✅ Core Idea
We maintain:
1. A **frequency map** → tells how many times each value has been pushed.
2. A **group of stacks** → each frequency has a stack of values that have appeared that many times.
3. A **maxFreq variable** → tells us the current highest frequency in the stack.

---

## 🧠 Step-by-Step Code Explanation

### **Declarations:**
```cpp
unordered_map<int, int> freq;
unordered_map<int, stack<int>> group;
int maxFreq = 0;
```
- `freq[val]`: how many times `val` has been pushed.
- `group[f]`: a **stack of all values** with frequency `f`. We use a stack because we need the most recent element.
- `maxFreq`: the **current maximum frequency** in the stack.

---

### **Constructor:**
```cpp
FreqStack() {
    // Nothing to initialize here, as maps and maxFreq are already default initialized
}
```

---

### **push(int val):**
```cpp
void push(int val) {
    freq[val]++;                 // Increase frequency of val
    int f = freq[val];           // Get new frequency
    if (f > maxFreq) maxFreq = f; // Update maxFreq if needed
    group[f].push(val);         // Add val to stack for its frequency
}
```

🔍 Example:
If we push `5` three times:
- `freq[5] = 3`
- `group[3] = stack containing 5`
- `maxFreq = 3`

---

### **pop():**
```cpp
int pop() {
    int val = group[maxFreq].top(); // Get the most recent element with max frequency
    group[maxFreq].pop();           // Remove it from the stack
    freq[val]--;                    // Decrease its frequency
    if (group[maxFreq].empty()) {   // If no more elements with maxFreq
        maxFreq--;                  // Lower the maxFreq
    }
    return val;                     // Return the element
}
```

🔍 Example:
If `group[3] = [5]`, then:
- `pop()` returns `5`
- `freq[5] = 2` now
- `group[3]` becomes empty → `maxFreq` decreases to 2

---

## 📚 Example Walkthrough

### Operations:
```cpp
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
```

### Breakdown:
| Step         | freq         | group                    | maxFreq | pop result |
|--------------|--------------|---------------------------|---------|------------|
| push(5)      | {5:1}        | {1: [5]}                  | 1       |            |
| push(7)      | {5:1, 7:1}   | {1: [5, 7]}               | 1       |            |
| push(5)      | {5:2, 7:1}   | {1: [5, 7], 2: [5]}        | 2       |            |
| push(7)      | {5:2, 7:2}   | {1: [5, 7], 2: [5, 7]}     | 2       |            |
| push(4)      | {5:2, 7:2, 4:1}| {1: [5, 7, 4], 2: [5, 7]}| 2       |            |
| push(5)      | {5:3, 7:2, 4:1}| {1: [...], 2: [...], 3:[5]}| 3     |            |
| pop()        | {5:2,...}    | group[3].pop() = 5        | 2       | 5          |
| pop()        | {5:2, 7:1,...}| group[2].pop() = 7       | 2       | 7          |
| pop()        | {5:1, 7:1,...}| group[2].pop() = 5       | 1       | 5          |
| pop()        | {5:1, 7:1, 4:0}| group[1].pop() = 4      | 1       | 4          |

---

## 🧠 Why This Works

- By maintaining `group[freq[val]]` as a **stack**, we guarantee the most recently pushed element is returned in a tie.
- By tracking `maxFreq`, we **always know where to pop from** in O(1) time.

---

## ⏱ Time & Space Complexity

| Operation | Time  | Space |
|-----------|-------|-------|
| `push()`  | O(1)  | O(N)  |
| `pop()`   | O(1)  | O(N)  |

Where **N = total number of pushes**.

---

Let me know if you want the **Python version**, or if you want to run the logic step by step using a small dry run.

*/