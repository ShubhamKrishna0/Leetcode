#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numNodes;
        cin >> numNodes;

        // Tree adjacency list
        vector<vector<int>> tree(numNodes);

        // Read edges and build the tree
        for (int i = 0; i < numNodes - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // Convert to 0-based index
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> parent(numNodes), distance(numNodes);
        function<void(int, int)> dfs = [&](int currentNodes, int parentNodes){
            //parentNode → the node we came from (to avoid going back in recursion)
            parent[currentNodes] = parentNodes;
            for(int neighbor : tree[currentNodes]) {
                if(neighbor != parentNodes) {
                    distance[neighbor] = distance[currentNodes] + 1;
                    dfs(neighbor, currentNodes);
                }
            }
        };
        /*
        After DFS:
distance[] gives us how far each node is from the start
parent[] allows us to trace paths back.
This is exactly how we find:
The farthest node from a starting point.
Then the farthest node from that → the diameter.
And finally, reconstruct the diameter path.
        */
        distance[0] = 0;
        dfs(0, -1);
        int diameterEnd1 = max_element(distance.begin(), distance.end()) - distance.begin();

        distance[diameterEnd1] = 0;
        dfs(diameterEnd1, -1);
        int diameterEnd2 = max_element(distance.begin(), distance.end()) - distance.begin();

        if(distance[diameterEnd2] == numNodes -1 ) {
            cout << -1 << '\n';
        }else{
            vector<int> isOnDiameter(numNodes, 0);
            int current = diameterEnd2;
            while(current != -1) {
                isOnDiameter[current] = 1;
                current = parent[current];
            }
            int firstA = -1, firstB = -1, firstC = -1;
            for (int node = 0; node < numNodes; node++) {
                for(int neighbor : tree[node]){
                    if(isOnDiameter[node] && !isOnDiameter[neighbor]) {
                        /*
                        node is on the diameter.
neighbor is not on the diameter.
➝ This means we found a branch sticking out from the main diameter path.
                        */
                        firstA = parent[node];
                        firstB = node;
                        firstC = neighbor;
                        break;
                    }
                }
                if(firstA != -1)
                    break;
            }
            cout << firstA + 1 << ' ' << firstB + 1 << ' ' << firstC + 1 << '\n';

        }
    }
}

