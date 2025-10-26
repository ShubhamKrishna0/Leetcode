#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(n == 2){
        cout << "1\n1\n";
        return;
    }
    
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    parent[1] = 1;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
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
    
    vector<string> ops;
    set<int> destroyed;
    
    for(int i = 0; i < path.size() - 1; i++){
        vector<int> to_destroy;
        for(int v : adj[path[i]]){
            if(v != path[i+1] && destroyed.find(v) == destroyed.end()){
                to_destroy.push_back(v);
            }
        }
        
        for(int v : to_destroy){
            ops.push_back("2 " + to_string(v));
            destroyed.insert(v);
            if(i < path.size() - 2){
                ops.push_back("1");
            }
        }
        
        if(to_destroy.empty() || i == path.size() - 2){
            ops.push_back("1");
        }
    }
    
    cout << ops.size() << "\n";
    for(string op : ops){
        cout << op << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}