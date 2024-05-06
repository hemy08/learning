/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 799. 香槟塔
 * link: https://leetcode-cn.com/problems/champagne-tower/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/8.
 */

#include "public.h"

double champagneTower(int poured, int query_row, int query_glass){
    int i=0;
    int j=0;
    float a[query_row+1];
    float b[query_row+1];
    a[0] = poured;
    for(i=1; i<= query_row; i++)
    {
        memset(b, 0, sizeof(b));   //一开始失误放到里面的for循环中了
        for(j=0;j<i;j++)
        {

            b[j] += a[j]>1?(a[j]-1)*0.5:0;
            b[j+1] += a[j]>1?(a[j]-1)*0.5:0;
        }
        memcpy(a, b, sizeof(b));    //一开始失误放到里面的for循环中了
    }
    return a[query_glass]<1?a[query_glass]:1;
}


double champagneTower2(int poured, int query_row, int query_glass)
{
    double dp[100][100] = {0};

    memset(dp, 0, sizeof(dp));

    // poured杯， 第i行 = poured - 第i-1行占用的杯数
    int glasses = 0;
    int reserved = 0;
    int i,j,k;
    if (poured == 0) {
        return 0.0;
    }
    dp[0][0] = poured;
    for (i = 1; i <= query_row; i++) {
        for (j = 0; j <= i; j++) {
            if (dp[i - 1][j] > 1){
                dp[i][j] += (dp[i - 1][j] - 1) * 0.5;
                dp[i][j + 1] += (dp[i - 1][j] - 1) * 0.5;
            }
        }
    }

    if (dp[query_row][query_glass] >= 1) {
        return 1;
    }
    return dp[query_row][query_glass];
}