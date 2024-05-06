/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 60. 第k个排列
 * link: https://leetcode-cn.com/problems/permutation-sequence/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/5.
 */

#include "public.h"

/*
 * 12 21  n = 2, nums = 2*1
 * 123 132 213 231 312 321 n = 3, nums = 3*2 = 6
 * 1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 xxxxx n = 4, nums = 4*6
 * nums[n+1] = (n + 1) * nums[n] = (n + 1) * n *...*1 = n!
 * k < (n - 1)! first = 1
 * k > (n - 1) * i  first = i
 * first = k / (n - 1)! + 1
 * second = k % (n - 1)! / (n - 2)! + 1
 * */

#define MAX_N_NUM 10

int g_numsPermutation[MAX_N_NUM] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int g_flagPermutation[MAX_N_NUM] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char * getPermutation(int n, int k)
{
    int tmp = k, val, j, cnt;

    if ((n <= 0) || (n > 9)) {
        return NULL;
    }

    char *result = (char*)malloc((n + 1) * sizeof(int));
    memset(result, 0, (n + 1));
    memset(g_flagPermutation, 0, MAX_N_NUM * sizeof(int));

    // 第一个
    /*val = tmp / g_numsPermutation[n - 1];
    g_flagPermutation[val + 1] = 1;
    result[0] = val + '1';
    tmp %= g_numsPermutation[n - 1];*/
    // 按照大小顺序，前(n - 1)!个的第一个字符肯定是1， n~2n的第一个字符肯定是2，......
    for (int i = 0; i < n; i++) {
        val = tmp / g_numsPermutation[n - i - 1];
        cnt = 0;
        for (j = 1; j <= n; j++) {
            if (g_flagPermutation[j] == 0) {
                cnt++;
            }

            if (cnt == val) {
                val = j;
                break;
            }
        }
        g_flagPermutation[val] = 1;
        result[i] = val + '0';
        tmp %= g_numsPermutation[n - i - 1];
    }

    // 给最后一位赋值
    for (int i = 1; i <= n; i++) {
        if (g_flagPermutation[i] == 0) {
            result[n - 1] = i  + '0';
            break;
        }
    }

    return result;
}