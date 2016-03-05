#include<stdio.h>
typedef struct node_s {
    int data;
    struct node_s * left;
    struct node_s * right;
} node_t;

typedef node_t * nodep_t;

void printTree(nodep_t tree,int *count){
    if(tree!=NULL){
		printTree(tree->left,&(*count));

		if((*count)==0 && tree->left==NULL){
            printf("%d", tree->data);
            (*count)++;
		}else printf(" %d", tree->data);

		printTree(tree->right,&(*count));
	}
}

void insertTree(nodep_t * tree,int data){
    nodep_t p=(nodep_t)malloc(sizeof(node_t));
    p->data=data;
    p->left=p->right=NULL;
    if(*tree==NULL){
		*tree = p;
		//printf("%d\n",(*tree)->data);
	}else if(data <=(*tree)->data){ //data比較小，塞到左子樹
        insertTree(&((*tree)->left), data);
    }else{
        insertTree(&((*tree)->right), data);
    }
}

int main(){
    nodep_t tree=NULL;
    char choose;
    int data;
    int n;
    int count=0;

    while(1){
        n=scanf("%c%*c",&choose);
        if(n==-1)return;
        if(choose=='p'){
            if(tree==NULL){
                printf("null\n");
            }else {
                count=0;
                printTree(tree,&count);
                printf("\n");
            }
        }
        if(choose=='i'){
            scanf("%d%*c",&data);
            insertTree(&tree,data);
        }
    }


}
