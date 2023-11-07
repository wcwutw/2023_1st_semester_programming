
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
const ll INF=8e18;
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
//#define pb push_back
#define eb emplace_back
//#define mp make_pair
#define uni(c) c.resize(distance(c.begin(), unique(c.begin(), c.end())))
#define unisort(c) sort(c.begin(), c.end());uni(c)
ll ABS(ll x, ll y) {
	return max(x-y, y-x);
}
struct point{
	ll x, y;
};
point add[200003];
ll n, ans=INF;
vector<point> graph;
vector<ll> a;
ll dist(point pa, point pb) {
	ll dif=ABS(pa.x, pb.x);
	return (dif)*(dif)+(pa.y-pb.y)*(pa.y-pb.y);
}
bool cmpx(point pa, point pb) {
	return pa.x<pb.x;
}
bool cmpy(point pa, point pb) {
	return pa.y<pb.y;
}
void calc(ll L, ll R) {
	if(R-L<=3) {
		for(ll i=L;i<=R;i++) {
			for(int j=i+1;j<=R;j++) ans=min(ans, dist(graph[i], graph[j]));
		}
		return;
	}
	ll mid=(L+R)>>1;
	point mp=graph[mid];
	calc(L, mid);
	calc(mid+1, R);
	ll id=0;
	/*rep1(i, n) {
		if(ABS(mp.x, graph[i].x)<ans) {
			add[id]=graph[i];
			id++;
		}
		//add[id]=graph[i];
		//id++;
	}*/
	for(int i=mid;i>=L;i--) {
		if(ABS(add[mid].x, add[i].x)>=ans) break;
		add[id]=graph[i];
		id++;
	}
	for(int i=mid+1;i<=R;i++) {
		if(ABS(add[i].x, add[mid].x)>=ans) break;
		add[id]=graph[i];
		id++;
	}
	sort(add, add+id, cmpy);
	/*for(int i=L;i<=R;i++) {
		if(ABS(graph[i].x, graph[mid].x)+1>ans) continue;
		for(ll j=0;j<=id-1;j++) {
			ans=min(ans, dist(graph[i], add[j]));
		}
	}*/
	rep(i, id) {
		for(ll j=i+1;j<=min(i+7, id-1);j++) {
			ans=min(ans, dist(add[j], add[i]));
		}
	}
	//cout<<L<<" "<<R<<" "<<mn<<"\n";
	return;
}
signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	IOS
	cin>>n;
	//ll ans=INF;
	a.resize(n+1);
	graph.resize(n+1);
	vector<ll> pre(n+2, 0);
	rep1(i, n) {
		cin>>a[i];
		ans=min(ans, a[i]*a[i]+1);
		pre[i]=pre[i-1]+a[i];
	}
	graph[0].x=graph[0].y=0;
	rep1(i, n) {
		graph[i].x=i;
		graph[i].y=pre[i];
		//cout<<graph[i].x<<" "<<graph[i].y<<"\n";
	}
	calc(0, n);
//	rep1(i, n) ans=min(ans, a[i]*a[i]+1);
	//cout<<calc(0, n)<<"\n";
	cout<<ans<<"\n";
}
