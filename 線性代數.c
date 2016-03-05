#include<stdio.h>
int main(){
    int i,j,k,o,p;
    int n;
    scanf("%d",&n);
    double x[n][n+1];

    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            scanf("%lf",&x[i][j]);
        }
    }

    for(o=0;o<n;o++){
        for(p=0;p<n+1;p++){
            printf("%.3lf  ",x[o][p]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j&&x[j][i]!=0){
                for(k=n;k>=i;k--){
                    x[j][k]=x[j][k]-x[i][k]/x[i][i]*x[j][i];
                }
                for(o=0;o<n;o++){
                    for(p=0;p<n+1;p++){
                        printf("%.3lf  ",x[o][p]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }

    /*for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf  ",x[i][j]);
        }
    }*/

    printf("\n");


    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            if(i==j)printf("%.3lf  \n",x[i][n]/x[i][i]);
        }
    }




}
