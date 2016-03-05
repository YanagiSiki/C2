#include<stdio.h>
#include<math.h>
int main(){
    int i=0,j=0,k=0;
    int n;

    scanf("%d",&n);
    double x[n][n+1];

    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            scanf("%lf",&x[i][j]);
        }
    }

    for(i=0;i<n;i++){
        printf("%.3lf X1",x[i][0]);
        for(j=1;j<n;j++){
            if(x[i][j]>=0)printf(" + %.3lf X%d",x[i][j],j+1);
            else printf(" - %.3lf X%d",fabs(x[i][j]),j+1);
        }
        printf(" = %.3lf\n",x[i][n]);
    }




    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                for(k=n;k>=i;k--){
                    x[j][k]=x[j][k]-x[i][k]/x[i][i]*x[j][i];
                }
            }
        }
    }

    /*for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf  ",x[i][j]);
        }
    }*/




    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            if(i==j)printf("X[%d] = %.3lf\n",i+1,x[i][n]/x[i][i]);
        }
    }

}
