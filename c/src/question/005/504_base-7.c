/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 504. 七进制数
 * link: https://leetcode-cn.com/problems/base-7/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/7/30.
 */

#include "public.h"
#define MAX_SEVEN_LEN 32

char * convertToBase7(int num)
{
    char tmpRes[MAX_SEVEN_LEN] = {0};
    int number = abs(num);
    int count = 0;

    while (number >= 7) {
        tmpRes[count] = (number % 7) + 0x30;
        number = number / 7;
        count++;
        // printf("%s , num %d\n", tmpRes, number);
    }
    tmpRes[count] = number + 0x30;
    count++;
    // printf("%s , count %d\n", tmpRes, count);

    char *result = (char*)malloc(sizeof(char) * MAX_SEVEN_LEN);

    memset(result, 0, MAX_SEVEN_LEN);
    if (num < 0) {
        result[0] = '-';
        for (int i = 0; i < count; i++) {
            result[i + 1] = tmpRes[count - i - 1];
        }
    } else {
        for (int i = 0; i < count; i++) {
            result[i] = tmpRes[count - i - 1];
        }
    }

    return result;
}