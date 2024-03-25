#include <stdio.h>
#include <string.h>

int compare(char a[101], char b[101]) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a > len_b) {
        return 0;
    } else if (len_a < len_b) {
        return 1;
    } else {
        for (int i = 0; i < len_a; i++) {
            if (a[i] > b[i]) {
                return 0;
            } else if (a[i] < b[i]) {
                return 1;
            }
        }
        return 2;
    }
}
void add(char a[101],char b[101],char ans[201]){
    int carry=0,alen=strlen(a),blen=strlen(b);
    int len=alen>blen?alen:blen;
    for(int i=alen-1,j=blen-1,k=len;i>=0||j>=0;i--,j--,k--){
        int adigit=i>=0?a[i]-'0':0;
        int bdigit=j>=0?b[j]-'0':0;
        int sum=adigit+bdigit+carry;
        ans[k]=sum%10+'0';
        carry=sum/10;
        printf("%d + %d = %d %c %c %c\n",adigit,bdigit,sum,sum/10+'0',sum%10+'0',ans[k]);
    }
    if(carry>0){
        for(int i=len;i>0;i--){
            ans[i]=ans[i-1];
        }
        ans[0]=carry+'0';
        ans[len+1]='\0';
    }
    else{
        ans[len]='\0';
    }
    printf("a: %s\n",ans);
}
void sub(char a[101],char b[101],char ans[201]){
    int borrow=0,alen=strlen(a),blen=strlen(b);
    int len=alen>blen?alen:blen;
    if(compare(a,b)==0){
        for(int i=alen-1,j=blen-1,k=len;i>=0||j>=0;i--,j--,k--){
            int diff;
            int adigit=i>=0?a[i]-'0':0;
            int bdigit=j>=0?b[j]-'0':0;
            if(adigit>=bdigit){
                diff=adigit-bdigit-borrow;
                borrow=0;
            }
            else{
                diff=10+adigit-bdigit;
                borrow=1;
            }
            ans[k]=diff+'0';
        }
    }
    else if(compare(a,b)==1){
        for(int i=alen-1,j=blen-1,k=len;i>=0||j>=0;i--,j--,k--){
            int adigit=i>=0?a[i]-'0':0;
            int bdigit=j>=0?b[j]-'0':0;
            int diff;
            if(adigit>=bdigit){
                diff=bdigit-adigit-borrow;
                borrow=0;
            }
            else{
                diff=10+bdigit-adigit;
                borrow=1;
            }
            ans[k]=diff+'0';
        }
    }
    else{
        ans[0]=0;
    }
    printf("a: %s\n",ans);
}
int main() {
    char a[101],b[101],ans[3][201];
    memset(ans,'\0',sizeof(ans));
    scanf("%s",a);
    scanf("%s",b);
    if(a[0]=='-' && b[0]=='-' || a[0]!='-' && b[0]!='-' ){
        char atemp[101],btemp[101];
        strncpy(atemp,a+1,strlen(a)-1);
        strncpy(btemp,b+1,strlen(b)-1);
        add(atemp,btemp,ans[0]);
        if(a[0]=='-' && b[0]=='-'){
            for(int i=strlen(ans[0]);i>0;i--){
                ans[0][i]=ans[0][i-1];
            }
            ans[0][0]='-';
        }
        sub(atemp,btemp,ans[1]);
        if(a[0]=='-' && b[0]=='-'){
            for(int i=strlen(ans[0]);i>0;i--){
                ans[1][i]=ans[0][i-1];
            }
            ans[1][0]='-';
        }
    }
    else if(a[0]=='-'){
        char atemp[101];
        strncpy(atemp,a+1,strlen(a)-1);
        sub(atemp,b,ans[0]);
        if(compare(atemp,b)==0){
            for(int i=strlen(ans[0]);i>0;i--){
                ans[0][i]=ans[0][i-1];
            }
            ans[0][0]='-';
        }
        add(atemp,b,ans[1]);
        for(int i=strlen(ans[0]);i>0;i--){
            ans[0][i]=ans[0][i-1];
        }
        ans[1][0]='-';
    }
    else{
        char btemp[101];
        strncpy(btemp,b+1,strlen(b)-1);
        sub(a,btemp,ans[0]);
        if(compare(a,btemp)==1){
            for(int i=strlen(ans[0]);i>0;i--){
                ans[0][i]=ans[0][i-1];
            }
            ans[0][0]='-';
        }
        add(a,btemp,ans[1]);
    }
    printf("b: %s\n%s",ans[0],ans[1]);
    return 0;
}