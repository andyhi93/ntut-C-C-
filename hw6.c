#include<stdio.h>
int main(){
    int N,M;
    char letter[4]="ABC";
    scanf("%d",&N);
    scanf("%d",&M);
    if(!(1<=N && N<=2) || !(2<=M && M<=9)){
        printf("error");
    }
    else{
        if(N==1){
            for(int i=0;i<M;i++){
                for(int j=0;j<M-1-i;j++){
                    printf("#");
                }
                for(int j=0;j<i+1;j++){
                    printf("*");
                    if(i-j>0){
                        printf("%c",letter[(i-1)%3]);
                    }
                }
                for(int j=0;j<M-1-i;j++){
                    printf("#");
                }
                printf("\n");
            }
        }
        else{
            for(int i=0;i<M;i++){
                for(int j=1;j<i+2;j++){
                    printf("%d",j);
                }
                for(int j=0;j<M-i;j++){
                    printf("**");
                }
                for(int j=i+1;j>0;j--){
                    printf("%d",j);
                }
                printf("\n");
            }
        }
    }
}