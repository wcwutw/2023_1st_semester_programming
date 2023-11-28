#include<stdio.h>
typedef struct hanoi hanoi;
struct hanoi{
	int sz;
	char from, to, mid;
};
void initialize(struct hanoi *hn, int num, char src, char dst, char buffer);
void moveHanoi(struct hanoi *hn);

