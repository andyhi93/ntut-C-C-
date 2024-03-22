#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    int base[3]={0,0,0},outnum,player[9][6];
    char temp[100],*tprt;
    for(int i=0;i<9;i++){
        fgets(temp, sizeof(temp), stdin);
        int k=1;
        player[i][0]=temp[0]-'0';
        for(int j=0;j<temp[0]-'0';j++){
            if(isdigit(temp[(j+1)*2])){
                tprt = &temp[(j + 1) * 2];
                player[i][k++]=atoi(tprt);
                }
            else if(temp[(j+1)*2]=='O'){
                player[i][k++]=0;
            }
            else{
                player[i][k++]=4;
            }
        }
    }
    scanf("%d",&outnum);
    int counter=0,p1,p2,score=0,zerocnt=0;
    for(int i=1;i<6;i++){
        for(int j=0;j<9;j++){
            if(player[j][i]==0){
                counter++;
                zerocnt++;
                if(zerocnt==3){
                    for(int k=0;k<3;k++){
                        base[k]=0;
                    }
                }
                if(counter==outnum){
                    p1=j;
                    p2=i;
                    break;
                }
            }
            else{
                for(int k=2;k>=0;k--){//移動
                    if(base[k]!=0){
                        if(k+player[j][i]>2){
                            base[k]=0;
                            score++;
                            printf("add:%d %d\n",k,player[j][i]);
                        }
                        else{
                            base[k]=0;
                            base[k+player[j][i]]=1;
                        }
                    }
                }
                if(player[j][i]<4){
                    base[player[j][i]-1]=1;
                }
                else{
                    score++;
                    printf("add\n");
                    }
            }
            printf("m: %d base: %d %d %d\n",player[j][i],base[0],base[1],base[2]);
        }
        if(counter==outnum){
            break;    
        }
    }
    printf("p:%d %d\n",p1,p2);
    printf("score: %d",score);
}