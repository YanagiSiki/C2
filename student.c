#include<stdio.h>
#include<string.h>
typedef struct student{
    int id;
    char phone[100];
}stu;
int main(){
    stu s[100]={};
    char input[100]={};
    int i,count=0;
    int n;
    int search=0;

    while(1){
        for(i=0;i<100;i++)input[i]='\0';
        scanf("%s",input);
        if(strcmp(input,"EXIT")==0)break;
//
        if(strcmp(input,"ADD")==0){
            scanf("%d %s",&s[count].id,&s[count].phone);
            count++;
        }
//
        if(strcmp(input,"EDIT")==0){
            scanf("%d ",&n);
            n--;
            if(s[n].phone=='\0' || n>=count || n<0)printf("error\n");
            else scanf("%s",&s[n].phone);
        }
//
        if(strcmp(input,"DELETE")==0){
            scanf("%d",&n);
            n--;
            if(s[n].phone=='\0' || n>=count || n<0)printf("error\n");
            else {
                for(i=0;i<count-n-1;i++){
                    s[n+i].id=s[n+1+i].id;
                    strcpy(s[n+i].phone,s[n+1+i].phone);
                }
                count--;
            }

        }
//
        if(strcmp(input,"INSERT")==0){
            scanf("%d ",&n);
            n--;
            if(s[n].phone=='\0' || n>=count || n<0)printf("error\n");
            else {
                for(i=0;i<count-n;i++){
                    s[count-i].id=s[count-1-i].id;
                    strcpy(s[count-i].phone,s[count-1-i].phone);
                }
                scanf("%d %s",&s[n].id,&s[n].phone);
                count++;
            }
        }
//
        if(strcmp(input,"SEARCH")==0){
            scanf("%d",&n);
            search=0;
            for(i=0;i<count;i++){
                if(s[i].id==n){
                    printf("%s\n",s[i].phone);
                    search=1;
                    break;
                }
            }
            if(search==0)printf("NULL\n");
        }
//
        if(strcmp(input,"PRINT")==0){
            if(count==0)printf("error\n");
            else{
                printf("********************\n");
				for(i=0;i<count;i++){
                    printf("id = %d, phone = %s\n",s[i].id,s[i].phone);
				}
				printf("********************\n");
            }
        }
    }

}
