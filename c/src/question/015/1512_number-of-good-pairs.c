/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1512. 好数对的数目
 * link: https://leetcode-cn.com/problems/number-of-good-pairs/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/7/27.
 */

#include "public.h"

int numIdenticalPairs(int* nums, int numsSize)
{
    int dp[100] = {0};
    int count = 0;

    qsort(nums, numsSize, sizeof(int), QsortCmpArrayAscOrder);

    dp[count] = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            dp[count]++;
            continue;
        }

        count++;
        dp[count] = 1;
    }

    //printf("dp[0] %d, count %d \n", dp[0], count);
    int result = 0;
    int tmp = 0;
    for (int i = 0; i <= count; i++) {
        tmp = 0;
        if (dp[i] == 2) {
            tmp = 1;
        }

        if (dp[i] > 2) {
            tmp = (dp[i] * (dp[i] - 1)) / 2;
        }

        result += tmp;
    }

    return result;
}