/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 820. 单词的压缩编码
 * link: https://leetcode-cn.com/problems/short-encoding-of-words/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"

int minimumLengthEncoding(char ** words, int wordsSize){
    int i;
    char str[16000] = {0};  /* 长度大于 2000 * 7 + 2000(#号) 即可 */
    int cnt = 0;
    char* tmp = NULL;

    if (words == NULL || wordsSize == 0) {
        return 0;
    }

    qsort(words, wordsSize, sizeof(words[0]), QsortCmpStrLengthDescOrder); /* 按长度排序，解决像【me, time】这种用例 */
    for (i = 0; i < wordsSize; i++) {
        tmp = strstr(str, words[i]);
        if (tmp == NULL || tmp[strlen(words[i])] != '#') {
            cnt += sprintf(str + cnt, "%s#", words[i]);
        }
    }

    return cnt;
}