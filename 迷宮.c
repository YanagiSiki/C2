#include<stdio.h>
#include<string.h>
int main(){
    char ch[500][500]={};
    int i;
    int len=0,x=0,y=0,crossx[10]={},crossy[10]={};
    int crossi=0,back=0,tmp=0;

    gets(ch[0]);

    len=(strlen(ch[0])+1)/2;
    for(i=1;i<len;i++){
        gets(ch[i]);
    }


    x=1,y=2;

        //printf("\n");

    /*for(i=0;i<len;i++){
        printf("%s\n",ch[i]);
        }*/
    while(1){
        while(1){
            ch[x][y]='#';
            //log cross
            if(ch[x+1][y]=='0'){//Down
                ch[x+1][y]='#';
                x+=1;
                continue;
            }
            if(ch[x-1][y]=='0'){//Up
                ch[x-1][y]='#';
                x-=1;
                continue;
            }
            if(ch[x][y-2]=='0'){//Left
                ch[x][y-2]='#';
                y-=2;
                continue;
            }
            if(ch[x][y+2]=='0'){//Right
                ch[x][y+2]='#';
                y+=2;
                continue;
            }
            //printf("%c",ch[x][y]);
            if(ch[len-2][2*(len-2)]=='#')break;
            if(ch[x+1][y]!='0' && ch[x-1][y]!='0' && ch[x][y-2]!='0' && ch[x][y+2]!='0'){
                break;
            }
        }
            /*for(i=0;i<len;i++){
                printf("%s\n",ch[i]);
                }
                printf("\n");*/
            //printf("%d,%d\n",x,y);

        if(ch[len-2][2*(len-2)]=='#')break;
        ch[x][y]='*';
        while(1){
            //printf("%d,%d\n",x,y);
            if(ch[x+1][y]=='0' || ch[x-1][y]=='0' || ch[x][y-2]=='0' || ch[x][y+2]=='0'){
                break;
            }
            if(ch[x][y+2]=='#'){//Right
                ch[x][y+2]='*';
                y+=2;
                continue;
            }
            if(ch[x][y-2]=='#'){//Left
                ch[x][y-2]='*';
                y-=2;
                continue;
            }
            if(ch[x-1][y]=='#'){//Up
                ch[x-1][y]='*';
                x-=1;
                continue;
            }
            if(ch[x+1][y]=='#'){//Down
                ch[x+1][y]='*';
                x+=1;
                continue;
            }
        }
    }

    for(i=0;i<len;i++){
        printf("%s\n",ch[i]);
    }



}
