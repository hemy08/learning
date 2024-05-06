/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 43. 字符串相乘
 * link: https://leetcode-cn.com/problems/multiply-strings/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

char * multiply(char * num1, char * num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    char* ans = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    memset(ans, '0', sizeof(char) * (len1 + len2));
    ans[len1 + len2] = '\0';
    int c = 0;
    for (int i = len2 - 1; i >= 0; i--)
    {
        int b = num2[i] - '0';
        for (int j = len1 - 1; j >= 0; j--)
        {
            int a = num1[j] - '0';
            int d = ans[i + j + 1] - '0';
            int x = a * b + d + c;
            ans[i + j + 1] = x % 10 + '0';
            c = x / 10;
        }
        if (c)
        {
            ans[i] = c + '0';
            c = 0;
        }
    }
    //下面去除前缀0
    int k = 0;
    for (; ans[k] == '0' && k <= len1 + len2; k++);
    if (k == len1 + len2) return "0";
    else ans += k;
    return ans;
}


#define MAX_NUMS_LEN 256

// 两个字符串相加
char * addStringsInverseOrder(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 < len2) {
        for (int i = 0; i < len2; i++) {
            if (i > len1) {
                num1[i] = num2[i];
            } else {
                int tmp = num1[i] - 0x30  + num2[i] - 0x30;
                num1[i] = tmp + 0x30;
            }
        }
    } else {
        for (int i = 0; i < len1; i++) {
            if (i > len2) {
                break;
            }

            int tmp = num1[i] - 0x30  + num2[i] - 0x30;
            num1[i] = tmp + 0x30;
        }
    }

    return num1;
}

// 字符串倒序存放
char *stringsInverseOrder(char *num)
{
    char tmp;
    int len = strlen(num);

    for (int i = 0; i < len; i++) {
        if (len < i + i) {
            break;
        }
        tmp = num[len - 1 - i];
        num[len - i - 1] = num[i];
        num[i] = tmp;
    }

    return num;
}

// 字符串乘以0-9的倍数, 结果倒序存放
char * multiplyInverseOrderOne(char *num1, int num, char *result)
{
    char *start = num1;
    int len = strlen(num1);
    char *end = num1 + len;
    int flag = 0;
    int count = 0;

    while(start != end) {
        int tmp = (*start - 0x30) * num + flag;
        result[count] = tmp % 10 + 0x30;
        flag = tmp / 10;
        start++;
        count++;
    }

    if (flag) {
        result[count] = flag + 0x30;
        count++;
    }

    result[count] = '\0';
    return result;
}

// 字符串乘以0-9的倍数, 结果倒序存放
char *strMovesOne(char *num1)
{
    char *start = num1;
    int len = strlen(num1);
    char *end = num1 + len;
    while ((start != end) && (len > 0)) {
        num1[len] = num1[len - 1];
        len--;
        end--;
    }

    num1[0] = '0';
    num1[len + 1] = '\0';

    return num1;
}

/*
char * multiply2(char * num1, char * num2)
{
    char pre[MAX_NUMS_LEN],cur[MAX_NUMS_LEN];

    memset(pre, 0, sizeof(pre));
    memset(cur, 0, sizeof(cur));

    // num1先倒序下
    num1 = stringsInverseOrder(num1);
    memcpy(pre, num1, strlen(num1));
    printf("pre %s, num1 %s\n", pre, num1);
    while(num2 != '\0') {
        // 乘以单个倍数。结果倒序存放
        cur = multiplyInverseOrderOne(num1, *num2, cur);
        // pre往后挪一个，第一个置为0，因为是倒序存放的，反过来之后，相当于pre*10
        pre = strMovesOne(pre);
        // cur+pre 得到新的pre，倒序存放的，直接相加就行
        pre = addStringsInverseOrder(pre, cur);
        memset(cur, 0, sizeof(cur));
        num2++;
    }

    char *result = (char*)malloc(MAX_NUMS_LEN);
}*/
