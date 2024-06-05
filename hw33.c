#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int city;
    struct queue *next,*last;
} queue;
typedef queue *queuePtr;

queuePtr create(queuePtr *p,int city){
    queuePtr newNode = (queuePtr)malloc(sizeof(queue));
    newNode->city = city;
    newNode->next = NULL;
    newNode->last = NULL;
    return newNode;
}
void push(queuePtr *p, int city){
    queuePtr newNode = create(p, city);
    if(*p == NULL){
        *p = newNode;
    }
    else{
        queuePtr current=(*p);
        while(current->next!=NULL) current=current->next;
        current->next=newNode;
        newNode->last=current;
    }
}
void empty(queuePtr *p){
    queuePtr head = (*p),tail=(*p);
    while(head->last!=NULL) head=head->last;
    while(head!=NULL){
        while(tail->next!=NULL) tail=tail->next;
        free(tail);
    }
}
queuePtr* FindEmpty(queuePtr p[]){
    int i=0;
    while(p[i]!=NULL) i++;
    return &p[i];
}
queuePtr copyRoad(queuePtr *currnetRoad,queuePtr RoadData[]){
    queuePtr *newRoad=(queuePtr)FindEmpty(RoadData);
    queuePtr current=(*currnetRoad);
    while(current->last!=NULL) current=current->last;
    while(current!=NULL){
        push(newRoad, current->city);
        current=current->next;
    }
    return *newRoad;
}
void Find(queuePtr RoadData[],queuePtr *currentRoad,int map[][2],int s,int e){
    if((*currentRoad)==NULL){
        currentRoad = FindEmpty(RoadData);
        push(currentRoad, s);
        Find(RoadData,currentRoad,map, s, e);
    }
    else{
        for(int i=0;map[i]!=NULL;i++){
            if(map[i][0]==s || map[i][1]==s){
                int next=(map[i][0]==s)?map[i][1]:map[i][0];
                queuePtr front=(*currentRoad);
                while(front->next!=NULL) front=front->next;
                if(front->city!=s){
                    Find(RoadData,copyRoad(currentRoad,RoadData),map,s,e);
                }
            }
        }
    }
}
int main(){
    int input[4];//n s e y
    char temp[20];
    scanf("%[^\n]",temp);
    char *token = strtok(temp, " ");
    int i=0;
    while(token != NULL){
        input[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    if(i!=4)input[4]=0;
    int map[input[0]][2];
    for(int i=0;i<input[0];i++){
        scanf(" %d %d", &map[i][0], &map[i][1]);
    }
    queuePtr allRoad[100];
}