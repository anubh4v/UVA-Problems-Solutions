#include <bits/stdc++.h>
/* #define int long long int */
typedef long long int ll;
using namespace std;
const int M = 1e9+7;

/**********************************************************/
ll power(ll a, ll b, ll m) {
	ll ans = 1;
	while(b>0) {
		ans*=a;
		b--;
	}
	return ans;
}
/**********************************************************/

string mult(char c, string &s1, int j) {
	string ans(j, '0');
	/* cout << ans << '\n'; */
	int n = s1.size(), carry = 0;
	for(int i=n-1; i>=0; --i) {
		int prod = (s1[i]-48)*(c-48)+carry;
		carry = prod/10;
		ans.push_back(prod%10+48);
	}
	ans.push_back(carry+48);
	return ans;
}

string add(string &temp, string &s3) {
	int m = temp.size(), n = s3.size(), carry = 0;
	string ans;
	for(int i=0; i<n; ++i) {
		if(i<m) {
			int sum = (s3[i]-48)+(temp[i]-48)+carry;
			carry = sum/10;
			ans.push_back(sum%10+48);
		}
		else
			ans.push_back(s3[i]-48);
	}
	ans.push_back(carry+48);
	return ans;
}

void solve() {
	string s1, s2;
	while(cin >> s1) {
		/* cin >> s1; */
		cin >> s2;
		string temp(s1.size()+1, '0');
		int n = s2.size();
		for(int i=n-1,j=0; i-j>=0; ++j) {
			string s3 = mult(s2[i-j], s1, j);
			/* cout <<i << ' '<< s3 << '\n'; */
			temp = add(temp, s3);
		}
		while(temp.back()=='0')
			temp.pop_back();
		if(temp.empty())
			temp.push_back('0');
		reverse(temp.begin(), temp.end());
		cout << temp << '\n';
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
