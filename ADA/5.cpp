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
const int N=1000005;
int p[N];
void init(int n) {
    for(int i=1;i<=n;i++) {
        p[i]=i;
    }
}
int Find(int x) {
    return x==p[x]?x:p[x]=Find(p[x]);
}
void Union(int x, int y) {
    x=Find(x), y=Find(y);
    if(x==y) return;
    p[x]=y;
}

vector< pair<ll, pair<ll, ll> > > e;
ll n, m;
ll kruskal() {
    sort(e.begin(), e.end());
    init(n);
    ll ans=0, cnt=0;
    rep(i, e.size()) {
        ll a=Find(e[i].S.F), b=Find(e[i].S.S);
        if(a==b) continue;
        else {
            ans+=e[i].F;
			//cout<<e[i].S.F<<" "<<e[i].S.S<<" "<<ans<<"\n";
            cnt++;
            Union(a, b);
        }
        if(cnt==n-1) break;
	}
	return ans;
}
signed main() {
    IOS
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt" ,"w", stdout);
	#endif
    cin>>n>>m;
    rep(i, m) {
        ll a, b, c;
        cin>>a>>b>>c;
        e.pb({c, {a, b}});
    }
    cout<<kruskal();
}

