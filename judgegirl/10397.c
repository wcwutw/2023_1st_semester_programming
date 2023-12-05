#include<stdio.h>
#include<stdint.h>
#include "numZeroBits.h"
/*#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;*/
int numZeroBits(GiantUnsignedInt *giantNum) {
	int n=giantNum->n;
	int cnt=0, ret=0;
	uint64_t one=1;
	for(int i=0;i<n;i++) {
		for(int j=63;j>=0;j--) {
			if(giantNum->array[i]&(one<<j)) {
				cnt=0;
			}
			else {
				cnt++;
				(cnt>ret)&&(ret=cnt);
			}
		}
	}
	return ret;
}

/*int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%llu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numZeroBits(&giantNum));
    }
    return 0;
}*/
