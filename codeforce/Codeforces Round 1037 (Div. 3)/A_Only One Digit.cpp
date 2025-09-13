#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x;
        cin >> x;

        set<int> digits;
        int temp = x;
        while (temp > 0) {
            digits.insert(temp % 10);
            temp /= 10;
        }

        for (int y = 0; y <= 9; ++y) {
            if (digits.count(y)) {
                cout << y << "\n";
                break;
            }
        }
    }

    return 0;
}
/*
Great question!

These two lines:

```cpp
digits.insert(temp % 10);
temp /= 10;
```

are **extracting digits** from the number `x` one by one. Let's break it down:

---

### 🔍 Line-by-Line Explanation:

#### 1. `temp % 10`

* This gives you the **last digit** of the number.
* For example, if `temp = 96`, then `temp % 10 = 6`.
* This is the digit we want to **store or check**.

#### 2. `digits.insert(temp % 10);`

* This line **stores the digit** in a `set<int> digits`, so that we know which digits exist in `x`.
* Using a `set` avoids duplicates automatically.

#### 3. `temp /= 10;`

* This removes the **last digit** from `temp`.
* For example, if `temp = 96`, after this line it becomes `9`.
* This prepares `temp` for the next loop iteration.

---

### 🔄 Example: x = 122

Let's trace it:

```cpp
temp = 122

1st loop:
  temp % 10 = 2 → digits.insert(2)
  temp = 12

2nd loop:
  temp % 10 = 2 → digits.insert(2)
  temp = 1

3rd loop:
  temp % 10 = 1 → digits.insert(1)
  temp = 0 → loop ends
```

Final set: `{1, 2}`

---

### 🧠 Why both lines are needed:

* `temp % 10` extracts the current digit.
* `temp /= 10` moves to the next digit.
  Without both, the loop would be infinite or wouldn't extract digits properly.

Let me know if you want to use an array or boolean for faster performance instead of `set`.

*/