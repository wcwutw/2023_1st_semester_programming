#include <stdio.h>
#include <stdlib.h>
#define MAXM 200

int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]) {
	int ret=0;
	for(int i=0;i<M;i++) {
		int dif=ptrRight[i]-ptrLeft[i];
		//printf("%d\n", dif);
		ret+=(dif%N+1)*(dif/N+1);
		if(i) {
			dif=ptrRight[i-1]-ptrLeft[i];
			//printf("%d\n", dif);
			ret-=(dif%N+1)*(dif/N+1);
		}
	}
	return ret;
}

/*int main() {
    int N, M;
    scanf("%d%d", &N, &M);
 
    int *ptrMatrix;
    int matrix[N][N];
    int *ptrLeft[MAXM];
    int *ptrRight[MAXM];
    int x, y, w, h;
 
    ptrMatrix = &matrix[0][0];
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        ptrLeft[i] = &matrix[x][y];
        ptrRight[i] = &matrix[x + w - 1][y + h - 1];
    }
    int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
    printf("%d\n", area);
}*/
