/*
Problem: Remove redundant parentheses from an expression
Link: https://www.geeksforgeeks.org/problems/redundant-parenthesis--170647/1
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

string removeBrackets(string s) {    
    string ans = "";

    // v[i] stores the index of the matching '(' for every character
    vector<int> v(s.size());

    // st is used to match parentheses
    stack<int> st;

    // st1: indexes of brackets that contain '+' or '-'
    // st3: indexes of brackets that contain '*' or '/'
    // st2: brackets that MUST be kept (not redundant)
    unordered_set<int> st1, st2, st3;

    // ---------- FIRST PASS ----------
    // Assign each character to its surrounding '(' bracket scope
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            // Push index of '(' onto stack
            st.push(i);
            v[i] = st.top(); // Store current '(' index
        }
        else if (s[i] == ')') {
            // Assign this ')' to the last unmatched '('
            v[i] = st.top();
            st.pop(); // Done matching, pop it
        }
        else if ((s[i] == '+' || s[i] == '-') && !st.empty()) {
            // '+' or '-' is found within a bracketed scope
            v[i] = st.top();
            st1.insert(st.top()); // Mark bracket scope in st1
        }
        else if ((s[i] == '*' || s[i] == '/') && !st.empty()) {
            // '*' or '/' is found within a bracketed scope
            v[i] = st.top();
            st3.insert(st.top()); // Mark bracket scope in st3
        }
        else if (!st.empty()) {
            // Normal char inside a bracket scope
            v[i] = st.top();
        }
    }

    // ---------- SECOND PASS ----------
    // Traverse expression again to detect which brackets must be kept
    for (int i = 0; i < s.size(); i++) {
        // Only process '*', '/', '-' as they can affect precedence
        if (s[i] != '*' && s[i] != '/' && s[i] != '-') continue;
        int j = i + 1;

        // Special handling for '-' (subtraction is not associative)
        if (s[i] == '-') {
            while (j < s.size() && s[j] == '(') {
                // If bracket contains '+' or '-', we cannot remove it
                if (st1.find(v[j]) != st1.end()) 
                    st2.insert(j); // Mark this bracket to keep
                j++;
            }
            continue; // Skip further checks for '-'
        }

        // For '*' or '/', check if the next part has bracket with '+' or '-'
        j = i + 1;
        while (j < s.size() && s[j] == '(') {
            if (st1.find(v[j]) != st1.end())
                st2.insert(j); // Bracket must stay to preserve order
            j++;
        }

        // Extra check if '/' appears before bracketed multiplication/division
        if (s[i] == '/') {
            j = i + 1;
            while (j < s.size() && s[j] == '(') {
                if (st3.find(v[j]) != st3.end())
                    st2.insert(j);
                j++;
            }
        }

        // Also check to the left of the operator for closing brackets
        j = i - 1;
        while (j >= 0 && s[j] == ')') {
            if (st1.find(v[j]) != st1.end())
                st2.insert(j); // Bracket must be preserved
            j--;
        }
    }

    // ---------- FINAL STEP ----------
    // Build final string by omitting unnecessary brackets
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '(' && s[i] != ')') {
            // Always include operands/operators
            ans += s[i];
        } else {
            // Include brackets only if they are marked as important
            if (st2.find(v[i]) != st2.end()) {
                ans += s[i];
            }
        }
    }

    return ans;
}

int main() {
    string s = "(A*(B+C))";
    // Expected Output: A*(B+C)
    cout << removeBrackets(s) << endl;
    return 0;
}
/*
Absolutely! Let's walk through the **entire code** line-by-line with the input:

```
Expression: (A*(B+C))
Index:       0 1 2 3 4 5 6 7 8
Chars:       ( A * ( B + C ) )
```

---

## ✅ STEP 1: First Pass — Fill `v[]`, `st1`, and `st3`

| i | s\[i] | Stack `st` | v\[i] | st1 (has + or -) | st3 (has \* or /) | Explanation                            |
| - | ----- | ---------- | ----- | ---------------- | ----------------- | -------------------------------------- |
| 0 | (     | \[0]       | 0     |                  |                   | Open bracket → push to stack           |
| 1 | A     | \[0]       | 0     |                  |                   | A belongs to bracket at index 0        |
| 2 | \*    | \[0]       | 0     |                  | {0}               | \* belongs to bracket 0 → add to `st3` |
| 3 | (     | \[0, 3]    | 3     |                  |                   | New open bracket → push to stack       |
| 4 | B     | \[0, 3]    | 3     |                  |                   | B belongs to bracket 3                 |
| 5 | +     | \[0, 3]    | 3     | {3}              |                   | + belongs to bracket 3 → add to `st1`  |
| 6 | C     | \[0, 3]    | 3     |                  |                   | C belongs to bracket 3                 |
| 7 | )     | \[0]       | 3     |                  |                   | Close bracket → pop 3                  |
| 8 | )     | \[]        | 0     |                  |                   | Close bracket → pop 0                  |

🔹 Final results after First Pass:

```cpp
v = [0, 0, 0, 3, 3, 3, 3, 3, 0]
st1 = {3}     // bracket (B+C)
st3 = {0}     // bracket (A*(B+C))
```

---

## ✅ STEP 2: Second Pass — Find Important Brackets in `st2`

Now loop through all `s[i]` to look for operators (`*`, `/`, `-`), and figure out which brackets must be kept (saved in `st2`).

| i | s\[i] | Action                                                      | st2 | Explanation                                                |
| - | ----- | ----------------------------------------------------------- | --- | ---------------------------------------------------------- |
| 0 | (     | skip                                                        |     | not an operator                                            |
| 1 | A     | skip                                                        |     | not an operator                                            |
| 2 | \*    | → check s\[3] = `(` <br>→ v\[3] = 3 ∈ st1 → insert 3 to st2 | {3} | `*` followed by `(B+C)` which has `+`, so retain bracket 3 |
| 3 | (     | skip                                                        |     | not an operator                                            |
| 4 | B     | skip                                                        |     | not an operator                                            |
| 5 | +     | skip                                                        |     | not considered here (we only react to \* / -)              |
| 6 | C     | skip                                                        |     | not an operator                                            |
| 7 | )     | skip                                                        |     | not an operator                                            |
| 8 | )     | skip                                                        |     | not an operator                                            |

🔹 Final `st2 = {3}` → Only inner bracket `3` (i.e., **`(B+C)`**) must stay.

---

## ✅ STEP 3: Build Final Answer

Loop over all characters and add to result if:

* Not a bracket, OR
* Bracket whose scope is in `st2`

| i | s\[i] | v\[i] | Is Printed? | Reason                |
| - | ----- | ----- | ----------- | --------------------- |
| 0 | (     | 0     | ❌ No        | Not in `st2`          |
| 1 | A     | 0     | ✅ Yes       | Normal character      |
| 2 | \*    | 0     | ✅ Yes       | Normal character      |
| 3 | (     | 3     | ✅ Yes       | Bracket 3 is in `st2` |
| 4 | B     | 3     | ✅ Yes       | Normal character      |
| 5 | +     | 3     | ✅ Yes       | Normal character      |
| 6 | C     | 3     | ✅ Yes       | Normal character      |
| 7 | )     | 3     | ✅ Yes       | Bracket 3 is in `st2` |
| 8 | )     | 0     | ❌ No        | Not in `st2`          |

✅ **Final output:** `"A*(B+C)"`

---

## ✅ Final Table Summary

| Character | Index | v\[i] | Bracket Kept? | Printed? | Notes                         |
| --------- | ----- | ----- | ------------- | -------- | ----------------------------- |
| (         | 0     | 0     | ❌             | No       | Outer bracket, removed        |
| A         | 1     | 0     | ✅             | Yes      | Normal                        |
| \*        | 2     | 0     | ✅             | Yes      | Operator                      |
| (         | 3     | 3     | ✅             | Yes      | Inner bracket kept            |
| B         | 4     | 3     | ✅             | Yes      | Normal                        |
| +         | 5     | 3     | ✅             | Yes      | Normal                        |
| C         | 6     | 3     | ✅             | Yes      | Normal                        |
| )         | 7     | 3     | ✅             | Yes      | Closing inner bracket kept    |
| )         | 8     | 0     | ❌             | No       | Outer closing bracket removed |

---

## 🧾 Final Output

```cpp
A*(B+C)
```

---

Would you like to trace another example, like `((A+B)*C)` or `A-(B+C)` to see how it behaves differently?

*/