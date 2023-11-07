#include <stdio.h>
#define MAX 2000 + 1
void dividePolynomial(int f[], int g[]) {
	int of[MAX], og[MAX];
	for(int i=0;i<=(int)f[0];i++) {of[i]=f[i+1]; og[i]=g[i+1];}
	//for(int i=0;i<=(int)g[0];i++) {og[i]=g[i+1];}
	int savid=1;
	for(int nowid=0;nowid<=f[0]-g[0];nowid++) {
		int quo=of[nowid]/og[0];
		f[savid]=quo;
		for(int j=nowid;j<=nowid+g[0];j++) {
			of[j]-=(quo*og[j-nowid]);
		}
		savid++;
	}
	/*for(int j=0;j<=f[0];j++) printf("%d ", of[j]);
    printf("\n");*/
    int orifsz=f[0];
	//printf("%d %d\n", f[0], g[0]);
	f[0]=savid-2;
	savid=1;
	/*if((int)g[0]==0) {
        g[0]=g[1]=0;
        return;
	}*/
	//printf("%d %d\n", f[0], g[0]);
	int flag=1;
	for(int nowid=orifsz+1-g[0];nowid<=orifsz;nowid++) {
		if(flag && of[nowid]==0) continue;
		g[savid]=of[nowid];
		flag=0;
		//printf("%d %d\n", nowid, of[nowid]);
		savid++;
	}
	if(savid>1) g[0]=savid-2;
	else {
        g[0]=0;
        g[1]=0;
	}
}

/*void readPolynomial(int p[]) {
    scanf("%d", &p[0]);
    for (int i = 1; i<=p[0]+1; i++)
        scanf("%d", &p[i]);
}

void printPolynomial(int p[]) {
    for (int i = 0; i<=p[0]; i++)
        printf("%d ", p[i]);
    printf("%d", p[p[0]+1]);
}

int main() {
    int n, f[MAX], g[MAX];
    scanf("%d", &n);
    while (n--) {
        readPolynomial(f);
        readPolynomial(g);

        dividePolynomial(f, g);

        printPolynomial(f);
        printf("\n");
        printPolynomial(g);
        if (n) printf("\n");
    }
    return 0;
}*/

/*
1
3
1 -2 1 -2
1
1 -2
*/
