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

void count(int *t,int *b,char input[],int *sub){
    char tmp[10];
    int sympos=0,leftpos=0,rightpos=0,divpos=0,tmpint=0,takeint=0;
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='-'){*sub=1;}
        else if(input[i]=='('){leftpos=i;}
        else if(input[i]==')'){rightpos=i;}
        else if(input[i]=='/'){divpos=i;}
    }
    strncpy(tmp,input+leftpos+1,divpos-1);
    *t=atoi(tmp);
    strncpy(tmp,input+divpos+1,rightpos-1);
    *b=atoi(tmp);
    if (leftpos != 0) {
        strncpy(tmp, input + *sub, leftpos - *sub);
        tmp[leftpos - *sub] = '\0';  // 修正這一行，確保字串結尾
        takeint = atoi(tmp);
        *t = takeint * (*b) + *t;
    } else {
        strncpy(tmp, input + *sub, divpos - *sub);
        tmp[divpos - *sub] = '\0';  // 修正這一行，確保字串結尾
        *t = atoi(tmp);
    }
}

void cal(int top1,int top2,int bot1,int bot2,char symbol,char ans[],int sub1,int sub2){
    int resulttop,resultbot;
    switch (symbol){
    case '+':
        resulttop=top1*bot2+top2*bot1;
        resultbot=bot1*bot2;
        break;
    case '-':
        resulttop=top1*bot2-top2*bot1;
        resultbot=bot1*bot2;
        break;
    case '*':
        resulttop=top1*top2;
        resultbot=bot1*bot2;
        break;
    case '/':
        resulttop=top1*bot2;
        resultbot=bot1*top2;
        break;
    default:
        printf("Invalid operator\n");
        break;
    }
    int commonDivisor = gcd(resulttop, resultbot);
    resulttop/=commonDivisor;
    resultbot/=commonDivisor;
    if (resulttop == 0) {
        sprintf(ans, "0");
    } else if (resulttop<resultbot) {
        if(sub1*sub2 && (resulttop*resultbot>0)){sprintf(ans,"-%d/%d",resulttop,resultbot);}
        else{sprintf(ans,"%d/%d",resulttop,resultbot);}
    } else {
        int intpart=resulttop/resultbot;
        resulttop=resulttop%resultbot;
        if(sub1*sub2 && (resulttop*resultbot>0)){sprintf(ans,"-%d(%d/%d)",intpart, resulttop, resultbot);}
        else{sprintf(ans,"%d(%d/%d)",intpart, resulttop, resultbot);}
    }
}

int main(){
    char input[50],symbol,state,ans[100][10],times=0;
    int top1,bot1,top2,bot2,sub1,sub2;
    while (1){
        sub1=0,sub2=0;
        scanf("%s",input);
        count(&top1,&bot1,input,&sub1);
        getchar();
        scanf(" %c",&symbol);
        getchar();
        scanf("%s",input);
        count(&top2,&bot2,input,&sub2);
        if(bot1==0 || bot2==0){strcpy(ans[times],"error");}
        cal(top1,top2,bot1,bot2,symbol,ans[times],sub1,sub2);
        getchar();
        scanf(" %c",&state);
        times++;
        if(state=='n'){break;}
    }
    for(int i=0;i<times;i++){
        printf("%s\n",ans[i]);
    }
}