/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 14. 最长公共前缀
 * link: https://leetcode-cn.com/problems/longest-common-prefix/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int strSameSize = 1000;
    int tmpCount = 0;
    int lenMax = 0;
    int j = 0;
    char *pcResult = (char*)malloc(1000);

    if ((strsSize < 1) || (strs == NULL) || (*strs == NULL)) {
        return "";
    }

    if (strsSize == 1)
        return *strs;

    lenMax = (int)strlen(strs[0]);
    memset(pcResult,0, 1000);
    for (int i = 1; i < strsSize; i++) {
        tmpCount = 0;
        for (j = 0; (j < lenMax)&&(j < (int)strlen(strs[i])); j++) {
            if (strs[0][j] != strs[i][j]) {
                break;
            }
            tmpCount++;
        }

        if (tmpCount < strSameSize) {
            strSameSize = tmpCount;
        }
    }

    if ( strSameSize == 0) {
        return "";
    } else {
        memcpy(pcResult,*(strs),strSameSize);
        return  pcResult;
    }
}