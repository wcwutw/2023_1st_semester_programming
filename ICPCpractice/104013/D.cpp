
#include <bits/stdc++.h>
//#include<random>
using namespace std;
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("O3")*/
/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")//for codeforces*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef map<ll, ll> mll;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int iINF=INT_MAX;
const ll INF=4e18;
const ld PI=3.14159265358979323846;
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll fpow(ll a,ll b,ll m) {
    if(!b) return 1;
    ll ans=fpow(a*a%m,b/2,m);
    return (b%2?ans*a%m:ans);
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define dbg(n) cerr<<#n<<": "<<n<<"\n";
#define optline cout<<"\n";
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define irep(i,m,n) for(ll i=m;i>=n;i--)
#define F first
#define S second
#define All(c) c.begin(), c.end()
#define pb push_back
#define eb emplace_back
//#define mp make_pair
#define uni(c) c.resize(distance(c.begin(), unique(c.begin(), c.end())))
#define unisort(c) sort(c.begin(), c.end());uni(c)

void solve() {

}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, w, h, s; cin >> n >> w >> h >> s;
	char c[n][h][w], ch[n];
	for(int i = 0; i < n; i++){
		cin >> ch[i];
		for(int j = 0; j < h; j++){
			for(int k = 0; k < w; k++){
				cin >> c[i][j][k];
			}
		}
	}
	string res = "";
	for(int i = 0; i < h; i++){
		int idx = -1, best = 0, add = 0;
		for(int j = 0; j < n; j++){
			char x = '.';
			int cnt = 0;
			for(int k = 0; k < w; k++){
				if(x != c[j][i][k]) cnt++, x = c[j][i][k];
			}
			if(c[j][i][w - 1] == '#'){
				if(cnt + 1 > best) best = cnt + 1, add = 1, idx = j;
			}
			//if(cnt + lst > best) best = cnt + lst, add = lst, idx = j;
			if(c[j][i][w - 1] == '.'){
				if(cnt >= best) best = cnt, add = 0, idx = j;
			}
		}
		if(best == 0) continue;
		int len = s / best + ((s % best) > 0);
		if((s % best == 0) && add>0) len++;
		if(res == "" || len < (int)res.size()){
			res = "";
			for(int j = 0; j < len; j++) res += ch[idx];
		}
	}
	cout << res;
}

