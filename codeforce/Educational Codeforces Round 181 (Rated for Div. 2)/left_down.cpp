#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll g = __gcd(a, b);
        ll dx = a / g;
        ll dy = b / g;
        if (dx <= k && dy <= k) {
            cout << 1 << '\n';  // One move direction is enough
        } else {
            cout << 2 << '\n';  // Need at least two distinct directions
        }
    }
    return 0;
}



