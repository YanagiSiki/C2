#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    int score;
} student_t;
typedef struct node {
    student_t data;
    struct node *next;
} node_t;

typedef node_t * nodep_t;

void delFromBack(nodep_t *head){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    tmp=*head;
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    //free(tmp->next);
    tmp->next=NULL;


}
void delFromFront(nodep_t *head){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    tmp->next=(*head)->next->next;
    (*head)->next=tmp->next;
    free(NULL);
}
void insertFromFront(nodep_t *head, student_t data){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    p->next=NULL;
    p->data=data;
    if((*head)->next==NULL){
        (*head)->next=p;
    }
    else{
        tmp->next=(*head)->next;
        (*head)->next=p;
        p->next=tmp->next;
    }
}
void insertFromBack(nodep_t *head, student_t data){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    p->next=NULL;
    p->data=data;
    tmp=*head;
    if((*head)->next==NULL){
        (*head)->next=p;
    }
    else{
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=p;
    }
}
void printList(nodep_t head){
    if(head->next==NULL)printf("null\n");
    else{
        while(head->next!=NULL){
            printf("%d,%d",head->next->data.id,head->next->data.score);
            head = head->next;
            if(head->next==NULL)printf("\n");
            else printf(" ");
        }
    }
}

int main(){
    student_t data;
    nodep_t head=(nodep_t)malloc(sizeof(node_t));
    char c;
    head->next=NULL;
    int n;
    while(1){
        n=scanf("%c%*c",&c);
        if(n==-1) break;
        if(c=='p')printList(head);
        else if(c=='i'){
            scanf("%c%*c",&c);
            scanf("%d,%d%*c",&data.id,&data.score);
            if(c=='f')insertFromFront(&head,data);
            else if(c=='b')insertFromBack(&head,data);
        }
        else if(c=='d'){
            scanf("%c%*c",&c);
            if(head->next==NULL){
                printf("error\n");
                continue;
            }
            else if(c=='f')delFromFront(&head);
            else if(c=='b')delFromBack(&head);
        }
        else break;
    }


}
