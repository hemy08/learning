/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1011. 在 D 天内送达包裹的能力
 * link: https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

int averageWeight(int *weights, int weightsSize)
{
    int i;
    int sum = 0;
    for (i = 0; i < weightsSize; i++) {
        sum = sum + weights[i];
    }
    return sum / weightsSize;
}

int countShipWeight(int *weights, int weightsSize, int D, int Days)
{
    int cap = 0;
    int curW = 0;
    int curShip = D;
    int i;
    while (1) {
        // printf("start curShip %d\n", curShip);
        for (i = 0; i < weightsSize; i++) {
            if (curW + weights[i] > curShip) {
                curW = weights[i];
                cap = cap + 1;
                // printf("[%d] cap %d \n", i,cap);
            } else {
                curW = weights[i] + curW;
            }
            if (cap > Days) {
                curShip++;
                curW = 0;
                cap = 0;
                i = 0;
                curW = weights[i];
                continue;
            }
            // 处理最后一次循环
            if (i == weightsSize - 1) {
                cap = cap + 1;
                // printf("loop[%d] last cap %d days is %d\n", i,cap,D);
                if (cap <= Days) {
                    // printf("cap %d curShip %d\n",cap ,curShip);
                    return curShip;
                }
                // 不满足条件，继续循环
                curShip++;
                curW = 0;
                cap = 0;
                i = 0;
                curW = weights[i];
                continue;
            }
        }
    }
}
int shipWithinDays(int *weights, int weightsSize, int D)
{
    int *ptemp = 0;
    int maxWeight, averWeight, startD;

    ptemp = malloc(weightsSize * sizeof(int));
    memcpy(ptemp, weights, weightsSize * sizeof(int));
    qsort(ptemp, weightsSize, sizeof(weights[0]), QsortCmpArrayDescOrder);
    maxWeight = ptemp[0];
    averWeight = averageWeight(weights, weightsSize);
    startD = GetMaxValue(maxWeight, averWeight);
    return  countShipWeight(weights, weightsSize, startD, D);
}