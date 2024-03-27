#include <stdio.h>
#include <string.h>
int compare(char a[102],char b[102]){
    if(strlen(a)>strlen(b)){return 0;}
    else if(strlen(a)<strlen(b)){return 1;}
    else{
        int i=0;
        do{
            if(a[i]>b[i]){return 0;}
            else if(a[i]<b[i]){return 1;}
            else{i++;}
        }while(a[i]==b[i]);
    }
    return 2;
}
void lpos(char ans[3][203],int index){
    int len=strlen(ans[index]);
    for(int i=0;i<len;i++){
        ans[index][i]=ans[index][i+1];
    }
    ans[index][len]='\0';
}
void rpos(char ans[3][203],int index){
    int len=strlen(ans[index]);
    for(int i=strlen(ans[index]);i>0;i--){
        ans[index][i]=ans[index][i-1];
    }
    ans[index][0]='-';
    ans[index][len+1]='\0';
}
void add(char a[102],char b[102],char ans[3][203],int index){
    int alen=strlen(a),blen=strlen(b),carry=0;
    int len=alen>blen?alen:blen;
    for(int i=alen-1,j=blen-1,k=len-1;i>=0||j>=0;i--,j--,k--){
        int adigit=i>=0?a[i]-'0':0;
        int bdigit=j>=0?b[j]-'0':0;
        int sum=adigit+bdigit+carry;
        ans[index][k]=sum%10+'0';
        carry=sum/10;
        //printf("%d+%d=%d digit:%c carry:%d\n",adigit,bdigit,sum,ans[index][k],carry);
    }
    ans[index][len]='\0';
    if(carry){
        rpos(ans,index);
        ans[index][0]='1';
    }
    printf("add1:%s\n",ans[index]);
}
void sub(char a[102],char b[102],char ans[3][203],int index){
    char atemp[102],btemp[102];
    int pos=0;
    if(compare(a,b)==0){
        strcpy(atemp,a);
        strcpy(btemp,b);
    }
    else if(compare(a,b)==1){
        strcpy(btemp,a);
        strcpy(atemp,b);
        pos=1;
    }
    else{
        ans[index][0]='0';
        return;
    }
    printf("atemp:%s\nbteamp:%s\n",atemp,btemp);
    int alen=strlen(atemp),blen=strlen(btemp),borrow=0;
    for(int i=alen-1,j=blen-1;i>=0||j>=0;i--,j--){
        int adigit=i>=0?a[i]-'0':0;
        int bdigit=j>=0?b[j]-'0':0;
        if(borrow==1){
            adigit-=1;
            borrow=0;
        }
        if(adigit<bdigit){
            borrow=1;
        }
        int diff=borrow*10+adigit-bdigit;
        ans[index][alen]=diff+'0';
        printf("%d-%d=%d digit:%c borrow:%d\n",adigit,bdigit,diff,ans[index][i],borrow);
    }
    int h=0;
    for(int i=0;i<alen;i++){
        if(ans[index][i]!=0){
            h=i;
            break;
        }
    }
    strncpy(ans[index],ans[index]+h,strlen(ans[index]));
    if(pos){
        rpos(ans,index);
    }
    printf("sub1:%s\n",ans[index]);
}
void mult(char a[102],char b[102],char ans[3][203],int index){}

int main(){
    char a[102],b[102],ans[3][203];
    int index=0;
    scanf("%s",a);
    scanf("%s",b);
    if(a[0]!='-'&&b[0]!='-'){
        add(a,b,ans,index++);
        printf("add:%s\n",ans[index-1]);
        sub(a,b,ans,index++);
        printf("sub:%s\n",ans[index-1]);
        mult(a,b,ans,index);
    }
    else if(a[0]=='-'&&b[0]=='-'){
        char atemp[102],btemp[102];
        strncpy(atemp,a+1,strlen(a)-1);
        atemp[strlen(a)-1]='\0';
        printf("atemp:%s\n",atemp);
        strncpy(btemp,b+1,strlen(b)-1);
        atemp[strlen(b)-1]='\0';
        printf("btemp:%s\n",btemp);
        add(atemp,btemp,ans,index++);
        rpos(ans,index-1);
        printf("add:%s\n",ans[index-1]);
        sub(atemp,btemp,ans,index++);
        if(ans[index-1][0]=='-'){lpos(ans,index-1);}
        else{rpos(ans,index-1);}
        printf("sub:%s\n",ans[index-1]);
        mult(atemp,btemp,ans,index);
    }
    else if(a[0]=='-'){
        char atemp[102];
        strncpy(atemp,a+1,strlen(a)-1);
        atemp[strlen(a)-1]='\0';
        printf("ateamp:%s\n",atemp);
        sub(atemp,b,ans,index++);
        add(atemp,b,ans,index++);
        rpos(ans,index-1);
        printf("sub:%s\n",ans[index-1]);
        mult(atemp,b,ans,index);
        rpos(ans,index);
    }
    else{
        char btemp[102];
        strncpy(btemp,b+1,strlen(b)-1);
        btemp[strlen(b)-1]='\0';
        printf("btemp:%s\n",btemp);
        sub(a,btemp,ans,index++);
        add(a,btemp,ans,index++);
        printf("sub:%s\n",ans[index-1]);
        mult(a,btemp,ans,index);
        rpos(ans,index);
    }
}