
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
const int N=55;
//#define ll unsigned long long
ll C[N][N], A[N];
ll n, k;
void init(int nn) {
	C[nn][0]=1;
	rep1(i, nn) {
		C[nn][i]=C[nn][i-1]*(nn+1-i)/i;
		//cout<<C[i]<<" ";
		//C[i]=(C[i]-i/2)/2+i/2;
	}
	//cout<<"\n";
}

signed main() {
	/*#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/
	IOS
	memset(C, 0, sizeof(C));
	cin>>n>>k;
	rep1(i, 50) init(i);
	rep(i, n+1) {
		if(n%2==0 && i%2==1) A[i]=C[n][i]/2;
		else A[i]=(C[n][i]-C[n/2][i/2]+1)/2+C[n/2][i/2];
		//cout<<A[i]<<"\n";
	}
	ll ans=0;
	rep(i, k/2+1) {
		if(i>k-i) break;
		if(i>n || k-i>n) continue;
		ll now;
		now=(A[i]+A[k-i]);
		//cout<<i<<" "<<now<<"\n";
		ans+=now;
	}
	cout<<ans<<"\n";

}
