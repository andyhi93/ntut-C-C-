#include <stdio.h>
#include <string.h>

int CMP(char s[10][11],char s1[10][11],char s2[10][11]){
    int count=0,target=0;
    for(int i=0;s[i][0]!='\0';i++)target++;
    for(int i=0;s1[i][0]!='\0';i++){
        int isSame=0;
        for(int j=0;s[j][0]!='\0';j++){
            if(strcmp(s[j],s1[i])==0){
                count++;
                isSame=1;
            }
        }
        if(!isSame)return 0;
    }
    for(int i=0;s2[i][0]!='\0';i++){
        int isSame=0;
        for(int j=0;s[j][0]!='\0';j++){
            if(strcmp(s[j],s2[i])==0){
                count++;
                isSame=1;
            }
        }
        if(!isSame)return 0;
    }
    for(int i=0;s1[i][0]!='\0';i++){
        for(int j=0;s2[j][0]!='\0';j++){
            if(strcmp(s1[i],s2[j])==0)return 0;
        }
    }
    if(count==target)return 1;
    return 0;
}

void split(char input[],char *symbol,char data[10][11]){
    char *token=strtok(input,symbol);
    int i=0,same=0;
    while(token!=NULL){
        for(int j=0;j<i;j++){
            if(strcmp(token,data[j])==0)same=1;
        }
        if(same==0) strcpy(data[i++],token);
        token=strtok(NULL,symbol);
        same=0;
    }
}

int main(){
    char data[10][11]={{0}},strData[10][10][11]={{{0}}},temp[101];
    int n;
    scanf("%[^\n]",temp);
    split(temp," ",data);
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        scanf(" %[^\n]",temp);
        split(temp," ",strData[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(CMP(data,strData[i],strData[j]))count++;
        }
    }
    printf("%d",count);
}