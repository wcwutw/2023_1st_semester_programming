#include <stdio.h>
#include <stdlib.h>
#include "numToTree.h"
#define NUMBITS 64
TreeNode *numToTree(uint64_t num, int bitNum) {
	if(num==0) return NULL;
	TreeNode *node=malloc(sizeof(TreeNode));
	node->value=num;
	uint64_t one=1;
	(bitNum==1)&&(node->left=NULL);
	(bitNum==1)&&(node->right=NULL);
	(bitNum!=1)&&(node->left=numToTree(num>>(bitNum>>1), bitNum>>1));
	(bitNum!=1)&&(node->right=numToTree(num%(one<<(bitNum>>1)), bitNum>>1));
	return node;
}

/*void preorderTree(TreeNode *root){
    if(root == NULL) return;
    printf("%llu ", root->value);
    preorderTree(root->left);
    preorderTree(root->right);
}
 
void inorderTree(TreeNode *root){
    if(root == NULL) return;
    inorderTree(root->left);
    printf("%llu ", root->value);
    inorderTree(root->right);
}
 
int main(){
    uint64_t num;
    scanf("%llu", &num);
 
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root = numToTree(num, NUMBITS);
 
    preorderTree(root);
    printf("\n");
    inorderTree(root);
    printf("\n");
 
    return 0;
}*/
