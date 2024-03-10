#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char* G(int n, int k) {
    if (n == 1) {
        char *t = (char*)malloc(2 * sizeof(char));
        sprintf(t, "%d", k);
        return t;
    } else if (k < pow(2, n - 1)) {
        char *zeroG = G(n - 1, k);
        char *result = (char*)malloc((strlen(zeroG) + 2) * sizeof(char));
        sprintf(result, "0%s", zeroG);
        free(zeroG);
        return result;
    } else if (k >= pow(2, n - 1)) {
        char *oneG = G(n - 1, pow(2, n - 1) - k);
        char *result = (char*)malloc((strlen(oneG) + 2) * sizeof(char));
        sprintf(result, "1%s", oneG);
        free(oneG);
        return result;
    }
}

int BiToDe(char *bi) {
    int length = strlen(bi);
    int de = 0;

    for (int i = 0; i < strlen(bi); i++) {
        int bit = bi[i] - '0';
        int power = length - 1 - i;
        de += bit << power;
    }

    return de;
}

char* DeToBi(int n) {
    int binaryNum[32], i = 0,start = 0;
    char result[33];
    while ((1 << start) <= n) {
        start++;
    }
    start--;
    for (int j = 0; j < 32; j++) {
        binaryNum[j] = 0;
    }
    while (n > 0) {
        binaryNum[start - i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = 0; j <= start; j++) {
        char digit[2];
        sprintf(digit, "%d", binaryNum[j]);
        strcat(result, digit);
    }

    return strdup(result);
}

int main(){
    char input[100];
    int input1,input2,ans[100],times=0;
    while (1){
        scanf("%s",input);
        if (sscanf(input,"%d %d", &input1, &input2) == 2) {
            sscanf(input,"%d %d", &input1, &input2);
        }
        else{break;}
        ans[times] = BiToDe(G(input1, input2));
        times++;
    }
    for(int i=0;i<times;i++){
        for (int j = 31; j >= 0; j--) {
            printf("%s\n",DeToBi(ans[j]));
        }
    }
}