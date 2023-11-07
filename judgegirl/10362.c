#include<stdio.h>

int gcd(int a, int b){if(b==0) return a; return gcd(b,a%b);}
int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}
int main() {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int c=s-t;
    f-=8*c;
    f/=2;
    int b=f-t;
    int a=t-b;
    printf("%d\n%d\n%d\n", a, b, c);
}
