#include <stdio.h>
#include <math.h>
float ft(float a){
    if(a==-0){return 0;}
    return round(a*10)/10;
}
int main(){
    float a,b,c,d;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    d=b*b-4*a*c;
    if(d>0){
        printf("%.1f\n%.1f",ft((-b+sqrt(d))/2/a),ft((-b-sqrt(d))/2/a));
    }
    else if(d==0){
        printf("%.1f\n%.1f",ft(-b/2/a),ft(-b/2/a));
    }
    else{
        printf("%.1f+%.1fi\n%.1f-%.1fi",ft(-b/2/a),ft(sqrt(-d)/2/a),ft(-b/2/a),ft(sqrt(-d)/2/a));
    }
}