#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses); // list of courses that depend on courses i
        vector<int> indegree(numCourses, 0); // number of prerequisites needed before you can take course i.

        for (const auto &pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        /*
For prerequisite [a, b]:
b → a (b must be taken first)
Increase indegree of a because it has one more dependency.
        */
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        // Courses with indegree 0 = no prerequisites → you can take them immediately.
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            /*
Every time you pop a node, it means:
You "finish" that course.
             */
            for (int next : adj[node])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
            /*
Removing indegree simulates:
"Since you finished ‘node’, one prerequisite of next is completed."
            */
        }
        return count == numCourses;
    }
};

/*

Great — this is the **BFS (Kahn’s Algorithm)** version of Course Schedule.
I’ll explain it **step-by-step with a full example**, so you will easily understand how and why it works.

---

# ⭐ Problem Reminder

We must check:

> “Can we finish all courses without violating prerequisites?”

This becomes a **topological sorting problem**.
If we can generate a valid ordering of all courses → ✔ possible.
If we cannot → ❌ cycle exists → impossible.

---

# ⭐ Your Code Uses Kahn’s Algorithm

Kahn’s Algorithm uses:

### ✔ `indegree[]`

Number of prerequisites for each course.

### ✔ A queue

Courses with **0 prerequisites** can be taken immediately.

### ✔ BFS

Process courses one-by-one and reduce indegrees of dependent courses.

---

# 📌 Let's Understand the Code With an Example

### **Example**

```
numCourses = 4
prerequisites = [[1,0],[2,1],[3,2]]
```

Meaning:

```
0 → 1 → 2 → 3
```

No cycle → we should return **true**.

---

# 🧩 Step 1 — Build Adj List + Indegree

### prerequisites:

```
[1,0]   // to take 1 you need 0
[2,1]   // to take 2 you need 1
[3,2]   // to take 3 you need 2
```

### Build graph:

```cpp
adj[0] = {1}
adj[1] = {2}
adj[2] = {3}
adj[3] = {}
```

### indegree:

| Course | indegree | Meaning         |
| ------ | -------- | --------------- |
| 0      | 0        | No prerequisite |
| 1      | 1        | Needs 0         |
| 2      | 1        | Needs 1         |
| 3      | 1        | Needs 2         |

---

# 🧩 Step 2 — Push all indegree 0 nodes into queue

```cpp
if(indegree[i] == 0) q.push(i);
```

Only `0` has indegree 0.

```
q = [0]
```

`count = 0`

---

# 🧩 Step 3 — BFS begins

---

## 🔥 Pop 0 from queue

```
node = 0
count = 1
```

Neighbors:

```
adj[0] = {1}
```

Decrease indegree of `1`:

```
indegree[1] = 0   (was 1)
```

Push into queue:

```
q = [1]
```

---

## 🔥 Pop 1

```
node = 1
count = 2
```

Neighbors:

```
adj[1] = {2}
```

Reduce indegree:

```
indegree[2] = 0
```

Push:

```
q = [2]
```

---

## 🔥 Pop 2

```
node = 2
count = 3
```

Neighbors:

```
adj[2] = {3}
```

Reduce indegree:

```
indegree[3] = 0
```

Push:

```
q = [3]
```

---

## 🔥 Pop 3

```
node = 3
count = 4
```

Neighbors:

```
adj[3] = {}     // nothing
```

---

# ⭐ End of BFS

Queue is empty.

`count = 4`

Since:

```
count == numCourses   → 4 == 4 → true
```

We successfully processed all courses → no cycle.

---

# ❗ Now Example With a Cycle

Let's take:

```
numCourses = 2
prerequisites = [[1,0],[0,1]]
```

Graph:

```
0 → 1
↑    ↓
└────┘
```

### indegree:

| Course | indegree |
| ------ | -------- |
| 0      | 1        |
| 1      | 1        |

### Queue initially:

No course has indegree 0 → queue stays **empty**.

```cpp
q = []
count = 0
```

We never enter the BFS loop.

At the end:

```
count == numCourses  → 0 == 2 → false
```

So we return **false** (cycle detected).

---

# ⭐ Final Explanation (Short Interview Style)

> I use Kahn’s Algorithm (BFS Topological Sort).
> I count indegrees for each course.
> Any course with indegree 0 can be taken immediately, so I push it into a queue.
> Then I repeatedly take a course from the queue, reduce indegree of its dependent courses, and push new nodes with 0 indegree.
> If I can process all `numCourses`, there is no cycle.
> If some courses remain unprocessed (indegree never became 0), it means a cycle exists.
> So the answer is `count == numCourses`.

---

If you want, I can also provide:

✅ A diagram
✅ Dry run animation
✅ DFS vs BFS comparison
Just tell me!

*/