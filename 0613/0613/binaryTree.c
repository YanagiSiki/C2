#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
   int data;
   struct node_s * left;
   struct node_s * right;    
} node_t;

typedef node_t * pnode_t, **ppnode_t;

pnode_t createNode(int data);
void insert(ppnode_t proot, int data);
void insertNode(ppnode_t proot, pnode_t node);
int removeNode(ppnode_t proot, int data);

void printTreePreOrder(pnode_t root);
void printTreeInOrder(pnode_t root);
void printTreePostOrder(pnode_t root);
void menu();

int main()
{
	pnode_t root = NULL;
	int input;
	for(menu(), scanf("%d", &input);input!=6;menu(), scanf("%d", &input)){
		switch(input){
			case 1:{ // 加入節點
				int data;
				scanf("%d", &data);
				insert(&root, data);
				break;
			}
			case 2:{ // 刪除節點
				int data;
				scanf("%d", &data);
				removeNode(&root, data);
				break;
			}
			case 3:{ // 前序 
				printTreePreOrder(root);
				puts("");
				break;
			}
			case 4:{ // 中序 
				printTreeInOrder(root);
				puts("");
				break;
			}
			case 5:{ // 後序 
				printTreePostOrder(root);
				puts("");
				break;
			}
		}
	}
	system("pause");
	return 0;
}

void menu(){
	puts("\
1. 輸入一數字並加入節點\n\
2. 輸入一數字並刪除節點\n\
3. 以前序方式印出整棵樹\n\
4. 以中序方式印出整棵樹\n\
5. 以後序方式印出整棵樹\n\
6. 結束程式\n");
}

pnode_t createNode(int data){
	pnode_t pnode = (pnode_t)malloc(sizeof(node_t));
	pnode->data = data;
	pnode->left = pnode->right = NULL;
	return pnode;
}

void insert(ppnode_t proot, int data){
	pnode_t pnode = createNode(data);
	insertNode(proot, pnode);
//	if(*proot==NULL){
//		*proot = createNode(data);
//	}else if(data <(*proot)->data){ //data比較小，塞到左子樹 
//		insert(&((*proot)->left), data);
//	}else{
//		insert(&((*proot)->right), data);
//	}
}

void insertNode(ppnode_t proot, pnode_t node){
	if(*proot==NULL){
		*proot = node;
	}else if(node->data <(*proot)->data){ //data比較小，塞到左子樹 
		insertNode(&((*proot)->left), node);
	}else{
		insertNode(&((*proot)->right), node);
	}
}


void printTreeInOrder(pnode_t root){
	if(root!=NULL){
		printTreeInOrder(root->left);
		printf("%d ", root->data);
		printTreeInOrder(root->right);
	}
}

void printTreePreOrder(pnode_t root)
{
	if(root!=NULL){
		printf("%d ", root->data);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreePostOrder(pnode_t root){
	if(root!=NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d ", root->data);
	}
}

int removeNode(ppnode_t proot, int data){
	if(*proot!=NULL){
		pnode_t root = *proot;
		if(root->data == data){
			if(root->left == NULL && root->right == NULL){
				*proot = NULL; 
			}else if(root->left !=NULL && root->right == NULL)
			{
				*proot = root->left;
			}else if(root->left ==NULL && root->right != NULL)
			{
				*proot = root->right;
			}else if(root->left !=NULL && root->right != NULL)
			{
				pnode_t leftTree = root->left;
				*proot = root->right;
				insertNode(proot, leftTree);
			} 
		}else if(data < root->data){// 節點可能在左子樹 
			removeNode(&(root->left), data);
		}else{
			removeNode(&(root->right), data);
		}
	} 
} 







