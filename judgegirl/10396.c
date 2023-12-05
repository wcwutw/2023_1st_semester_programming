#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define N 25
int swap(int *x, int *y) {
	int tmp=*x;
	*x=*y;
	*y=tmp;
	return 0;
}
int max(int a, int b) {return a>b?a:b;}
int dfs(int x, int mx, int n, int m, int (*G)[N], bool *vis, int *res, int *ans, int *mn) {
	if(x==n+1) {
		for(int i=1;i<=n;i++) ((mx<*mn)&&(ans[i]=res[i]));
		(mx<*mn)&&(*mn=mx);
		return 0;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			int now=0;
			for(int j=1;j<=n;j++) {
				int vv=(res[j]>i)*(res[j]-i)+(res[j]<=i)*(i-res[j]);
				((G[x][j]==1)&&(now=now*(now>vv)+vv*(now<=vv)));
			}
			int ori=*mn;
			//if(now>=*mn) continue;
			(now<ori)&&(vis[i]=1);
			(now<ori)&&(res[x]=i);
			(now<ori)&&(dfs(x+1, max(mx, now), n, m, G, vis, res, ans, mn));
			(now<ori)&&(vis[i]=0);
		}
	}
	return 0;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int G[N][N];
	bool vis[N];
	int ans[N], res[N];
	memset(G, 0, sizeof(G));
	memset(ans, 0, sizeof(ans));
	memset(res, 0, sizeof(res));
	memset(vis, false, sizeof(vis));

	for(int i=0;i<m;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		(x<y)&&(swap(&x, &y));
		G[x][y]=1;
	}
	int mn=1005;
	dfs(1, 0, n, m, G, vis, res, ans, &mn);
	for(int i=1;i<=n;i++) printf("%d ", ans[i]);
}
