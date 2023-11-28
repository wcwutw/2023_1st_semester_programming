#include<stdio.h>
void calc(int n, int nx, int ny, int x, int y) {
	if(n==1) return;
	int type=(x-nx<n/2)+2*(y-ny<n/2);
	printf("%d %d %d\n", type+1, nx+n/2, ny+n/2);
	for(int i=0;i<=3;i++) {
		if(i==type) {
			calc(n/2, nx+(n/2)*(i%2==0), ny+(n/2)*(i<=1), x, y);
		}
		else {
			calc(n/2, nx+(n/2)*(i%2==0), ny+(n/2)*(i<=1), nx+(n/2)-(i%2==1), ny+(n/2)-(i>=2));
		}
	}
}
int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	calc(n, 0, 0, x, y);
}
