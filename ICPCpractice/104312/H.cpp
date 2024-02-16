#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++) 
int n, m;
 
int getx(int x){
    if(x >= n) return x - n;
    if(x < 0) return x + n;
    return x;
}
int gety(int y){
    if(y >= m) return y - m;
    if(y < 0) return y + m;
    return y;
}
 
signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    int dx[9]{-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[9]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        if(s == "Blur"){
            vector<vector<int>> newv(n, vector<int>(m, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    for(int k = 0; k < 9; k++){
                        newv[i][j] += v[getx(i + dx[k])][gety(j + dy[k])];
                    }
                }
            }
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) newv[i][j] /= 9;
        	rep(i, n) rep(j, m) v[i][j]=newv[i][j];
		} else if(s == "Shift"){
            int x, y; cin >> x >> y;
            y = -y;
            swap(x, y);
            vector<vector<int>> newv = v;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    newv[getx(i + x)][gety(j + y)] = v[i][j];
                }
            }
        	rep(i, n) rep(j, m) v[i][j]=newv[i][j];
		} else if(s == "Sharpen"){
            //vector<vector<int>> newv = v;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    bool mx = 1, mn = 1;
                    for(int k = 0; k < 9; k++){
                        mx &= (v[i][j] >= v[getx(i + dx[k])][gety(j + dy[k])]);
                        mn &= (v[i][j] <= v[getx(i + dx[k])][gety(j + dy[k])]);
                    }
                    if(mx) v[i][j] += 100;
                    if(mn) v[i][j] -= 100;
                }
            }
        } 
		else if(s == "Rotate"){
			string ss;
			cin>>ss;
			if(ss=="CW") {
				vector<vector<int>> newv(m, vector<int>(n));
        	    for(int i = 0; i < n; i++){
            	    for(int j = 0; j < m; j++){
                	    newv[j][n - i - 1] = v[i][j];
                	}
            	}
            	v.resize(m, vector<int>(n));
            	swap(n, m);
            	rep(i, n) rep(j, m) v[i][j]=newv[i][j];
			}
			else {
				vector<vector<int>> newv(m, vector<int>(n));
				for(int i=0;i<n;i++) {
					for(int j=0;j<m;j++) {
						newv[m-j-1][i]=v[i][j];
					}
				}
				v.resize(m, vector<int>(n));
				swap(n, m);
				rep(i, n) rep(j, m) v[i][j]=newv[i][j];
			}
        } 
        else if(s == "Flip"){
			string ss;
			cin>>ss;
			if(ss=="Horizontal") {
            	vector<vector<int>> newv = v;
            	for(int i = 0; i < n; i++){
                	for(int j = 0; j < m; j++){
                    	newv[i][m - j - 1] = v[i][j];
                	}
            	}
            	rep(i, n) rep(j, m) v[i][j]=newv[i][j];
			}
			}
         	else{
            	vector<vector<int>> newv = v;
            	for(int i = 0; i < n; i++){
                	for(int j = 0; j < m; j++){
                    	newv[n - i - 1][j] = v[i][j];
               		}
            	}
				rep(i, n) rep(j, m) v[i][j]=newv[i][j];
			}
		}
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        } cout << '\n';
    }
}
