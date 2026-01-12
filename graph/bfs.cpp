#include<bits/stdc++.h>
using namespace std;

class Solution  {
    public:
    vector<int> bfsOfGraph(int v , vector<int> adj[]) {
        int vis[v] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            bfs.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
                }
        return bfs;
    }
};

/*
Perfect 👍 Let’s go **line-by-line** and *visually understand* what every line in this BFS code is doing.
I’ll treat this as if you’re **seeing the graph being explored step-by-step in your mind**.

---

### 🧠 Context

We’re doing a **Breadth-First Search (BFS)** on a graph starting from node `0`.

**Input:**

* `v` → number of vertices in the graph
* `adj[]` → adjacency list (for every vertex, it stores a list of all its neighboring vertices)

**Output:**

* A list (`bfs`) representing the order in which we visit nodes during BFS.

---

## 💻 Code Walkthrough (with Visualization)

---

```cpp
#include<bits/stdc++.h>
using namespace std;
```

✅ Includes *all standard libraries* (like vector, queue, etc.)
✅ `using namespace std;` — so we don’t have to prefix `std::` everywhere.

---

```cpp
class Solution  {
```

🧩 We define a class `Solution` to encapsulate our BFS function (common in LeetCode/GeeksForGeeks-style problems).

---

```cpp
public:
    vector<int> bfsOfGraph(int v , vector<int> adj[]) {
```

🔹 We define a **public function** `bfsOfGraph`.
It takes:

* `v` = number of vertices (e.g., 5)
* `adj[]` = adjacency list representation of the graph.

And returns a `vector<int>` (the BFS traversal order).

---

```cpp
int vis[v] = {0};
```

🔹 Creates a **visited array** of size `v`, initialized to all zeros.
Each index `i` represents whether node `i` is visited (`1` = yes, `0` = no).

🧠 Think of it as light bulbs:

```
Initially: [0, 0, 0, 0, 0]
           (All bulbs OFF → no node visited yet)
```

---

```cpp
vis[0] = 1;
```

🔹 Mark the **starting node (0)** as visited.

```
[1, 0, 0, 0, 0]
Node 0 → visited
```

---

```cpp
queue<int> q;
```

🔹 Creates a **queue** for BFS — it stores nodes we need to explore next.

---

```cpp
q.push(0);
```

🔹 Add **starting node (0)** into the queue.

```
Queue: [0]
```

---

```cpp
vector<int> bfs;
```

🔹 Create a vector to store BFS traversal order (the answer).

---

### 🌀 Now starts the BFS loop

```cpp
while(!q.empty()) {
```

🔹 Run the loop while the queue is **not empty** — meaning there are still nodes to explore.

---

```cpp
int node = q.front();
q.pop();
```

🔹 Take the **front element** from the queue (the next node to explore).
🔹 Remove it from the queue.

📊 Example visualization:

```
Queue before: [0]
Take out → node = 0
Queue after: []
```

---

```cpp
bfs.push_back(node);
```

🔹 Record that we’ve **visited** this node.

```
bfs = [0]
```

---

### 👀 Explore neighbors

```cpp
for(auto it : adj[node]) {
```

🔹 For every **neighbor** (`it`) of the current node (`node`):

* Look into its adjacency list to find connected nodes.

---

```cpp
if(!vis[it]){
```

🔹 If this neighbor **has not been visited yet**, proceed.

---

```cpp
vis[it] = 1;
```

🔹 Mark it as visited in the visited array.

---

```cpp
q.push(it);
```

🔹 Add it into the queue, meaning we’ll explore it later.

📊 Visualization example:

```
Current node = 0
adj[0] = [1, 2]
vis before = [1, 0, 0, 0, 0]
After exploring:
vis = [1, 1, 1, 0, 0]
Queue = [1, 2]
```

---

```cpp
}
```

🔹 Ends the `if` condition for checking visited status.

---

```cpp
}
```

🔹 Ends the `for` loop — done exploring all neighbors of the current node.

---

🔁 **Then the `while` loop continues**:

* The next element in the queue is popped.
* Its neighbors are visited and added to the queue.
* Repeat until queue becomes empty.

---

When the queue is finally empty, all reachable nodes have been visited.

---

```cpp
return bfs;
```

🔹 Return the final traversal order.

---

### 🧩 Example Visualization: Graph Traversal

Let’s assume the graph is:

```
0 → [1, 2]
1 → [0, 3, 4]
2 → [0]
3 → [1]
4 → [1]
```

#### Step-by-step BFS:

| Step  | Queue   | Visited Array | BFS Result  |
| ----- | ------- | ------------- | ----------- |
| Start | [0]     | [1,0,0,0,0]   | []          |
| Pop 0 | [1,2]   | [1,1,1,0,0]   | [0]         |
| Pop 1 | [2,3,4] | [1,1,1,1,1]   | [0,1]       |
| Pop 2 | [3,4]   | same          | [0,1,2]     |
| Pop 3 | [4]     | same          | [0,1,2,3]   |
| Pop 4 | []      | same          | [0,1,2,3,4] |

✅ **Final BFS Traversal = [0, 1, 2, 3, 4]**

---

### 🧮 Time & Space Complexity

* **Time Complexity:** `O(V + E)`
  (Each vertex and each edge is processed once)
* **Space Complexity:** `O(V)`
  (For the queue, visited array, and BFS result)

---

### 📘 Summary in Plain English

> Start from node `0`, mark it as visited, and explore all its neighbors before moving deeper.
> Keep doing this level by level (using a queue), until all reachable nodes are visited.

---

Would you like me to **add an animated-style step-by-step visualization** (like a graph expanding level by level with arrows and queue states)?
That helps *see* BFS like it’s running live.


*/