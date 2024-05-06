/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 71. 简化路径
 * link: https://leetcode-cn.com/problems/simplify-path/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/9.
 */

#include "public.h"

#define MAX_DIR_NUM 100
#define MAX_DIR_PATH 1024

char * simplifyPath(char *path)
{
    char *stack[MAX_DIR_NUM];
    int size = 0;

    char *s = strtok(path,"/");

    while (s != NULL) {
        if (strcmp(s, ".") == 0) {
            // do nothing
        } else if (strcmp(s, "..") == 0) {
            size--;
            if (size < 0) {
                size = 0;
            }
        } else {
            stack[size] = s;
            size++;
        }
        s = strtok(NULL, "/");
    }

    if (size == 0) {
        return "/";
    }

    char *res = (char*)malloc(MAX_DIR_PATH);
    if (res == NULL) {
        return NULL;
    }

    (void)memset(res, 0, MAX_DIR_PATH);
    for (int i = 0; i < size; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }

    return res;
}

/*
int main()
{
    char path[MAX_DIR_PATH] = {"/home//foo/"};

    printf("path[%s] result: [%s]", path, simplifyPath(path));
    return 0;
}*/
