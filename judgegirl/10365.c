#include<stdio.h>

int main() {
	int xa, xb, xc, xd, ya, yb, yc, yd;
	while(scanf("%d%d%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd)!=EOF) {
		int disa=(xa-xd)*(xa-xd)+(ya-yd)*(ya-yd), disb=(xb-xd)*(xb-xd)+(yb-yd)*(yb-yd), disc=(xc-xd)*(xc-xd)+(yc-yd)*(yc-yd);
		if(disa==disb && disa==disc) printf("0 ");
		else if(disa<disb && disa<disc) printf("1 ");
		else if(disb<disa && disb<disc) printf("2 ");
		else if(disc<disa && disc<disb) printf("3 ");
		else if(disa==disb && disa<disc) printf("4 ");
		else if(disa==disc && disa<disb) printf("5 ");
		else if(disb==disc && disb<disa) printf("6 ");
	}
	
}
