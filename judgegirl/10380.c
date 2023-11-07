#include <stdio.h>

void Turing_Machine(int *head, int K) {
	int cur=0;
	while(K--) {
		if(cur==0) {
			if(*head==0 || *head==2) {
				head++;
				cur=2;
			}
			else {
				head++;
				cur=1;
			}
		}
		else if(cur==1) {
			*head=(*head+1)%4;
			if(*head==1 || *head==3) {
				cur=2;
				head--;
			}
			else {
				cur=0;
				head++;
			}
		}
		else {
			*head=(*head+2)%4;
			if(*head==2) {
				cur=1;
			}
			else if(*head==3) {
				cur=0;
				head--;
			}
			else if(*head==0) {
				cur=1;
				head++;
			}
			else cur=0;
		}
	}
}

/*int main()
{
    int n, p, K;
    scanf("%d%d%d", &n, &p, &K);
    int tape[n];
    for(int i = 0; i < n; i++) scanf("%d", &tape[i]);
 
    int *head = &tape[p];
    Turing_Machine(head, K);
 
    for(int i = 0; i < n; i++) printf("%d ", tape[i]);
 
    return 0;
}*/
