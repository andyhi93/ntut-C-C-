#include<stdio.h>

typedef struct _project{
    int day,taskAmount,task[10];
}project;

int calculate(project *obj){
    int doneTask[obj->taskAmount],index=0;
    if(index==obj->taskAmount-1)return 0;
    for(int i=0;i<obj->taskAmount;i++){}
    return 0;
}

int main(){
    int N,M,day,Amount,temp,ans[3];
    scanf("%d",&N);
    project projectData[N][100];
    for(int i=0;i<N;i++){
        scanf(" %d",&M);
        for(int j=0;j<M;j++){
            scanf("%d %d",&day,&Amount);
            projectData[i][j].day=day;
            projectData[i][j].taskAmount=Amount;
            for(int k=0;k<Amount;k++){
                scanf("%d",&temp);
                projectData[i][j].task[k]=temp;
            }
        }
    }
}