#include <stdio.h>
#include <string.h>

void DF(int n,int m,char ans[101][10],int data[],int dindex,int aindex,int squareNum){//n當前格子大小 m除了幾次
    if(squareNum==0){return;}
    if(data[dindex]==0){DF(n,m,ans,data,dindex+1,aindex,squareNum-1);}
    if(data[dindex]==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sprintf(ans[aindex++],"%d,%d",abs(squareNum-4)%2*n+i,abs(squareNum-4)%2*n+j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        }
    }
}

int main(){
    int N;
    char input[101],ans[101][10];
    scanf("%s",input);
    scanf(" %d",&N);
    int data[strlen(input)];
    if(input[0]=='0'){printf("all white");}
    else{
        for(int i=0;i<strlen(input);i++){
            data[i]=input[i]-'0';
        }
        DF(N/2,1,ans,data,1,N/2);
    }
}