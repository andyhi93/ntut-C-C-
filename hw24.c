#include <stdio.h>
#include <string.h>

typedef struct student_s{
    char name[50];
    int score;
}student_t;
void input(student_t s[], int n){
    int inputPoint;
    char inputstr[50];
    for(int i=0;i<n;i++){
        scanf(" %s",inputstr);
        scanf(" %d",&inputPoint);
        strcpy(s[i].name,inputstr);
        s[i].score=inputPoint;
    }
}
void getHigh(student_t s[], int n, char name[]){
    int maxPoint=0,index;
    for(int i=0;i<n;i++){
        if(s[i].score>maxPoint){
            maxPoint=s[i].score;
            index=i;
        }
    }
    strcpy(name,s[index].name);
}
int getAverage(student_t s[], int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=s[i].score;
    return sum/n;
}
int main(){
    int N;
    char maxName[50];
    student_t student_data[15];
    scanf("%d",&N);
    input(student_data,N);
    getHigh(student_data,N,maxName);
    printf("%s\n",maxName);
    printf("%d",getAverage(student_data,N));
}