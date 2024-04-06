#include <stdio.h>
#include <string.h>
#include <math.h>

#define SWAP(x,y) {char t[100]; strcpy(t,x); strcpy(x,y); strcpy(y,t);}
int getMinIndex(char d[101][10], int left, int right) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
        if (d[i][0]-'0'<d[minIndex][0]-'0') minIndex=i;
        else if(d[i][0]-'0'==d[minIndex][0]-'0' &&d[i][2]-'0'<d[minIndex][2]-'0') minIndex=i;
    }
    return minIndex;
}
void sortData(char ans[101][10],int anslen){
    for(int i=0;i<anslen;i++){
        int index=getMinIndex(ans,i,anslen);
        SWAP(ans[i],ans[index]);
    }
}

void findBlack(int offsetx,int offsety,int offsetN,char ans[101][10],int *aindex){
    for(int i=0;i<offsetN;i++){
        for(int j=0;j<offsetN;j++){
            sprintf(ans[(*aindex)++],"%d,%d",j+offsety,i+offsetx);
        }
    }
}

void DF(int N,char layer[100],int data[],int *dindex,char ans[101][10],int *aindex,int lenth,int sqrnum){
    if(*dindex>lenth-1){return;}
    if(sqrnum>3){
        layer[strlen(layer)-1]='\0';
        sqrnum=layer[strlen(layer)-1]+1-'0';
        layer[strlen(layer)-1]=sqrnum+'0';
        DF(N,layer,data,dindex,ans,aindex,lenth,sqrnum);
    }
    if(data[*dindex]==2){
        layer[strlen(layer)]='0';
        layer[strlen(layer)]='\0';
        (*dindex)++;
        DF(N,layer,data,dindex,ans,aindex,lenth,0);
    }
    else if(data[*dindex]==1){
        int offsetx=0,offsety=0,offsetN=N;
        for(int i=0;i<strlen(layer);i++){
            offsetN/=2;
            offsetx+=(layer[i]-'0')%2*offsetN;
            offsety+=(layer[i]-'0')/2*offsetN;
        }
        findBlack(offsetx,offsety,offsetN,ans,aindex);
        (*dindex)++;
        layer[strlen(layer)-1]=sqrnum+1+'0';
        layer[strlen(layer)]='\0';
        DF(N,layer,data,dindex,ans,aindex,lenth,sqrnum+1);
    }
    else if(data[*dindex]==0){
        layer[strlen(layer)-1]=sqrnum+1+'0';
        (*dindex)++;
        DF(N,layer,data,dindex,ans,aindex,lenth,sqrnum+1);
    }
}

int main(){
    int N,dindex=1,aindex=0;
    char input[101],ans[101][10],layer[100]="0";
    scanf("%s",input);
    scanf(" %d",&N);
    int lenth=strlen(input);
    int data[lenth];
    if(input[0]=='0'){printf("all white");}
    else if(input[0]=='1'){
        findBlack(0,0,N,ans,&aindex);
    }
    else{
        for(int i=0;i<lenth;i++){
            data[i]=input[i]-'0';
        }
        DF(N,layer,data,&dindex,ans,&aindex,lenth,0);
    }
    sortData(ans,aindex);
    for(int i=0;i<aindex;i++){
        printf("%s\n",ans[i]);
    }
    return 0;
}