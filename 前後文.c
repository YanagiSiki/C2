#include<stdio.h>
void prL(char ans[500][500],int anscount){
    int i,j;
    int tmp[500]={};
    for(i=0;i<anscount;i++){
        for(j=0;j<anscount;j++){
            if(i!=j){
                if(strcmp(ans[i],ans[j])<0){
                    strcpy(tmp,ans[i]);
                    strcpy(ans[i],ans[j]);
                    strcpy(ans[j],tmp);
                }
            }
        }
    }
}
void prR(char ans[500][500],int anscount,char target[500]){
    char *str1,*str2;
    int i,j;
    int tmp[500]={};
    for(i=0;i<anscount;i++){
        for(j=i+1;j<anscount;j++){
            if(i!=j){
                str1=strstr(ans[i],target)+strlen(target)+1;
                str2=strstr(ans[j],target)+strlen(target)+1;
                if(strcmp(str1,str2)>0){
                    strcpy(tmp,ans[i]);
                    strcpy(ans[i],ans[j]);
                    strcpy(ans[j],tmp);
                }

            }
        }
    }
}
int Thesame(char article[500][500],char target[500],int count,int n,char ans[500][500],int *anscount){
    int length=strlen(target);
    int tmp=0;
    int same=0;
    int i=0;
//
    //printf("%s\n",article[i]);

    while(length>=0 && target[tmp]!='\0'){
        length--;
        if(article[count][tmp]==target[tmp]+32){
           same++;
        }
        tmp++;
    }
//
    //printf("%d",same);
    if(same==strlen(target)){
        for(i=0;i<n;i++){
            if(count-n+i<0)continue;
            strcat(ans[*anscount],article[count-n+i]);
            strcat(ans[*anscount]," ");
        }
        strcat(ans[*anscount],target);
        for(i=1;i<=n;i++){
            if(article[count+i][0]=='\0')break;
            strcat(ans[*anscount]," ");
            strcat(ans[*anscount],article[count+i]);
        }
        //printf("%s *%d*\n",ans[*anscount],*anscount);
        (*anscount)++;
    }
//


}
int main(){
    char target[500]={},input[500]={},article[500][500]={},ans[500][500]={};
    char RL,*test;
    int n=0;
    int count=0,same=0,anscount=0;
    int i=0,j=0,k=0;
//
    scanf("%s%*c%d%*c%c%*c",target,&n,&RL);
//
    for(i=0;target[i]!='\0';i++){
        if(target[i]>='a' && target[i]<='z')target[i]=target[i]-32;
    }

//
    gets(input);
    for(i=0;input[i]!='\0';i++){
        if(input[i]>='A' && input[i]<='Z')input[i]=input[i]+32;
    }
    //printf("%s\n",input);
//
    test=strtok(input," ");
    while(test!=NULL){
        strcpy(article[count],test);
        test=strtok(NULL," ");
        count++;
    }
//for(vocAmount=0;symbol!='\n';vocAmount++) scanf("%s%c",vocabulary[vocAmount],&symbol);


//
    /*while(i>=0){
        printf("%s \n",article[i]);
        i--;
    }*/

    while(count>0){
        count--;
        same=0;
        if(strlen(target)==strlen(article[count])){
            Thesame(article,target,count,n,ans,&anscount);
        }
    }
//
    if(RL=='R')prR(ans,anscount,target);
    if(RL=='L')prL(ans,anscount);


//
    while(j<anscount){
        printf("%s\n",ans[j]);
        j++;
    }



}
