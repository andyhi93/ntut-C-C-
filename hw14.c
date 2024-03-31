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
void add(char a[103],char b[103],char ans[3][203],int index){
    int alen=strlen(a),blen=strlen(b),carry=0;
    int len=alen>blen?alen:blen;
    for(int i=alen-1,j=blen-1,k=len-1;i>=0||j>=0;i--,j--,k--){
        int adigit=i>=0?a[i]-'0':0;
        int bdigit=j>=0?b[j]-'0':0;
        int sum=adigit+bdigit+carry;
        ans[index][k]=sum%10+'0';
        carry=sum/10;
    }
    ans[index][len]='\0';
    if(carry){
        rpos(ans,index);
        ans[index][0]='1';
        ans[index][len+1]='\0';
    }
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
        ans[index][1]='\0';
        return;
    }
    int alen=strlen(atemp),blen=strlen(btemp),borrow=0;
    for(int i=alen-1,j=blen-1;i>=0||j>=0;i--,j--){
        int adigit=i>=0?atemp[i]-'0':0;
        int bdigit=j>=0?btemp[j]-'0':0;
        if(borrow==1){
            adigit-=1;
            borrow=0;
        }
        if(adigit<bdigit){
            borrow=1;
        }
        int diff=borrow*10+adigit-bdigit;
        ans[index][i]=diff+'0';
    }
    int h=0;
    for(int i=0;i<alen;i++){
        if(ans[index][i]!=0){
            h=i;
            break;
        }
    }
    strncpy(ans[index],ans[index]+h,strlen(ans[index]));
    ans[index][alen-h]='\0';
    if(ans[index][0]=='0'){
        lpos(ans,index);
    }
    if(pos){
        rpos(ans,index);
    }
}
void ze(char temp[103]){
    for(int i=0;i<103;i++){temp[i]='0';}
}
void mult(char a[102],char b[102],char ans[3][203],int index){
    int alen=strlen(a),blen=strlen(b);
    int len=102-alen-blen+2;
    char temp[103],product[202];
    product[0]='0';
    if(a[0]=='0' || b[0]=='0'){
        ans[index][0]='0';
        return;
    }
    for(int i=alen-1;i>=0;i--){
        for(int j=blen-1;j>=0;j--){
            ze(temp);
            int adigit=a[i]-'0';
            int bdigit=b[j]-'0';
            temp[len+i+j]=(temp[len+i+j]-'0')+(adigit*bdigit%10)+'0';
            temp[len+i+j-1]=(temp[len+i+j-1]-'0')+(adigit*bdigit/10)+'0';
            int h=0;
            for(int j=0;j<103;j++){
                if(temp[j]!='0'){
                    h=j;
                    break;
                }
            }
            strncpy(temp,temp+h,103);
            temp[103-h]='\0';
            add(ans[index],temp,ans,index);
        }
    }
    int h=0;
    for(int j=0;j<103;j++){
        if(ans[index][j]!='0'){
            h=j;
            break;
        }
    }
    strncpy(ans[index],ans[index]+h,103);
    ans[index][103-h]='\0';
}

int main(){
    char a[103],b[103],ans[3][203];
    int index=0;
    scanf("%s",a);
    scanf("%s",b);
    if(a[0]!='-'&&b[0]!='-'){
        add(a,b,ans,index++);
        printf("%s\n",ans[index-1]);
        sub(a,b,ans,index++);
        printf("%s\n",ans[index-1]);
        mult(a,b,ans,index);
        printf("%s\n",ans[index]);
    }
    else if(a[0]=='-'&&b[0]=='-'){
        char atemp[103],btemp[103];
        strncpy(atemp,a+1,strlen(a)-1);
        atemp[strlen(a)-1]='\0';
        strncpy(btemp,b+1,strlen(b)-1);
        btemp[strlen(b)-1]='\0';
        add(atemp,btemp,ans,index++);
        rpos(ans,index-1);
        printf("%s\n",ans[index-1]);
        sub(atemp,btemp,ans,index++);
        if(ans[index-1][0]=='-'){lpos(ans,index-1);}
        else{rpos(ans,index-1);}
        printf("%s\n",ans[index-1]);
        mult(atemp,btemp,ans,index);
        printf("%s\n",ans[index]);
    }
    else if(a[0]=='-' && b[0]=='0'){
        char atemp[102];
        strncpy(atemp,a+1,strlen(a)-1);
        atemp[strlen(a)-1]='\0';
        add(atemp,b,ans,index++);
        rpos(ans,index-1);
        printf("%s\n",ans[index-1]);
        add(atemp,b,ans,index++);
        rpos(ans,index-1);
        printf("%s\n",ans[index-1]);
        mult(atemp,b,ans,index);
        printf("%s\n",ans[index]);
    }
    else if(a[0]=='-'){
        char atemp[102];
        strncpy(atemp,a+1,strlen(a)-1);
        atemp[strlen(a)-1]='\0';
        sub(atemp,b,ans,index++);
        if(ans[index-1][0]=='-'){lpos(ans,index-1);}
        printf("%s\n",ans[index-1]);
        add(atemp,b,ans,index++);
        rpos(ans,index-1);
        printf("%s\n",ans[index-1]);
        mult(atemp,b,ans,index);
        rpos(ans,index);
        printf("%s\n",ans[index]);
    }
    else if(b[0]=='-' && a[0]=='0'){
        char btemp[102];
        strncpy(btemp,b+1,strlen(b)-1);
        btemp[strlen(b)-1]='\0';
        sub(a,btemp,ans,index++);
        printf("%s\n",ans[index-1]);
        add(a,btemp,ans,index++);
        printf("%s\n",ans[index-1]);
        mult(a,btemp,ans,index);
        printf("%s\n",ans[index]);
    }
    else{
        char btemp[102];
        strncpy(btemp,b+1,strlen(b)-1);
        btemp[strlen(b)-1]='\0';
        sub(a,btemp,ans,index++);
        printf("%s\n",ans[index-1]);
        add(a,btemp,ans,index++);
        printf("%s\n",ans[index-1]);
        mult(a,btemp,ans,index);
        rpos(ans,index);
        printf("%s\n",ans[index]);
    }
}