/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:329. 矩阵中的最长递增路径
 * link:https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/4.
 */

#include "public.h"

const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, columns;

int longestIncreasingPathDfs(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    rows = matrixSize;
    columns = matrixColSize[0];

    int** memo = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        memo[i] = (int*)malloc(sizeof(int) * columns);
        memset(memo[i], 0, sizeof(int) * columns);
    }
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            ans = fmax(ans, dfs(matrix, i, j, memo));
        }
    }
    free(memo);
    return ans;
}

int dfs(int** matrix, int row, int column, int** memo) {
    if (memo[row][column] != 0) {
        return memo[row][column];
    }
    ++memo[row][column];
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
        if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
            memo[row][column] = fmax(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
        }
    }
    return memo[row][column];
}


//const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//int rows, columns;

typedef struct point {
    int x, y;
} point;

int longestIncreasingPathTps(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    rows = matrixSize;
    columns = matrixColSize[0];

    int** outdegrees = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        outdegrees[i] = (int*)malloc(sizeof(int) * columns);
        memset(outdegrees[i], 0, sizeof(int) * columns);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            for (int k = 0; k < 4; ++k) {
                int newRow = i + dirs[k][0], newColumn = j + dirs[k][1];
                if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                    ++outdegrees[i][j];
                }
            }
        }
    }

    point* q = (point*)malloc(sizeof(point) * rows * columns);
    int l = 0, r = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (outdegrees[i][j] == 0) {
                q[r++] = (point){i, j};
            }
        }
    }
    int ans = 0;
    while (l < r) {
        ++ans;
        int size = r - l;
        for (int i = 0; i < size; ++i) {
            point cell = q[l++];
            int row = cell.x, column = cell.y;
            for (int k = 0; k < 4; ++k) {
                int newRow = row + dirs[k][0], newColumn = column + dirs[k][1];
                if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                    --outdegrees[newRow][newColumn];
                    if (outdegrees[newRow][newColumn] == 0) {
                        q[r++] = (point){newRow, newColumn};
                    }
                }
            }
        }
    }
    return ans;
}