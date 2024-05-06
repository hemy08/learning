/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 67. 二进制求和
 * link: https://leetcode-cn.com/problems/add-binary/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/23.
 */

#include "public.h"

#define MAX_LEN 10005

unsigned int binaryStringToUint(const char *str)
{
    unsigned int result = 0;
    int len = (int)strlen(str);
    int pos = 0;

    while (len > pos) {
        result |= (unsigned int)(str[pos] - 0x30);
        result = result << 1u;
        pos++;
    }

    return result >> 1u;
}

char *uintToBinaryString(unsigned int num)
{
    char *ret;
    int count = 0;
    char tmp[MAX_LEN] = {0};
    ret = (char*)malloc(sizeof(char) * MAX_LEN);
    if (ret == NULL) {
        return NULL;
    }

    if (num == 0) {
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }

    while (num) {
        int a = (int)(num & 0x01u);
        tmp[count] = (char)(a + 0x30);
        count++;
        num = num >> 1u;
    }
    //tmp[count] = (char)(num & 0x01u + 0x30);
    //count++;

    for (int i = 0; i < count; i++) {
        ret[i] = tmp[count - i - 1];
    }
    ret[count] = '\0';

    return ret;
}

#define MAX_VAL(a,b) ((a) > (b) ? (a) : (b))

char *addBinary(const char *a, const char *b)
{
    int len_a, len_b, len, result, pos, int_a, int_b;
    char *ret;

    if (a == NULL) {
        return (char*)b;
    }

    if (b == NULL) {
        return (char*)a;
    }

    len_a = (int)strlen(a);
    len_b = (int)strlen(b);
    len = GetMaxValue(len_a, len_b) + 1;
    ret = (char*)malloc(sizeof(char) * len);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, len);

    int flag = 0;
    for (int i = 0; i < len; i++) {
        if ((len_a - i - 1) < 0) {
            int_a = 0;
        } else {
            int_a = a[len_a - i - 1] - 0x30;
        }

        if ((len_b - i - 1) < 0) {
            int_b = 0;
        } else {
            int_b = b[len_b - i - 1] - 0x30;
        }

        result = int_a + int_b + flag;
        pos = len - i - 1;
        if (result <= 1) {
            ret[pos] = (char)(result + 0x30);
            flag = 0;
        } else {
            flag = 1;
            if (result == 2) {
                ret[pos] = '0';
            } else {
                ret[pos] = '1';
            }
        }
    }
    if (ret[0] == '0') {
        return &ret[1];
    }

    return ret;
}

// char boolStr[2][6] = {"false", "true"};
/*
void main()
{
    char a[256] = "11";
    char b[256] = "1";

    int int_a = (int)binaryStringToUint(a);

    printf("%s\n", boolStr[int_a]);
}*/
