/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 415. 字符串相加
 * link: https://leetcode-cn.com/problems/add-strings/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

// 从糖果或者孩子开始，进行匹配。
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    int child = 0, cookie = 0;

    if ((gSize == 0) || (sSize == 0)) {
        return 0;
    }

    qsort(g, gSize, sizeof(int), QsortCmpArrayAscOrder);
    qsort(s, sSize, sizeof(int), QsortCmpArrayAscOrder);

    while ((child < gSize) && (cookie < sSize)) {
        // sj分配给gi，i加一，表示已经分配过
        if (g[child] <= s[cookie]) {
            child++;
        } 
        
        // 分配不成功，j也加一，说明这块饼干分不出去
        cookie++;
    }
    
    return child;
}
