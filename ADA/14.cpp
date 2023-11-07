
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
struct dat{
	ll cap, sz, id;
};

bool cmp(dat x, dat y) {
	if(x.cap!=y.cap) return x.cap<y.cap;
	if(x.sz!=y.sz) return x.sz<y.sz;
	return x.id<y.id;
}

bool cmp2(dat x, dat y) {
	if(x.sz!=y.sz) return x.sz<y.sz;
	if(x.cap!=y.cap) return x.cap<y.cap;
	return x.id<y.id;
}

void solve() {
	ll n, k;
	cin>>n>>k;
	vector<dat> a(n);
	vector<ll> ans(n, -2);
	rep(i, n) cin>>a[i].cap;
	rep(i, n) {cin>>a[i].sz; a[i].id=i; }
	sort(All(a), cmp);
	ll gid=0;
	rep(i, n) {
		if(a[i].id==k-1) {
			gid=i;
			ans[i]=0;
			break;
		}
	}
	rep(i, gid) {
		if(a[i].cap<a[gid].sz) ans[i]=-1;
	}
	priority_queue<pair<pll, ll>, vector<pair<pll, ll> >, greater<pair<pll, ll> > > pq;
	deque<ll> nxtcap, tmp;
	ll dep=0;
	ll thresh=0;
	/*rep(i, n) {
		cout<<a[i].cap<<" "<<a[i].sz<<" "<<a[i].id<<"\n";
	}
	cout<<"\n";*/
	rep(i, n) {
		if(a[i].sz==0) {
			nxtcap.pb(i);
			//cout<<i<<" ";
			//thresh=max(thresh, a[i].cap);
		}
		else pq.push({{a[i].sz, a[i].cap}, i});
	}
	//cout<<"\n";
	while(!nxtcap.empty()) {
		ll nid=nxtcap.front();
		nxtcap.pop_front();
		thresh=max(thresh, a[nid].cap);
		//cout<<"thresh: "<<thresh<<"\n";
		if(ans[nid]==-2) ans[nid]=dep+1;
		while(!pq.empty()) {
			auto p=pq.top();
			if(p.F.F<=thresh) {
				pq.pop();
				//cout<<"p.S: "<<p.S<<"\n";
				tmp.pb(p.S);		
			}
			else break;
		}
		//cout<<nxtcap.size()<<"\n";
		if(nxtcap.empty()) {
			thresh=0;
			dep++;
			nxtcap=tmp;
			tmp.clear();
		}
	}
	vector<ll> rans(n);
	rep(i, n) {
		rans[a[i].id]=ans[i];
		if(ans[i]==-2) rans[a[i].id]=-1;
	}
	rep(i, n) cout<<rans[i]<<" ";
	cout<<"\n";
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
