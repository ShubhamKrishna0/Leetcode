//https://codeforces.com/contest/2130/problem/D


#include <bits/stdc++.h>
using namespace std;
#define ll long long

void insert(ll i, ll node, ll l, ll h, ll s[]) {
    if (l == h) {
        s[node]++;
    } else {
        ll m = (l + h) / 2;
        if (i <= m) insert(i, 2 * node + 1, l, m, s);
        else insert(i, 2 * node + 2, m + 1, h, s);
        s[node] = s[2 * node + 1] + s[2 * node + 2];
    }
}

void update(ll i, ll node, ll l, ll h, ll s[]) {
    if (l == h) {
        s[node]--;
    } else {
        ll m = (l + h) / 2;
        if (i <= m) update(i, 2 * node + 1, l, m, s);
        else update(i, 2 * node + 2, m + 1, h, s);
        s[node] = s[2 * node + 1] + s[2 * node + 2];
    }
}

ll query(ll node, ll l, ll h, ll l1, ll h1, ll s[]) {
    if (l1 > h1 || l1 > h || l > h1) return 0;
    if (l >= l1 && h <= h1) return s[node];
    ll m = (l + h) / 2;
    return query(2 * node + 1, l, m, l1, h1, s) + query(2 * node + 2, m + 1, h, l1, h1, s);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> p(n), a(n);
        for (ll &x : p) cin >> x;

        ll ans = 0;
        ll s1[8 * n + 1] = {}, s2[8 * n + 1] = {};

        for (ll i = 0; i < n; i++) {
            insert(i + 1, 0, 1, 2 * n, s2);
        }

        for (ll i = 0; i < n; i++) {
            ll c1 = query(0, 1, 2 * n, p[i] + 1, 2 * n - p[i] - 1, s1);
            ll c2 = query(0, 1, 2 * n, p[i] + 1, 2 * n - p[i] - 1, s2);
            ans += min(c1, c2);
            a[i] = (c1 > c2) ? 2 * n - p[i] : p[i];
            insert(a[i], 0, 1, 2 * n, s1);
            update(p[i], 0, 1, 2 * n, s2);
        }

        cout << ans << "\n";
    }
}