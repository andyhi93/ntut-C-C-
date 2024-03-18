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
            printf("v[i]: %d\n",v[i]-'0');
            de+=(v[i]-'0')*cpower(b,strlen(v)-1-i);
            printf("ch: %d\n",(v[i]-'0')*cpower(b,strlen(v)-1-i));
            }
        else{
            printf("v2: %c %d\n",v[i],v[i]-'7');
            de+=(v[i]-'7')*cpower(b,strlen(v)-1-i);
            printf("ch: %d\n",(v[i]-'0')*cpower(b,strlen(v)-1-i));
        }
    }
    printf("de: %d\n",de);
    return de;
}
void turnans(int de,int b,char ans[100]){
    int j=0;
    while (de>0)
    {
        j=de%b;
        printf("j: %d\n",j);
        if(j<10){
            ans[j++]=j+'0';
        }
        else{
            ans[j++]=j+'7';
        }
        de/=b;
    }
    
    for(int i=j-1;i>=0;i--){
        printf("%c",ans[i]);
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