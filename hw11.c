#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cpower(int a,int b){
    int c=1;
    for(int i=0;i<b;i++){
        c*=a;
    }
    return c;
}
int ToDe(int b,char v[100]){
    int de=0,temp;
    for(int i=0;i<strlen(v);i++){
        if(isdigit(v[i])){
            de+=(v[i]-'0')*cpower(b,strlen(v)-1-i);
            }
        else{
            de+=(v[i]-'7')*cpower(b,strlen(v)-1-i);
        }
    }
    return de;
}
void turnans(int de,int b,char ans[100]){
    int j=0,k;
    while (de>0)
    {
        k=de%b;
        if(k<10){
            ans[j++]=k+'0';
        }
        else{
            ans[j++]=k+'A'-10;
        }
        de/=b;
    }
    if(j==0){
        printf("%d",0);
    }
    else{
    for(int i=j-1;i>=0;i--){
            printf("%c",ans[i]);
        }
    }
}
int main(){
    int M,N;
    char value[100],ans[100];
    scanf("%d",&M);
    scanf("%s",&value);
    scanf("%d",&N);
    turnans(ToDe(M,value),N,ans);
}