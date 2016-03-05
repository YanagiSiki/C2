#include<stdio.h>
#include<string.h>
#include<math.h>
int main (){
    int ans[10000]={},num=0,A=0,B=0;
    int tmpi=0,tmpnum=0,tmpA=0,tmpB=0;
    int i,j,k,base1=1000,base2=1000;
    int count=0;

    for(i=0;i<10000;i++)ans[i]=1;



    while(1){
        count=0;
        scanf("%d,%dA%dB",&num,&A,&B);
        //printf("%d",num);
        for(i=0;i<10000;i++){
            tmpi=i;
            tmpA=tmpB=0;
            base2=1000;
            for(j=3;j>=0;j--){
                tmpnum=num;
                base1=1000;
                for(k=3;k>=0;k--){
                    if((tmpi/base2)==(tmpnum/base1)){
                        if(j==k)tmpA++;
                        if(j!=k)tmpB++;
                    }
                    tmpnum=tmpnum%base1;
                    base1/=10;
                }
                tmpi=tmpi%base2;
                base2/=10;
            }
            if(tmpA!=A || tmpB!=B)ans[i]=0;
        }
        for(i=0;i<10000;i++){
            if((ans[i]==1) && (i%10!=(i%100)/10) && (i%10!=(i%1000)/100) && (i%10!=i/1000) && ((i%100)/10!=(i%1000)/100) && ((i%100)/10!=i/1000) && ((i%1000)/100!=i/1000)){
                //printf("%d\n",i);
                tmpi=i;
                count++;
            }
        }
        if(count==1)break;
    }


    printf("%d\n",tmpi);

}
