
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
ll dp[3][10000005], mx[3][10000005]; //dp:
ll mxs[3][10000005], spe[3][10000005]; //mxs: last isn'tspe: can't be transformed by diagonosal
ll dist0, dist1, dist2;
void solve() {
	ll n, k;
	cin>>n>>k;
	dist0=sqrtl(k-1)+1;
	dist1=(ll)sqrtl(k-1-1)+1;
	dist2=(ll)sqrtl(k-4-1)+1;
	rep(i, 3) {
		string s;
		cin>>s;
		rep(j, n) {
			if(s[j]=='#') spe[i][j]=dp[i][j]=-INF;
			else spe[i][j]=dp[i][j]=1;
			mxs[i][j]=mx[i][j]=-INF;
		}
	}
	ll ret=0;
	//assert(k!=5);
	if(k==5) {
		if(n<=2) {
			ret=max(ret, max(dp[0][0], max(dp[1][0], dp[2][0])));
			if(n==2) {
				ret=max(ret, max(dp[0][0]+dp[2][1], dp[2][0]+dp[0][1]));
				ret=max(ret, max(dp[0][1], max(dp[1][1], dp[2][1])));
			}
			cout<<ret<<"\n";
			return;
		}
		for(ll j=0;j<n;j++) {
			rep(i, 3) {
				int dif=1;
				if(dp[i][j]==-INF) {
					dif=0;
					//continue;
				}
				if(j>=3) {
					dp[i][j]=max(dp[i][j], mx[i][j-3]+dif);
					spe[i][j]=max(spe[i][j], mx[i][j-3]+dif);
				}
				if(i==0) {
					if(j>=2) {
						dp[i][j]=max(dp[i][j], mx[i+1][j-2]+dif);
						spe[i][j]=max(spe[i][j], mx[i+1][j-2]+dif);
						spe[i][j]=max(spe[i][j], mx[i+2][j-2]+dif);
					}
					if(j>=1) dp[i][j]=max(dp[i][j], mxs[i+2][j-1]+dif);
				}
				else if(i==1) {
					if(j>=2) {
						dp[i][j]=max(dp[i][j], max(mx[i+1][j-2]+dif, mx[i-1][j-2]+dif));
						spe[i][j]=max(spe[i][j], max(mx[i+1][j-2]+dif, mx[i-1][j-2]+dif));
					}
				}
				else {
					if(j>=2) {
						dp[i][j]=max(dp[i][j], mx[i-1][j-2]+dif);
						spe[i][j]=max(spe[i][j], mx[i-1][j-2]+dif);
						spe[i][j]=max(spe[i][j], mx[i-2][j-2]+dif);
					}
					if(j>=1) dp[i][j]=max(dp[i][j], mxs[i-2][j-1]+dif);
				}
				if(j) mx[i][j]=max(mx[i][j-1], dp[i][j]);
				else mx[i][j]=dp[i][j];
				if(j) mxs[i][j]=max(mx[i][j-1], spe[i][j]);
				else mxs[i][j]=spe[i][j];
				dp[i][j]=max(dp[i][j], spe[i][j]);
				if(dif==1) ret=max(ret, dp[i][j]);
				//cout<<dp[i][j]<<" ";
			}
			//cout<<"\n";
		}
		//cout<<ret<<"\n";
	}
	else {
		rep(j, n) {
			rep(i, 3) {
				int dif=1;
				if(dp[i][j]==-INF) {
					dif=0;
				}
				/*if(j>=dist0) {
					dp[i][j]=max(dp[i][j], mx[i][j-dist0]+dif);
				}*/
				if(i==0) {
					if(j-dist1>=0) dp[i][j]=max(dp[i][j], mx[i+1][j-dist1]+dif);
					if(j-dist2>=0) dp[i][j]=max(dp[i][j], mx[i+2][j-dist2]+dif);
				}
				else if(i==1) {
					if(j-dist1>=0) dp[i][j]=max(dp[i][j], max(mx[i+1][j-dist1]+dif, mx[i-1][j-dist1]+dif));
				}
				else {
					if(j-dist1>=0) dp[i][j]=max(dp[i][j], mx[i-1][j-dist1]+dif);
					if(j-dist2>=0) dp[i][j]=max(dp[i][j], mx[i-2][j-dist2]+dif);
				}
				/*if(j<dist0) {}
				else dp[i][j]=min(dp[i][j], ans[i][j-dist0]+1);
				ans[i][j]=max(ans[j], dp[i][j]);*/
				if(j) mx[i][j]=max(mx[i][j-1], dp[i][j]);
				else mx[i][j]=dp[i][j];
				if(dif==1) ret=max(ret, dp[i][j]);
				//cout<<dp[i][j]<<" ";
			}
			//cout<<"\n";
		}
	}
	cout<<ret<<"\n";
	
}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    IOS
	int T=1;
    while(T--) solve();
}
