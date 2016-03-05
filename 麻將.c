#include<stdio.h>
void f(int *tmp){
    int i;
    for(i=0;i<7;i++){
        if(tmp[i]>0 && tmp[i+1]>0 && tmp[i+2]>0){
            tmp[i]--;
            tmp[i+1]--;
            tmp[i+2]--;
            //i--;
        }
    }

    for(i=9;i<16;i++){
        if(tmp[i]>0 && tmp[i+1]>0 && tmp[i+2]>0){
            tmp[i]--;
            tmp[i+1]--;
            tmp[i+2]--;
            //i--;
        }
    }

    for(i=18;i<25;i++){
        if(tmp[i]>0 && tmp[i+1]>0 && tmp[i+2]>0){
            tmp[i]--;
            tmp[i+1]--;
            tmp[i+2]--;
            //i--;
        }
    }

}
void triple(int *tmp){
    int i;
    for(i=0;i<34;i++){
        if(tmp[i]==3){
            tmp[i]-=3;
        }
    }

    for(i=0;i<34;i++){
        if(tmp[i]==2){
            tmp[i]-=2;
        }
    }
}
int main(){
    int x[17]={},all[34]={},tmp[34]={};
    int i,check=0;

    for(i=0;i<17;i++){
        scanf("%d",&x[i]);
        all[x[i]]++;
        tmp[x[i]]=all[x[i]];
    }
    //return x[0];
//
    f(tmp);
    triple(tmp);
//

    for(i=0;i<34;i++){
        if(tmp[i]>0){
            check=1;
        }
    }

    if(check==1){
        for(i=0;i<17;i++){
            tmp[x[i]]=all[x[i]];
        }
        triple(tmp);
        f(tmp);
    }

    for(i=0;i<34;i++){
        if(tmp[i]>0){
            printf("0\n");
            return;
        }
    }

    printf("1\n");
    return ;


}
