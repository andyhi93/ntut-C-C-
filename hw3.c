#include <stdio.h>
#include <string.h>
int find(int target,int a[],int size){
    for (int i=0;i< size;++i){
        if(a[i]==target){
            return i;
        }
    }
    return -1;
}
bool z(int a[]){
    for (int i=3;i>=0;--i){
        if(a[i]!=-1){
            return 0;
        }
    }
    return 1;
    }
int main(){
    int players[5]={0};
    int tmp=0;
    int base[3]={0,0,0};
    int npsn=-1;
    int point=0;
    for(int i=0;i<5;++i){
        scanf("%d",tmp);
        players[i]=tmp;
    }
    for(int i;i<5;++i){
        tmp=players[i];
        for(int j=2;j>=0;--j){
            if (base[j]==1){
                npsn=j+tmp;
                if(npsn>2){
                    point+=1;
                    base[j]=0;
                }
                else{
                    base[j]=0;
                    base[npsn]=1;
                }
            }
        }
    }
    return 0;
}