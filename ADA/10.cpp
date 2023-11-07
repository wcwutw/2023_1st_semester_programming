
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
const int M=15;
const int K=35;
const int N=1e5+5;
ll n, m, k, q;
ll dp[K][M]; //the sum of all n values under root with gf=i, started_dep=j-1
ll pre[N][M], a[N], c[K];
ll dep=0, totc=0;
void initdp() {
	for(int lv=k;lv>=0;lv--) {
		rep(i, m) {
			if(lv==k) dp[lv][i]=pre[n-1][i];
			else dp[lv][i]=dp[lv+1][i]+dp[lv+1][(i+c[lv])%m];
		}
	}
	/*rep(i, k+1) {
		rep(j, m) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/

}
ll query(ll nowlv, ll nowc, ll L, ll R, ll ql, ll qr) {
	//cout<<"query "<<L<<" "<<R<<" "<<nowlv<<" "<<nowc<<"\n";
	if(ql>R || qr<L) return 0;
	if(ql<=L && R<=qr) {
		//cout<<L<<" "<<R<<" "<<calc(nowlv, nowc)<<"\n";
		return dp[nowlv][nowc];
	}
	ll mid=(L+R)>>1;
	//nowc+=c[nowlv];
	//nowlv++;
	ll al=query(nowlv+1, nowc, L, mid, ql, qr);
	ll ar=query(nowlv+1, (nowc+c[nowlv])%m, mid+1, R, ql, qr);
	//cout<<L<<" "<<R<<" "<<al<<" "<<ar<<"\n"; 
	return al+ar;
}
void binary(ll L, ll R, ll id) {
	ll mid=(L+R)>>1;
	if(L==R && L==id) {
		return; 
	}
	if(id<=mid) {
		totc+=0;
		dep++;
		binary(L, mid, id);
	}
	else {
		totc+=c[dep];
		dep++;
		totc%=m;
		binary(mid+1, R, id);
	}
}
ll special(ll ql, ll ind) {
	dep=0;
	totc=0;
	binary(0, (1<<k)-1, ql);
	ll ret=pre[n-1][totc];
	if(ind>0) ret-=pre[ind-1][totc];
	return ret;
}
ll speciar(ll qr, ll ind) {
	dep=0;
	totc=0;
	binary(0, (1<<k)-1, qr);
	//cout<<"totc: "<<totc<<"\n";
	ll ret=pre[n-1][totc];
	//cout<<"ret: "<<ret<<"\n";
	if(ind<n-1) ret-=(pre[n-1][totc]-pre[ind][totc]);
	return ret;
}
ll inanode(ll id, ll lind, ll rind) {
	dep=0;
	totc=0;
	binary(0, (1<<k)-1, id);
	ll ret;
	if(lind==0) ret=pre[rind][totc];
	else ret=pre[rind][totc]-pre[lind-1][totc];
	return ret;
}

signed main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	IOS
	cin>>n>>m>>k;
	rep(i, n) {
		cin>>a[i];
		if(i==0) pre[i][0]=a[i];
		else pre[i][0]=pre[i-1][0]+a[i];
	}
	rep1(i, m-1) {
		rep(j, n) {
			if(j==0) pre[j][i]=(a[j]+i)%m;
			else pre[j][i]=pre[j-1][i]+(a[j]+i)%m;
		}
	}
	/*rep(i, m) {
		rep(j, n) cout<<pre[j][i]<<" ";
		cout<<"\n";
	}*/
	rep(i, k) cin>>c[i];
	initdp();
	cin>>q;
	rep(zz, q) {
		ll l, r;
		cin>>l>>r;
	   	ll ql=l/n, qr=r/n, rl=l%n, rr=r%n;
		ll ans=0;
		if(ql+1==qr) {
			ans+=special(ql, rl);
			ans+=speciar(qr, rr);
		}
		else if(ql==qr) {
			ans+=inanode(ql, rl, rr);
		}
		else { 
			ans+=query(0, 0, 0, (1<<k)-1, ql+1, qr-1);
			//cout<<ans<<"\n";
			ans+=special(ql, rl);
			//cout<<ans<<"\n";
			ans+=speciar(qr, rr);
			//cout<<ans<<"\n\n";
		}
		cout<<ans<<"\n";
	}
}
