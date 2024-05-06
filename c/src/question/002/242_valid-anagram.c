/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 242. 有效的字母异位词
 * link: https://leetcode-cn.com/problems/valid-anagram/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool isAnagram(char * s, char * t){
    unsigned long s1,s2,t1,t2;
    s1 = s2 = t1 = t2 = 1;
    while(*s != '\0'){
        *s -=96;
        s1 *= *s;
        s2 += *(s++);
    }
    while(*t != '\0'){
        *t -= 96;
        t1 *= *t;
        t2 += *(t++);
    }
    
    if(s1 == t1 && s2 == t2)
        return true;
    return false;
}


// 1 先对字符串进行排序
// 2 排序后的两个字符串应该完全一样
bool isAnagramQsort(char * s, char * t)
{
    qsort(s, strlen(s), sizeof(char), QsortCmpCharDescOrder);
    qsort(t, strlen(t), sizeof(char), QsortCmpCharDescOrder);

    if (strcmp(s, t) == 0) {
        return true;
    }

    return false;
}