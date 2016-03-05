#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(TYPE,TYPE)

typedef struct _Gate{
	GATEVALUE(int);
}Gate;

int GateAndValue(int in1,int in2){
    return in1*in2;
}
int GateOrValue(int in1,int in2){
    if(in1+in2==0)return 0;
    else return 1;
}
int GateNotValue(int in1,int in2){
    if(in1==0)return 1;
    else return 0;
}
int GateEmptyValue(int in1,int in2){
    if(in1==0)return 0;
    else return 1;
}

int CreateGateAND(Gate *obj){
	obj->GateValue = GateAndValue;
}
int CreateGateOr(Gate *obj){
	obj->GateValue = GateOrValue;
}
int CreateGateNot(Gate *obj){
	obj->GateValue = GateNotValue;
}
int CreateGateEmpty(Gate *obj){
	obj->GateValue = GateEmptyValue;
}

int main(){
    int x[3]={},out[3]={};
    int i,tmp=0;
    char ch[3]={};

    scanf("%d,%d,%d\n",&x[0],&x[1],&x[2]);
    scanf("%c,%c,%c",&ch[0],&ch[1],&ch[2]);

    Gate gate[3];

    if(ch[0]=='A'){
        CreateGateAND(&gate[0]);
    }
    if(ch[0]=='O'){
        CreateGateOr(&gate[0]);
    }
    if(ch[0]=='N'){
        CreateGateNot(&gate[0]);
    }
    if(ch[0]=='E'){
        CreateGateEmpty(&gate[0]);
    }
    out[0]=gate[0].GateValue(x[0],x[0]);
    tmp=out[0];
    //printf("%d",out[0]);
    for(i=1;i<3;i++){
        if(ch[i]=='A'){
            CreateGateAND(&gate[i]);
        }
        if(ch[i]=='O'){
            CreateGateOr(&gate[i]);
        }
        if(ch[i]=='N'){
            CreateGateNot(&gate[i]);
        }
        if(ch[i]=='E'){
            CreateGateEmpty(&gate[i]);
        }
        out[i]=gate[i].GateValue(tmp,x[i]);
        tmp=out[i];
    }

    printf("%d,%d,%d\n",out[0],out[1],out[2]);
    system("PAUSE");

    return 0;
}
