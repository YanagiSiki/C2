#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){ char xy[1000][1000]; int xt[9999],yt[9999],x1[9999],y1[9999],x=2,y=1,t[9999]; int i=0,j=0,a=0,b=0,k=0,l; gets(xy[0]); l=strlen(xy[0]); for(i=1;i<l/2+1;i++){ gets(xy[i]); } xt[0]=2; yt[0]=1; a=1; while(1){ while(1){ b=0; if(xy[y+1][x]=='0'){ b++ ; } if(xy[y-1][x]=='0'){ b++; } if(xy[y][x-2]=='0'){ b++; } if(xy[y][x+2]=='0'){ b++; } if(b>=2){ x1[k]=x; y1[k]=y; t[k]=a; k++; break; } else{ break; } } if(x==(l-3) && y==(l/2-1)){ for(i=0;i<a;i++){ xy[yt[i]][xt[i]]='#'; } for(i=0;i<strlen(xy[0])/2+1;i++){ printf("%s\n",xy[i]); } break; } else if(xy[y+1][x]!='0'&&xy[y-1][x]!='0'&&xy[y][x-2]!='0'&&xy[y][x+2]!='0'){ x=x1[k-1]; y=y1[k-1]; a=t[k-1]; k--; } else{ if(xy[y+1][x]=='0'){ xt[a]=x; yt[a]=y+1; xy[y+1][x]='*'; y++; a++; } else if(xy[y-1][x]=='0'){ xt[a]=x; yt[a]=y-1; xy[y-1][x]='*'; y--; a++; } else if(xy[y][x-2]=='0'){ xt[a]=x-2; yt[a]=y; xy[y][x-2]='*'; x=x-2; a++; } else if(xy[y][x+2]=='0'){ xt[a]=x+2; yt[a]=y; xy[y][x+2]='*'; x=x+2; a++; } } } }
