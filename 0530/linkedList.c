#include <stdio.h>
#include <stdlib.h>

//#define pnode_t node_t*

//�ŧi�ǥͪ��򥻵��c
typedef struct {
	int coefficient;
	int power;
} x_t;

// �ŧi�H�ǥͷ�@data��node
typedef struct node {
	x_t data;
	struct node *next;
} node_t, *pnode_t, **ppnode_t;


// �Q��student���ͤ@��node
pnode_t createNode(x_t);

// �L�X�@��student�����
void printX(x_t);

// �L�X�@�Ӹ`�I�����
void printNode(pnode_t pnode);

// �L�X�Ҧ�node�����e
void printList(pnode_t head);

// �q�e���[�J
void insertFromFront(ppnode_t head, x_t data);

// �q�᭱�[�J
void insertFromBack(ppnode_t head, x_t data);

// insert from spefic index
void insert(ppnode_t head, x_t data, int index);

// �q�e���R��
x_t delFromFront(ppnode_t head);

// �q�᭱�R��
x_t delFromBack(ppnode_t head);

// delete from specfic index
x_t del(ppnode_t head, int index);

// �����R��
void deleteList(ppnode_t head);

// count size of list
int size(pnode_t head);

pnode_t getList();
void setPower(pnode_t pnode);

int main()
{
	pnode_t head1 = NULL;
	pnode_t head2 = NULL;
	pnode_t answer = NULL;
	head1 = getList();
	head2 = getList();

	printList(head1);
	puts("");
	printList(head2);
	puts("");

	while(!(head1==NULL && head2==NULL))
	{
		x_t x;
		if(head1!=NULL && head2!=NULL){
			x_t x1 = head1->data;
			x_t x2 = head2->data;
			if(x1.power<x2.power){
				x = x1;
				delFromFront(&head1);
			}else if(x1.power == x2.power){
				x = x1;
				x.coefficient += x2.coefficient;
				delFromFront(&head1);
				delFromFront(&head2);
			}else{
				x = x2;
				delFromFront(&head2);
			}
		}else if(head1!=NULL){
			x = delFromFront(&head1);
		}else if(head2!=NULL){
			x = delFromFront(&head2);
		}

		insertFromBack(&answer, x);
		setPower(answer);
	}
	printList(answer);
	puts("");
	system("pause");
	return 0;
}

pnode_t getList(){
	char ch;
	int coff;
	pnode_t head = NULL;
	do{
		scanf("%d%c", &coff, &ch);
		x_t x;
		x.coefficient = coff;
		x.power = 0;
		insertFromFront(&head, x);
	}while(ch!='\n');

	setPower(head);
	return head;
}

void setPower(pnode_t pnode){
	int i=0;
	while(pnode!=NULL){
		pnode->data.power = i++;
		pnode = pnode->next;
	}
}

//�Q��student���ͤ@��node
pnode_t createNode(x_t student)
{
	// ���ͤ@��node���x�s�bheap�O���餺
	pnode_t pnode = (pnode_t)malloc(sizeof(node_t));
	// �]�w�ǥ͸�ƨ�node��
	pnode->data = student;
	(*pnode).data = student;

	// �]�w�o�ӫ��Ъ��U�@��node����
	pnode->next = NULL;
	return pnode;
}

void printX(x_t x)
{
	//2x^4
	printf("%dx%d", x.coefficient, x.power);
}

void printNode(pnode_t pnode)
{
	printX(pnode->data);
}

void insertFromFront(ppnode_t head, x_t data)
{
	pnode_t node = createNode(data);
	if(*head == NULL){
		*head = node;
	}else{
		node->next = *head;
		*head = node;
	}
}

void insertFromBack(ppnode_t head, x_t data)
{
	if(*head == NULL){
		insertFromFront(head, data);
	}else{
		pnode_t node = *head;
		while(node->next!=NULL){
			node = node->next;
		}
		node->next = createNode(data);
	}
}

void printList(pnode_t pnode)
{
	if(pnode->next==NULL){
		if(pnode->data.coefficient>=0){
			printf(" + ");
		}
		printNode(pnode);
	}else{
		printList(pnode->next);
		if(pnode->data.coefficient>=0){
			printf("+");
		}
		printNode(pnode);
	}
}

x_t delFromFront(ppnode_t head)
{
	x_t student;
	if(*head != NULL){
		pnode_t next = (*head)->next;
		student = (*head)->data;
		free(*head);
		*head = next;
	}
	return student;
}

// �q�᭱�R��
x_t delFromBack(ppnode_t head)
{
	x_t student;
	if(*head != NULL){
		//�p�G���@�Ӥ@�W
		pnode_t node = *head;
		if(node->next == NULL){
			// �p�G�u���@��
			return delFromFront(head);
		}else{
			while(node->next->next!=NULL){
				node = node->next;
			}
			student = node->next->data;
			free(node->next);
			node->next = NULL;
		}
	}
	return student;
}

void deleteList(ppnode_t head)
{
	pnode_t node = *head;
	if(node!=NULL){
		if(node->next!=NULL){
	 		deleteList(&(node->next));
		}
 		free(node);
 		*head = NULL;
	 }
}

int size(pnode_t head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}

// insert from spefic index
void insert(ppnode_t head, x_t data, int index){
	int i;
	for(i=0;i<index;i++){
		pnode_t pnode = (*head);
		head = &(pnode->next);
	}
	pnode_t pnode = createNode(data);
	pnode->next = *head;
	*head = pnode;
}

x_t del(ppnode_t head, int index){
	x_t student;
	if(*head!=NULL){
		int i;
		for(i=0;i<index;i++){
			pnode_t pnode = (*head);
			head = &(pnode->next);
		}
		pnode_t pnode = (*head)->next;
		free(*head);
		*head = pnode;
	}
	return student;
}

