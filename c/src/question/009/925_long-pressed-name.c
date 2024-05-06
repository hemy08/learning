/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 925. 长按键入
 * link: https://leetcode-cn.com/problems/long-pressed-name/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/21.
 */

#include "public.h"

bool isLongPressedName(char * name, char * typed)
{
    char c;
    int count_name, count_typed;

    char *c_name = name;
    char *c_typed = typed;

    c = *c_name;
    count_name = 0;
    count_typed = 0;
    while (true) {
        // 计算c_name字符个数
        while (*c_name == c) {
            count_name++;
            c_name++;
        }

        while (*c_typed == c) { // 计算c_type重复次数
            count_typed++;
            c_typed++;
        }

        // name比typed多，返回false
        if (count_name > count_typed) {
            return false;
        }

        // name和type中有一个结束了，另外一个没有结束
        if (*c_name == '\0') {
            if (*c_typed == '\0') {
                return true;
            }

            return false;
        } else {
            if (*c_typed == '\0') {
                return false;
            }
        }

        // 当前字符属于重复输入，找下一个
        c = *c_name;
        count_name = 0;
        count_typed = 0;
    }
}

bool isLongPressedName2(char * name, char * typed)
{
    char c;
    int count_name, count_typed;

    char *c_name = name;
    char *c_typed = typed;

    c = *c_name;
    count_name = 0;
    count_typed = 0;
    while (*c_typed != '\0') {
        // 计算c_name字符个数
        if (*c_name == c) {
            count_name++;
            c_name++;
            continue;
        }

        // 计算c_type重复次数
        if (*c_typed == c) {
            count_typed++;
            c_typed++;
            continue;
        }

        // name比typed多，返回false
        if (count_name > count_typed) {
            return false;
        }

        if (*c_name == '\0') {
            return false;
        }

        // 当前字符属于重复输入，找下一个
        c = *c_name;
        count_name = 0;
        count_typed = 0;
    }

    if (*c_name != '\0') {
        return false;
    }

    return true;
}

/*
void main()
{
    char name[20] = "rz";
    char typed[20] = "r";

    isLongPressedName(name, typed);
}*/
