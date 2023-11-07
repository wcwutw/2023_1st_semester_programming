#include <stdio.h>
#include <assert.h>
const int MAX=1001;

void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
	int *tmp[MAX], ans[MAX], id[MAX];
	for(int i=0;i<MAX && ptrArray[i]!=NULL;i++) {
		ans[i]=*(ptrArray[i]);
	}
	for(int i=0;i<MAX && ptrPerms[i]!=NULL;i++) {
		for(int j=0;j<MAX && ptrArray[j]!=NULL;j++) {
			id[j]=*(ptrPerms[i]+j);
			tmp[j]=ptrArray[id[j]];
		}
		for(int j=0;j<MAX && ptrArray[j]!=NULL;j++) {
			ptrArray[j]=tmp[j];
		}
		
	}
	/*for(int i=0;i<MAX && ptrArray[i]!=NULL;i++) {
		ptrArray[i]=&ans[tmp[i]];
	}*/
}

/*int main() {
    int n, array[MAX], check[MAX];
    int *ptrArray[MAX];
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        ptrArray[i] = &array[i];
        scanf("%d", &array[i]);
        check[i] = array[i];
    }
    ptrArray[n] = NULL;
 
    int m, perms[MAX][MAX];
    int *ptrPerms[MAX];
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++)
            scanf("%d", &perms[i][j]);
        ptrPerms[i] = perms[i];
    }
    ptrPerms[m] = NULL;
 
    permute(ptrArray, ptrPerms);
 
    for (int i = 0; i<n; i++) {
        assert(array[i] == check[i]);
        printf("%d ", *(ptrArray[i]));
    }
 
    return 0;
}*/
