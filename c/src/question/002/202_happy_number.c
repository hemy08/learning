/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 202. 快乐数
 * link: https://leetcode-cn.com/problems/happy-number/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/*
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
 *如果 n 是快乐数就返回 True ；不是，则返回 False 。
 */
int g_sqrArr[10] = {0,1,4,9,16,25,36,49,64,81};

bool isHappy(int n){
    int count = 0, sum = 0, i;
    while(1) {

        i = n % 10;
        sum += g_sqrArr[i];
        n /= 10;
        count++;

        if ((sum == 1) && (n == 0)) {
            return true;
        }

        if(n == 0) {
            n = sum;
            sum = 0;
        }

        if (count >= 50) {
            return false;
        }
    }
    return false;
}