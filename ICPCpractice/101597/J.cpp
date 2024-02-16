
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
	ll n;
	cin>>n;
	vector<pll> cor(n);
	ll mxx=-INF, mnx=INF, mxy=0;
	rep(i, n) {
		cin>>cor[i].F>>cor[i].S;
		mxx=max(mxx, cor[i].F);
		mnx=min(mnx, cor[i].F);
		mxy=max(mxy, cor[i].S);
	}
	sort(All(cor));
	ll circumference=(2*mxy+4+(mxx-mnx+3));
	cout<<circumference<<" "<<circumference-2<<" ";
	ll ans=(mxy+1)*(mxx-mnx+1);
	ll nextid=1;
	reverse(All(cor));
	cor.pb({INF, INF});
	reverse(All(cor));
	cor.pb({INF, INF});
	for(int i=1;i<=n && cor[i].S!=mxy;) {
		ll nowid=i;
		while(cor[nowid].F==cor[i].F) nowid++;
		nowid--;
		nextid=nowid;
		while(cor[nextid].S<=cor[nowid].S) nextid++;
		ans-=(max(cor[i].F-cor[nextid].F, cor[nextid].F-cor[i].F)*(mxy-cor[nowid].S));
		i=nextid;
	}
	for(int i=n;i>0 && cor[i].S!=mxy;) {
		nextid=i;
		while(cor[nextid].S<=cor[i].S) nextid--;
		ans-=((max(cor[i].F-cor[nextid].F, cor[nextid].F-cor[i].F))*(mxy-cor[i].S));
		i=nextid;
	}
	cout<<ans<<"\n";
}

signed main() {
	IOS
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int T=1;
    //cin>>T;
    while(T--) solve();
}
