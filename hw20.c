    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct{
        char key[21];
        int value;
    }KeyValuePair;

    int KeyFind(KeyValuePair *dict,char target[21],int count){
        for(int i=0;i<count;i++){
            if(strcmp(dict[i].key,target)==0){
                return i;
            }
        }
        return -1;
    }

    int compareDict(const void *a, const void *b) {
        KeyValuePair *pair1 = (KeyValuePair *)a;
        KeyValuePair *pair2 = (KeyValuePair *)b;
        if (pair1->value > pair2->value) {
            return -1;
        } else if (pair1->value < pair2->value) {
            return 1;
        } else {
            return strcmp(pair1->key, pair2->key);
        }
    }


    int main(){
        char input[100],A[21],B[21],Vocabulary[50][21],*token,ans1[100]="\0",ans2[100]="\0",ans3[100]="\0";
        int count=0,dcount=0;
        KeyValuePair dict[50];
        scanf("%99[^\n]",input);
        scanf(" %s",A);
        scanf(" %s",B);
        //printf("%s\n%s\n%s\n",input,A,B);
        token=strtok(input," ");
        while (token!=NULL){
            strcpy(Vocabulary[count++],token);
            token=strtok(NULL," ");
        }
        for(int i=0;i<count;i++){
            printf("ans1:%s %d %d+",ans1,strlen(ans1),sizeof(ans1));
            int dindex=KeyFind(dict,Vocabulary[i],dcount);
            if(dindex==-1){
                strcpy(dict[dcount].key,Vocabulary[i]);
                dict[dcount++].value=1;
            }
            else{
                dict[dindex].value+=1;
            }
            if(strcmp(Vocabulary[i],A)==0){
                strcat(ans1,B);
                strcat(ans1," ");

                strcat(ans2,B);
                strcat(ans2," ");
                strcat(ans2,A);
                strcat(ans2," ");
            }
            else{
                strcat(ans1,Vocabulary[i]);
                strcat(ans1," ");

                strcat(ans2,Vocabulary[i]);
                strcat(ans2," ");
                
                strcat(ans3,Vocabulary[i]);
                strcat(ans3," ");
            }
            printf("%s %d %d\n",Vocabulary[i],strlen(Vocabulary[i]),sizeof(Vocabulary[i]));
        }
        printf("%s\n%s\n%s\n",ans1,ans2,ans3);
        qsort(dict, dcount, sizeof(KeyValuePair), compareDict);
        for(int i=0;i<dcount;i++){printf("%s %d\n",dict[i].key,dict[i].value);}
        //system("pause");
    }