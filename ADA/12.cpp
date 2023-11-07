
#include <bits/stdc++.h>
//#include<random>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("O3")
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
//0 5 -3 -11 -12 -19 -10 -14 -4 -7 
void solve() {
	ll n;
	cin>>n;
	vector<ll> a(n), suf(n+1, 0), art(n, 0);
	vector<pll> b(n);
	rep(i, n) cin>>a[i];
	for(int i=n-1;i>=0;i--) {
		suf[i]=suf[i+1]+a[i];
		//if(i!=n-1) {
			b[i].F=suf[i];
			b[i].S=i;
		//}
	}
	sort(All(b));
	/*for(pll p:b) {
		cout<<p.F<<" "<<p.S<<"\n";
	}*/
	for(int i=0;i<n/2;i++) {
		art[b[i].S]=-1;
	}
	for(int i=n-1;i>n-1-n/2;i--) {
		art[b[i].S]=1;
	}
	ll ans=0;
	rep(i, n) {
		ans+=(suf[i]*art[i]);
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
