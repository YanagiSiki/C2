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


void insert(nodep_t *head, student_t data){
    nodep_t p=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    p->next=NULL;
    p->data=data;
    tmp->next=(*head)->next;
    (*head)->next=p;
    p->next=tmp->next;
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
    nodep_t head=(nodep_t)malloc(sizeof(node_t)),tmp=(nodep_t)malloc(sizeof(node_t));
    char c;
    head->next=NULL;

    int n;

    while(1){
        n=scanf("%c%*c",&c);
        if(n==-1) break;
        if(c=='p')printList(head);
        else if(c=='i'){
            scanf("%d,%d%*c\n",&data.id,&data.score);
            tmp=head;
            while(tmp->next!=NULL){
                if(tmp->next->data.score>=data.score){
                    if(tmp->next->data.score!=data.score)break;
                    if(tmp->next->data.score==data.score && tmp->next->data.id<data.id){
                        //printf("%d\n",tmp->next->data.id);
                        tmp=tmp->next;
                        continue;
                    }
                    if(tmp->next->data.score==data.score && tmp->next->data.id>data.id){
                        break;
                    }
                }
                else tmp=tmp->next;
            }
            if(tmp->next!=NULL){
                //printf("insert\n");
                insert(&tmp,data);
            }
            if(tmp->next==NULL){
                //printf("insertFromBack\n");
                insertFromBack(&tmp,data);
            }
        }
        else break;
    }


}
