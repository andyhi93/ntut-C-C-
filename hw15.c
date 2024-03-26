#include <stdio.h>
#include <string.h>

void sorted(int a[100][10],int s,int m,int j,int index[100],int d){
    //s資料量 m長度 j目前比較索引 d目前排序索引
    int smallest[2]={10,0},same=0;
    for(int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            if(i==index[k]){same=1;}
        }
        if(same){
            same=0;
            continue;
        }
        if(a[i][j]<smallest[0]){
            smallest[1]=i;
            smallest[0]=a[i][j];
        }
        else if(a[i][j]==smallest[0]){
            int next = j + 1;
            while (next < m && a[i][next] == a[smallest[1]][next]) {
                next++;
            }
            if (next == m || a[i][next] < a[smallest[1]][next]) {
                smallest[1] = i;
            }
        }
    }
    index[d]=smallest[1];
}

int main(){
    int m,neg,input[20],data[100][10],n=0,len,sort[100][10],ans[100][10];
    char temp[50];
    scanf("%d ",&m);
    fgets(temp, sizeof(temp), stdin);
    len=(strlen(temp)+1)/2;
    int i=0,repeat=0;
    while(i<strlen(temp)){
        input[i/2]=temp[i]-'0';
        i+=2;
    }
    scanf("%d",&neg);
    for(int i=0;i<len-m+1;i++){
        for(int j=0;j<m;j++){
            data[i][j]=input[i+j];
        }
    }
    int s=0,count,r=0;
    for(int i=0;i<len-m+1;i++){//重複移除
        repeat=0,count=0;
        for(int j=0;j<m;j++){//重複數字
            for(int k=j+1;k<m;k++){
                if(data[i][k]==data[i][j]){
                    repeat=1;
                }
            }
        }
        for(int j=0;j<s;j++){
            for(int k=0;k<m;k++){
                if(data[i][k]==sort[j][k]){
                    count++;
                }
            }
        }
        if(repeat==0 && count!=m){
            for(int j=0;j<m;j++){
                sort[s][j]=data[i][j];
            }
            s++;
        }
        if(count==m && repeat!=1){
            r++;
        }
    }
    //排序
    int index[100];
    for (int i = 0; i < s; i++) {
        index[i] = -1;
    }
    for(int i=0;i<s;i++){
        sorted(sort,s,m,0,index,i);
    }
    printf("%d\n",s+r);
    for(int i=0;i<s;i++){
        for(int j=0;j<m;j++){
            printf("%d ",sort[index[i]][j]);
        }
        printf("\n");
    }
}