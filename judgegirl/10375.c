#include<stdio.h>
#include<stddef.h>
#define MAX_PTR_ARR_SIZE 1000
#define MAX_ARR_SIZE 10000 
int countIntersections(int* ptrArray[]) {
	int ret=0;
	for(int i=0;i<MAX_ARR_SIZE && ptrArray[i]!=NULL;i++) {
		//printf("%d\n", (ptrArray[i]));
		for(int j=i+1;j<MAX_ARR_SIZE && ptrArray[j]!=NULL;j++) {
			ret+=((ptrArray[j])<(ptrArray[i]));
		}
	}
	return ret;
}

/*int main(void) {
    int array[MAX_ARR_SIZE];
    int *ptrArray[MAX_PTR_ARR_SIZE];
    for (int i = 0; i < MAX_ARR_SIZE; i++) {
        array[i] = 0;
    }
    int n;
    scanf("%d", &n);
    int index[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &index[i]);
        ptrArray[i] = &array[index[i]];
    }
    ptrArray[n] = NULL;
    int numIntersections = countIntersections(ptrArray);
    printf("%d\n", numIntersections);
    return 0;
}*/
