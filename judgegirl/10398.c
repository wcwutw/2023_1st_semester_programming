#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void solve(int cur, bool *flag, int id, int k, int *cnt, bool *vis, char *str, char *ans) {
	if(id==9 && cur==k) {*flag=1; return;}
	if(cur>k || id==9) return;
	for(int i=0;i<9;i++) {
		if(vis[i]) continue;
		vis[i]=1;
		ans[id]=str[i];
		//printf("%c ", ans[id]);
		solve(cur+cnt[str[i]-'a']*(id+1), flag, id+1, k, cnt, vis, str, ans);
		(*flag)&&(i=13);
		vis[i]=0;
	}
	return;
}
int cmp(const void *a, const void *b) {
	return (*(char *)a-*(char *)b);
}
int main() {
	int k;
	scanf("%d", &k);
	char c[105];
    int n=0, id=0;
    char str[14], ans[14];
	int cnt[31];
	bool vis[14];
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	while(scanf("%s", &c)!=EOF) {
        for(int i=0;i<strlen(c);i++) {
			(cnt[c[i]-'a']==0)&&(str[id++]=c[i]);
			cnt[c[i]-'a']++;
		}
	}
	/*for(int i=0;i<9;i++) printf("%c ", str[i]);
	printf("\n");*/
	bool flag=0;
	qsort(str, 9, sizeof(char), cmp);
	solve(0, &flag, 0, k, cnt, vis, str, ans);
	printf("%c %c %c %c %c %c %c %c %c\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7], ans[8]);
}
