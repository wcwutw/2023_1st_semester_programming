#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
		//printf("%d %s\n", (int)strlen(tar), tar);
		for(int j=0;j<strlen(fnd);j++) {
			char now=fnd[j];
			char *ptr=strchr(tar, now);
			//printf("%s\n", ptr);
			if(ptr) {
				l[(i+1)%n]=j;
				r[i]=ptr-tar;
				ans+=r[i];
				ans-=l[(i+1)%n];
				break;
			}
		}
	}
	/*for(int i=0;i<n;i++) {
		//printf("%d %d\n", l[i], r[i]);
		ans+=(r[i]-l[i]);
	}*/
	printf("%d", ans);
}
