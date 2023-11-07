#include<stdio.h>
#define rep(i, n) for(int i=0;i<n;i++)

int main() {
	int n;
	scanf("%d", &n);
	int a[n+5][n+5];
	rep(i, n) {
		rep(j, n) scanf("%d", &a[i][j]);
	}
	int m;
	scanf("%d", &m);
	int x[m+5], y[m+5];
	rep(i, m) {
		scanf("%d%d", &x[i], &y[i]);
		//cin>>x[i]>>y[i];
		for(int j=0;j<i;j++) {
			if((x[j]>x[i] || (x[j]==x[i]) && (y[j]>y[i]))) {
				int tmpx=x[i], tmpy=y[i];
				x[i]=x[j], y[i]=y[j];
				x[j]=tmpx, y[j]=tmpy;
			}
		}
	}
	rep(i, m) {
		int nx=x[i], ny=y[i];
		int llen=1, rlen=1, ulen=1, dlen=1;
		int lflag=0, rflag=0, uflag=0, dflag=0;
		nx--;
		while(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==1) {
			ulen++;
			nx--;
			uflag=1;
		}
		nx=x[i], ny=y[i];
		nx++;
		while(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==1) {
			dlen++;
			nx++;
			dflag=1;
		}
		nx=x[i], ny=y[i];
		ny--;
		while(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==1) {
			llen++;
			ny--;
			lflag=1;
		}
		nx=x[i], ny=y[i];
		ny++;
		while(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==1) {
			rlen++;
			ny++;
			rflag=1;
		}
		if(uflag && rflag) {
			printf("0 %d %d\n", ulen, rlen);
		} else if(uflag && lflag) {
			printf("1 %d %d\n", ulen, llen);
		} else if(dflag && lflag) {
			printf("2 %d %d\n", dlen, llen);
		} else {
			printf("3 %d %d\n", dlen, rlen);
		}
	}
}
