//https://youtu.be/aQD4N_p_0es?si=rHBGsnhk-MD3Mcrr

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll a[n], b[n];
        bool take[n];

        for (ll i = 0; i < n; i++) {
            take[i] = true;
            cin >> a[i] >> b[i];
        }

        for (ll i = 0; i < n;i++) {
            if(take[i]){
                for (ll j = 0; j < n; j++) {
                    if(take[j] && i != j) {
                        if(a[j] >=a[i] && b[j] <=b[i]){
                            take[j] = false;
                        }
                    } 
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if(take[i])
                ans++;
        }
            cout << ans << "\n";
            for (ll i = 0; i < n; i++) {
                if(take[i])
                    cout << i + 1 << " ";
            }
            cout << "\n";
    }
}
