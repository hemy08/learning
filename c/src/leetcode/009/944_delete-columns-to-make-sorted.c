/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 944. 删列造序
 * link: https://leetcode-cn.com/problems/delete-columns-to-make-sorted/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"

int minDeletionSize( char ** A , int ASize ){

    //the param is used to save the number of the column that is not meet the conditions
    int count = 0 ;

    for( int j = 0 ; j < strlen( A[0] ) ; j++ ){

        for( int i = 0 ; i < ASize - 1 ; i++ ){

            if( A[i][j]  >  A[i+1][j]){

                count++;
                break;

            }

        }

    }

    return count;

}