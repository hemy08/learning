/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 62. 不同路径
 * link: https://leetcode-cn.com/problems/unique-paths/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_NUM 101
int uniquePaths(int m, int n)
{
    unsigned int dp[MAX_NUM] = {1};

    // 横向第一行为1, 从0开始，可以把第一行初始化下
    for (int i = 0; i < m; i++) {
        // printf("\n 1");
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + dp[j];
            // printf("\t%d", dp[j]);
        }
    }
    
    return dp[n - 1];
}