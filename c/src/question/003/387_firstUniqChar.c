/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/2.
 */

#include "public.h"

int firstUniqChar(char * s){
    for (int i = 0; i < strlen(s); i++) {
        char* first = strchr(s,s[i]);
        char* flow = strrchr(s,s[i]);

        if ((first == NULL) && (flow == NULL)) {
            return i;
        }
    }

    return -1;
}