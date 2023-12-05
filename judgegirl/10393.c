#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void dfs(int now, int id, bool *rem, int *mx, int n, int m, int (*edge)[2], bool *vis, bool *ans, int (*G)[70]) {
	if(id==m || now+m-id<=*mx) {
		for(int i=0;i<m;i++) (now>*mx)&&(ans[i]=rem[i]);
		(now>*mx)&&(*mx=now);
		return;
	}
	int x=edge[id][0], y=edge[id][1];
	bool flag=0;
	for(int i=0;i<n;i++) {
		//if(G[x][i] && G[y][i]) { //the edge can't be added
			flag=(G[x][i]&&G[y][i]);
			i=i+n*(G[x][i]&&G[y][i]);
		//}
	}
	if(!flag) {
		G[x][y]=G[y][x]=1;
		rem[id]=1;
		dfs(now+1, id+1, rem, mx, n, m, edge, vis, ans, G);
		G[x][y]=G[y][x]=0;
		rem[id]=0;
	}
	dfs(now, id+1, rem, mx, n, m, edge, vis, ans, G);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int edge[m][2];
	int G[70][70];
	memset(G, 0, sizeof(G));
	bool rem[m+1], vis[m+1], ans[m+1];
	memset(vis, false, sizeof(vis));
	memset(rem, false, sizeof(rem));
	memset(ans, false, sizeof(ans));
	for(int i=0;i<m;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[i][0]=x; 
		edge[i][1]=y;
	}
	int mx=0;
	dfs(0, 0, rem, &mx, n, m, edge, vis, ans, G);
	for(int i=0;i<m;i++) (ans[i])&&(printf("%d %d\n", edge[i][0], edge[i][1]));
}
