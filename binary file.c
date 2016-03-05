#include<stdio.h>
#include<string.h>
typedef struct _file {
    char name[100];
    int list[100][8];
    int count;
}File;

void tomatrix(int input,int matrix[100][8],int count){
    int i=0;
    int base=1;
    int inputtmp=input;
    while(1){
        if(inputtmp==1)break;
        inputtmp=inputtmp/2;
        i++;
        base=base*2;
    }
    //printf("%d %d",i,base);
    while(i>=0){
        matrix[count][i]=input/base;
        if(input>=base)input=input-base;
        base=base/2;
        i--;
    }
}
int main(){
    File data[100];
    int choose;
    char file_name[100]={};
    int file_count=0;
    int input;
    int i,j,k;
    int target,change;
    int m,n;
    int tmp=0;
    int br=0;

    while(1){
        printf("(1)write(2)read(3)change(4)exit\n");
        scanf("%d",&choose);

        if(choose==1){
            printf("Input file name:\n");
            scanf("%s%*c",file_name);
            br=0;
            for(i=0;i<file_count;i++){
                if(strcmp(file_name,data[i].name)==0){
                    while(1){
                        scanf("%d",&input);
                        if(input==-1)break;
                        if(input==0){
                            data[i].count++;
                            continue;
                        }
                        tomatrix(input,data[i].list,data[i].count);
                        data[i].count++;
                    }
                    br=1;
                    tmp=i;
                    break;
                }
            }
            if(br==0){
                strcpy(data[file_count].name,file_name);
                for(i=0;i<100;i++){
                    for(j=0;j<8;j++){
                        data[file_count].list[i][j]=0;
                    }
                }
                data[file_count].count=0;
                while(1){
                    scanf("%d",&input);
                    if(input==-1)break;
                    if(input==0){
                        data[file_count].count++;
                        continue;
                    }
                    tomatrix(input,data[file_count].list,data[file_count].count);
                    data[file_count].count++;
                }
                tmp=file_count;
                file_count++;
            }
        }

        else if(choose==2){
            printf("Input file name:\n");
            scanf("%s%*c",file_name);
            br=0;
            for(i=0;i<file_count;i++){
                if(strcmp(file_name,data[i].name)==0){
                    printf("size = %d bytes\n",data[i].count);
                    for(j=0;j<data[i].count;j++){
                        for(k=7;k>=0;k--)printf("%d ",data[i].list[j][k]);
                        printf("\n");
                    }
                    br=1;
                    tmp=i;
                    break;
                }
            }
            if(br==0)printf("size = 0 bytes\n");
        }
        else if(choose==3){
            printf("Input n bits\n");
            scanf("%d",&target);
            printf("Input value\n");
            scanf("%d",&change);
            m=target/8;
            n=target%8;
            data[tmp].list[m][n]=change;
            for(j=0;j<data[tmp].count;j++){
                for(k=7;k>=0;k--)printf("%d ",data[tmp].list[j][k]);
                    printf("\n");
            }
        }
        else break;

    }
}
