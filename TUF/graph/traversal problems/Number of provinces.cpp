#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void bfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            for (auto adjNode : adjLs[i])
            {
                if (vis[adjNode] != 1)
                {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj)
    {
        int V = adj.size();
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;

                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

/*
Perfect! Let’s **visualize this specific input step by step**, using the same line-by-line logic and plain English explanation.

---

### **Input matrix:**

```
    0 1 2 3
0 [ 1 0 0 1 ]
1 [ 0 1 1 0 ]
2 [ 0 1 1 0 ]
3 [ 1 0 0 1 ]
```

Interpretation:

* City 0 ↔ City 3
* City 1 ↔ City 2
* So we can already see two separate groups (provinces): `{0,3}` and `{1,2}`.

---

## **Step 1: Convert to adjacency list**

Code logic:

```cpp
for i in 0..V-1:
    for j in 0..V-1:
        if adj[i][j] == 1 and i != j:
            add j to adj[i]
            add i to adj[j]
```

**Adjacency list after conversion:**

```
0 → [3]
1 → [2]
2 → [1]
3 → [0]
```

Think of it like a **friend list**:

```
0 ↔ 3
1 ↔ 2
```

---

## **Step 2: Initialize visited array**

```
vis = [0, 0, 0, 0]
count = 0
```

---

## **Step 3: Loop through each city**

### **i = 0**

* `vis[0] == 0` → new province → `count = 1`
* Start BFS from city 0
* Queue = [0]
* Mark visited: `vis = [1, 0, 0, 0]`

**BFS Loop:**

1. Pop 0 → queue = []

   * Neighbours = [3]
   * vis[3] = 0 → mark visited, push 3
   * vis = [1,0,0,1], queue = [3]

2. Pop 3 → queue = []

   * Neighbours = [0] → already visited → skip

* Queue empty → BFS ends

✅ Province `{0,3}` fully explored

---

### **i = 1**

* `vis[1] == 0` → new province → `count = 2`
* Start BFS from city 1
* Queue = [1], vis = [1,1,0,1]

**BFS Loop:**

1. Pop 1 → queue = []

   * Neighbours = [2]
   * vis[2] = 0 → mark visited, push 2
   * vis = [1,1,1,1], queue = [2]

2. Pop 2 → queue = []

   * Neighbours = [1] → already visited → skip

* Queue empty → BFS ends

✅ Province `{1,2}` fully explored

---

### **i = 2**

* `vis[2] == 1` → already visited → skip

### **i = 3**

* `vis[3] == 1` → already visited → skip

---

## **Step 4: Final count**

```
count = 2
```

✅ So the answer is **2 provinces**.

---

### **Plain-language explanation**

1. Look at each city.
2. If it hasn’t been visited, start a BFS to find all connected cities → that’s one province.
3. City 0 connects to 3 → province `{0,3}`
4. City 1 connects to 2 → province `{1,2}`
5. All cities are visited → done.
6. Total provinces = 2

---

### **Visual diagram (friend circles)**

```
Province 1: 0 — 3

Province 2: 1 — 2
```

Two completely separate clusters → 2 provinces.

---

If you want, I can make a **step-by-step ASCII table showing the queue, vis array, and BFS wave for each iteration** for this input — it will feel like watching the BFS happen live.

Do you want me to do that?


*/