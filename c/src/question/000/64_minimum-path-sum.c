/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 64. 最小路径和
 * link: https://leetcode-cn.com/problems/minimum-path-sum/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int minPathSumSolution1(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int m = *gridColSize;

    int **dp = NULL;

    dp = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(m * sizeof(int));
    }

    // first col
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int load1 = dp[i - 1][j] + grid[i][j];
            int load2 = dp[i][j - 1] + grid[i][j];
            dp[i][j] = MIN_VAL(load1,load2);
        }
    }

    return dp[n - 1][m - 1];
}

/*
 * 直接使用源数组，进行倒序的动态规划+贪心算法
 */

#define MIN_VAL(a,b) ((a) > (b) ? (b) : (a))

int minPathSumSolution2(int** grid, int gridSize, int* gridColSize)
{
    int i = 0;
    int j = 0;
    int row = gridSize;
    int col = *gridColSize;

    // 从grid[m][n]往前计算，最后返回grid[0][0]
    // printf("col %d, row %d \n", col, row);
    // 最后一行
    for (j = col - 2; j >= 0; j--) {
        grid[row - 1][j] += grid[row - 1][j + 1];
        // printf("grid[%d][%d] %d \n", row - 1, j, grid[row - 1][j]);
    }

    // 最后一列
    for (i = row - 2; i >= 0; i--) {
        grid[i][col - 1] += grid[i + 1][col - 1];
        // printf("grid[%d][%d] %d \n", i, col - 1, grid[i][col - 1]);
    }

    for (i = row - 2; i >= 0; i--) {
        for (j = col - 2; j >= 0; j--) {
            int min = MIN_VAL(grid[i][j+1], grid[i+1][j]);
            grid[i][j] += min;
            // printf("grid[%d][%d] %d \n", i, j, grid[i][j]);
        }
    }

    // grid[0][0] += MIN_VAL(grid[0][1], grid[1][0]);

    return grid[0][0];
}