/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 657. 机器人能否返回原点
 * link: https://leetcode-cn.com/problems/robot-return-to-origin/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/28.
 */

#include "public.h"

bool judgeCircle(char * moves)
{
    int len =  strlen(moves);
    int ul = 0;
    int rl = 0;

    // len必须是偶数
    if ((len % 2) != 0) {
        return false;
    }

    while (*moves != '\0') {
        switch (*moves) {
            case 'U':
                ul++;
                break;
            case 'D':
                ul--;
                break;
            case 'R':
                rl++;
                break;
            case 'L':
                rl--;
                break;
            default:
                return false;
        }
        moves++;
    }

    if ((ul != 0) || (rl != 0)) {
        return false;
    }

    return true;
}