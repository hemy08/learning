/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1025. 除数博弈
 * link: https://leetcode-cn.com/problems/divisor-game/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool divisorGame(int N)
{
    // 取x恒为1，如此，偶数时，谁先行就谁会胜利
    // 奇数时，取一次1之后就变成了偶数，这样谁先行就谁会输
    if (N == 1) {
        return false;
    }
    
    if (N == 2) {
        return true;
    }
    
    if (N > 512) {
        return divisorGame(N - 512);
    } else if (N > 256) {
        return divisorGame(N - 256);
    } else if (N > 128) {
        return divisorGame(N - 128);
    } else if (N > 64) {
        return divisorGame(N - 64);
    } else if (N > 32) {
        return divisorGame(N - 32);
    } else if (N > 16) {
        return divisorGame(N - 16);
    } else if (N > 8) {
        return divisorGame(N - 8);
    } else if (N > 4) {
        return divisorGame(N - 4);
    } else {
        return divisorGame(N - 2);
    }
}

/*
 * 移位的算法
 */
bool divisorGame2(int N)
{
    // N % x == 0，x必然是能整除N的，取1，如此，偶数时，谁先行就谁会胜利
    // 奇数时，取一次1之后就变成了偶数，这样谁先行就谁会输
    if (N == 1) {
        return false;
    }

    if (N == 2) {
        return true;
    }

    // 偶数时，能被2的次方整除，肯定可以被2整除
    // N最大是1000，所以这里取512
    int tmp = N;
    if (tmp >> 9) {
        return divisorGame(N&0x01FF);
    } else if (tmp >> 8) {
        return divisorGame(N&0x00FF);
    } else if (tmp >> 7) {
        return divisorGame(N&0x007F);
    } else if (tmp >> 6) {
        return divisorGame(N&0x003F);
    } else if (tmp >> 5) {
        return divisorGame(N&0x001F);
    } else if (tmp >> 4) {
        return divisorGame(N&0x000F);
    } else if (tmp >> 3) {
        return divisorGame(N&0x0007);
    } else if (tmp >> 2) {
        return divisorGame(N&0x0003);
    } else {
        return divisorGame(N - 2);
    }

}