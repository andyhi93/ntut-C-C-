#include <stdio.h>
#define SWAP(x, y){ int temp = x; x = y; y = temp; }

int countRP(int arr[],int num,int index){
    int c=0;
    for(int i=0;i<4;i++){
        if(arr[i]==arr[index] && i!=index){
            c++;
        }
    }
    return c;
}
void Score(int data[4][6]){
    int temp[4]={data[0][1],data[1][1],data[2][1],data[3][1]},count[4],zCount=0,twinGroup=0,same;
    for(int i=0;i<4;i++){
        count[i]=countRP(temp,temp[i],i);
        if(count[i]==3){
            printf("18");
            return;
        }
        else if(count[i]==2){
            printf("0");
            return;
        }
        else if(count[i]==1){
            twinGroup++;
            same=temp[i];
        }
        else if(count[i]==0){zCount++;}
    }
    if(zCount==4){
        printf("0");
    }
    else if(twinGroup==4){
        int maxNum=0;
        for(int i=0;i<4;i++){
            if(temp[i]>maxNum){maxNum=temp[i];}
        }
        printf("%d",maxNum*2);
    }
    else if(twinGroup==2){
        int s=0;
        for(int i=0;i<4;i++){
            if(temp[i]!=same){
                s+=temp[i];
            }
        }
        printf("%d",s);
    }
}

void RollDice(int p[],int cmd){
    switch (cmd)
    {
    case 1:
        for(int i=3;i>0;i--){SWAP(p[i],p[i-1]);}
        break;
    case 2:
        for(int i=0;i<3;i++){SWAP(p[i],p[i+1]);}
        break;
    case 3:
        SWAP(p[1],p[5]);
        SWAP(p[1],p[4]);
        SWAP(p[3],p[4]);
        break;
    case 4:
        SWAP(p[1],p[5]);
        SWAP(p[3],p[4]);
        SWAP(p[4],p[5]);
        break;
    default:
        printf("wrong");
        break;
    }
}

int main(){
    int N,input[4],data[4][6]={{4,1,3,6,5,2},{4,1,3,6,5,2},{4,1,3,6,5,2},{4,1,3,6,5,2}};//f,m,bk,bt,l,r
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf(" %d %d %d %d",&input[0],&input[1],&input[2],&input[3]);
        for(int j=0;j<4;j++){
            RollDice(data[j],input[j]);
        }
    }
    Score(data);
    return 0;
}