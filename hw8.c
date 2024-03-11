#include <stdio.h>
#include <string.h>

void G(int n, int k, char *tmp) {
    if (n == 1) {
        char t[12];
        sprintf(t, "%d", k);
        strcat(tmp, t);
    } else if (k < (1 << (n - 1))) {
        strcat(tmp, "0");
        G(n - 1, k, tmp);
    } else if (k >= (1 << (n - 1))) {
        strcat(tmp, "1");
        G(n - 1, (1 << n) - 1 - k, tmp);
    }
}

int main() {
    char input[100], tmp[100], ans[100][20];
    int input1, input2, times = 0;

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "-1") == 0) {
            break;
        }
        if (sscanf(input, "%d %d", &input1, &input2) != 2) {
            break;
        }
        strcpy(tmp, "");
        G(input1, input2, tmp);
        strcpy(ans[times], tmp);
        times++;
    }
    for (int i = 0; i < times; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}
