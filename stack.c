#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float data;
    struct node *next;
} node_t;

typedef node_t * nodep_t;


void delFromFront(nodep_t *head){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    tmp->next=(*head)->next->next;
    (*head)->next=tmp->next;
    free(NULL);
}
void insertFromFront(nodep_t *head,float data){
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

int main(){
    float data;
    nodep_t head=(nodep_t)malloc(sizeof(node_t));
    char c;
    head->next=NULL;

    while(1){
        scanf("%c%*c",&c);
        if(c=='1'){
            scanf("%f%*c",&data);
            insertFromFront(&head,data);
        }
        if(c=='2'){
            if(head->next==NULL){
                printf("The Stack is empty\n");
                continue;
            }
            printf("The data %.2f is pop\n",head->next->data);
            delFromFront(&head);
        }
        if(c=='3') break;
    }
}
