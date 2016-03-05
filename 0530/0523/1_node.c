#include <stdio.h>
#include <stdlib.h>

//#define pnode_t node_t*

//�ŧi�ǥͪ��򥻵��c 
typedef struct {
	int id;		//�Ǹ�
	int score;	//����
} student_t;

// �ŧi�H�ǥͷ�@data��node 
typedef struct node {
student_t data;
struct node *next;
} node_t, *pnode_t, **ppnode_t;

/*
typedef type typeAlias;
typedef type* typeAlias2;
typedef type typeAlias, *typeAlias2;
*/

// �Nnode_t������(node_t*)��pnode_t²�� 
// typedef node_t* pnode_t;
// typedef node_t** ppnode_t;

// �Q��student���ͤ@��node 
pnode_t createNode(student_t student);

// �L�X�@��student�����
void printStudent(student_t student); 

// �L�X�@�Ӹ`�I����� 
void printNode(pnode_t pnode);

// �L�X�Ҧ�node�����e
void printList(pnode_t head); 

// �q�e���[�J 
void insertFromFront(ppnode_t head, student_t data);

// �q�᭱�[�J
void insertFromBack(ppnode_t head, student_t data);

// insert from spefic index
void insert(ppnode_t head, student_t data, int index);

// �q�e���R��
student_t delFromFront(ppnode_t head);

// �q�᭱�R��
student_t delFromBack(ppnode_t head);

// delete from specfic index
student_t del(ppnode_t head, int index);

// �����R�� 
void deleteList(ppnode_t head);

// count size of list
int size(pnode_t head);



int main()
{
	student_t student;
	student.id = 99590306;
	student.score = 80;
	pnode_t head = createNode(student);
	
	student.id = 99590301;
	student.score = 90;
	insertFromFront(&head, student);
	
	student.id = 99590330;
	student.score = 100;
	insertFromBack(&head, student);
	
	
	printf("=====printList=====\n");
	printList(head);
	
	student.id = 99590399;
	student.score = 10;
	insert(&head, student, 1);
	
	printf("=====afterInsert=====\n");
	printList(head);
	
	
	del(&head, 1);
	
	printf("=====afterDel=====\n");
	printList(head);
	
	
	printf("=====size=====\n");
	int count = size(head);
	printf("size=%d\n", count);
	
	
	printf("=====deleteList=====\n");
	deleteList(&head);
	
	printf("=====printList=====\n");
	printList(head);
	
	student = delFromFront(&head);
	printf("=====deleteFrontNode=====\n");
	printStudent(student);
	printf("=====after deleteFrontNode=====\n");
	printList(head);
	
	student = delFromBack(&head);
	printf("=====deleteBackNode=====\n");
	printStudent(student);
	printf("=====after deleteBackNode=====\n");
	printList(head);
	
	system("pause");
	return 0;
}


//�Q��student���ͤ@��node 
pnode_t createNode(student_t student)
{
	// ���ͤ@��node���x�s�bheap�O���餺
	pnode_t pnode = (pnode_t)malloc(sizeof(node_t));
	// �]�w�ǥ͸�ƨ�node�� 
	pnode->data = student;
	//(*pnode).data = student;
	
	// �]�w�o�ӫ��Ъ��U�@��node���� 
	pnode->next = NULL;
	return pnode;
}

void printStudent(student_t student)
{
	printf("id=%d, score=%d\n", student.id, student.score);
} 

void printNode(pnode_t pnode)
{
	printStudent(pnode->data); 
} 

void insertFromFront(ppnode_t head, student_t data)
{
	pnode_t node = createNode(data);
	if(*head == NULL){
		*head = node;
	}else{
		node->next = *head;
		*head = node;
	} 
} 

void insertFromBack(ppnode_t head, student_t data)
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
	while(pnode!=NULL){
		printNode(pnode);
		pnode = pnode->next;
	}
} 

student_t delFromFront(ppnode_t head)
{
	student_t student;
	if(*head != NULL){
		pnode_t next = (*head)->next;
		student = (*head)->data;
		free(*head);
		*head = next;
	}
	return student;
}

// �q�᭱�R��
student_t delFromBack(ppnode_t head)
{
	student_t student;
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
void insert(ppnode_t head, student_t data, int index){
	int i;
	for(i=0;i<index;i++){
		pnode_t pnode = (*head);
		head = &(pnode->next);
	}
	pnode_t pnode = createNode(data);
	pnode->next = *head;
	*head = pnode;
}

student_t del(ppnode_t head, int index){
	student_t student;
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

