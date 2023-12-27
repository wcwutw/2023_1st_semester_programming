
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
ll dist[N], cnt[N], distt[N];
ll n, m, s, t;
vector<ll> G[N], R[N];
ll bit[N];
void upd(ll x, ll d) {
	for(;x<N;x+=x&-x) bit[x]+=d;
}
ll qry(ll x) {
	ll ret=0;
	for(;x;x-=x&-x) ret+=bit[x];
	return ret;
}
ll pare[N];
void dijk1(ll x) {
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	fill(pare, pare+N, -1);
	fill(dist, dist+N, INF);
  	pq.push({0, x}); dist[x]=0;
 	while(!pq.empty()) {
    	pll u=pq.top();
   		pq.pop();
    	if(dist[u.S]<u.F) continue;
      	for(auto i:G[u.S]) {
			if(dist[i]>dist[u.S]+1) {
				pare[i]=u.S;
				dist[i]=dist[u.S]+1;
				pq.push({dist[i], i});
        	}
      	}
	}
}
void dijk2(ll x) {
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	fill(pare, pare+N, -1);
	fill(dist, dist+N, INF);
  	pq.push({0, x}); dist[x]=0;
 	while(!pq.empty()) {
    	pll u=pq.top();
   		pq.pop();
    	if(dist[u.S]<u.F) continue;
      	for(auto i:R[u.S]) {
			if(dist[i]>dist[u.S]+1) {
				pare[i]=u.S;
				dist[i]=dist[u.S]+1;
				pq.push({dist[i], i});
        	}
      	}
	}
}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//IOS
	cin>>n>>m>>s>>t;
	set<pll> edge;
	rep(i, m) {
		ll x, y;
		cin>>x>>y;
		G[x].pb(y);
		R[y].pb(x);
	}
	dijk2(t);
	ll ans=n*n-m;
	rep(i, n+1) distt[i]=dist[i];
	//cout<<ans<<"\n";
	if(dist[s]==INF) {
		ans=n*n-m;
		ll tmp=0;
		rep1(i, n) {
			//if(i==s) continue;
			if(dist[i]!=INF) {
				tmp++;
			}
		}
		dijk1(s);
		rep1(i, n) {
			if(dist[i]!=INF) {
				ans-=tmp;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	rep(i, n+1) distt[i]=dist[i];
	dijk1(s);
	ll d=dist[t];
	memset(cnt, 0, sizeof(cnt));
	memset(bit, 0, sizeof(bit));
	rep(i, n+1) {
		if(distt[i]!=INF) {
			cnt[distt[i]]++;
		}
	}
	//cout<<ans<<"\n";
	//path P:s->t shortest path
	//case 1:P to P: dist a<=dist b-2
	//case 2:not in P to P:outside dist<=inside dist-2
	/*rep(i, n+1) {
		if(cnt[i]!=0) cout<<i<<" "<<cnt[i]<<"\n";
	}*/
	for(int i=0;i<=n;i++) {
		upd(i+1, cnt[i]);
		//if(i>1) ans-=cnt[i]*qry(i-1);
		//if(cnt[i]!=0) cout<<ans<<"\n";
	}
	for(int i=1;i<=n;i++) {
		if(dist[i]==INF) continue;
		int now=d-1-dist[i];
		if(now>0) ans-=qry(now);
	}
	cout<<ans;
}
