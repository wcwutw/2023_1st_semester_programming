#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max(a, b) (a>b?a:b);

int main() {
	int n;
	scanf("%d", &n);
	int orix, oriy, prex, prey;
	scanf("%d%d", &orix, &oriy);
	scanf("%d%d", &prex, &prey);
	int ans=orix*prey-oriy*prex, x, y;
	//printf("%d", ans);
	for(int i=2;i<n;i++) {
		scanf("%d%d", &x, &y);
		ans+=prex*y-prey*x;
		prex=x; prey=y;
		//printf("%d", ans);
	}
	ans+=(-prey*orix+oriy*prex);
	printf("%d", ans);
}
