/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 771. 宝石与石头
 * link: https://leetcode-cn.com/problems/jewels-and-stones/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int numJewelsInStones(char * J, char * S){
    int count = 0;
    for(int i = 0; i < strlen(S); i++) {
        for(int j = 0; j < strlen(J); j++) {
            if(S[i] == J[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}