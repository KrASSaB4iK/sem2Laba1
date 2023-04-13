#include "errors.h"

void cleaner() {
    scanf("%*[^\n]");
}

int checkNumInt(int *vol) {
    int num, status;
    status = scanf("%d", &num);
    while (status == 0 || status == -1) {
        if (status == -1) {
            printf("Don't break me, please");
            return -1;
        }
        printf("Incorrect number\n");
        cleaner();
        status = scanf("%d", &num);
    }
    *vol = num;
    return 0;
}

int checkNumFloat(float *vol) {
    int status;
    float num;
    status = scanf("%f", &num);
    while (status == 0 || status == -1) {
        if (status == -1) {
            printf("Don't break me, please");
            return -1;
        }
        printf("Incorrect number\n");
        cleaner();
        status = scanf("%f", &num);
    }
    *vol = num;
    return 0;
}

int checkRange (int *vol, int len) {
    int num, status;
    status = scanf("%d", &num);
    while (num < 0 || status == 0 || status == -1 || num >= len) {
        if (status == -1) {
            printf("Don't break me, please");
            return -1;
        }
        printf("Incorrect number\n");
        cleaner();
        status = scanf("%d", &num);
    }
    *vol = num;
    return 0;
}