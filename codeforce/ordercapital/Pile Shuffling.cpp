#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		long long ans = 0;
		while(x--){
			long long a, b, c, d; cin >> a >> b >> c >> d;
			if(a > c){
				ans += a - c;
				a = c;
			}
			if(b > d){
				ans += a + b - d;
			}
		}
		cout << ans << "\n";
	}
}