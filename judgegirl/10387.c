#include<stdio.h>

void calc(int** plate, int n, int m, int cnt, int cur, int *ret) {
	if(cnt>=n*m || (n*m-cnt)/2+cur<*ret) {
		((cnt>=n*m && *ret<cur)&&(*ret=cur));
		return;
	}
	int dm=cnt/m, mm=cnt%m;
	if((plate[dm][mm]==1)||(dm>=1&&mm>=2&&plate[dm-1][mm-2]==2)||(dm>=1&&mm+2<m&&plate[dm-1][mm+2]==2)||(dm>=2&&mm>=1&&plate[dm-2][mm-1]==2)||(dm>=2&&mm+1<m&&plate[dm-2][mm+1]==2)) {
		calc(plate, n, m, cnt+1, cur, ret);
	}
	else {
		plate[dm][mm]=2;
		calc(plate, n, m, cnt+1, cur+1, ret);
		plate[dm][mm]=0;
		calc(plate, n, m, cnt+1, cur, ret);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y;
	int plate[n][m];
	int* p[n];
	int ret=0;
	memset(plate, 0, sizeof(plate));
	while(scanf("%d%d", &x, &y)!=EOF) {
		plate[x][y]=1;
	}
	for(int i=0;i<n;i++) {
		p[i]=plate[i];
	}
	calc(p, n, m, 0, 0, &ret);
	printf("%d", ret);
}
