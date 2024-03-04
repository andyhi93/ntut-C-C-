#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int M,team1[2]={0,0},team2[2]={0,0},team3[2]={0,0},tmpscore1,tmpscore2;
    char tmpt1[20],tmpt2[20];
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int total1=0,total2=0;
        scanf("%s %s",&tmpt1,&tmpt2);
        for(int j=0;j<4;j++){
            scanf("%d %d",&tmpscore1,&tmpscore2);
            total1+=tmpscore1;
            total2+=tmpscore2;
        }
        if(total1>total2){
            if(strcmp(tmpt1,"A")==0){//AB、BC、AC
                team1[0]+=1;
            }
            else{//BC
                team2[0]+=1;
            }
        }
        else{
            if(strcmp(tmpt2,"B")==0){//AB
                team2[0]+=1;
            }
            else{//AC、BC
                team3[0]+=1;
            }
        }
        if(strcmp(tmpt1,"A")==0){//AB,AC
            team1[1]+=total1;
            if(strcmp(tmpt2,"B")==0){
                team2[1]+=total2;
            }
            else{
                team3[1]+=total2;
            }
        }
        else{//BC
            team2[1]+=total1;
            team3[1]+=total2;
        }
    }
    if (team1[0]>team2[0]){
        if(team1[0]>team3[0]){
            printf("A\n%d",team1[1]);
        }
        else{
            printf("C\n%d",team3[1]);
        }
        }
    else{
        if(team2[0]>team3[0]){
            printf("B\n%d",team2[1]);
        }
        else{
            printf("C\n%d",team3[1]);
        }
    }
}