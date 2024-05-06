/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 205. 同构字符串
 * link: https://leetcode-cn.com/problems/isomorphic-strings/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_STR_NUM 128
bool isIsomorphic1(char * s, char * t){
    int a[MAX_STR_NUM]={0};
    int b[MAX_STR_NUM]={0};
    // 如果映射关系唯一，每次加1之后，索引值应该是一样的
    for(int i = 0; s[i]; ++i) {
        a[s[i]] += i+1;
        b[t[i]] += i+1;
        if(a[s[i]] != b[t[i]]) return false;
    }
    return true;
}

#define MAX_STR_NUM 128
bool isIsomorphic2(char * s, char * t){
    char tags[MAX_STR_NUM] = {0};
    char tagt[MAX_STR_NUM] = {0};
    int j = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if ((tagt[t[i]] == 0) && (tags[s[i]] == 0)) {
            tags[s[i]] = t[i];
            tagt[t[i]] = s[i];
            //printf("%d: tags[%d] = %c, tagt[%d] =  %c\n",i,s[i],tags[s[i]],t[i],tagt[t[i]]);
            continue;
        }
        //printf("%d: tags[%d] = %c, tagt[%d] =  %c\n",i,s[i],tags[s[i]],t[i],tagt[t[i]]);
        if ((tags[s[i]] != t[i]) || (tagt[t[i]] != s[i])) {
            return false;
        }
    }

    return true;
}


#define MAX_STR_NUM 128
bool isIsomorphic3(char * s, char * t){
    char tag[MAX_STR_NUM] = {0};
    int index = 0;
    int find = 0;
    
    for (int i = 0; i < strlen(s); i++) {        
        for (int j = 0; j < MAX_STR_NUM; j++) {
            if (tag[j] == t[i]) {
                find = 1;
                break;
            }
        }
        if ((find != 1) && (tag[s[i]] == 0)) {
            tag[s[i]] = t[i];
            printf("tag[%d] %c\n",index, tag[s[i]]);
        }
        find = 0;
    }
    
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tag[s[i]];
    }
    
    if (strcmp(s,t) == 0) {
        return true;
    } else {
        return false;
    }
}