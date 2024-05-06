/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 8. 字符串转换整数 (atoi)
 * link: https://leetcode-cn.com/problems/string-to-integer-atoi/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/22.
 */

#include "public.h"

int myAtoi(char * s)
{
    //    读入字符串并丢弃无用的前导空格
    //    检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
    //    读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
    //    将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
    //    如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
    //    返回整数作为最终结果。

    int signed_flag = 1;
    int MaxInt32 = INT32_MAX;
    int MinInt32  = INT32_MIN;

    int n = strlen(s);
    char *begin = s;
    char *end = s + n - 1;
    while (begin < end) {
        // 去掉前导空格
        if (*begin == ' ') {
            begin++;
            continue;
        }

        // 符号位为-
        if (*begin == '-') {
            begin++;
            signed_flag = -1;
            break;
        }

        // 符号位为+,或者没有符号位
        if (*begin == '+') {
            begin++;
        }
        signed_flag = 1;
        break;
    }
    // printf("begin %s\n", begin);
    // printf("signed_flag %d\n", signed_flag);

    long sum = 0;
    while (begin <= end) {
        if ((*begin > '9') || (*begin < '0')) {
            break;
        }
        sum = sum * 10 + (*begin - '0');
        // printf("begin %c sum %ld\n", *begin, sum);
        begin++;
        if ((sum*signed_flag) >= MaxInt32) {
            return MaxInt32;
        }

        if ((sum*signed_flag) <= MinInt32 ) {
            return MinInt32;
        }
    }


    return (int)sum*signed_flag;
}