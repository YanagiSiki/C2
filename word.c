#include<stdio.h>
#include<string.h>
void change(char vocabulary[][500],int x[]){//to change and print
    char changevocabulary[500][500];
    int changex[500];
    int i=0,j=0,k=0,tmpx=0;

    for(i=0;i<500;i++){
        for(j=0;j<500;j++){
            changevocabulary[i][j]=vocabulary[i][j];
        }
        changex[i]=x[i];
    }
    char tmp[500]={};

    for(i=0;i<500;i++){
        for(j=i;j<500;j++){
            if(changex[i]!=0 && i!=j){
                if(changex[j]>changex[i]){
                    for(k=0;k<500;k++){
                        tmp[k]=changevocabulary[i][k];
                        changevocabulary[i][k]=changevocabulary[j][k];
                        changevocabulary[j][k]=tmp[k];
                    }
                    tmpx=changex[i];
                    changex[i]=changex[j];
                    changex[j]=tmpx;
                }
                else if(changex[i]==changex[j]){
                    if(strcmp(changevocabulary[i],changevocabulary[j])>0){
                        for(k=0;k<500;k++){
                        tmp[k]=changevocabulary[i][k];
                        changevocabulary[i][k]=changevocabulary[j][k];
                        changevocabulary[j][k]=tmp[k];
                        }
                    }

                }
            }
        }
        if(x[i]!=0)printf("%s [%d]\n",changevocabulary[i],changex[i]);
    }
}


void finsert(char vocabulary[][500],char x[],char target[],char insert[]){//insert the char
    int i,j,k,same;
    printf("%s",vocabulary[0]);
    for(i=1;i<500;i++){
            same=0;
            for(j=0;j<500;j++){
                if(vocabulary[i][j]==target[j]){
                    same++;
                }
            }
            if(same==500){
                printf(" %s %s",insert,vocabulary[i]);
            }
            if(same!=500 && vocabulary[i][0]!='\0'){
                printf(" %s",vocabulary[i]);
            }
    }

    printf("\n");

}


void freplace(char vocabulary[][500],char x[],char target[],char insert[]){//replace the target
    int i,j,k,same;
    printf("%s",vocabulary[0]);
    for(i=1;i<500;i++){
            same=0;
            for(j=0;j<500;j++){
                if(vocabulary[i][j]==target[j]){
                    same++;
                }
            }
            if(same==500){
                printf(" %s",insert);
            }
            if(same!=500 && vocabulary[i][0]!='\0'){
                printf(" %s",vocabulary[i]);
            }
    }

    printf("\n");


}



void delete(char vocabulary[][500],char x[],char target[],char insert[]){//delete the target
    int i,j,k,same;
    printf("%s",vocabulary[0]);
    for(i=1;i<500;i++){
            same=0;
            for(j=0;j<500;j++){
                if(vocabulary[i][j]==target[j]){
                    same++;
                }
            }
            if(same!=500 && vocabulary[i][0]!='\0'){
                printf(" %s",vocabulary[i]);
            }
    }
    printf("\n");

}



void frequency(char c[],char target[],char insert[]){//count each vocabulary
    char vocabulary[500][500]={},tmp[500]={};
    int i=0,j=0,NO=0,x[500]={},same=0,m,n;

    while(c[i]!='\0'){
        if(c[i]==' ')i++;
        for(j=0;j<500;j++)tmp[j]='\0';

        for(j=0;c[i]!=' '&& c[i]!='\0';j++){
            tmp[j]=c[i];
            i++;
        }
        if(tmp[0]!='\0' && tmp[0]!=' '){
            for(m=0;m<NO;m++){
                same=0;
                for(n=0;n<500;n++){
                    if(vocabulary[m][n]==tmp[n])same++;
                }
                if(same==500){
                    x[m]++;
                    break;
                }
            }

            if(same!=500)x[NO]++;

            for(j=0;j<500;j++){
                vocabulary[NO][j]=tmp[j];
            }
            NO++;
        }

    }

    change(vocabulary,x);
    freplace(vocabulary,x,target,insert);
    finsert(vocabulary,x,target,insert);
    delete(vocabulary,x,target,insert);
    //for(i=0;i<500;i++)printf("%d",x[i]);
}


int main(){
    char c[500]={},target[500]={},insert[500]={};
    int x[500],i=0,j,NO=0;
    gets(c);
    gets(target);
    gets(insert);
    //printf("%s",c);
    frequency(c,target,insert);
}
