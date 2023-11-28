#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int main() {
	char c[1005];
	char a[105][1005];
	int n=0, wid=0;
	while(scanf("%s", &c)!=EOF) {
		strcpy(a[n++], c);
	}
	int l[n], r[n];
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	int ans=0;
	for(int i=0;i<n;i++) {
		char* tar=a[i];
		char* fnd=a[(i+1)%n];
		int mn=1e9, sz=(int)strlen(tar);
		for(int j=sz-1;j>=0;j--) {
			for(int k=0;k<(int)strlen(fnd);k++) {
				if(tar[j]==fnd[k] && sz-1-j+k<mn) {
					//if(sz-1-j+k<mn) {
						mn=sz-1-j+k;
						r[i]=j;
						l[(i+1)%n]=k;
					//}
				}
			}
		}
	}
	for(int i=0;i<n;i++) {
		assert(r[i]>=l[i]);
		//printf("%d %d\n", l[i], r[i]);
		ans+=(r[i]-l[i]);
	}
	printf("%d", ans);
}
