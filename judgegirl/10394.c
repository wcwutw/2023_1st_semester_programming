#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 1005
void solve();
 
void dfs(int id, int dep, int *mx, bool *vis, int (*G)[65], int *sz, int (*ans)[105], int (*now)[105], int k, int n, bool *flag) {
    if(*flag) {
        return;
    }
    if(id==n/k) {
        //if(dep>*mx) {
            //*mx=dep;
			bool fas=0;
			(dep>*mx)&&(fas=1);
			(dep>*mx)&&(*mx=dep);
			for(int i=0;i<(*mx)*k;i++) {
                //for(int j=0;j<k;j++) 
				(fas==1)&&(ans[i/k][i%k]=now[i/k][i%k]);
            }
        //}
        *flag=(*mx==n/k);
        //printf("find %d %d %d\n", id, dep, *mx);
        return;
    }
    now[dep][0]=id;
    vis[id]=1;
    solve(id, id, dep, mx, vis, G, sz, ans, now, k, n, flag);
    vis[id]=0;
    dfs(id+1, dep, mx, vis, G, sz, ans, now, k, n, flag);
 
}
void solve(int nowid, int stid, int dep, int *mx, bool *vis, int (*G)[65], int *sz, int(*ans)[105], int(*now)[105], int k, int n, bool *flag) {
    //printf("solve: %d %d %d\n", nowid, stid, dep);
    if(*flag) return;
    if(nowid+n/k>=n) {
        dfs(stid+1, dep+1, mx, vis, G, sz, ans, now, k, n, flag);
        return;
    }
    for(int i=0;i<sz[nowid];i++) {
        int j=G[nowid][i];
		if(!vis[j]) {
            vis[j]=1;
            now[dep][nowid*k/n+1]=j;
            solve(j, stid, dep, mx, vis, G, sz, ans, now, k, n, flag);
            vis[j]=0;
        }
    }
}

int main() {
    bool vis[N], flag=0;
    int ans[65][105], now[65][105], G[N][65], sz[N];
    int n, k;
	memset(sz, 0, sizeof(sz));
    memset(vis, false, sizeof(vis));
	//memset(G, 0x3f3f3f3f, sizeof(G));
    scanf("%d%d", &k, &n);
    int e;
    scanf("%d", &e);
    int x, y;
    for(int i=0;i<e;i++) {
        scanf("%d%d", &x, &y);
        //adj[x][y]=1;
		G[x][sz[x]++]=y;
    }
	/*for(int i=0;i<n;i++) {
		qsort(G[i], 65, sizeof(int), cmpfunc);
	}*/
    int mx=0;
    dfs(0, 0, &mx, vis, G, sz, ans, now, k, n, &flag);
    for(int i=0;i<mx*k;i++) {
        //for(int j=0;j<k;j++) {
            printf("%d ", ans[i/k][i%k]);
        //}
        (i%k==k-1)&&(printf("\n"));
    }
    return 0;
}
