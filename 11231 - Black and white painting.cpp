#include <bits/stdc++.h>
/* #define int long long int */
typedef long long int ll;
using namespace std;
const int M = 1e9+7;

ll power(ll a, ll b, ll m) {
	ll ans = 1;
	while(b>0) {
		ans*=a;
		b--;
	}
	return ans;
}

ll gcd(ll a, ll b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}

void solve() {
	ll n, m, c;
	while(cin >> n >> m >> c) {
		if(n == 0 && m == 0 && c == 0) return;
		int validColumn = m - 7;
		int validRow = n - 7;
		int ans = 0;
		if(validColumn&1) {
			if(c==1) {
				ans += (validColumn/2+1)*(validRow/2+(validRow&1));
				ans += (validColumn/2)*(validRow/2);
			}
			else {
				ans += (validColumn/2)*(validRow/2+(validRow&1));
				ans += (validColumn/2+1)*(validRow/2);
			}
		}
		else {
			ans = validRow*(validColumn/2);
		}

		cout << ans << '\n';
	}
}

int32_t main () {
	/* DO NOT USE IN UVA */
     /* ios_base::sync_with_stdio(0);cin.tie(0); */

     // #ifndef ONLINE_JUDGE
     // freopen("vs_input.txt", "r", stdin);
     // freopen("vs_output.txt", "w", stdout);
     // #endif

    int t=1 ; 
    /* cin >> t; */
    for(int i=1; i<=t; ++i){
        /* cout << "Case #" << i << ": "; */
        solve();
    }
}
