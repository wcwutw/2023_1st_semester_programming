#include <stdint.h>
#include <stdio.h>
#include "numBitChanges.h"
//#define ARRAYSIZE 1000
 
/*typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 */
int numBitChanges(GiantUnsignedInt *giantNum){
    int n=giantNum->n;
	uint64_t one=1, now=giantNum->array[n-1]&one;
	int res=0;
	for(int i=0;i<n;i++) {
		for(int j=63;j>=0;j--) {
			uint64_t cur=giantNum->array[i]&(one<<j);
			if((now&&!cur)||(!now&&cur)) res++;
			now=cur;
		}
	}
    return res;
}
/*int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%llu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numBitChanges(&giantNum));
    }
    return 0;
}*/
