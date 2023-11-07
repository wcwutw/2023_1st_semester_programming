#include<stdio.h>

int main() {
	int xa, ya, ra, xb, yb, rb;
	scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);
	int x, y;
	while(scanf("%d%d", &x, &y)!=EOF) {
		int disa=(x-xa)*(x-xa)+(y-ya)*(y-ya), disb=(x-xb)*(x-xb)+(y-yb)*(y-yb);
		if(disa>ra*ra && disb>rb*rb) printf("Out\n");
		else if(disa<ra*ra || disb<rb*rb) printf("In\n");
		else printf("On\n");
	}
}
