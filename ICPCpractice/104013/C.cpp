
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
	int n;cin >> n;
	int idx,r,l;
	int fin=n+1;
	int cnt=0;
	string s;
	for(int t = 0;t<10000;t++){
			for(int i=n;i>=fin;i--){
				cout << i-1 << ' ' << i << endl;
				cin >> s;cnt++;
				if(s == "WIN") return 0;
				if(s == "SWAPPED") {r = i;break;}
		}
		if(r!=-1){
			for(int i=2;i<fin;i++){
				cout << i-1 << ' ' << i << endl;
				cin >> s;cnt++;
				if(s == "WIN") return 0;
			}
			if(r!=fin){
                cout << fin-1 << ' ' << r-1 << endl;
				cin >> s;cnt++;
				if(s == "WIN") return 0;
				if(s == "SWAPPED"){
    				cout << r-1 << ' ' << r << endl;cnt++;
					break;
				}
			 	else{
					for(int i=fin;i<r-1;i++){
						cout << i << ' ' << i+1 << endl;
						cin >> s;cnt++;
						if(s=="WIN") return 0;
						if(s=="SWAPPED"){l=i;break;}
					}

				if(l==r-2) {
					cout << r-1 << ' ' << r << endl;
					cin >> s;cnt++;
				}
				else{
					cout << l+1 << ' ' << r-1 << endl;
					cin >> s;cnt++;
					cout << r-1 << ' ' << r << endl;
					cin >> s;cnt++;
					cout << l << ' ' << l+1
				}
				}
			}
		}
			
	}
    
}
