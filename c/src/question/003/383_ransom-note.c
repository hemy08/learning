/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:383. 赎金信
 * link:https://leetcode-cn.com/problems/ransom-note/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/4.
 */

#include "public.h"

bool canConstruct(char * ransomNote, char * magazine)
{
    int rans[26] = {0};
    int maga[26] = {0};

    int lena = strlen(ransomNote);
    int lenb = strlen(magazine);
    if (lenb < lena) {
        return false;
    }

    for (int i = 0;i < lena; i++) {
        int index = ransomNote[i] - 'a';
        rans[index]++;
    }

    for (int i = 0;i < lenb; i++) {
        int index = magazine[i] - 'a';
        maga[index]++;
    }

    for (int i = 0;i < 26; i++) {
        if (rans[i] > maga[i]) {
            return false;
        }
    }

    return true;
}