/*
Nice — I’ll explain **every single line** of that program and *visualize it with the concrete 6-node example* you gave earlier. I’ll show the state of the important variables (adjacency list, `parent`, `distance`, `isOnDiameter`, and the chosen triple) after each logical step so you can use this as a revision cheat-sheet.

---

# Code (numbered lines for reference)

```cpp
 1  #include <bits/stdc++.h>
 2  using namespace std;
 3
 4  int main() {
 5      ios::sync_with_stdio(false);
 6      cin.tie(nullptr);
 7
 8      int testCases;
 9      cin >> testCases;
10
11      while (testCases--) {
12          int numNodes;
13          cin >> numNodes;
14
15          // Tree adjacency list
16          vector<vector<int>> tree(numNodes);
17
18          // Read edges and build the tree
19          for (int i = 0; i < numNodes - 1; i++) {
20              int u, v;
21              cin >> u >> v;
22              u--; v--; // Convert to 0-based index
23              tree[u].push_back(v);
24              tree[v].push_back(u);
25          }
26
27          // parent[node] = parent of node in DFS
28          // distance[node] = distance from DFS root
29          vector<int> parent(numNodes), distance(numNodes);
30
31          // DFS function to fill parent and distance
32          function<void(int, int)> dfs = [&](int currentNode, int parentNode) {
33              parent[currentNode] = parentNode;
34              for (int neighbor : tree[currentNode]) {
35                  if (neighbor != parentNode) {
36                      distance[neighbor] = distance[currentNode] + 1;
37                      dfs(neighbor, currentNode);
38                  }
39              }
40          };
41
42          // Step 1: Find one endpoint of the diameter
43          distance[0] = 0;
44          dfs(0, -1);
45          int diameterEnd1 = max_element(distance.begin(), distance.end()) - distance.begin();
46
47          // Step 2: Find the other endpoint of the diameter
48          distance[diameterEnd1] = 0;
49          dfs(diameterEnd1, -1);
50          int diameterEnd2 = max_element(distance.begin(), distance.end()) - distance.begin();
51
52          // Step 3: Check if the tree is already a path
53          if (distance[diameterEnd2] == numNodes - 1) {
54              cout << -1 << '\n'; // No operation needed
55          } else {
56              // Step 4: Mark nodes on the diameter
57              vector<int> isOnDiameter(numNodes, 0);
58              int current = diameterEnd2;
59              while (current != -1) {
60                  isOnDiameter[current] = 1;
61                  current = parent[current];
62              }
63
64              // Step 5: Find first sliding operation
65              int firstA = -1, firstB = -1, firstC = -1;
66              for (int node = 0; node < numNodes; node++) {
67                  for (int neighbor : tree[node]) {
68                      if (isOnDiameter[node] && !isOnDiameter[neighbor]) {
69                          firstA = parent[node]; // parent of node on diameter
70                          firstB = node;         // node on diameter
71                          firstC = neighbor;     // neighbor off diameter
72                          break;
73                      }
74                  }
75                  if (firstA != -1) break;
76              }
77
78              // Output first sliding operation (convert back to 1-based)
79              cout << firstA + 1 << ' ' << firstB + 1 << ' ' << firstC + 1 << '\n';
80          }
81      }
82  }
```

---

# Line-by-line explanation (grouped by logical blocks)

### Lines 1–3: includes & namespace

* **1:** `#include <bits/stdc++.h>` — convenience header that pulls in STL (vector, algorithm, function, etc.).
* **2:** `using namespace std;` — so we don't have to write `std::` everywhere.

---

### Lines 4–9: main, fast IO, read test count

* **4:** `int main() {` — program entry.
* **5–6:** `ios::sync_with_stdio(false); cin.tie(nullptr);` — standard fast I/O boilerplate.
* **8–9:** Declare `testCases` and read it from input.

---

### Lines 11–25: per-test setup and building the adjacency list

* **11:** `while (testCases--) {` — loop over test cases.
* **12–13:** Read `numNodes` (call it `n` conceptually).
* **16:** `vector<vector<int>> tree(numNodes);` — adjacency list: `tree[i]` contains neighbors of node `i`.
* **19–25:** Read the `n-1` edges. For each:

  * **21:** read `u, v` (1-based).
  * **22:** convert to 0-based: `u--, v--;`
  * **23–24:** add each endpoint to the other’s neighbor list.

**Important:** after this loop you have the full tree in `tree`.

---

### Lines 27–40: `parent` & `distance` arrays and DFS lambda

* **29:** `vector<int> parent(numNodes), distance(numNodes);`

  * `parent[i]` will store the parent of node `i` in the DFS tree.
  * `distance[i]` will store distance from the DFS root used in that DFS pass.
* **32–40:** Define a recursive lambda `dfs(currentNode, parentNode)`:

  * **33:** set `parent[currentNode] = parentNode`.
  * **34–39:** iterate neighbors; if neighbor ≠ parent, set `distance[neighbor] = distance[currentNode] + 1` and `dfs(neighbor, currentNode)`.

**Note:** the lambda captures everything by reference (`[&]`) so it uses `tree`, `parent`, `distance` from outer scope.

---

### Lines 42–46: first DFS — find `diameterEnd1`

* **43:** `distance[0] = 0;` — pick root node 0 and initialize its distance.
* **44:** `dfs(0, -1);` — run DFS from node `0` (parent = -1).
* **45:** `int diameterEnd1 = max_element(distance.begin(), distance.end()) - distance.begin();`

  * `max_element(...)` returns iterator to largest `distance` value; subtracting `begin()` produces the index of that maximum — one end of a diameter.

**Why this finds an endpoint?** Running DFS from any node and taking the farthest reached node yields a diameter endpoint.

---

### Lines 47–50: second DFS — find `diameterEnd2`

* **48:** `distance[diameterEnd1] = 0;` — reinitialize the distance for new DFS root (we reuse the `distance` array).
* **49:** `dfs(diameterEnd1, -1);` — run DFS again from `diameterEnd1`.
* **50:** `int diameterEnd2 = max_element(distance.begin(), distance.end()) - distance.begin();` — the farthest node from `diameterEnd1`, so the other end of the diameter. `distance[diameterEnd2]` is the diameter length.

---

### Lines 52–55: check if already a path

* **53:** `if (distance[diameterEnd2] == numNodes - 1)` — if diameter length equals `n-1` (i.e., tree is already a single path covering all nodes).
* **54:** `cout << -1 << '\n';` — no operation needed.

---

### Lines 56–62: mark nodes on the diameter

* **57:** `vector<int> isOnDiameter(numNodes, 0);` — boolean flags (0/1) for nodes on diameter.
* **58:** `int current = diameterEnd2;` — start from one endpoint of diameter.
* **59–62:** walk upwards using `parent[]`:

  * mark `isOnDiameter[current] = 1`, then `current = parent[current]` until `current == -1`.
  * This traces the exact node sequence from `diameterEnd2` back to `diameterEnd1` (because the last DFS filled `parent` relative to `diameterEnd1`).

---

### Lines 64–76: choose the first sliding operation `(a,b,c)`

* **65:** initialize `firstA, firstB, firstC` to `-1` (meaning not found yet).
* **66–76:** loop over every `node` and its neighbors:

  * **68:** condition `if (isOnDiameter[node] && !isOnDiameter[neighbor])` — we found a *branch* attached to the diameter at `node`.
  * If found:

    * **69:** `firstA = parent[node];` — the parent of `node` on the diameter (so `a`).
    * **70:** `firstB = node;` — the diameter node where the branch attaches (so `b`).
    * **71:** `firstC = neighbor;` — some branch node not on the diameter (so `c`).
  * **72–75:** break both loops as soon as we find one valid triple (we only need the first move).

**Why this triple is valid?** `b` is on the diameter and connected to `a` (its parent on diameter) and to `c` (off-diameter neighbor). That's exactly the sliding operation form `(a,b,c)`.

---

### Lines 78–79: output

* **79:** `cout << firstA + 1 << ' ' << firstB + 1 << ' ' << firstC + 1 << '\n';` — print 1-based indices as required.

---

# Concrete worked example (the one you used)

Input edges (1-based):

```
n = 6
4 3
3 5
3 1
1 2
3 6
```

**Convert to 0-based and build adjacency**:

Edges (0-based):
(3,2), (2,4), (2,0), (0,1), (2,5)

Adjacency `tree` (index: neighbors):

```
0: {2, 1}       // node 1 connected to 3 and 2
1: {0}          // node 2 connected to 1
2: {3, 4, 0, 5} // node 3 connected to 4,5,1,6
3: {2}          // node 4
4: {2}          // node 5
5: {2}          // node 6
```

**Visual (1-based labels)**:

```
      3
    / | \
   4  5  1
         |
         2
         |
         6
```

(But more accurately: node 3 connects to 4,5,1,6 and node 1 connects to 2.)

---

## First DFS: `dfs(0, -1)`  (root = node 0 = 1 in 1-based)

Start: `distance[0] = 0`

Traversal (one possible order matching adjacency lists):

```
dfs(0,-1): parent[0] = -1
  neighbor 2 -> distance[2] = 1, dfs(2,0):
     neighbor 3 -> distance[3] = 2, parent[3] = 2
     neighbor 4 -> distance[4] = 2, parent[4] = 2
     neighbor 0 -> skip (parent)
     neighbor 5 -> distance[5] = 2, parent[5] = 2
  neighbor 1 -> distance[1] = 1, parent[1] = 0
```

`distance` after DFS(0): indices 0..5:

```
distance = [0, 1, 1, 2, 2, 2]
parent   = [-1,0,0,2,2,2]  // parent filled in that order
```

* The farthest distance is `2`. `max_element` returns first index with value 2 → index `3` (0-based). So:

```
diameterEnd1 = 3  // node 4 in 1-based
```

---

## Second DFS: `dfs(diameterEnd1=3, -1)`

Initialize `distance[3] = 0` and call `dfs(3,-1)`. The DFS (following adjacency order) sets:

Traversal:

```
dfs(3,-1): parent[3] = -1, neighbor 2 -> distance[2] = 1, parent[2]=3
  dfs(2,3):
     neighbor 3 -> skip
     neighbor 4 -> distance[4] = 2, parent[4] = 2
     neighbor 0 -> distance[0] = 2, parent[0] = 2
        dfs(0,2):
           neighbor 2 -> skip
           neighbor 1 -> distance[1] = 3, parent[1] = 0
     neighbor 5 -> distance[5] = 2, parent[5] = 2
```

`distance` after second DFS:

```
distance = [2, 3, 1, 0, 2, 2]
parent   = [2, 0, 3, -1, 2, 2]
```

* Max distance value = `3` at index `1` (0-based). So:

```
diameterEnd2 = 1  // node 2 in 1-based
diameter length = distance[1] = 3
```

**Thus diameter path (by following parent\[]):**
start at `diameterEnd2 = 1`:

```
1 -> parent[1]=0 -> parent[0]=2 -> parent[2]=3 -> parent[3]=-1
indices: 1,0,2,3  => 1-based nodes: 2,1,3,4
So diameter path = 2 — 1 — 3 — 4
(length = 3 edges)
```

---

## Mark nodes on diameter (Lines 56–62)

We walk from `current = diameterEnd2 (=1)` up parents and mark:

```
isOnDiameter indices 0..5:
start: all 0
visit 1 -> set isOnDiameter[1] = 1
parent[1] = 0 -> set isOnDiameter[0] = 1
parent[0] = 2 -> set isOnDiameter[2] = 1
parent[2] = 3 -> set isOnDiameter[3] = 1
parent[3] = -1 -> stop
Result: isOnDiameter = [1,1,1,1,0,0]
```

So nodes on the diameter (0-based) are `{0,1,2,3}` → (1-based `{1,2,3,4}`).

---

## Find first sliding operation (Lines 64–76)

We loop nodes 0..5 and check neighbors:

* node 0 (on diameter): neighbors {2,1} — both on diameter → skip
* node 1 (on diameter): neighbor {0} — on diameter → skip
* node 2 (on diameter): neighbors {3,4,0,5}

  * neighbor 3 → on diameter
  * neighbor 4 → **NOT** on diameter → we found branch
    So set:

```
firstA = parent[2] = 3     // 0-based
firstB = 2
firstC = 4
```

Convert to 1-based for output:

```
(firstA+1, firstB+1, firstC+1) = (4, 3, 5)
```

That matches the sample solution.

---

# Visualizing the selected triple `(a,b,c) = (4,3,5)` (1-based)

Before the sliding operation:

```
    4
     \
      3
     /| \
    5 1  6
      |
      2
```

We picked `b = 3`, `a = 4` (parent on diameter), and `c = 5` (branch off diameter). The sliding operation with `(4,3,5)` will reattach all other neighbors of `b` (except `a` and `c`) to `c`. That moves the subtree hanging at `1` to be attached to `5`, increasing the diameter by 1. (You only need this first triple as output.)

---

# Complexity, edge cases, and final notes

* **Time complexity:** Each test case does two DFS traversals and then simple linear scans — `O(n)` per test. Sum of `n` over tests ≤ 2·10⁵ so this is fine.
* **Space complexity:** `O(n)` for adjacency + arrays.
* **Edge cases:**

  * `n = 1`: code works — diameter length 0 ⇒ prints `-1`.
  * Already a path → `distance[diameterEnd2] == n-1` triggers `-1`.
* **Why this is optimal:** Each sliding increases diameter by at most 1; we pick operations that increase it by 1 along the way, so the minimal total is `(n-1) - diameter_length`. We only need the *first* such operation.

---

If you want, I can:

* produce a **step-by-step animation** of the DFS call stack for the example,
* produce similar walkthroughs for other sample trees (like a star, or an already-path), or
* rewrite the code with inline comments on each line (so you can paste it and study).

Which would help your revision most?

*/