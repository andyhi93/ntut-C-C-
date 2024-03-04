#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isint(char s[]){
    int npst=0;
    if(s[0]=='-'){npst=1;}
    if (strlen(s)<1 || strlen(s)>50){
        return 0;
    }
    if(strlen(s)==1 && s[npst]=='0'){return 1;}
    if(s[npst]=='0'){return 0;}
    for(int i=npst;i<strlen(s);i++){
        if(!isdigit(s[i])){return 0;}
    }
    return 1;
}

int isf(char s[]){
    int dcount=0,dpst,npst=0;
    if(s[0]=='-'){npst=1;}
    if (strlen(s)<3+npst || strlen(s)>50){
        return 0;
    }
    
    for(int i=npst;i<strlen(s);i++){
        if(s[i]=='.'){
            dcount++;
            dpst=i;
        }
        if(dcount>1 || s[i]=='-'){return 0;}
    if(dpst+1==strlen(s)){return 0;}
    }
    for(int i=npst;i<dpst;i++){
        if(i+1!=dpst && s[i]=='0' && s[i+1]=='0'){
            return 0;
        }
    }
    for(int i=npst;i<strlen(s);i++){
        if(!isdigit(s[i]) && i!=dpst){
            return 0;
        }
    }
    return 1;
}

int isvar(char s[]){
    if(strlen(s)<1 || strlen(s)>10){return 0;}
    if(isalpha(s[0]) || s[0]=='_'){
        for(int i=0;i<strlen(s);i++){
            if (s[i]!='_' && !isalpha(s[i]) && !isdigit(s[i]))
            {
                return 0;
            }
        }
    }
    else{return 0;}
    return 1;
}
int main(){
    int N;
    scanf("%d",&N);
    int ans[N];
    char tmp[51];
    for(int i=0;i<N;i++){
        scanf(" %s",&tmp);
        if(isint(tmp)){ans[i]=1;}
        else if(isf(tmp)){ans[i]=2;}
        else if(isvar(tmp)){ans[i]=3;}
        else{ans[i]=4;}
    }
    for(int i=0;i<N;i++){
        if(ans[i]==1){printf("integer\n");}
        else if(ans[i]==2){printf("float\n");}
        else if(ans[i]==3){printf("variable\n");}
        else{printf("string\n");}
    }
}