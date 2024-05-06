/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 860. 柠檬水找零
 * link: https://leetcode-cn.com/problems/lemonade-change/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool lemonadeChange(int* bills, int billsSize)
{
    // 五元和十元个数，20元只进不出，不计数
    int money5 = 0;
    int money10 = 0;

    for (size_t i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5) {
            money5++;
        } else if (bills[i] == 10) {
            money10++;
            if (money5 > 0) {
                money5--;
            } else {
                return false;
            }
        } else {
            // 找零一个10元，一个5元 或者 找零3个5元
            if ((money10 > 0) && (money5 > 0)) {
                money10--;
                money5--;
            } else if (money5 > 3){
                money5 -= 3;
            } else {
                return false;
            }
        }
    }
    
    return true;
}