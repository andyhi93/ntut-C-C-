#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int change(char x){
    if(x=='A'){return 0;}
    else if(x=='B'){return 1;}
    else{return 2;}
}

int main(){
    int M,x,y,score[3][2],tmppoint[2];
    char tmpc1,tmpc2,tmpscore[6],token;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%c %c",&tmpc1,&tmpc2);
        x=change(tmpc1);
        y=change(tmpc2);
        for(int j=0;j<4;j++){
            scanf("%c",&tmpscore);
            char *token=strtok(tmpscore," ");
            tmppoint[0]+=atoi(token);
            token=strtok(NULL," ");
            tmppoint[1]+=atoi(token);
        }
        score[x][1]+=tmppoint[0];
        score[y][1]+=tmppoint[1];
        if(tmppoint[0]>tmppoint[1]){
            score[x][0]+=1;
        }
        else{score[y][0]+=1;}
    }
    printf("%d %d %d %d %d %d",score[0][1],score[1][1],score[2][1],score[0][0],score[1][0],score[2][0]);
}