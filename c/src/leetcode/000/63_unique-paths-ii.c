/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 63. 不同路径 II
 * link: https://leetcode-cn.com/problems/unique-paths-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int flag = 0;
    unsigned int **dp = obstacleGrid;

    if ((m == 0) || (n == 0)) return 0;

    // start或者finish在障碍物上，返回0
    if ((dp[0][0] == 1) || (dp[m - 1][n - 1] == 1)) return 0;

    dp[0][0] = 1;

    // 第一行先进行初始化, 1之前的全初始化为1，1包括之后的全初始化为0
    for (int i = 1; i < m; i++) {
        if (dp[i][0] == 1) {
            flag = 1;
            if (n == 1) return 0;
        }

        if (flag == 0) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }


    flag = 0;
    // 第一列先进行初始化, 1之前的全初始化为1，1包括之后的全初始化为0
    for (int j = 1; j < n; j++) {
        if (dp[0][j] == 1) {
            flag = 1;
            if (m == 1) return 0;
        }

        if (flag == 0) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[m - 1][n - 1];
}