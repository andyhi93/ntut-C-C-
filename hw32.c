#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* front;
    struct node* back;
} node;
typedef node* nodep;

nodep create(int data) {
    nodep newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->front = NULL;
    newnode->back = NULL;
    return newnode;
}

void AddFront(nodep* head, nodep* tail, int data) {
    nodep newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
        newnode->front = newnode;
        newnode->back = newnode;
    } else {
        newnode->back = *head;
        newnode->front = (*tail);
        (*head)->front = newnode;
        (*tail)->back = newnode;
        *head = newnode;
    }
}

void AddBack(nodep* head, nodep* tail, int data) {
    nodep newnode = create(data);
    if (*tail == NULL) {
        *head = newnode;
        *tail = newnode;
        newnode->front = newnode;
        newnode->back = newnode;
    } else {
        newnode->front = *tail;
        newnode->back = (*head);
        (*head)->front = newnode;
        (*tail)->back = newnode;
        *tail = newnode;
    }
}

void RemoveFront(nodep* head, nodep* tail) {
    if (*head == NULL) printf("Double link list is empty\n");
    else{
        nodep temp = *head;
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            (*tail)->back = (*head)->back;
            (*head)->back->front = *tail;
            *head = (*head)->back;
        }
        free(temp);
    }
}

void RemoveBack(nodep* head, nodep* tail) {
    if (*tail == NULL) printf("Double link list is empty\n");
    else{
        nodep temp = *tail;
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            (*head)->front = (*tail)->front;
            (*tail)->front->back = *head;
            *tail = (*tail)->front;
        }
        free(temp);
    }
}

void empty(nodep* head, nodep* tail) {
    if (*head == NULL) printf("Double link list is empty\n");
    else while (*head != NULL) RemoveFront(head, tail);
}
void insert(nodep* head, nodep* tail,int target, int data) {
    nodep newnode = create(data),current= (*head);
    int index=1;
    while(target!=index && current->back!=(*head)){
        current=current->back;
        index++;
    }
    if(index!=target) {
        printf("Invalid command\n");
        free(newnode);
        return;
    }
    else{
        newnode->front=current;
        newnode->back=current->back;
        current->back->front=newnode;
        current->back=newnode;
    }
}
void removeT(nodep* head, nodep* tail,int target) {
    nodep current= (*head);
    int index=1;
    while(target!=index && current->back!=(*head)){
        current=current->back;
        index++;
    }
    if(index!=target) {
        printf("Invalid command\n");
        return;
    }
    if(current==*head)RemoveFront(head, tail);
    else if(current==*tail)RemoveBack(head, tail);
    else{
        current->front->back=current->back;
        current->back->front=current->front;
    }
    free(current);
}
void print(nodep* head, nodep* tail) {
    if (*head == NULL) printf("Double link list is empty\n");
    else{
        nodep current= (*head);
        do {
            printf("%d\n", current->data);
            current = current->back;
        } while (current != (*head));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    nodep head = NULL;
    nodep tail = NULL;
    for (int i = 0; i < n; i++) {
        char cmd[20];
        scanf(" %s", cmd);
        if(strcmp(cmd,"addFront")==0){
            int data;
            scanf("%d", &data);
            AddFront(&head, &tail, data);
        }
        else if(strcmp(cmd, "addBack")==0){
            int data;
            scanf("%d", &data);
            AddBack(&head, &tail, data);
        }
        else if(strcmp(cmd, "removeFront")==0){
            RemoveFront(&head, &tail);
        }
        else if(strcmp(cmd, "removeBack")==0){
            RemoveBack(&head, &tail);
        }
        else if(strcmp(cmd, "empty")==0){
            empty(&head, &tail);
        }
        else if(strcmp(cmd, "insert")==0){
            int target,data;
            scanf("%d %d", &target, &data);
            insert(&head, &tail, target, data);
        }
        else if(strcmp(cmd, "remove")==0){
            int target;
            scanf("%d", &target);
            removeT(&head, &tail, target);
        }
        else if(strcmp(cmd, "print")==0){
            print(&head, &tail);
        }
        else printf("Invalid command\n");
    }
}