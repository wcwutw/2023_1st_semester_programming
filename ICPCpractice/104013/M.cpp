
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

}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	vector<ll> a(n);
	rep(i, n) cin>>a[i];
	sort(All(a));
	ll bd=a[0], sd=a[1]-1;
	rep(i, n-1) {
		bd=max(bd, a[i+1]-a[i]);
	}
	rep(i, n-2) {
		sd=min(sd, a[i+2]-a[i]-1);
	}
	if(sd<bd) {
		cout<<"0\n";
	}
	else {
		cout<<bd<<"\n";
	}
	/*ll st=0, id=0;
	rep(i, n) {
		ll now=st+d;
		ll cnt=0;
		for(int j=i;j<n;j++) {
			if(a[j]<=now) cnt++;
			if(cnt>=2) {
				cout<<"0\n";
				return 0;
			}
		}
		st=a[i];
	}
	cout<<d<<"\n";*/
	/*while(id<n) {
		ll now=st+d;
		ll cnt=0;
		while(id<n && now>=a[id]) {
			id++;
			cnt++;
			//cout<<now<<" "<<id<<"\n";
		}
		if(id<n) st=a[id-1];
		//cout<<st<<"\n";
		if(cnt>1) {
			cout<<"0\n";
			return 0;
		}
	}
	cout<<d<<"\n";*/
}
