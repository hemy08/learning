/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 767. 重构字符串
 * link: https://leetcode-cn.com/problems/reorganize-string/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/30.
 */

#include "public.h"

#define MAX_LEN 500
#define MAX_CHR_TYPE 26


char * reorganizeString(char * S)
{
    int len = (int)strlen(S);
    int counts[MAX_CHR_TYPE][2] = {{0}};

    if (len == 0) {
        return S;
    }

    // 计数
    for (int i = 0; i < len; i++) {
        int index = S[i] - 'a';
        counts[index][0]++;
        counts[index][1] = S[i] - 'a';
    }

    int pos = 0;
    int index = 0;
    int get_num = 0;
    qsort(counts, MAX_CHR_TYPE, sizeof(int) * 2, QsortCmpArrayDescOrder);
    while (pos < len) {
        index = index % MAX_CHR_TYPE;
        // 每次只取俩
        if (counts[index][0] != 0) {
            S[pos++] = (char)('a' + counts[index][1]);
            counts[index][0]--;
            get_num++;
        }
        if (get_num == 2) {
            get_num = 0;
            qsort(counts, MAX_CHR_TYPE, sizeof(int) * 2, QsortCmpArrayDescOrder);
            index = 0;
            continue;
        }
        index++;
    }

    for (int i = 1; i < len; i++) {
        if (S[i] == S[i - 1]) {
            return "";
        }
    }
    return S;
}

/*
void main()
{
    char testcase[500] = "vvvlo";

    printf("%s", reorganizeString(testcase));
}
*/
