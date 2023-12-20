#include <stdio.h>
#include <stdlib.h>
#define MAXARR 10000
struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
typedef struct treenode TreeNode;
TreeNode *buildTree(int traverseOrder[MAXARR], int arrSize) {
	TreeNode *node=malloc(sizeof(TreeNode));
	node->value=traverseOrder[0];
	if(arrSize==1) {
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	for(int i=1;i<arrSize;i++) {
		(traverseOrder[i]==node->value)&&(node->left=buildTree(traverseOrder+1, i));
		(traverseOrder[i]==node->value)&&(node->right=buildTree(traverseOrder+i+1, arrSize-i));
		(traverseOrder[i]==node->value)&&(i=arrSize);
	}
	return node;
}

/*void preorderTree(TreeNode *root){
    if(root == NULL) return;
    printf("%d ", root->value);
    preorderTree(root->left);
    preorderTree(root->right);
}
 
void inorderTree(TreeNode *root){
    if(root == NULL) return;
    inorderTree(root->left);
    printf("%d ", root->value);
    inorderTree(root->right);
}
 
int main(){
    int traverseOrder[MAXARR];
    int arrSize = 0;
 
    while(scanf("%d", &traverseOrder[arrSize]) != EOF)
        arrSize++;
 
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root = buildTree(traverseOrder, arrSize);
 
    preorderTree(root);
    printf("\n");
    inorderTree(root);
    printf("\n");
 
    return 0;
}*/
