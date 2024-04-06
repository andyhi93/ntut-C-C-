#include <stdio.h>
#include <string.h>

#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void insertionSort(int a[], int n,int *Scount,int *Ccount) {
    int target=0, i=0, j=0;
    for (i=1; i<n; i++) {
        target = a[i];
        (*Ccount)++;
        for (j=i; (j>0) ||(a[j-1]>target) ; j--){
            if (j>0 &&(a[j-1]>target)){
                (*Scount)+=2;
                a[j] = a[j-1];
                (*Ccount)++;
            }
            else if(j>0){
                (*Scount)++;
                break;
            }
            else{break;}
        }
        (*Scount)++;
        a[j] = target;
        (*Ccount)++;
    }
}
int getMinIndex(int d[], int left, int right,int *Scount) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
        if (d[i]<d[minIndex]) minIndex=i;
        (*Scount)++;
    }
    return minIndex;
}
void selectSort(int d[], int n,int *Scount,int *Ccount) {
    int i=0, index=0;
    for (i=0; i<n; i++) {
        index = getMinIndex(d, i, n,Scount);
        SWAP(d[i], d[index]);
        if(i!=index){(*Ccount)+=3;}
    }
}
int main(){
    int lenth,Scount=0,Ccount=0;
    scanf("%d",&lenth);
    int Sdata[lenth],Idata[lenth];
    for(int i=0;i<lenth;i++){
        scanf(" %d",&Sdata[i]);
    }
    memcpy(Idata, Sdata, sizeof(Sdata));
    selectSort(Sdata,lenth,&Scount,&Ccount);
    printf("%d %d\n",Scount,Ccount);
    Scount=0,Ccount=0;
    insertionSort(Idata,lenth,&Scount,&Ccount);
    printf("%d %d\n",Scount,Ccount);
}