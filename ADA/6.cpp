
#include <bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

struct trio{
	int a, b, c;
};
signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	vector<int> ans(n+1, 0);
	vector<trio> v(m);
	for(int i=0;i<m;i++) {
		cin>>v[i].a>>v[i].b>>v[i].c;
		//v[i].a--;
		//v[i].b--;
		//v[i].c--;
	}
	for(int i=1;i<=n;i++) {
		ans[i]=rng()%2;
		if(ans[i]==0) ans[i]=-1;
		//if(x) cout<<"1 ";
		//else cout<<"-1 ";
	}
	for(int i=0;i<m;i++) {
		if((ans[abs(v[i].a)]*v[i].a<0) && (ans[abs(v[i].b)]*v[i].b<0) && (ans[abs(v[i].c)]*v[i].c<0)) {
			int x=rng()%3;
			if(x==0) ans[abs(v[i].a)]=-ans[abs(v[i].a)];
			else if(x==1) ans[abs(v[i].b)]=-ans[abs(v[i].b)];
			else ans[abs(v[i].c)]=-ans[abs(v[i].c)];
		}
	}
	for(int i=0;i<m;i++) {
		if((ans[abs(v[i].a)]*v[i].a<0) && (ans[abs(v[i].b)]*v[i].b<0) && (ans[abs(v[i].c)]*v[i].c<0)) {
			int x=rng()%3;
			if(x==0) ans[abs(v[i].a)]=-ans[abs(v[i].a)];
			else if(x==1) ans[abs(v[i].b)]=-ans[abs(v[i].b)];
			else ans[abs(v[i].c)]=-ans[abs(v[i].c)];
		}
	}
	for(int i=0;i<m;i++) {
		if((ans[abs(v[i].a)]*v[i].a<0) && (ans[abs(v[i].b)]*v[i].b<0) && (ans[abs(v[i].c)]*v[i].c<0)) {
			int x=rng()%3;
			if(x==0) ans[abs(v[i].a)]=-ans[abs(v[i].a)];
			else if(x==1) ans[abs(v[i].b)]=-ans[abs(v[i].b)];
			else ans[abs(v[i].c)]=-ans[abs(v[i].c)];
		}
	}
	rep1(i, n) {
		cout<<ans[i]<<" ";
	}
}
