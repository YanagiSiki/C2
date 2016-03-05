#include<stdio.h>//Computer(1)、Player(0)
void d(int x[3][3]){//即將要獲勝
    int com=0,play=0,space=0;//space=0,com=1,play=2
    int i,j;
    for(i=0;i<3;i++){//橫的
        com=0,play=0,space=0;
        for(j=0;j<3;j++){
            if(x[i][j]==0)space++;
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==2){
            for(j=0;j<3;j++){
                if(x[i][j]==0)printf("Computer will win with (%d, %d)\n",i,j);
            }
        }
        if(play==2){
            for(j=0;j<3;j++){
                if(x[i][j]==0)printf("Player will win with (%d, %d)\n",i,j);
            }
        }
    }


    for(j=0;j<3;j++){//直的
        com=0,play=0,space=0;
        for(i=0;i<3;i++){
            if(x[i][j]==0)space++;
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==2){
            for(i=0;i<3;i++){
                if(x[i][j]==0)printf("Computer will win with (%d, %d)\n",i,j);
            }
        }
        if(play==2){
            for(i=0;i<3;i++){
                if(x[i][j]==0)printf("Player will win with (%d, %d)\n",i,j);
            }
        }
    }




    for(i=0;i<3;i++){//左上右下
        com=0,play=0,space=0;
        if(x[i][i]==0)space++;
        if(x[i][i]==1)com++;
        if(x[i][i]==2)play++;
    }
    if(com==2){
        for(i=0;i<3;i++){
            if(x[i][i]==0)printf("Computer will win with (%d, %d)\n",i,i);
        }
    }
    if(play==2){
        for(i=0;i<3;i++){
            if(x[i][i]==0)printf("Player will win with (%d, %d)\n",i,i);
        }
    }


    for(i=2;i>=0;i--){//左上右下
        com=0,play=0,space=0;
        if(x[i][2-i]==0)space++;
        if(x[i][2-i]==1)com++;
        if(x[i][2-i]==2)play++;
    }
    if(com==2){
        for(i=2;i>=0;i--){
            if(x[i][2-i]==0)printf("Computer will win with (%d, %d)\n",i,2-i);
        }
    }
    if(play==2){
        for(i=2;i>=0;i--){
            if(x[i][2-i]==0)printf("Player will win with (%d, %d)\n",i,2-i);
        }
    }
}


void w(int x[3][3]){//即將要獲勝
    int com=0,play=0,space=0;//space=0,com=1,play=2
    int i,j;
    for(i=0;i<3;i++){//橫的
        com=0,play=0,space=0;
        for(j=0;j<3;j++){
            if(x[i][j]==0)space++;
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==2){
            for(j=0;j<3;j++){
                if(x[i][j]==0)printf("Computer will win with (%d, %d)\n",i,j);
            }
        }

    }


    for(j=0;j<3;j++){//直的
        com=0,play=0,space=0;
        for(i=0;i<3;i++){
            if(x[i][j]==0)space++;
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==2){
            for(i=0;i<3;i++){
                if(x[i][j]==0)printf("Computer will win with (%d, %d)\n",i,j);
            }
        }

    }




    for(i=0;i<3;i++){//左上右下
        com=0,play=0,space=0;
        if(x[i][i]==0)space++;
        if(x[i][i]==1)com++;
        if(x[i][i]==2)play++;
    }
    if(com==2){
        for(i=0;i<3;i++){
            if(x[i][i]==0)printf("Computer will win with (%d, %d)\n",i,i);
        }
    }


    for(i=2;i>=0;i--){//右上左下
        com=0,play=0,space=0;
        if(x[i][2-i]==0)space++;
        if(x[i][2-i]==1)com++;
        if(x[i][2-i]==2)play++;
    }
    if(com==2){
        for(i=2;i>=0;i--){
            if(x[i][2-i]==0)printf("Computer will win with (%d, %d)\n",i,2-i);
        }
    }

}

int winf(int x[3][3]){//獲勝
    int com=0,play=0,space=0;//space=0,com=1,play=2
    int i,j;
    for(i=0;i<3;i++){//橫的
        com=0,play=0,space=0;
        for(j=0;j<3;j++){
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==3){
            printf("Computer win\n");
            return 1;
        }
        if(play==3){
            printf("Player win\n");
            return 1;
        }
    }


    for(j=0;j<3;j++){//直的
        com=0,play=0,space=0;
        for(i=0;i<3;i++){
            if(x[i][j]==1)com++;
            if(x[i][j]==2)play++;
        }
        if(com==3){
            printf("Computer win\n");
            return 1;
        }
        if(play==3){
            printf("Player win\n");
            return 1;
        }
    }




    for(i=0;i<3;i++){//左上右下
        com=0,play=0,space=0;
        if(x[i][i]==1)com++;
        if(x[i][i]==2)play++;
    }
        if(com==3){
            printf("Computer win\n");
            return 1;
        }
        if(play==3){
            printf("Player win\n");
            return 1;
        }



    for(i=2;i>=0;i--){//右上左下
        com=0,play=0,space=0;
        if(x[i][2-i]==1)com++;
        if(x[i][2-i]==2)play++;
    }
    if(com==3){
            printf("Computer win\n");
            return 1;
        }
    if(play==3){
        printf("Player win\n");
        return 1;
    }
    return 0;
}


int main(){
    int x[3][3]={0};
    int first,win=0;
    char m;
    int i,j;
    int n;//space=0,com=1,play=2
    scanf("%d",&first);//Computer(1)、Player(0)
    while(1){
        scanf(" %c",&m);
        if(m!='w'&&m!='d'){
            scanf("%d",&n);
            //printf("%d %d",m-48,n);
            /*for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf("%d",x[i][j]);
                }
                printf("\n");
            }*/
            if(x[m-48][n]!=0)printf("input error\n");
            if(x[m-48][n]==0 && first%2==0)x[m-48][n]=2;
            if(x[m-48][n]==0 && first%2==1)x[m-48][n]=1;
        }
        /*for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf("%d",x[i][j]);
                }
                printf("\n");
            }*/
        if(m=='d')d(x);
        if(m=='w')w(x);
        win=winf(x);
        if(win==1)break;
        first++;
    }

}
