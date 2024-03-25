#include <stdio.h>
#include <string.h>

int main(){
    int m,neg,input[20],data[100][10],n=0,len,sort[100][10],ans[100][10];
    char temp[30];
    scanf("%d ",&m);
    fgets(temp, sizeof(temp), stdin);
    len=(strlen(temp)+1)/2;
    printf("len:%d\n",len);
    int i=0,repeat=0;
    while(i<strlen(temp)){
        input[i/2]=temp[i]-'0';
        i+=2;
    }
    scanf("%d",&neg);
    for(int i=0;i<len;i++){
        printf("%d ",input[i]);
    }
    printf("\n");
    for(int i=0;i<len-m+1;i++){
        for(int j=0;j<m;j++){
            data[i][j]=input[i+j];
        }
        for(int j=0;j<m;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    int s=0;
    for(int i=0;i<len-m+1;i++){//重複移除
        repeat=0;
        for(int j=0;j<i;j++){
            for(int k=0;k<m;k++){
                if(data[i][k]==data[j][k]){
                    repeat++;
                }
            }
        }
        if(repeat!=m){
            for(int j=0;j<m;j++){
                sort[s][j]=data[i][j];
            }
            s++;
        }
    }
    printf("s:\n");
    for(int i=0;i<s;i++){
        for(int j=0;j<m;j++){
            printf("%d ",sort[i][j]);
        }
        printf("\n");
    }
    
}