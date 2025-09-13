#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector<pair<int,int>> edges(m);
        for(int i = 0; i < m; i++){
            cin >> edges[i].first >> edges[i].second;
        }
        
        if(m < n - 1){
            cout << -1 << "\n";
            continue;
        }
        
        long long ans = 0;
        for(int i = 1; i <= n - 1; i++){
            ans += i;
        }
        cout << ans << "\n";
    }
    
    return 0;
}