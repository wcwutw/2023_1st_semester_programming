#include<stdio.h>
#include <limits.h>
#define min(a, b) a<b?a:b
struct Pair{
	int F, S;
};
int x[50005], y[50005];
int ans[50005];
int main() {
	int n, ox, oy;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	scanf("%d%d", &ox, &oy);
	int mn=INT_MAX, prev=0, nowid=0;
	for(int i=0;i<n;i++) {
		int now=(x[i]-ox)*(x[i]-ox)+(y[i]-oy)*(y[i]-oy);
		if(now<mn) {
			nowid=prev;
			ans[nowid]=i;
			nowid++;
			mn=now;
		}
		else if(now==mn) {
			ans[nowid]=i;
			nowid++;
		}
	}
	for(int i=prev;i<nowid;i++) printf("%d\n", ans[i]);
}
