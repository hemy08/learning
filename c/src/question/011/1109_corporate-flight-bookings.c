/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1109. 航班预订统计
 * link: https://leetcode-cn.com/problems/corporate-flight-bookings/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/3.
 */

#include "public.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_BOOK_LIST 20002

/*
 * 暴力处理，这个会超时
 * */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    if (bookingsColSize = NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *dp = (int*)malloc(sizeof(int) * MAX_BOOK_LIST);
    memset(dp, 0, sizeof(int) * MAX_BOOK_LIST);

    *returnSize = n;
    int start = 0;
    int end = 0;
    int books = 0;
    for (int i = 0; i<bookingsSize; i++) {
        start = bookings[i][0];
        end = bookings[i][1];
        books = bookings[i][2];
        if ((start < 1) || (end > n)) {
            *returnSize = 0;
            return NULL;
        }

        for (int j = start; j <= end; j++) {
            dp[j - 1] += books;
        }
    }

    return dp;
}


/*
 * 首先，这个题目可以转换成dp[i] = dp[i] + dp[i - 1]
 * 以bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5为例
 * 1、dp[0]......dp[5] 全部初始化为0
 * 2、[1,2,10] --- dp[0] += 10, dp[2] -= 10 这样，按照上面的dp公式，dp[0]和dp[1]航班的计算，都有+10，dp[2]往后的航班就不加10
 *    10  0   -10  0    0   0   ---->按照dp计算公式计算后是10 10 0 0 0
 * 3、 [2,3,20] dp[1] += 20, dp[3] -= 20，中间的值不变
 *    10  20  -10  -20  0   0   ---->按照dp计算公式计算后是10 30 20 0 0  第二个和第三个的值都加了20
 * 4、 [2,5,25] dp[1] += 25, dp[5] -= 25，中间的值不变
 *    10  45  -10  -20  0  -25   ---->按照dp计算公式计算后是10 55 45 25 25 0  第二个和第三个的值都加了20
 * 5、返回n=5，最终的结果就是 10 55 45 25 25
 * */
int* corpFlightBookings2(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int start, end, books, sum;
    if (bookingsColSize = NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *dp = (int*)malloc(sizeof(int) * MAX_BOOK_LIST);
    memset(dp, 0, sizeof(int) * MAX_BOOK_LIST);
    for (int i = 0; i < bookingsSize; i++) {
        start = bookings[i][0];
        end = bookings[i][1];
        books = bookings[i][2];
        dp[start - 1] += books;
        dp[end] -= books;
    }

    sum = 0;
    for (int i = 1; i < n; i++) {
        dp[i] += dp[i - 1];
    }

    *returnSize = n;
    return dp;
}