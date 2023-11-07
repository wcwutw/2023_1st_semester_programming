#include <stdio.h>
#define MAXR 100
#define MAXC 100
#define MAXK 10

 
void img2col(int r, int c, int k, int imgMatrix[MAXR][MAXC], int colMatrix[MAXR * MAXC][MAXK * MAXK]) {
	int id=0;
	for(int i=0;i+k<=c;i++) {		
		for(int j=0;j+k<=r;j++) {
			int cnt=0;
			for(int ii=i;ii<i+k;ii++) {
				for(int jj=j;jj<j+k;jj++) {
					colMatrix[id][cnt]=imgMatrix[jj][ii];
					//printf("%d %d %d\n", id, cnt, colMatrix[id][cnt]);
					cnt++;
					
				}
			}
			//printf("%d %d\n", i, j);
			id++;
		}
	}
}

