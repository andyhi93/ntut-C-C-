#include<stdio.h>

int main(){
    int order[3],time[3][4],bool_c=1;

    for(int i=0;i<3;i++){
        scanf("%d",&order[i]);
        scanf("%d",&time[i][0]);
        for(int j=1;j<time[i][0]+1;j++){
            scanf("%d",&time[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            for(int k=1;k<time[i][0]+1;k++){
                for(int l=1;l<time[j][0]+1;l++){
                    if (time[i][k]==time[j][l]){
                        bool_c=0;
                        printf("%d,%d,%d\n",order[i],order[j],time[i][k]);
                    }
                }
            }
        }
    }
    if(bool_c==1){
        printf("correct");
    }
    return 0;
}