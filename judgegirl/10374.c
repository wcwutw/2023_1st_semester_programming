#include<stdio.h>
#include<stdbool.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define rep1(i, n) for(int i=1;i<=n;i++)
#define max(x, y) x>y?x:y
int n, m;
bool checkx(int x) {
	return (0<=x && x<n);
}
bool checky(int y) {
	return (0<=y && y<m);
}
 
int main() {
	int l, w;
	scanf("%d%d%d%d", &n, &m, &l, &w);
	int ox, oy;
	scanf("%d%d", &ox, &oy);
	//swap(ox, oy);
	int s, k;
	scanf("%d%d", &s, &k);
	int a[n+5][m+5];
	rep(i, n) {
		rep(j, m) scanf("%d", &a[n-1-i][j]);
	}
	int nowx=oy, nowy=ox;
	int difx=nowx-(n-1), dify=nowy-(m-1);
	difx=(difx+s-1)/s; dify=(dify+s-1)/s;
	int mindif=max(difx, dify);
	mindif=max(0, mindif);
	nowx-=mindif*s;
	nowy-=mindif*s;
	k-=mindif-1;
	//k++;
	//printf("%d %d %d\n", nowx, nowy, k);
	while(k && nowx+l-1>=0 && nowy+w-1>=0/* && ((checkx(nowx) && checky(nowy)) || (checkx(nowx+l-1) && checky(nowy+w-1)))*/) {
		/*if(!((checkx(nowx) && checky(nowy)) || (checkx(nowx+l-1) && checky(nowy+w-1)))) {
			nowx-=s;
			nowy-=s;
			k--;
			continue;
		}*/
		/*if(nowx+l-1<0 || nowy+w-1<0) {
			break;
		}*/
		int flag=0;
		int output;
		for(int i=n-1;i>=0;i--) {
			rep(j, m) {
				if(nowx<=i && i<nowx+l && nowy<=j && j<nowy+w) {
					flag=1;
					output=0;
				}
				else output=a[i][j];
				printf("%d ", output);
			}
			printf("\n");
		}
		/*if(flag) {
			for(int i=n-1;i>=0;i--) {
				rep(j, m) {
					printf("%d ", output[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}*/
		printf("\n");
		nowx-=s;
		nowy-=s;
		k--;
	}
}
