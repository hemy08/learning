/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1269. 停在原地的方案数
 * link: https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

#define MAX_STEPS 501
#define MAX_ARRLEN 500
#define DIV (1000000000 + 7)

long g_record[MAX_STEPS][MAX_ARRLEN];

bool judgeParamIsInvalid(int steps, int arrLen, int loc){
    if (steps <= 0 || loc < 0 || loc >= arrLen) {
        return true;
    }

    return false;
}

bool judgeLastStep(int steps, int arrLen, int loc){
    if (steps == 1 && (loc == 0 || loc == 1)) {
        return true;
    }

    return false;
}

long numWaysCalc(int steps, int arrLen, int loc){
    // 结束条件
    if (judgeParamIsInvalid(steps, arrLen, loc) == true) {
        return 0;
    }

    if (judgeLastStep(steps, arrLen, loc) == true) {
        return 1;
    }

    // 返回中间值
    if (g_record[steps][loc] != -1) {
        return g_record[steps][loc];
    }

    // 状态转移方程
    // f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1];
    long times = (numWaysCalc(steps - 1, arrLen, loc)
                  + numWaysCalc(steps - 1, arrLen, loc - 1)
                  + numWaysCalc(steps - 1, arrLen, loc + 1)) % DIV;

    // 返回值
    g_record[steps][loc] = times;
    return g_record[steps][loc];
}

int numWays1269(int steps, int arrLen){
    if (arrLen <= 1) {
        return steps;
    }

    memset(g_record, 0xFF, sizeof(long) * MAX_STEPS * MAX_ARRLEN);
    numWaysCalc(steps, arrLen, 0);

    return g_record[steps][0] % DIV;
}