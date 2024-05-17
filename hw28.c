#include <stdio.h>
#include <stdlib.h>

typedef struct _project {
    int day, taskAmount, task[100];
} project;

int max(int a, int b) {return a > b ? a : b;}

void calculate(int node, project *projectData, int *dp) {
    if (dp[node] != -1) return; // If already calculated, return

    int maxTime = 0;
    for (int i = 0; i < projectData[node].taskAmount; i++) {
        int preTask = projectData[node].task[i] - 1; // Convert 1-based to 0-based
        calculate(preTask, projectData, dp);
        maxTime = max(maxTime, dp[preTask]);
    }

    dp[node] = projectData[node].day + maxTime;
}

int main() {
    int N;
    scanf("%d", &N);
    int ans[N];
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        project projectData[M];
        for (int j = 0; j < M; j++) {
            int Amount;
            scanf("%d %d", &projectData[j].day, &Amount);
            projectData[j].taskAmount = Amount;
            for (int k = 0; k < Amount; k++) {
                scanf("%d", &projectData[j].task[k]);
            }
        }

        int dp[M];
        for (int j = 0; j < M; j++) dp[j] = -1; // Initialize dp array

        int totalTime = 0;
        for (int j = 0; j < M; j++) {
            calculate(j, projectData, dp);
            totalTime = max(totalTime, dp[j]);
        }
        ans[i] = totalTime;
    }
    for(int i=0;i<N;i++)printf("%d\n",ans[i]);
    return 0;
}
