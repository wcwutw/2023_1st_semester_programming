#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int x, y, w, h;
	int prex, prey;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	prex=x+w;
	prey=y+h;
	int ans=w*h;
	for(int i=1;i<n;i++) {
		scanf("%d%d%d%d", &x, &y, &w, &h);
		ans+=w*h;
		ans-=(prex-x)*(prey-y);
		prex=x+w;
		prey=y+h;
	}
	printf("%d\n", ans);
	
}
