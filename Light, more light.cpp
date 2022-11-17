#include <bits/stdc++.h>
/* #define int long long int */
typedef long long int ll;
using namespace std;
const int M = 1e9+7;

void solve() {
	ll n;
	while(cin >> n) {
		if(n == 0) return;

		ll x = sqrt(n) + 1;
		while(x * x > n) x--;
		if(x * x == n) cout << "yes\n";
		else cout << "no\n";
	}
}

int32_t main () {
     /* ios_base::sync_with_stdio(0);cin.tie(0); */

     // #ifndef ONLINE_JUDGE
     // freopen("vs_input.txt", "r", stdin);
     // freopen("vs_output.txt", "w", stdout);
     // #endif

    int t=1 ; 
    /* cin >> t; */
    for(int i=1; i<=t; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
