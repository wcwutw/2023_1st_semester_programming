
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
class Compare {
	public:
		bool operator()(pair<ll, vector<ll> > &x, pair<ll, vector<ll> > &y) {
			if(x.F!=y.F) return x.F>y.F;
			else return (int)x.S.size()>(int)y.S.size();
		}
};
void solve() {
	ll n;
	cin>>n;
	vector<pair<ll, vector<ll> > > f(n);
	vector<string> ans(n);
	priority_queue<pair<ll, vector<ll> >, vector<pair<ll, vector<ll> > >, Compare> pq;
	rep(i, n) {
		vector<ll> tmp;
		cin>>f[i].F;
		tmp.pb(i);
		f[i].S=tmp;
		pq.push(f[i]);
	}
	if(n==1) {
		cout<<"0\n";
		return;
	}
	while((int)pq.size()!=1) {
		auto u=pq.top();
		pq.pop();
		auto v=pq.top();
		pq.pop();
		vector<ll> tmp;
		for(int i:u.S) {
			ans[i]+="1";
			tmp.pb(i);
		}
		for(int i:v.S) {
			ans[i]+="0";
			tmp.pb(i);
		}
		pq.push({u.F+v.F, tmp});
	}
	rep(i, n) {
		reverse(All(ans[i]));
		cout<<ans[i]<<"\n";
	}


}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int T=1;
    //cin>>T;
    while(T--) solve();
}
