#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GCD(int a,int b){
    a=abs(a);
    b=abs(b);
    if(b>a){
        int temp=a;
        a=b;
        b=temp;
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void mfraction(int numerator,int denominator,char temp[100],int *z){
    int g=GCD(numerator,denominator);
    if(numerator%denominator!=0){
        if(numerator*denominator>0){
            sprintf(temp,"y = %d/%dx",abs(numerator/g),abs(denominator/g));
        }
        else{
            sprintf(temp,"y = -%d/%dx",abs(numerator/g),abs(denominator/g));
        }
    }
    else if(numerator/denominator==0){
        *z=1;
        sprintf(temp,"y = ");
    }
    else{
        if(numerator/denominator==1){
            sprintf(temp,"y = x");
        }
        else if(numerator/denominator==-1){
            sprintf(temp,"y = -x");
        }
        else{
            sprintf(temp,"y = %dx",numerator/denominator);
        }
    }
}

void bfraction(int numerator,int denominator,char ans[100],int z){
    int g=GCD(numerator,denominator);
    if(numerator%denominator!=0){
        if(numerator*denominator>0){
            if(z==1){
                sprintf(ans,"%d/%d",abs(numerator/g),abs(denominator/g));
            }
            else{
                sprintf(ans," + %d/%d",abs(numerator/g),abs(denominator/g));
            }
        }
        else{
            if(z==1){
                sprintf(ans,"-%d",abs(numerator/g),abs(denominator/g));
            }
            else{
                sprintf(ans," - %d/%d",abs(numerator/g),abs(denominator/g));
            }
        }
    }
    else if(numerator/denominator==0){
        sprintf(ans,"");
    }
    else{
        if(numerator/denominator>0){
             if(z==1){
                sprintf(ans,"%d",numerator/denominator);
            }
            else{
                sprintf(ans," + %d",numerator/denominator);
            }
        }
        else{
            if(z==1){
                sprintf(ans,"-%d",abs(numerator/denominator));
            }
            else{
                sprintf(ans," - %d",-numerator/denominator);
            }
        }
    }
}

int main(){
    int times,x1,y1,x2,y2,z;
    char ans[5][100],temp[100];
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        z=0;
        scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
        mfraction(y1-y2,x1-x2,ans[i],&z);
        bfraction(x2*y1-x1*y2,x2-x1,temp,z);
        strcat(ans[i],temp);
    }
    for(int i=0;i<times;i++){
        printf("%s\n",ans[i]);
    }
}