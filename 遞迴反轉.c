#include<stdio.h>
#include<string.h>
char reversedString(char *s1, char *s2){
    if(*s1=='\0')return ;
    s1++;
    reversedString(s1,s2);
    strncat(s2,s1-1,1);
    //printf("%s",s2);
    return ;
}
void reversedSentence(char ch[500][500], char ans[500][500],int i,int n){
    if(i==0)return;
    i--;
    reversedSentence(ch,ans,i,n);
    strcpy(ans[n-i],ch[i]);
    return;

}

int main(){
    char input[500]={},ch[500][500]={},ans[500][500]={};
    char *test;
    int i=0,j=0;

    while(1){
        char input[500]={},ch[500][500]={},ans[500][500]={};
        int i=0,j=0;

        gets(input);
        if(strcmp(input,"-1")==0)break;
//
        test=strtok(input," ");
        while (test != NULL) {
            strcpy(ch[i],test);
            test = strtok(NULL, " ");
            i++;
        }
//
        if(i==1){
            reversedString(ch,ans);
            printf("%s\n",ans);
        }
//
        if(i>1){
            reversedSentence(ch[0],ans[0],i,i-1);
            printf("%s",ans[0]);
            j++;
            while(j<i){
                printf(" %s",ans[j]);
                j++;
            }
            printf("\n");
        }

    }




}
