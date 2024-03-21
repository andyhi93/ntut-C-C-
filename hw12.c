#include <stdio.h>

int main(){
    int base[3]={0,0,0};
    char player[9][5],temp[100];
    for(int i=0;i<9;i++){
        scanf("%s",&temp);
        int k=1;
        player[i][0]=temp[0]-'0';
        for(int j=0;j<temp[0]-'0';j++){
            player[i][k++]=temp[(j+1)*2];
        }
    }
}