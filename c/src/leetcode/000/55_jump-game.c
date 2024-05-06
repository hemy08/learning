/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 55. 跳跃游戏
 * link: https://leetcode-cn.com/problems/jump-game/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

bool canJump(int* nums, int numsSize)
{
    int fast = 0;

    for (int i = 0; i < numsSize; i++) {
        if (fast >= i) {
            fast = MAX_VAL(i + nums[i], fast);
        }

        if (fast > numsSize - 1) {
            return true;
        }
    }

    return false;
}