#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
}node_t;
typedef node_t *nodep_t;

nodep_t create(int data) {
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(nodep_t *p, int data) {
    nodep_t newNode = create(data);
    if((*p)==NULL)*p=newNode;
    else{
        nodep_t current;
        current = *p;
        while(current->next!=NULL)current = current->next;
        current->next = newNode;
    }
}
void pop(nodep_t *p) {
    if ((*p)==NULL)
        printf("Queue is empty\n");
    else {
        printf("%d\n", (*p)->data);
        nodep_t current = (*p);
        (*p) = (*p)->next;
        free(current);
    }
}
void front(nodep_t *p){
    if((*p)==NULL)printf("Queue is empty\n");
    else{
        printf("%d\n", (*p)->data);
    }
}
void empty(nodep_t *p){
    if((*p)==NULL)printf("Queue is empty\n");
    else{
        nodep_t current;
        while((*p)!=NULL){
            current = (*p);
            (*p) = (*p)->next;
            free(current);
        }
    }
}
void print(nodep_t *p){
    if((*p)==NULL)printf("Queue is empty\n");
    else{
        nodep_t current = (*p);
        while(current!=NULL){
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main(){
    int N;
    nodep_t p = NULL;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int d;
        char cmd[10];
        scanf(" %s", cmd);
        if(strcmp(cmd, "push")==0){
            scanf(" %d", &d);
            push(&p, d);
        }
        else if(strcmp(cmd, "pop")==0){
            pop(&p);
        }
        else if(strcmp(cmd, "front")==0){
            front(&p);
        }
        else if(strcmp(cmd, "empty")==0){
            empty(&p);
        }
        else if(strcmp(cmd, "print")==0){
            print(&p);
        }
    }
}