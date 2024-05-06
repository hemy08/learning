/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1486. 数组异或操作
 * link: https://leetcode-cn.com/problems/xor-operation-in-an-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/22.
 */

#include "public.h"

int xorOperation(int n, int start){
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= (start + 2 * i);
    }
    return result;
}