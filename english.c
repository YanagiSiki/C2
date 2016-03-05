#include<stdio.h>
#include<string.h>
void f(char string[3][500]){
    char tmp[3][500]={};
    char mains[][10] = {"I", "He", "She", "They", "Mary", "John"};
    char so[][10]={"me", "him", "her", "them", "Mary", "John"};
    char verbs[][10] = {"love", "like", "see", "find"};
    int i,j,k,br=0;
//
    for(i=0;i<3;i++){
        for(j=0;j<6;j++){
            if(strcmp(string[i],mains[j])==0){
                strcpy(tmp[0],string[i]);
                for(k=0;k<500;k++)string[i][k]='\0';
                br=1;
                break;
            }
        }
        if(br==1)break;
    }
    br=0;
//
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(strcmp(string[i],verbs[j])==0){
                strcpy(tmp[1],string[i]);
                for(k=0;k<500;k++)string[i][k]='\0';
                br=1;
                break;
            }
        }
        if(br==1)break;
    }
    br=0;
//
    for(i=0;i<3;i++){
        for(j=0;j<6;j++){
                if(strcmp(string[i],so[j])==0){
                strcpy(tmp[2],string[i]);
                for(k=0;k<500;k++)string[i][k]='\0';
                br=1;
                break;
            }
        }
        if(br==1)break;
    }
    br=0;
//
    if(strcmp(tmp[0],"I")==0 && strcmp(tmp[2],"me")==0)printf("%s %s myself\n",tmp[0],tmp[1]);
    else if((strcmp(tmp[0],"John")==0 && strcmp(tmp[2],"Mary")==0) || (strcmp(tmp[2],"John")==0 && strcmp(tmp[0],"Mary")==0))printf("%s %ss %s or %s %ss %s\n",tmp[0],tmp[1],tmp[2],tmp[2],tmp[1],tmp[0]);
    else if(strcmp(tmp[0],"He")==0 || strcmp(tmp[0],"She")==0 || strcmp(tmp[0],"John")==0 || strcmp(tmp[0],"Mary")==0)printf("%s %ss %s\n",tmp[0],tmp[1],tmp[2]);
    else if((strcmp(tmp[0],"John")==0 || strcmp(tmp[0],"He")==0) && strcmp(tmp[2],"him")==0)printf("%s %ss himself\n",tmp[0],tmp[1]);
    else if((strcmp(tmp[0],"Mary")==0 ||strcmp(tmp[0],"She")==0)&& strcmp(tmp[2],"her")==0)printf("%s %ss herself\n",tmp[0],tmp[1]);
    else if(strcmp(tmp[0],"They")==0 && strcmp(tmp[2],"them")==0)printf("%s %s themselves\n",tmp[0],tmp[1]);
    else printf("%s %s %s\n",tmp[0],tmp[1],tmp[2]);



}
int main(){
    char string[3][500];
    int n,i;

    scanf("%d",&n);

    while(n>0){
        for(i=0;i<3;i++){
            scanf("%s",string[i]);
        }
        f(string);
        n--;
    }


}
