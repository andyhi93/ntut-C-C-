#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int gcd(int a, int b) {
    if (a < b) {
        int temp=a;
        a=b;
        b=temp;
    }
    while (b!=0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void count(int *t, int *b, char input[], int *sub) {
    char tmp[10]={0};
    int sympos = 0, leftpos = 0, rightpos = 0, divpos = 0, tmpint = 0, takeint = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '-') {
            *sub = 1;
        } else if (input[i] == '(') {
            leftpos = i;
        } else if (input[i] == ')') {
            rightpos = i;
        } else if (input[i] == '/') {
            divpos = i;
        }
    }

    if (leftpos != 0) {
        strncpy(tmp, input + divpos+1,rightpos-divpos-1);
        *b = atoi(tmp);
        memset(tmp, '\0', sizeof(tmp));
        strncpy(tmp, input + *sub, leftpos-*sub);
        takeint = atoi(tmp);
        memset(tmp, '\0', sizeof(tmp));
        strncpy(tmp, input + leftpos+1, divpos-leftpos-1 );
        *t = atoi(tmp);
        memset(tmp, '\0', sizeof(tmp));
        *t = takeint * (*b)+*t;
    } else {
        strncpy(tmp, input + divpos+1,strlen(input)-divpos-1);
        *b = atoi(tmp);
        memset(tmp, '\0', sizeof(tmp));
        strncpy(tmp, input + *sub, divpos);
        *t = atoi(tmp);
        memset(tmp, '\0', sizeof(tmp));
    }
}



void cal(int top1,int top2,int bot1,int bot2,char symbol,char ans[],int sub1,int sub2){
    int resulttop,resultbot;
    if(sub1==1){sub1=-1;}
    else{sub1=1;}
    if(sub2==1){sub2=-1;}
    else{sub2=1;}
    switch (symbol){
    case '+':
        resulttop=top1*bot2*sub1+top2*bot1*sub2;
        resultbot=bot1*bot2;
        break;
    case '-':
        resulttop=top1*bot2*sub1-top2*bot1*sub2;
        resultbot=bot1*bot2;
        break;
    case '*':
        resulttop=top1*top2*sub1*sub2;
        resultbot=bot1*bot2;
        break;
    case '/':
        resulttop=top1*bot2*sub1*sub2;
        resultbot=bot1*top2;
        break;
    default:
        printf("Invalid operator\n");
        break;
    }
    int commonDivisor = gcd(resulttop, resultbot);
    resulttop/=commonDivisor;
    resultbot/=commonDivisor;
    if(resultbot<0){
        resulttop*=-1;
        resultbot*=-1;
        }
    if (resulttop == 0) {
        sprintf(ans, "0");
    }
    else if(resultbot==1){
        sprintf(ans,"%d",resulttop);
    } else if (abs(resulttop)<abs(resultbot)) {
        sprintf(ans,"%d/%d",resulttop,resultbot);
    } else {
        int intpart=resulttop/resultbot;
        resulttop=resulttop%resultbot;
        sprintf(ans,"%d(%d/%d)",intpart, abs(resulttop), resultbot);
    }
}

int main(){
    char input[100],symbol,state='y',ans[100][50],times=0;
    int top1,bot1,top2,bot2,sub1,sub2;
    while (1){
        sub1=0,sub2=0;
        scanf(" %s",input);
        count(&top1,&bot1,input,&sub1);
        getchar();
        scanf(" %c",&symbol);
        getchar();
        scanf(" %s",input);
        count(&top2,&bot2,input,&sub2);
        if(bot1==0 || bot2==0 || (top2==0 && symbol=='/')){strcpy(ans[times],"error");}
        else{cal(top1,top2,bot1,bot2,symbol,ans[times],sub1,sub2);}
        getchar();
        scanf(" %c",&state);
        times++;
        if(state=='n'){break;}
    }
    for(int i=0;i<times;i++){
        printf("%s\n",ans[i]);
    }
}