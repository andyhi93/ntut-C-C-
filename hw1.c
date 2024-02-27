#include <stdio.h>
#include <math.h>
int main(){
    float w,h;
    scanf("%f",&w);
    scanf("%f",&h);
    h/=100;
    printf("%.1f",round(w/(h*h)*10)/10);
}