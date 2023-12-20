#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    bool color;
    struct Node *left, *right;
    int farthestLeft, farthestRight;
} Node; 
/*Node *newNode (bool color, Node *l, Node *r) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->color = color;
    n->left = l;
    n->right = r;
    n->farthestLeft = n->farthestRight = 0;
    return n;
}*/
int maxDist(Node *root) {
	if(root==NULL) return -1000000000;
	root->farthestLeft=root->farthestRight=-1000000000;
	int ans=0, ld=0, rd=0;
	ld=maxDist(root->left);
	(root->left!=NULL)&&(root->farthestLeft=1+root->left->farthestLeft*(root->left->farthestLeft>root->left->farthestRight)+root->left->farthestRight*(root->left->farthestLeft<=root->left->farthestRight));
	rd=maxDist(root->right);
	(root->right!=NULL)&&(root->farthestRight=1+root->right->farthestLeft*(root->right->farthestLeft>root->right->farthestRight)+root->right->farthestRight*(root->right->farthestLeft<=root->right->farthestRight));
	ans=(ld>ans)*ld+(ans>=ld)*ans;
	ans=(rd>ans)*rd+(ans>=rd)*ans;
	(root->color==0&&root->farthestLeft<0)&&(root->farthestLeft=0);
	(root->color==0&&root->farthestRight<0)&&(root->farthestRight=0);
	int ret=root->farthestLeft+root->farthestRight;
	ans=(ret>ans)*ret+(ans>=ret)*ans;
	return ans;
}

/*int main () {
    Node *root = newNode(
        false, // 1
            newNode(
                true, // 2
                    newNode(
                        false, // 3
                            newNode(
                                true, // 4
                                    newNode(false,  NULL, NULL), // 5
                                    newNode(true,  NULL, NULL) // 6
                            ),
                            newNode(
                                false, // 7
                                    newNode(true,  NULL, NULL), // 8
                                    NULL
                            )
                    ),
                    newNode(
                        false, // 9
                            newNode(
                                true, // 10
                                    NULL,
                                    newNode(false, NULL, NULL) // 11
                            ),
                            NULL
                    )   
            ),
            newNode(
                false, // 12
                    NULL,           
                    newNode(true, // 13
                                newNode(true, NULL, NULL), // 14
                                NULL)
            )
    );
    printf("%d\n", maxDist(root));
    return 0;
}*/
