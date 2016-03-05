#include<stdio.h>
int f(int i){
    if(i==1)return 1;
    if(i%2==1){
        i=3*i+1;
        return f(i)+1;
    }
    if(i%2==0){
        i=i/2;
        return f(i)+1;
    }
}



int main(){
    int m=0,n=0;
    int i=0;
    int tmp=0;
    int max=0;


    while(1){
        max=0;
        tmp=0;
        if(scanf("%d %d",&n,&m)==EOF)break;
        printf("%d %d",n,m);
        if(m<n){
            tmp=m;
            m=n;
            n=tmp;
        }
        for(i=m;i>=n;i--){
                tmp=f(i);
                if(tmp>max)max=tmp;
            }
            printf(" %d\n",max);
    }


}
