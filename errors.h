#ifndef ERRORS_H
#define ERRORS_H
#include <stdlib.h>
#include <stdio.h>

void cleaner();
int checkNumInt(int *vol);
int checkNumFloat(float *vol);
int checkRange (int *vol, int len);

#endif