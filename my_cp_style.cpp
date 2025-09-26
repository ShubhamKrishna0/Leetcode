#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>
#include <climits>
#include <deque>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <bitset>
#include <stack>
#include <sstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Shubham Krishna CP style
// "The harder you train, the luckier you get."

#define int long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define FOR(i,k,n) for(int i=k;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define get(a) for(auto &i:a) cin>>i
#define put(a) cout<<endl; for(auto &i:a) cout<<i<<" "
#define ps(x,y) fixed<<setprecision(y)<<x
#define endl "\n"

const int mod=1e9+7;
const int INF=LLONG_MAX;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

const int MAXN=1e6+1;
int st[MAXN][20];

void buildSparse(const vector<pii>& v,int N){
    for(int i=0;i<N;i++) st[i][0]=v[i].ff;
    for(int j=1;j<=20;j++)
        for(int i=0;i+(1<<j)<=N;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int query(int L,int R){
    int j=log2(R-L+1);
    return max(st[L][j],st[R-(1<<j)+1][j]);
}

void fastIO(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

void solve(){
    
}

signed main(){
    fastIO();
    solve();
    return 0;
}
