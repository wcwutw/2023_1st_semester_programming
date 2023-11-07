#include<stdio.h>

double a[100005];
int main() {
	int n;
	scanf("%d", &n);
	double sum=0.0;
	for(int i=0;i<n;i++) {
		scanf("%lf", &a[i]);
		sum+=a[i];
	}
	double mu=sum/(double)n;
	sum=0.0;
	for(int i=0;i<n;i++) {
		sum=sum+(a[i]-mu)*(a[i]-mu);
	}
	double var=sum/(double)n;
	printf("%.6lf\n%.6lf\n", mu, var);
}
