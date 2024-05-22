#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{//stack
    int coeff;
    int power;
    struct _Node *next;
}Node;
typedef Node *NodeP;

int getCoeff(NodeP p,int power){
    while(p!=NULL){
        if(p->power==power)return p->coeff;
        p=p->next;
    }
    return 0;
}

void AddPower(NodeP *p){
    NodeP current=*p;
    int power=0;
    while(current!=NULL){
        current->power=power++;
        current = current->next;
    }
}
NodeP create(int coeff){
    NodeP newNode=malloc(sizeof(Node));
    newNode->coeff=coeff;
    newNode->power=0;
    newNode->next=NULL;
    return newNode;
}
void push(NodeP *p, int coeff) {
    NodeP newNode = create(coeff);
    newNode->next = *p;
    *p = newNode;
}
void inputPoly(NodeP *p){
    char input[100];
    NodeP newNode=NULL;
    scanf("%[^\n]",input);
    getchar();
    char *token=strtok(input, " ");
    while(token!=NULL){
        push(p, atoi(token));
        token=strtok(NULL, " ");
    }
    AddPower(p);
}
void printPoly(NodeP *p){
    int isFirst=1;
    NodeP current=*p;
    while(current!=NULL){
        if(isFirst){
            if(current->coeff==0)current=current->next;
            else if(current->coeff<0){
                printf("-%dx^%d", current->coeff,current->power);
                current=current->next;
                isFirst=0;
            }
            else{
                printf("%dx^%d", current->coeff, current->power);
                current=current->next;
                isFirst=0;
            }
        }
        else if(current->power==0){
            if(current->coeff<0){
                printf("-%d", current->coeff);
            }
            else if(current->power>0){
                printf("+%d", current->coeff);
            }
            return;
        }
        else{
            if(current->coeff==0)current=current->next;
            else if(current->power==1){
                printf("+x^%d", current->power);
                current=current->next;
            }
            else if(current->power==-1){
                printf("-x^%d", current->power);
                current=current->next;
            }
            else if(current->coeff<0){
                printf("-%dx^%d", current->coeff, current->power);
                current=current->next;
            }
            else{
                printf("+%dx^%d", current->coeff, current->power);
                current=current->next;
            }
        }
    }
    printf("\n");
}

int main(){
    NodeP node1,node2,node3,node4,node5;
    inputPoly(&node1);
    inputPoly(&node2);
    while(node1!=NULL || node2!=NULL){
        int i=0;
        int coeff=0;
        push(&node3,(getCoeff(node1,i)+getCoeff(node2, i)));
        printf("c:%d\n", getCoeff(node3,i));
        node3->power=i;
        push(&node4,(getCoeff(node1,i)-getCoeff(node2, i)));
        node4->power=i;
        push(&node5,(getCoeff(node1,i)*getCoeff(node2, i)));
        node5->power=i;
        i++;
    }
    printPoly(&node3);
    printPoly(&node4);
    printPoly(&node5);
}