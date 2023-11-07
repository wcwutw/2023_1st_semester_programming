
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
const int N=5005;
ll dp[N][N];
ll dist(pll x, pll y) {
	return (x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S);
}
void solve() {
	ll n;
	cin>>n;
	rep(i, n+2) rep(j, n+2) dp[i][j]=INF;
	vector<pll> a(n+1, {0, 0});
	rep1(i, n) cin>>a[i].F>>a[i].S;
	dp[0][1]=dp[1][0]=dist(a[0], a[1]);
	for(int now=2;now<=n;now++) {
		for(int i=0;i<now-1;i++) {
			dp[now][i]=dp[now-1][i]+dist(a[now-1], a[now]); //move first USB, last is first USB
		}
		for(int i=0;i<now-1;i++) {
			dp[now][now-1]=min(dp[now][now-1], dp[i][now-1]+dist(a[i], a[now]));// move first USB, last is second USB
		}
		for(int i=0;i<now-1;i++) {
			dp[i][now]=dp[i][now-1]+dist(a[now-1], a[now]); //move second USB, last is second USB
		}
		for(int i=0;i<now-1;i++) {
			dp[now-1][now]=min(dp[now-1][now], dp[now-1][i]+dist(a[i], a[now]));// move second USB, last is first USB
		}
	}
	/*rep(i, n+1) {
		rep(j, n+1) {
			if(i==j) cout<<"X ";
			else cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	ll ans=INF;
	for(int now=0;now<=n-1;now++) {
		ans=min(ans, dp[now][n]+dist(a[now], a[0])+dist(a[n], a[0]));
		ans=min(ans, dp[n][now]+dist(a[now], a[0])+dist(a[n], a[0]));
	}
	cout<<ans<<"\n";
}
signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	IOS
    int T=1;
    cin>>T;
    while(T--) solve();
}
