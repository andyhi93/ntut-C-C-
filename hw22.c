#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Find_K(int start,char s[51],int k){
    int isBig=0,counter=1,maxLen=0,lenCount=1;
    isBig=isupper(s[start]);
    //printf("%c",s[start]);
    for(int i=start+1;i<strlen(s);i++){
        if(counter==k){
            isBig=isBig==1?0:1;
            counter=0;
        }
        if(isupper(s[i])==isBig){
            lenCount++;
            counter++;
            //printf("%c",s[i]);
        }
        else{
            break;
        }
    }
    //printf("\n");
    return lenCount;
}

int main(){
    char inputS[51];
    int inputN,temp,N,ans[5]={0,0,0,0,0},end=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf(" %s",inputS);
        scanf(" %d",&inputN);
        //printf("A:%s %d\n",inputS,inputN);
        for(int j=0;j<strlen(inputS);j++){
            temp=Find_K(j,inputS,inputN);
            if(temp>ans[i] && temp>=inputN*2)ans[i]=temp/inputN*inputN;
        }
    }
    for(int i=0;i<N;i++)printf("%d\n",ans[i]);
    return 0;
}