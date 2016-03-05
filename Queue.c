#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list_s{
    int data;
    struct list_s * next;
}list_t;
typedef list_t * plist_t;

int size(plist_t head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}

void MergeQueue(plist_t *head1,plist_t *head2){
    plist_t p=(plist_t)malloc(sizeof(list_t)),tmp=(plist_t)malloc(sizeof(list_t));
    tmp=*head1;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=*head2;
}

void DeQueue(plist_t *head){//delete from front
    plist_t p=(plist_t)malloc(sizeof(list_t)),tmp=(plist_t)malloc(sizeof(list_t));
    if(*head==NULL){
        printf("Queue is empty\n");
        return;
    }
    tmp=(*head)->next;
    //free(*head);
    (*head)->next=tmp;

}

void PrintAllQueue(plist_t head){
    int elementcount;
    elementcount=size(head);
    printf(" Queue Size:%d Queue Element:",elementcount);
    while(head!=NULL){
        printf("%d",head->data);
        head = head->next;
        if(head==NULL)printf("\n");
        else printf(" ");
    }
}

void EnQueue(plist_t *head){//insert from back
    plist_t p=(plist_t)malloc(sizeof(list_t)),tmp=(plist_t)malloc(sizeof(list_t));
    scanf("%d",&(p->data));

    p->next=NULL;
    tmp=*head;
    if(*head==NULL){
        *head=p;
    }
    else{
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=p;
    }
}

int main(){
    plist_t head[100]={};
    char x,name[100][100]={},name_tmp1[100]={},name_tmp2[100]={};
    int queue_count=0,i,j,br=0,elementcount=0;

    while(1){
        scanf("%c",&x);
        if(x=='1'){
            head[queue_count]=NULL;
            scanf(" %s",name[queue_count]);
            queue_count++;
        }
        else if(x=='2'){
            scanf(" %s",name_tmp1);
            for(i=0;i<queue_count;i++){
                if(strcmp(name[i],name_tmp1)==0){
                   EnQueue(&(head[i]));
                    break;
                }
                else if(i==queue_count-1)printf("Queue %s isn't exist\n",name_tmp1);
            }
        }
        else if(x=='3'){
            scanf(" %s",name_tmp1);
            for(i=0;i<queue_count;i++){
                if(strcmp(name[i],name_tmp1)==0 && head[i]!=NULL){
                    DeQueue(&(head[i]));
                    strcpy(name[i],"");
                    //queue_count--;
                    break;
                }
                else if(i==queue_count-1)printf("Queue is empty\n");
            }
        }
        else if(x=='4'){
            scanf(" %s",name_tmp1);
            scanf(" %s",name_tmp2);
            for(i=0;i<queue_count;i++){
                for(j=0;j<queue_count;j++){
                    if(strcmp(name_tmp1,name[i])==0 && strcmp(name_tmp2,name[j])==0){
                        MergeQueue(&(head[i]),&(head[j]));
                        strcpy(name[j],"");
                        break;
                    }
                    else if(strcmp(name_tmp1,name[j])==0 && strcmp(name_tmp2,name[i])==0){
                        MergeQueue(&(head[j]),&(head[i]));
                        strcpy(name[i],"");
                        break;
                    }
                    if(i==queue_count-1 && j==queue_count-1)printf("Queue %s isn't exist\n", name_tmp1);
                }
            }

        }
        else if(x=='5'){
            printf("****************************************\n");
            if(queue_count==0)printf("Isn't have any queue\n");
            else{
                for(i=0;i<queue_count;i++){
                    if(name[i][0]!='\0'){
                        printf("Queue Name:%s",name[i]);
                        PrintAllQueue(head[i]);
                    }
                }
            }
            printf("****************************************\n");
        }
        else if(x=='6')return;

    }


}
