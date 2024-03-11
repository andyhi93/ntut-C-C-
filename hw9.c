#include <stdio.h>
#include <string.h>

void DeToBi(int N,char input[15]){
    for (int i = 13; i >= 0; i--) {
        input[i] = (N & 1) + '0';  // 將最低位添加到字符串
        N >>= 1;  // 右移一位，準備處理下一位
    }

    input[14] = '\0';  // 添加結尾的 null 字符
}

int C(int N) {
    if (N == 0 || N == 1) {
        return 1;
    } else if (N % 2 == 0) {
        return 1 + C(N/2);
    } else if (N % 2 == 1) {
        return 1 + C((N + 1)/2);
    }
}

int T(int N){
    int t=0;
    for(int i=N;i>=0;i--){
        t+=C(i);
    }
    return t;
}



int main(){
    int state,times,de,anscount=0,input;
    char bi[15],ans[50][15];
    while (1)
    {
        scanf("%d",&input);
        scanf("%d",&state);
        if(state==-1){break;}
        times=T(de);
        DeToBi(times,bi);
        strcpy(ans[anscount],bi);
        anscount++;
    }
    for(int i=0;i<anscount;i++){
        printf("%s\n",ans[i]);
    }
}