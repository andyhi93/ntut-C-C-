#include <stdio.h>
#include <string.h>

int CMP(char s[10][11],char s1[10][11],char s2[10][11]){}

void split(char input[],char *symbol,char data[10][11]){
    char *token=strtok(input,symbol);
    int i=0,same=0;
    while(token!=NULL){
        for(int j=0;j<i;j++){
            if(strcmp(token,data[j])==0)same=1;
        }
        if(same==0) strcpy(data[i++],token);
        printf("b:%s\n",data[i-1]);
        token=strtok(NULL,symbol);
        same=0;
    }
}

int main(){
    char data[10][11]={{0}},strData[10][10][11]={{{0}}},temp[101];
    int n;
    scanf("%[^\n]",temp);
    printf("a:%s\n",temp);
    split(temp," ",data);
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        scanf(" %[^\n]",temp);
        printf("a:%s\n",temp);
        split(temp," ",strData[i]);
    }
    for(int i=0;data[i][0]!='\0';i++){
        printf("%s ",data[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;strData[i][j][0]!='\0';j++){
            printf("%s ",strData[i][j]);
        }
        printf("\n");
    }

}