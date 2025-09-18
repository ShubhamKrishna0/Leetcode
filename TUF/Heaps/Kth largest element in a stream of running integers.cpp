#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    private:
        int K;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        public:
        KthLargest(int k , vector<int> &nums) {
            K = k;
            for (int i = 0; i < nums.size(); i++) {
                if(pq.size() < k)
                    pq.push(nums[i]);

                else if (nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        int add(int val) {
            if(pq.size() < K) {
                pq.push(val);
                return pq.top();
            }
            if(val >pq.top()) {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
};

/*
Got it 👍 Let’s **visualize** what your code is doing step by step.
The key idea is:
👉 Maintain a **min-heap of size K** that always contains the **K largest elements** seen so far.
👉 The **smallest element in the heap (`pq.top()`) is the Kth largest overall**.

---

### Example Walkthrough

Suppose:

```cpp
KthLargest obj(3, [4, 5, 8, 2]);
```

So:

* `K = 3`
* Initial nums = `[4, 5, 8, 2]`

---

#### Step 1: Build the heap from nums

* Start with empty `pq`.

1. Insert `4` → pq = `[4]` (size < 3 ✅)
2. Insert `5` → pq = `[4, 5]` (size < 3 ✅, internally min-heap arranges as `[4, 5]`)
3. Insert `8` → pq = `[4, 5, 8]` (size = 3 ✅)
4. Insert `2` → pq.top() = `4` and `2 < 4`, so we **skip**. pq = `[4, 5, 8]`.

Now, pq = `[4, 5, 8]`.
👉 Smallest is `4` → that’s the **3rd largest** among `[4, 5, 8, 2]`.

---

#### Step 2: Add new values one by one

Let’s do `obj.add(3)`:

* Heap = `[4, 5, 8]`, top = 4.
* New val = 3 (smaller than 4).
  ❌ Don’t insert. Heap unchanged.
* Return `4` (3rd largest so far).

---

`obj.add(5)`:

* Heap = `[4, 5, 8]`, top = 4.
* New val = 5 (greater than 4). ✅
* Pop 4 → heap becomes `[5, 8]`.
* Push 5 → heap becomes `[5, 8, 5]`.
* Return `5` (new 3rd largest).

---

`obj.add(10)`:

* Heap = `[5, 8, 5]`, top = 5.
* New val = 10 (greater than 5). ✅
* Pop 5 → heap becomes `[5, 10, 8]`.
* Return `5` (still 3rd largest).

---

`obj.add(9)`:

* Heap = `[5, 10, 8]`, top = 5.
* New val = 9 (greater than 5). ✅
* Pop 5 → `[8, 10]` then push 9 → `[8, 10, 9]`.
* Return `8`.

---

`obj.add(4)`:

* Heap = `[8, 10, 9]`, top = 8.
* New val = 4 (smaller than 8). ❌ Skip.
* Return `8`.

---

### Visualization Summary

At each step:

* Heap always holds **K largest values**.
* The smallest in heap (`pq.top()`) = **Kth largest overall**.

---

### Memory Trick (to picture heap):

Think of the heap as a **“window” of the K best numbers so far**.

* Anything smaller than the smallest in the window is ignored.
* Anything bigger kicks out the smallest to keep the window size at K.

---

⚡Would you like me to draw this as an **ASCII heap tree diagram** (showing the shape after each insertion), so you can literally *see* how the heap evolves?

*/