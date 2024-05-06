/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1055. 形成字符串的最短路径
 * link: https://leetcode-cn.com/problems/shortest-way-to-form-string/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

int shortestWay(char * source, char * target)
{
    // 以目标字符串为基准，向source字符串查找满足条件的子字符串，找到一个，计数+1；

    int lent = (int)strlen(target);
    int lens = (int)strlen(source);
    int count = 0;
    char *start = target;

    while (start < (target + lent)) {
        int find = 0;
        for (int i = 0; i < lens; i++) {
            if (source[i] == *start) {
                *start++;
                find = 1;
            }
        }
        count++;

        // 没找到匹配的
        if (find == 0) {
            return -1;
        }
    }

    return count;
}


/*
void main()
{
    char source[100] = "xyz";
    char target[100] = "xzyxz";

    printf("%d", shortestWay(source, target));
}*/
