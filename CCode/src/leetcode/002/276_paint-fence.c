/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 276. 栅栏涂色
 * link: https://leetcode-cn.com/problems/paint-fence/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int numWays(int n, int k)
{
    int fn_2 = 0;
    int fn_1 = k;
    int fn = k * k;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return k;
    }

    if (n == 2) {
        return fn;
    }

    // 与前一个相同，n-2要取一种颜色，所以n-1和n能涂的色只有k-1中，所以总数是（k-1）* f（n-2）
    // 与前一个不同，则前一个要取一个颜色，所以n也是有k-1中涂色方案，总数是（k-1）*f（n-1）
    // 综上，总数应该是（k-1）*（f（n-1）+ f（n-2））
    // 后面部分是不是很像斐波那契数列，fn = fn-1 + fn-2；不过千万别用斐波那契数列，这个只是像而已，fn的值是乘了一个系数的。
    for (int i = 3; i <= n; i++) {
        fn_2 = fn_1;
        fn_1 = fn;
        fn = (k - 1) * (fn_1 + fn_2);
    }

    return fn;
}