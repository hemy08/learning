//
// Created by z00579768 on 2024/4/15.
//

#include "stdio.h"
#include "stdlib.h"
#include <time.h>

#define ARR_ROW_LEN  5
#define ARR_COL_LEN  5

// InitMatrix 初始化一个二维数组矩阵
int** InitMatrix(unsigned int row_size, unsigned int col_size) {
    int temp_num = 100;
    int **arr = NULL;

    arr = (int *) malloc(row_size * sizeof(unsigned int *));
    for (int row = 0; row < row_size; row++) {
        arr[row] = (int *) malloc(col_size * sizeof(unsigned int));
    }

    return arr;
}

void FreeMatrix(int **arr, unsigned int row_size) {
    for (int row = 0; row < row_size; row++) {
        free(arr[row]);
    }

    free(arr);
}

void PrintMatrixPtrAddr(int **arr, unsigned int row_size, unsigned int col_size) {
    for (int row = 0; row < row_size; row++) {
        for (int col = 0; col < col_size; col++) {
            printf("%p ", (void*)&arr[row][col]);
        }
        printf("\n");
    }
}

void RowTraversal(int **arr, unsigned int row_size, unsigned int col_size) {
    // 记录开始时间
    clock_t start_time = clock();
    for (int row = 0; row < row_size; row++) {
        for (int col = 0; col < col_size; col++) {
            arr[row][col] = row + col;
        }
    }
    // 记录结束时间
    clock_t end_time = clock();
    // 计算并打印运行时间（以秒为单位）
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("RowTraversal took %f seconds to execute\n", cpu_time_used);
}

void ColumnTraversal(int **arr, unsigned int row_size, unsigned int col_size) {
    // 记录开始时间
    clock_t start_time = clock();
    for (int row = 0; row < row_size; row++) {
        for (int col = 0; col < col_size; col++) {
            arr[col][row] = row + col;
        }
    }
    // 记录结束时间
    clock_t end_time = clock();
    // 计算并打印运行时间（以秒为单位）
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("ColumnTraversal took %f seconds to execute\n", cpu_time_used);
}

void PrintRunTime() {
    int **array = InitMatrix(ARR_ROW_LEN, ARR_COL_LEN);
    // RowTraversal(array,ARR_ROW_LEN,ARR_COL_LEN);
    // ColumnTraversal(array,ARR_ROW_LEN,ARR_COL_LEN);
    PrintMatrixPtrAddr(array, ARR_ROW_LEN, ARR_COL_LEN);
    FreeMatrix(array, ARR_ROW_LEN);
}