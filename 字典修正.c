#include <stdio.h>
#include <string.h>

int correct(char *input_article,char *input_dictionary){
    char tmp1[500]={},tmp2[500]={};
    int article_len=0,dictionary_len=0;
    int i,j,k;
    int difference_count=0,dc=0,tmp=999;
    char *p1=tmp1,*p2=tmp2;

    if(strlen(input_article)>=strlen(input_dictionary)){
        strcpy(tmp1,input_article);
        strcpy(tmp2,input_dictionary);
    }
    else{
        strcpy(tmp1,input_dictionary);
        strcpy(tmp2,input_article);
    }
    article_len=strlen(p1);
    dictionary_len=strlen(p2);
    difference_count=article_len-dictionary_len;
    for(i=0;tmp1[i]!='\0';i++){
        difference_count=article_len-dictionary_len;
        for(j=0;tmp2[j]!='\0';j++){
            if(p1[j]!=p2[j] && p1[j]!=p2[j]-'a'+'A' && p1[j]!=p2[j]-'A'+'a') difference_count++;
        }
        if(difference_count<tmp)tmp=difference_count;
    }
    return tmp;


}

void check(char input_article[500][500],char input_dictionary[500][500],int num){
    int i,j,same=0,comma=0,period=0,find=0,times=0;
    for(i=0;input_article[i][0]!='\0';i++){
        same=comma=period=find=times=0;
        if(strstr(input_article[i],",")!=NULL){
            printf("%s",strtok(input_article[i],","));
            comma=1;
        }
        else if (strstr(input_article[i],".")!=NULL){
            printf("%s",strtok(input_article[i],"."));
            period=1;
        }
        else {
            printf("%s",input_article[i]);
        }
        for(j=0;input_dictionary[j][0]!='\0';j++){
            if(correct(input_article[i],input_dictionary[j])==0) same=1;
        }
        if(same==0){
            for(j=0;input_dictionary[j][0]!='\0';j++){
                if(correct(input_article[i],input_dictionary[j])<=num){
                    find=1;
                    if(times==0) printf("(");
                    else printf(", ");
                    printf("%s",input_dictionary[j]);
                    times++;
                }
            }
        }
        if(find==1) printf(")");
        if(comma==1) printf(",");
        if(period==1) printf(".");
        if(input_article[i+1][0]!='\0') printf(" ");
    }
}

int main(){
    char input[500]={},*test;
    char input_dictionary[500][500]={},input_article[500][500]={};
    int num=0;
    int i=0;
//
    gets(input);
    test=strtok(input," ");
    for(i=0;test!=NULL;i++){
        strcpy(input_dictionary[i],test);
        test=strtok(NULL," ");
    }
//
    scanf("%d%*c",&num);
//

    for(i=0;input[i]!=NULL;i++)input[i]='\0';
    gets(input);
    test=strtok(input," ");
    for(i=0;test!=NULL;i++){
        strcpy(input_article[i],test);
        test=strtok(NULL," ");
    }
//

    check(input_article,input_dictionary,num);

}
