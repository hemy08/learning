/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 6. Z 字形变换
 * link: https://leetcode-cn.com/problems/zigzag-conversion/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/21.
 */

#include "public.h"

/*
 * 使用指针申请内存操作，耗时短，内存占用较大
 */

#define MAX_STR_LEN 100

typedef struct CLASS_CVT_ROW_T {
    char str[MAX_STR_LEN];
    int index;
}CVT_ROW_T;

char *convert(char *s, int numRows)
{
    int len = (int)strlen(s);
    CVT_ROW_T *cvt = NULL;

    if ((numRows == 1) || (len < numRows)) {
        return s;
    }

    cvt = (CVT_ROW_T *)malloc(sizeof(CVT_ROW_T) * numRows);
    (void)memset(cvt, 0, sizeof(CVT_ROW_T) * numRows);

    int row = 0;
    int flag = 1;
    for (int i = 0; i < len; i++) {
        int index = cvt[row].index;
        cvt[row].str[index] = s[i];
        cvt[row].index++;
        if ((row + 1) >= numRows) {
            flag = -1;
        }
        if (row <= 0) {
            flag = 1;
        }
        row += flag;
    }

    /* char *result = (char *)malloc(len + 1);
    (void)memset(result, 0, (len + 1));
    for (int i = 0; i < numRows; i++) {
        strcat(result, cvt[i].str);
    } */

    // 这里也可以直接对入参s进行操作
    (void)memset(s, 0, len);
    for (int i = 0; i < numRows; i++) {
        strcat(s, cvt[i].str);
    }
    free(cvt);
    return s;
}

/*
"PAYPALISHIRING"
P   A   H   N
A P L S I I G
Y   I   R
 */

/*
 * 使用结构体数组实现，内存占用较小, 耗时较长
 */
/*
#define MAX_STR_LEN 1024
#define MAX_ROWS 1024

typedef struct CLASS_CVT_ROW_T {
    char str[MAX_STR_LEN];
    int index;
}CVT_ROW_T;

char *convert(char *s, int numRows)
{
    int len = strlen(s);
    CVT_ROW_T cvt[MAX_ROWS];

    if ((numRows == 1) || (len < numRows)) {
        return s;
    }

    (void)memset(cvt, 0, sizeof(CVT_ROW_T) * MAX_ROWS);

    int row = 0;
    int flag = 1;
    for (int i = 0; i < len; i++) {
        int index = cvt[row].index;
        cvt[row].str[index] = s[i];
        cvt[row].index++;
        if ((row + 1) >= numRows) {
            flag = -1;
        }
        if (row <= 0) {
            flag = 1;
        }
        row += flag;
    }

    char *result = (char *)malloc(len + 1);
    (void)memset(result, 0, (len + 1));
    for (int i = 0; i < numRows; i++) {
        strcat(result, cvt[i].str);
    }
    return result;
}
*/

/*
void main()
{
    char s[20] = "PAYPALISHIRING";

    printf("%s", convert(s, 3));
}
*/
