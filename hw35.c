#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int time;
    int waiteNodeNum;
    int waiteNode[100];
    struct node_s* next;
}node_t;
typedef node_t* nodep;

nodep findNode(nodep p, int target){
    nodep current=p;
    for(int i = 0; i < target; i++) current = current->next;
    return current;
}
nodep create(int data){
    nodep newNode=(nodep)malloc(sizeof(node_t));
    newNode->time=data;
    newNode->next=NULL;
    return newNode;
}
void push(nodep *p, int data){
    nodep newNode = create(data);
    if(*p == NULL)*p = newNode;
    else{
        nodep current=(*p);
        while(current->next!=NULL) current=current->next;
        current->next=newNode;
    }
}
void findMaxWay(int *dist, nodep headnode, int index){
    for(int i = 0; i < findNode(headnode, index)->waiteNodeNum; i++){
        int waitNode = findNode(headnode, index)->waiteNode[i];
        if(dist[waitNode] < dist[index] + findNode(headnode, waitNode)->time){
            dist[waitNode] = dist[index] + findNode(headnode, waitNode)->time;
            findMaxWay(dist, headnode, waitNode);
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    int ans[N];
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        nodep projectData=NULL;
        for (int j = 0; j < M; j++) {
            int day,Amount;
            scanf("%d %d",&day, &Amount);
            push(&projectData, day);
            nodep current=findNode(projectData,j);
            current->waiteNodeNum=Amount;
            for (int k = 0; k < Amount; k++) {
                scanf("%d", &current->waiteNode[k]);
                current->waiteNode[k]--;
            }
        }
        int* dist=calloc(M, sizeof(int));
        for(int j=0;j<M;j++) dist[j]=findNode(projectData, j)->time;
        findMaxWay(dist, projectData, 0);
        ans[i]=0;
        for(int j=0; j<M; j++) if(dist[j] > ans[i]) ans[i] = dist[j];
        free(dist);
    }
    for (int i = 0; i < N; i++) printf("%d\n", ans[i]);
    return 0;
}