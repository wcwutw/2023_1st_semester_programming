#include<stdio.h>

int main() {
	long long pren=0, n;
	int cnt=1;
	scanf("%lld", &pren);
	while(scanf("%lld", &n)!=EOF) {
		if(pren*n>0) cnt++;
		else {
			if(pren<0) printf("-%d ", cnt);
			else printf("%d ", cnt);
			cnt=1;
		}
		pren=n;
	}
	if(pren<0) printf("-%d\n", cnt);
	else printf("%d\n", cnt);
}
