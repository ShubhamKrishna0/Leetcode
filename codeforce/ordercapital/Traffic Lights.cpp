#include <bits/stdc++.h>
using namespace std;

// Maximum number of nodes
const int N = 5010;

// vec[i] stores the neighbors of node i in input order
vector<int> vec[N];

// dp[2][N]: dp[t][u] = minimum wait time to reach node u at time layer t (0 or 1)
int dp[2][N], T;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        // Clear previous test case's graph
        for (int i = 1; i <= n; i++)
            vec[i].clear();

        // Read edges and construct adjacency list
        // Order of insertion matters due to time-dependent edge selection
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        // Initialize all dp values to "infinity" (0x3f3f3f3f)
        // This value acts as a large unreachable number for comparisons
        memset(dp, 0x3f, sizeof(dp));

        // Start from node 1 at time 0, with 0 waiting time
        dp[0][1] = 0;

        int t = 0;  // t toggles between 0 and 1 to save space

        // Simulate time from 0 to 3*n (upper bound for guaranteed reachability)
        for (int i = 0; i <= 3 * n; i++) {

            // Reset the next time layer of dp to "infinity"
            for (int j = 1; j <= n; j++)
                dp[1 - t][j] = dp[0][0];
                /*
                 Explanation:
                 - dp[0][0] was previously filled with 0x3f3f3f3f, acts as INF.
                 - We reset the next layer dp[1 - t][j] to INF before computing updates.
                 - `1 - t` flips between 0 and 1 to simulate dp[t + 1] using only two arrays.
                */

            // Process transitions from each node j at current time layer
            for (int j = 1; j <= n; j++) {

                // Only update if node j is reachable at current time
                if (dp[t][j] != dp[0][0]) {

                    int deg = vec[j].size();  // degree of node j

                    if (deg > 0) {
                        // At time i, the allowed neighbor is based on (i % degree)
                        int moveIndex = i % deg;
                        int nextNode = vec[j][moveIndex];

                        // Move to nextNode without increasing wait time
                        dp[1 - t][nextNode] = min(dp[1 - t][nextNode], dp[t][j]);
                    }

                    // Or: wait 1 second at node j (which increases wait time by 1)
                    dp[1 - t][j] = min(dp[1 - t][j], dp[t][j] + 1);
                }
            }

            // Check if destination node n is reachable at this time step
            if (dp[1 - t][n] != dp[0][0]) {
                cout << i + 1 << ' ' << dp[1 - t][n] << '\n';  // total time, min wait time
                break;
            }

            // Swap layers: current becomes next, and next becomes current
            t = 1 - t;
        }
    }

    return 0;
}
