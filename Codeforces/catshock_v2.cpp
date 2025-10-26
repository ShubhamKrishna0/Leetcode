#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void solve(){
    int n; 
    cin >> n;
    vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < n-1; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Find path from 1 to n
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    parent[1] = 1;
    
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        for(int v : adj[u]){
            if(parent[v] == -1){
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    vector<int> path;
    int cur = n;
    while(cur != 1){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    
    vector<string> result;
    
    // Process each node on path except last
    for(int i = 0; i < (int)path.size() - 1; i++){
        int curr = path[i];
        int next = path[i+1];
        
        // Destroy all neighbors except the next one on path
        for(int neighbor : adj[curr]){
            if(neighbor != next){
                result.push_back("2 " + to_string(neighbor));
            }
        }
        
        // Move forward
        result.push_back("1");
    }
    
    cout << result.size() << "\n";
    for(const string& op : result){
        cout << op << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}