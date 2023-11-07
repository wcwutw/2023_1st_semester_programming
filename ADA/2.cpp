
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
const int N=3005;
int dp[N][N];
// a[i]=b[j], dp[i][j]=dp[i-1][j-1]
// a[i]!=b[j], dp[i][j]=dp[i-1][j-1]+1
// dp[i][j]=dp[i-1][j]+2 or dp[i][j-1]+2
signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string a, b;
	cin>>a>>b;
	memset(dp, 0, sizeof(dp));
	int n=a.size(), m=b.size();
	rep(i, n+1) dp[i][0]=i;
	rep(j, m+1) dp[0][j]=j;
	rep1(i, n) {
		rep1(j, m) {
			dp[i][j]=min(dp[i-1][j]+1, dp[i][j-1]+1);
			if(a[i-1]==b[j-1]) dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
			else dp[i][j]=min(dp[i][j], dp[i-1][j-1]+1);
		}
	}
	/*rep1(i, n) {
		rep1(j, m) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	cout<<dp[n][m]<<"\n";
}
