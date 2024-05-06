/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 843. 猜猜这个单词
 * link: https://leetcode-cn.com/problems/guess-the-word/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */
#define _MAX_TRIES_ 10

void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    int i,j;
    int round=0;
    int result = 0;
    int *score = (int*)calloc(wordlistSize, sizeof(int));
    char * tmp;
    
    int counter = 0;
    
    tmp = wordlist[0];
    wordlist[0] = wordlist[wordlistSize/2];
    wordlist[wordlistSize/2] = tmp;

    for(round=0; round<_MAX_TRIES_; round++){
        for(i=0; i<wordlistSize; i++){
            if(score[i] == round){
                result = guess(master, wordlist[i]);                
                for(j=0; j<wordlistSize; j++){                    
                    if(score[j] == round && i != j && compareFindSecretWord(wordlist[i], wordlist[j]) == result){
                        score[j] = round + 1;                     
                    }              
                }                
                break;
            }
        }

    }

}

int compareFindSecretWord(char *s1, char* s2){
    int result = 0;

    while(*s1){
        if(*s1==*s2){
            result++;
        }
        s1++;
        s2++;
    }

    return result;
}