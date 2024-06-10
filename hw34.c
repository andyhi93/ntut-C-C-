//前序遍歷（Pre-order Traversal） 順序為：根節點 -> 左子樹 -> 右子樹 第一個為根
//中序遍歷（In-order Traversal） 順序為：左子樹 -> 根節點 -> 右子樹 從小排到大
//後序遍歷（Post-order Traversal）順序為：左子樹 -> 右子樹 -> 根節點 最後一個為根
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree_t {
    char data;
    struct tree_t * right, * left;
} tree_t;
typedef tree_t * btree;

btree create_node(char data) {
    btree node = (btree)malloc(sizeof(tree_t));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
btree P_I_tree(char *dataP,char *dataI,int start,int end,int *preIndex) {
    if (start > end) return NULL;
    char Proot_data = dataP[*preIndex];
    btree root = create_node(Proot_data);
    (*preIndex)++;
    if (start == end) return root;
    int in_index;
    for (in_index = start; in_index <= end; in_index++) {
        if (dataI[in_index] == Proot_data) break;
    }
    root->left = P_I_tree(dataP, dataI, start, in_index - 1, preIndex); //比目前節點小
    root->right = P_I_tree(dataP, dataI, in_index + 1, end, preIndex); //比目前節點大
    return root;
}
btree O_I_tree(char *dataO, char *dataI, int start, int end, int *postIndex) {
    if (start > end) return NULL;
    char root_data = dataO[*postIndex];
    btree root = create_node(root_data);
    (*postIndex)--;
    if (start == end) return root;
    int in_index;
    for (in_index = start; in_index <= end; in_index++) {
        if (dataI[in_index] == root_data)break;
    }
    root->right = O_I_tree(dataO, dataI, in_index + 1, end, postIndex);
    root->left = O_I_tree(dataO, dataI, start, in_index - 1, postIndex);
    return root;
}
void print_tree(btree root) {
     if (root == NULL) return;
    btree queue[100];
    int start = 0, end = 0;
    queue[end++] = root;
    while (start < end) {
        btree current = queue[start++];
        printf("%c", current->data);
        if (current->left) queue[end++] = current->left;
        if (current->right) queue[end++] = current->right;
    }
}
int main(){
    btree binaryTree=NULL;
    char cmd[2],data[2][21],temp;
    for(int i=0;i<2;i++){
        scanf("%c",&cmd[i]);
        scanf("%c", &temp);
        scanf("%[^\n]", data[i]);
        scanf("%c", &temp);
    }
    if((cmd[0]=='P' && cmd[1]=='I') || (cmd[0]=='I' && cmd[1]=='P')){
        int preIndex=0;
        if(cmd[0]=='P') binaryTree=P_I_tree(data[0],data[1],0,strlen(data[0])-1,&preIndex);
        else binaryTree=P_I_tree(data[1],data[0],0,strlen(data[1])-1,&preIndex);
    }
    else if((cmd[0]=='O' && cmd[1]=='I') || (cmd[0]=='I' && cmd[1]=='O')){
        int postIndex = strlen(data[0]) - 1;
        if (cmd[0] == 'O') binaryTree = O_I_tree(data[0], data[1], 0, strlen(data[0]) - 1, &postIndex);
        else binaryTree = O_I_tree(data[1], data[0], 0, strlen(data[1]) - 1, &postIndex);
    }
    print_tree(binaryTree);
}