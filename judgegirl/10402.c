#include <stdio.h>
#include <stdlib.h>
/*#include "tree.h"
Node *newNode (int data, Node *l, Node *r) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = data;
    n->left = l;
    n->right = r;
    return n;
}*/
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
 
typedef struct Answer {
    int sumDepth;
    int sumData;
    int dep;
} Answer; 

void trace(Node *root, Answer *ans) {
	if(root==NULL) return;
	Answer* lans=malloc(sizeof(ans));
	Answer* rans=malloc(sizeof(ans));
	rans->sumData=lans->sumData=0;
	rans->sumDepth=rans->sumData=0;
	lans->dep=rans->dep=0;
	trace(root->left, lans);
	trace(root->right, rans);
	ans->dep=lans->dep+rans->dep+1;
	ans->sumDepth=lans->sumDepth+rans->sumDepth+ans->dep;
	ans->sumData=root->data+lans->sumData+rans->sumData;
}
/*int main () {
    Node *root = newNode(
        10,
            newNode(
                5,
                    NULL,
                    newNode(2, NULL, NULL)
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    NULL
            )
    );
    Answer *ans = (Answer*) malloc(sizeof(Answer));
    ans->sumDepth = 0;
    ans->sumData = 0;
    trace(root, ans);
    printf("%d %d\n", ans->sumDepth, ans->sumData);
    return 0;
}*/
