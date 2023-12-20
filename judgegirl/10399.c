#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
double* freqCalculate(char names[1024]){
	double *arr=(double*)malloc(345*sizeof(double));
 	int b[7]={9, 11, 0, 2, 4, 5, 7};
	double c5=1.0594630943593;
	int l=0, id=0;
	while(names[l]!='\0') {
		char c=names[l];
		l++;
		(c=='#')&&(arr[id]*=c5);
		(c=='b')&&(arr[id]/=c5);
		(isupper(c))&&(arr[id]=523.251131);
		if(isupper(c)) for(int i=0;i<b[c-'A'];i++) arr[id]*=c5;
		else if(isdigit(c)) {
			int dif=c-'5';
			for(int i=0;i<abs(dif);i++) {
				(dif>0)&&(arr[id]*=2);
				(dif<=0)&&(arr[id]/=2);
			}
			id++;
		}
	}
	return arr;
}
