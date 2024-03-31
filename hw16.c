#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N,count=0,len;
    char temp[500],num[200];
    scanf("%d ",&N);
    fgets(temp, sizeof(temp), stdin);
    int input[N];
    int i=0,index=0,inputindex=0;
    while(inputindex!=N){
        if(temp[i]==' ' || temp[i]=='\0'){
            num[index] = '\0';
            sscanf(num, "%d", &input[inputindex++]);
            memset(num, '\0', sizeof(num));
            index=0;
        }
        else{
            num[index++]=temp[i];
        }
        i++;
    }
    for(int i=0;i<inputindex;i++){
        for(int j=i+1;j<inputindex;j++){
            if(input[i]>input[j]){count++;}
        }
    }
    printf("\n%d",count);
}