#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    int base[3]={0,0,0},outnum,player[9][6],data[9][3]={0};
    char temp[100],*tprt;
    for(int i=0;i<9;i++){
        data[i][0]=i+1;
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
                    zerocnt=0;
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
                for(int k=2;k>=0;k--){//²¾°Ê
                    if(base[k]!=0){
                        if(k+player[j][i]>2){
                            data[base[k]-1][2]+=3-k;
                            base[k]=0;
                            score++;
                        }
                        else{
                            data[base[k]-1][2]+=player[j][i];
                            base[k+player[j][i]]=base[k];
                            base[k]=0;
                        }
                    }
                }
                if(player[j][i]<4){
                    data[j][1]+=1;
                    data[j][2]+=player[j][i];
                    base[player[j][i]-1]=j+1;
                }
                else{
                    data[j][1]+=1;
                    data[j][2]+=4;
                    score++;
                    }
            }
        }
        if(counter==outnum){
            break;
        }
    }
    int ans[3][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            ans[i][j] = -1;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            if(data[j][2]>ans[i][1] && j!=ans[0][0] && j!=ans[1][0]){
                ans[i][1]=data[j][2];
                ans[i][0]=j;
            }
        }
    }
    printf("%d\n",score);
    for(int i=0;i<3;i++){
        printf("%d %d %d\n",data[ans[i][0]][0],data[ans[i][0]][1],data[ans[i][0]][2]);
    }
}