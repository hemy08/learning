/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/8/31.
 */

#include "public.h"


int maxProfit(const int* prices, int pricesSize) {
    int begin = 0;
    int end = 0;
    int profit = 0;

    for (int index = 1; index < pricesSize; index++) {
        if (prices[index] <= prices[end]) {
            profit = profit + prices[end] - prices[begin];
            begin = index;
        }
        end = index;
    }

    profit = profit + prices[end] - prices[begin];
    return profit;
}

#define MAX(a,b) (a) > (b) ? (a) : (b)

int maxProfitDP(const int* prices, int pricesSize) {
    int dayHave = 0;
    int dayNoHave = 0 - prices[0];

    for (int index = 1; index < pricesSize; index++) {
        // 当天手中有股票 = max（前一天有股票今天不出售， 前一天没有股票但以今天的价格买入）
        int curHave = MAX(dayHave, dayNoHave - prices[index]);
        // 当天手中没有股票 = max（前一天没有股票今天不买入， 前一天有股票但以今天的价格出售）
        int curNoHave = MAX(dayNoHave, dayHave + prices[index]);
        dayHave = curHave;
        dayNoHave = curNoHave;
    }
    return dayNoHave;
}