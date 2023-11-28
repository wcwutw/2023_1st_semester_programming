#include <stdio.h>
#include<stdlib.h>
#include "hanoi.h"
 
void initialize(struct hanoi *hn, int num, char src, char dst, char buffer) {
	hn->from=src;
	hn->to=dst;
	hn->mid=buffer;
	hn->sz=num;
}
void moveHanoi(struct hanoi *hn) {
	if(hn->sz==1) {
		printf("move 1 disk from %c to %c\n", hn->from, hn->to);
	}
	else {
		printf("move %d disks from %c to %c\n", hn->sz-1, hn->from, hn->mid);
		printf("move 1 disk from %c to %c\n", hn->from, hn->to);
		printf("move %d disks from %c to %c\n", hn->sz-1, hn->mid, hn->to);
	}
}
 
int main(){
    int num;
    char src, dst, buffer;
    while(scanf("%d %c %c %c", &num, &src, &dst, &buffer) != EOF){
        struct hanoi hn;
        initialize(&hn, num, src, dst, buffer);
        moveHanoi(&hn);
    }
}
