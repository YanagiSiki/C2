#include<stdio.h>
typedef struct type_s{
    int x;
    struct type_s *next;
}type_t;
typedef type_t * ptype_t;

void printlist(ptype_t head){
    ptype_t p=(ptype_t)malloc(sizeof(type_t));
    p->next=NULL;
    while(head->next!=NULL){
        insertfront(&p,head->next->x);
        head=head->next;
    }
    printf("%d",p->next->x);
    p = p->next;
    while(p->next!=NULL){
        printf(" %d",p->next->x);
        p = p->next;
    }

	printf("\n");
}

void insertfront(ptype_t *head,int x){
    ptype_t p=(ptype_t)malloc(sizeof(type_t)),tmp=(ptype_t)malloc(sizeof(type_t));
    p->x=x;
    p->next=NULL;
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
    ptype_t head1=(ptype_t)malloc(sizeof(type_t));
    ptype_t head2=(ptype_t)malloc(sizeof(type_t));
    ptype_t p1=(ptype_t)malloc(sizeof(type_t));
    ptype_t p2=(ptype_t)malloc(sizeof(type_t));
    head1->next=NULL;
    head2->next=NULL;
    p1->next=NULL;
    p2->next=NULL;

    int x,count_head1=0,count_head2=0;
    char c;

    while(1){
        scanf("%d%c",&x,&c);
        insertfront(&head1,x);
        count_head1++;
        if(c=='\n')break;
    }
    //printlist(head1);
    while(1){
        scanf("%d%c",&x,&c);
        insertfront(&head2,x);
        count_head2++;
        if(c=='\n')break;
    }
    //printlist(head2);
    p1=head1;
    p2=head2;
    while(1){
        if(p1->next==NULL || p2->next==NULL)break;
        if(count_head1>=count_head2){
            p1->next->x=p1->next->x+p2->next->x;
            p1=p1->next;
            p2=p2->next;
        }
        else{
            p2->next->x=p1->next->x+p2->next->x;
            p2=p2->next;
            p1=p1->next;
        }
    }
    if(count_head1>=count_head2){
        printlist(head1);
    }
    else printlist(head2);
}
