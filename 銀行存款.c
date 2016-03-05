#include<stdio.h>
int main(){
    char c,ch;
    double a=0,b=0,num=0;
    while(1){
        scanf("%c",&c);
        if(c=='-')break;
        if(c=='w'){
            scanf(" %c",&ch);
            if(ch=='a'){
                scanf("%lf",&num);
                a=a-num;
            }
            else{
                scanf("%lf",&num);
                b=b-num;
            }
        }

        if(c=='s'){
            scanf(" %c",&ch);
            if(ch=='a'){
                scanf("%lf",&num);
                a=a+num;
            }
            else{
                scanf("%lf",&num);
                b=b+num;
            }
        }

        if(c=='v')printf("A : %.0lf, B : %.0lf\n",a,b);
        if(c=='p'){
            if(a<=0){
                printf("A : 0.0%%,");
            }
            else if((a+b)!=0)printf("A : %.1lf%%,",a/(a+b)*100);
            else printf("A : 100.0%%,");

            if(b<=0){
                printf(" B : 0.0%%\n");
            }
            else if((a+b)!=0)printf(" B : %.1lf%%\n",b/(a+b)*100);
            else printf(" B : 100.0%%\n");
        }
    }

    return 0;
}
