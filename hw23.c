#include <stdio.h>
#include <string.h>

typedef enum scoreType_s{G,GPA,S}scoreType_t;
typedef enum G_s{Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X}G_t;
typedef enum GPA_s{b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0}GPA_t;
typedef enum S_s{b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0}S_t;
typedef union student_s{
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
}student_t;
typedef struct student {
    int id;
    int scores[4];
    int average_score;
} student_data;

int FindIndex(char input_str[10],char rank[11][10]){
    for(int i=0;i<11;i++){
        if(strcmp(input_str,rank[i])==0)return i;
    }printf("find worng\n");
    return -1;
}

int main(){int M,N;
    char temp[10],
    G_rank[11][10]={"A-","A","A-","B+","B","B-","C+","C","C-","F","X"},
    GPA_rank[11][10]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","1","0"},
    S_rank[11][10]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","1-59","0"};
    int intPoint[11]={95,87,82,78,75,70,68,65,60,50,0};
    scoreType_t course_types[4];
    student_data students[10];
    student_t grades;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf(" %s",temp);
        if(strcmp(temp,"G")==0)course_types[i]=G;
        else if(strcmp(temp,"GPA")==0)course_types[i]=GPA;
        else if(strcmp(temp,"S")==0)course_types[i]=S;
        else printf("wrong\n");
    }
    scanf(" %d",&N);
    for(int i=0;i<N;i++){
        int id,averageScore;
        char score[3][10],input_str[10];
        students[i].average_score = 0;
        scanf(" %d",&id);
        students[i].id = id;
        for(int j=0;j<M;j++){
            switch (course_types[j])
            {
            int index;
            case G:
                scanf("%s",input_str);
                index=FindIndex(input_str,G_rank);
                break;
            case GPA:
                scanf("%s",input_str);
                index=FindIndex(input_str,GPA_rank);
                break;
            case S:
                scanf("%s",input_str);
                index=FindIndex(input_str,S_rank);
                break;
            default:
                printf("something wrong\n");
            }
        }
    }
}