/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 415. 字符串相加
 * link: https://leetcode-cn.com/problems/add-strings/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_NUM_LEN 5100
char g_acResult[MAX_NUM_LEN + 5] = {0};

// 调整A和B，使长度一致, 并且首位置0
void ChangeSourceString(char *A, int lenA, char *B, int lenB) {
    int maxLen = lenA > lenB ? lenA  : lenB;
    int i= 0;

    for (i = maxLen + 1; i >= 0 ; i--) {
        if (i + lenA >= maxLen) {
            A[i] = A[i - (maxLen - lenA)];
        } else {
            A[i] = '0';
        }

        if (i + lenB >= maxLen) {
            B[i] = B[i - (maxLen - lenB)];
        } else {
            B[i] = '0';
        }
    }
}


// 从倒数位置开始进行相加求和
void SumAndPrint(const char *A, const char *B, int len)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int sum = 0;
    int flag = 0;

    for (i = (len - 1); i >= 0; i--) {
        a = A[i] - 0x30;
        b = B[i] - 0x30;
        sum = a + b + flag;
        if (sum >= 10) {
            sum -= 10;
            flag = 1;
        } else {
            flag = 0;
        }
        g_acResult[i + 1] = (char)(sum + 0x30);
    }

    if (flag) {
        g_acResult[0] = (char)(flag + 0x30);
    } else {
        // 首位为0，则前移一位
        for (i = 1; i <= len; i++) {
            g_acResult[i - 1] = g_acResult[i];
        }
        g_acResult[len] = '\0';
    }
}

char * addStrings(char * num1, char * num2)
{
    char A[MAX_NUM_LEN] = {0};
    char B[MAX_NUM_LEN] = {0};
    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);
    
    strcpy(A,num1);
    strcpy(B,num2);
    memset(g_acResult, 0, (int)sizeof(g_acResult));
    
    ChangeSourceString(A, len1, B, len2);
    SumAndPrint(A, B, (int)strlen(A));
    return g_acResult;
}

/*
 * 直接字符串从后往前相加
 * 如果最首位是0，从后移一位返回
 * */
#define MAX_VAL(a,b) ((a) > (b) ? (a) : (b))

int getCharToInt(const char *nums, int *index)
{
    int len = *index;
    int result = 0;
    if (len > 0) {
        result = nums[len - 1] - 0x30;
        len--;
    }

    *index = len;

    return result;
}

char getNumberAddResult(int num1, int num2, int *flag)
{
    int number;
    char result;
    number = num1 + num2 + *flag;
    if (number >= 10) {
        number -= 10;
        *flag = 1;
    } else {
        *flag = 0;
    }

    result = (char)(number + 0x30);
    return result;
}

char *addStringsGetResult(char *result, int count, char * num1, char * num2)
{
    int num1_len = (int)strlen(num1);
    int num2_len = (int)strlen(num2);
    int tmp1, tmp2;
    int flag = 0;

    if (result == NULL) {
        return NULL;
    }

    while ((num1_len >= 0) && (num2_len >= 0) && (count >= 0 )) {
        tmp1 = getCharToInt(num1, &num1_len);
        tmp2 = getCharToInt(num2, &num2_len);
        result[count] = getNumberAddResult(tmp1, tmp2, &flag);
        count--;
    }

    if (flag) {
        result[0] = '1';
    }

    if (result[0] == '0') {
        result++;
    }

    return result;
}

char * addStrings2(char * num1, char * num2)
{
    int num1_len = (int)strlen(num1);
    int num2_len = (int)strlen(num2);
    char *result = NULL;

    if (num1_len == 0) {
        return num2;
    }

    if (num2_len == 0) {
        return num1;
    }

    int count = GetMaxValue(num1_len, num2_len);
    result = (char*)malloc(sizeof(char) * (count + 2));
    if (result == NULL) {
        return NULL;
    }
    memset(result, '\0', sizeof(char) * (count + 2));

    return addStringsGetResult(result, count, num1, num2);
}