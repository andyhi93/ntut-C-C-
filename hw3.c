#include <stdio.h>
#include <string.h>
int main(){
    int players[5]={0};
    int tmp=0;
    int base[3]={0,0,0};
    int npsn=-1;
    int point=0;
    int ztimes=0;
    for(int i=0;i<5;++i){
        scanf("%d",&tmp);
        players[i]=tmp;
    }
    for(int i=0;i<5;++i){
        tmp=players[i];
        if(tmp==0){
            ztimes+=1;
        }
        if(ztimes==3){
            for (int j=0;j<3;j++){
                base[j]=0;
            }
            ztimes=0;
        }
        else {
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
            if(tmp==4){
                point+=1;
            }
            else{
                base[tmp-1]=1;
            }
        }
    }
    printf("%d\n",point);
    printf("%d %d %d",base[0],base[1],base[2]);
    return 0;
}