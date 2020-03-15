﻿#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct line {
    int n;
    int* arr;
} line;

typedef struct matrix {
    int m;
    line* pt;
} matrix;

int getInt(int* a) {
    int n;
    do {
        n = scanf_s("%d", a);
        if (n < 0)
            return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf_s("%*[^\n]", 0);
        }
    } while (n == 0);
    return 1;
}

void input(int** pointer)
{
    int length;
    int* ptr;
    int flag;
    int i;

    printf("vvedite kolichestvo elementov\n");

    do {
        getInt(&length);
        if (length < 1)
            printf("%s\n", "Error! Repeat input");
    } while (length < 1);
    *pointer = (int*)malloc((length + 1) * sizeof(int));
    ptr = *pointer;
    *ptr = length;
    flag = 1;
    for (i = 0; i < length; i++) {
        ptr++;
        *ptr = rand() % 20001 - 10000;
    }
}


void print(int** pointer) {
    int i;
    int* pointr = *pointer;
    for (i = 0; i < **pointer; i++) {
        pointr++;
        printf(" %d ", *pointr);
    }
    printf("\n");
}


void summa(int** pointer, int* vptr) {
    int i, k;
    int* ptr;
    int chet = 0, nechet = 0;
    int sum = 0;

    ptr = *pointer;

    for (i = 0; i < **pointer; ++i) {
        ptr++;
        k = *ptr;
        if (k % 2 == 0)
        {
            chet = chet + k;
        }
        else
        {
            nechet = nechet + k;
        }

        *vptr = chet - nechet;
    }
}



void erase(int** pointer)
{
    free(*pointer);
    *pointer = NULL;

}


int main() {
    int m, i;
    struct matrix matrix;
    int* vector;
    int* ptr;
    int* vecptr;
    int** pointarr;
    int** ptrarr;

    printf("vvedite kolichestvo strok\n");
    do {

        getInt(&m);
        if (m < 1)
            printf("%s\n", "Error! Repeat input");
    } while (m < 1);
    pointarr = (int**)malloc(m * sizeof(int*));
    ptrarr = pointarr;
    vector = (int*)malloc(m * sizeof(int));
    vecptr = vector;
    srand(time(0));
    for (i = 0; i < m; i++) {
        input(ptrarr);
        summa(ptrarr, vecptr);
        vecptr++;
        ptrarr++;
    }

    ptrarr = pointarr;
    printf("\nVvedennaya matrisa: \n");
    for (i = 0; i < m; i++) {
        print(ptrarr);
        ptrarr++;
    }

    vecptr = vector;
    printf("\nVECTOR\n");
    for (i = 0; i < m; i++) {
        printf("%d ", *vecptr);
        vecptr++;
    }

    ptrarr = pointarr;

    for (i = 0; i < m; i++) {
        erase(ptrarr);

        ptrarr++;
    }

    free(vector);


    return 0;
}