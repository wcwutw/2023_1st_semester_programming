
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
const int N=2e5+5;
vector<ll> G[N], R[N];
ll n, m, times[N], sum[N];
ll cnt=1, sz=0;
bool vis[N];
void dfs(ll x) {
	vis[x]=1;
	for(auto u:G[x]) {
		if(vis[u]) continue;
		dfs(u);
	}
	times[cnt++]=x;
}

void revdfs(ll x) {
	sz++;
	vis[x]=1;
	for(auto u:R[x]) {
		if(vis[u]) continue;
		revdfs(u);
	}
	
}

signed main() {
	IOS
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt" ,"w", stdout);
	#endif
	sum[1]=0;
	sum[2]=1;
	sum[3]=3;
	for(int i=4;i<N;i++) sum[i]=sum[i-1]+i-1;
	cin>>n>>m;
	rep(i, m) {
		int x, y;
		cin>>x>>y;
		G[x].pb(y);
		R[y].pb(x);
	}
	memset(vis, false, sizeof(vis));
	rep1(i, n) {
		if(!vis[i]) dfs(i);
	}
	memset(vis, false, sizeof(vis));
	ll ans=0;
	for(int i=cnt-1;i>=1;i--) {
		if(!vis[times[i]]) {
			revdfs(times[i]); ans+=sum[sz]; sz=0;
		}
	}
	cout<<ans<<"\n";
}
