#include<stdio.h>
void calc(int n, int nx, int ny, int nz, int x, int y, int z) {
	if(n==1) return;
	int type=(x-nx<n/2)+2*(y-ny<n/2)+4*(z-nz<n/2);
	printf("%d %d %d %d\n", type+1, nx+n/2, ny+n/2, nz+n/2);
	for(int i=0;i<=7;i++) {
		if(i==type) {
			calc(n/2, nx+(n/2)*(i%2==0), ny+(n/2)*(((i>>1)&1)==0), nz+(n/2)*(((i>>2)&1)==0), x, y, z);
		}
		else {
			calc(n/2, nx+(n/2)*(i%2==0), ny+(n/2)*(((i>>1)&1)==0), nz+n/2*(((i>>2)&1)==0), nx+(n/2)-(i%2==1), ny+(n/2)-((i>>1)&1), nz+(n/2)*(((i>>2)&1)==1));
		}
	}
}
int main() {
	int n, x, y, z;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	calc(n, 0, 0, 0, x, y, z);
}
