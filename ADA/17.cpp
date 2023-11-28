
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
const ll INF=5e18;
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
const int N=3e5+5;
vector<pll> G[N];
vector<ll> tree[N];
ll dist[N], pare[N], dep[N];
ll fa[N][25];
ll n, m;
vector<ll> wei;
vector<pll> edge;

void dfs(int x, int p, int d){
    dep[x]=d;
    //par[x]=p;
    fa[x][0]=p;
    for(int i:tree[x]){
        if(i==p) continue;
        dfs(i, x, d+1);
    }
}
ll lca(ll u, ll v) {
    if(dep[u]>dep[v]) swap(u, v);
    rep(i, 25) {
        if((dep[v]-dep[u])>>i &1) v=fa[v][i];
    }
    if(u==v) return u;
    for(int i=24;i>=0;i--) {
        if(fa[u][i]!=fa[v][i]) {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

void dijk(ll st) {
	priority_queue<pll, vector<pll>, greater<pll> > pq;
 	fill(pare, pare+N, 0);
	fill(dist, dist+N, INF);
	fill(dep, dep+N, 0);
  	pq.push({0, st}); dist[st]=0;
 	while(!pq.empty()) {
    	pll u=pq.top();
   		pq.pop();
    	if(dist[u.S]<u.F) continue;
      	for(auto i:G[u.S]) {
			if(dist[i.F]>dist[u.S]+i.S) {
          		dist[i.F]=dist[u.S]+i.S;
				pare[i.F]=u.S;
				pq.push({dist[i.F], i.F});
        	}
      	}
	}
}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	IOS
	cin>>n>>m;
	rep(i, m) {
		ll x, y, w;
		cin>>x>>y>>w;
		if(x>y) swap(x, y);
		wei.pb(w);
		edge.pb({x, y});
		G[x].pb({y, w});
		G[y].pb({x, w});
	}
	ll ans=INF;
	dijk(1);
	set<pll> sel_edge;
	vector<pll> sele;
	for(ll i=2;i<=n;i++) {
		pll e;
		e.F=min(i, pare[i]);
		e.S=max(i, pare[i]);
		sele.pb(e);
		tree[e.F].pb(e.S);
		tree[e.S].pb(e.F);
		//cout<<e.F<<" "<<e.S<<"\n";
		sel_edge.insert(e);
	}
	rep(i, n-1) {
		pare[sele[i].S]=sele[i].F;
	}
	dfs(1, 0, 1);
	rep1(i, 24) {
		rep1(j, n) {
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	for(ll i=0;i<m;i++) {
		if(sel_edge.find(edge[i])==sel_edge.end() && lca(edge[i].F, edge[i].S)==1) {
			ans=min(ans, dist[edge[i].F]+dist[edge[i].S]+wei[i]);
			//cout<<dist[edge[i].F]<<" "<<dist[edge[i].S]<<" "<<wei[i]<<"\n";
		}
	}
	cout<<ans<<"\n";
}
